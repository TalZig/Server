//
// Created by yoel on 09/01/2020.
//

#ifndef SERVER__MATRIX_H_
#define SERVER__MATRIX_H_

#include <vector>
#include <string>
#include <algorithm>
#include "Searchable.h"
#include "Point.h"
using namespace std;
//template <typename T>
class Matrix : public Searchable<Point> {
  State<Point> *initialState;
  State<Point> *goalState;
  vector<vector<State<Point>*>> mat;
 public:
  Matrix(vector<string> lines) {
    // save last 2 lines in order to create
    string goalLine = lines.back();
    lines.pop_back();
    string initLine = lines.back();
    lines.pop_back();

    //create vector of vector
    for (int i = 0; i < lines.size(); ++i) {
      vector<State<Point>*> line;
      vector<double> values = createValuesVector(lines[i]);
      for (int j = 0; j < values.size(); ++j) {
        Point* p = new Point(i, j, values[j]);
        line.push_back(new State<Point>(p));
      }
      mat.push_back(line);
    }

    string temp1;
    // create initial and goal states
    initLine.erase(std::remove_if(initLine.begin(), initLine.end(), ::isspace), initLine.end());
    string temp = initLine;
    auto find = initLine.find_first_of(',');
    temp1 = initLine.substr(0,find);
    int x = stoi(temp1);
    initLine = temp;
    find = initLine.find_first_of(',');
    initLine.erase(0, find+1);
    find = initLine.find_first_of(',');
    temp1 = initLine.substr(find+1,initLine.size()-find);
    int y = stoi(temp1);
    this->initialState = mat[x][y];

    //this->initialState = new State<pair<int,int>>(init1, mat[x][y]);

    goalLine.erase(std::remove_if(goalLine.begin(), goalLine.end(), ::isspace), goalLine.end());
    temp = goalLine;
    find = goalLine.find_first_of(',');
    x = stoi(temp.substr(0,find));
    goalLine = temp;
    find = goalLine.find_first_of(',');
    goalLine.erase(0, find+1);
    find = goalLine.find_first_of(',');
    y = stoi(goalLine.substr(find + 1, goalLine.size() - find));
    pair<int, int> goal1;
    this->goalState = mat[x][y];
  }

  State<Point> *getInitialState() override {
    return initialState;
  }
  State<Point> *getGoalState() override {
    return goalState;
  }
//
//  State<Point>* getInitialState() override {
//    this->initialState;
//  }
//
//  State<Point>* getGoalState() override {
//    this->goalState;
//  }

  vector<State<Point> *> getSuccessors(State<Point> *s) override {
    vector<State<Point>*> successors;
    int x = s->state->getX();
    int y = s->state->getY();

    if(x+1 < this->mat.size()) {
      successors.push_back(mat[x+1][y]);
    }
    if(x-1 >= 0) {
      successors.push_back(this->mat[x-1][y]);
    }
    if(y+1 < this->mat.size()) {
      successors.push_back(mat[x][y+1]);
    }
    if(y-1 >= this->mat.size()) {
      successors.push_back(mat[x][y-1]);
    }
  }

  vector<double> createValuesVector (string line) {
    vector<double> values;
    double val;
    string temp;
    line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());
    auto find = line.find_first_of(',');
    while (find != string::npos) {
      temp = line;
      line.substr(0, find-1);
      val = stod(line);
      values.push_back(val);
      auto find2 = temp.find_first_of(',');
      line = temp.erase(0, find2+1);
      find = line.find_first_of(',');
    }
    //push last value
    val = stod(line);
    values.push_back(val);
    return values;
  }

  string traceBack(State<Point> *init, State<Point> *goal) override {
    string ans = "";
    State<Point>* curr = goal;
    State<Point>* previous = goal->prev;

    // insert last move
    if (previous->state->getY() > curr->state->getY()) {
      ans += "Right\n";
    } else if (previous->state->getX() < curr->state->getX()) {
      ans += "Left\n";
    } else if (previous->state->getY() > curr->state->getY()) {
      ans += "Down\n";
    } else {
      ans += "Up\n";
    }

    while (!previous->equals(*init)) {
      if (previous->state->getY() > curr->state->getY()) {
        ans = "Right, " + ans;
      } else if (previous->state->getX() < curr->state->getX()) {
        ans += "Left, " + ans;
      } else if (previous->state->getY() > curr->state->getY()) {
        ans += "Down, " + ans;
      } else {
        ans += "Up, " + ans;
      }
      previous = previous->prev;
      curr = curr->prev;
    }
    //insert first move
    if (previous->state->getY() > curr->state->getY()) {
      ans = "Right, " + ans;
    } else if (previous->state->getX() < curr->state->getX()) {
      ans += "Left, " + ans;
    } else if (previous->state->getY() > curr->state->getY()) {
      ans += "Down, " + ans;
    } else {
      ans += "Up, " + ans;
    }

    // todo add values?

    return ans;
  }

};

#endif //SERVER__MATRIX_H_
