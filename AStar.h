//
// Created by tal on 7.1.2020.
//

#ifndef MILESTONE2__ASTAR_H_
#define MILESTONE2__ASTAR_H_

#include "iSearcher.h"
#include "set"
#include <cmath>
#include <queue>
template<typename T>
class AStar : public iSearcher<T> {
  priority_queue<State<T> *, vector<State<T> *>, compareStateAStar<T>> open;
  set<State<T> *> openSet;
  State<T> *goal;
  State<T> *startingState;
  void insertToOpenSet(State<T> *state) {
    open.push(state);
    openSet.insert(state);
  }
  void removeFromOpen() {
    State<T> *temp = open.top();
    openSet.erase(temp);
    open.pop();
  }
  State<T> *search(Searchable<T> *search_able) {
    goal = search_able->getGoalState();
    State<T> *current;
    startingState = search_able->getInitialState();
    set<State<T> *> closedSet;
    insertToOpenSet(startingState);
    vector<State<T> *> neighbours;
    startingState->costOfTrack = 0;
    startingState->fCost = hCost(startingState);
    while (!open.empty()) {
      this->numberOfNodesEvaluated++;
      current = open.top();
      closedSet.insert(current);
      removeFromOpen();
      if (current->equals(*goal)) {
        //todo traceBack
        break;
      }
      neighbours = search_able->getSuccessors(current);
      for (int i = 0; i < neighbours.size(); i++) {
        int tentative_g_score = current->costOfTrack;
        int tentetive_h_score = hCost(current);
        if ((!openSet.count(neighbours[i]) || tentative_g_score + neighbours[i]->state->getValue() < neighbours[i]->costOfTrack) &&
            !closedSet.count(neighbours[i])) {
          neighbours[i]->prev = current;
          neighbours[i]->costOfTrack = current->costOfTrack + neighbours[i]->state->getValue();
          neighbours[i]->fCost = neighbours[i]->costOfTrack + hCost(neighbours[i]);
          if (!openSet.count(neighbours[i]))
            insertToOpenSet(neighbours[i]);
        }
      }
    }
    cout << to_string(this->numberOfNodesEvaluated) << endl;
  }
  int hCost(State<T> *state1) {
    int x;
    int y;
    x = abs(state1->state->getX() - goal->state->getX());
    y = abs(state1->state->getY() - goal->state->getY());
    return (int) (x + y);
  }
  int gCost(State<T> *state1) {
    int x;
    int y;
    x = abs(state1->state->getX() - startingState->state->getX());
    y = abs(state1->state->getY() - startingState->state->getY());
    return (int) (x + y);
  }
};

#endif //MILESTONE2__ASTAR_H_
