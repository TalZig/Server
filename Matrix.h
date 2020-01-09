//
// Created by yoel on 09/01/2020.
//

#ifndef SERVER__MATRIX_H_
#define SERVER__MATRIX_H_

#include <vector>
#include <string>
#include <algorithm>
#include "Searchable.h"
template <typename T>
class Matrix : public Searchable<pair<int,int>> {
 vector<vector<State<pair<int, int>>*>> mat;
 public:
  Matrix(vector<string> lines) {
    // save last 2 lines in order to create
    string goalLine = lines.back();
    lines.pop_back();
    string initLine = lines.back();
    lines.pop_back();

    //create vector of vector

    for (int i = 0; i < lines.size(); ++i) {
      vector<State<pair<int,int>>> line;
      vector<double> values = createValuesVector(lines[i]);
      for (int j = 0; j < values.size(); ++j) {
        pair<int, int> pair1;
        pair1.first = i;
        pair1.second = j;
        line.push_back(new State<T>(pair1, values[j]));
      }
      mat.push_back(line);
    }

    // create initial and goal states
    initLine.erase(std::remove_if(initLine.begin(), initLine.end(), ::isspace), initLine.end());
    string temp = initLine;
    auto find = initLine.find_first_of(',');
    int x = stoi(temp.substr(0,find-1));
    int y = stoi(initLine.substr(find+1,initLine.size()-find));
    pair<int, int> init1;
    init1.first = x;
    init1.second = y;
    this->initialState = new State<T>(init1, mat[x][y]);

    goalLine.erase(std::remove_if(goalLine.begin(), goalLine.end(), ::isspace), goalLine.end());
    temp = goalLine;
    find = goalLine.find_first_of(',');
    x = stoi(temp.substr(0,find-1));
    y = stoi(goalLine.substr(find + 1, goalLine.size() - find));
    pair<int, int> goal1;
    goal1.first = x;
    goal1.second = y;
    this->initialState = new State<T>(goal1, mat[x][y]);
  }

  vector<double> createValuesVector (string line) {
    vector<double> values;
    double val;
    line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());
    auto find = line.find_first_of(',');
    while (find != string::npos) {
      string temp = line;
      temp.substr(0, find-1);
      line.erase(0, find);
      val = stod(temp);
      values.push_back(val);
    }
    //push last value
    val = stod(line);
    values.push_back(val);
    return values;
  }

  string traceBack(State<pair<int,int>> *init, State<pair<int,int>> *goal) override {
    string ans = "";
    State<pair<int, int>>* curr = goal;
    State<pair<int, int>>* previous = goal->prev;
    while (!previous->equals(*init)) {
      if (previous->state.first > curr->state.first) {
        ans += "Right,";
      } else if (previous->state.first < curr->state.first) {
        ans += "Left,";
      } else if (previous->state.second > curr->state.second) {
        ans += "Down,";
      } else {
        ans += "Up,";
      }
      previous = previous->prev;
      curr = curr->prev;
    }
    //check last move
    if (previous->state.first > curr->state.first) {
      ans += "Right\n";
    } else if (previous->state.first < curr->state.first) {
      ans += "Left\n";
    } else if (previous->state.second > curr->state.second) {
      ans += "Down\n";
    } else {
      ans += "Up\n";
    }
    return ans;
  }
};

#endif //SERVER__MATRIX_H_
