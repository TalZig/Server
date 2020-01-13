//
// Created by tal on 7.1.2020.
//

#ifndef MILESTONE2__BESTFIRSTSEARCH_H_
#define MILESTONE2__BESTFIRSTSEARCH_H_
#include "iSearcher.h"
#include "queue"
#include "stack"
#include "set"
template<typename T>
class BestFirstSearch : public iSearcher<T> {
  priority_queue<State<T> *> openQue;
  set<State<T> *> closedSet;
  set<State<T> *> openSet;
  vector<State<T> *> listOfSuccessors;
  void pushToOpenQue(State<T> *state) {
    openSet.insert(state);
    openQue.push(state);
  }

  void addToClosedSet(State<T> *newVal) {
    closedSet.insert(newVal);
  }

  bool isInClosedSet(State<T> *state) {
    return (closedSet.find(state) != closedSet.end());
  }
  bool isInOpenSet(State<T> *state) {
    return (openSet.find(state) != openSet.end());
  }
  State<T> *popOpenList() {
    State<T> *tempState = openQue.top();
    openQue.pop();
    openSet.erase(tempState);
    return tempState;
  }
  void updateOpenQue(State<T> *state) {
    stack<State<T> *> tempStack;
    while (!openQue.empty()) {
      tempStack.push(popOpenList());
    }
    while (!tempStack.empty()) {
      openQue.push(tempStack.top());
      openSet.insert(tempStack.top());
      tempStack.pop();
    }
  }
  void addToOpenList(State<T> *state) {
    openQue.push(state);
    //todo need updated the push to que mathod!
    openSet.insert(state);
  }
 public:
  State<T> *search(Searchable<T> *search_able) override {
    pushToOpenQue(search_able->getInitialState());
    addToOpenList(search_able->getInitialState());
    State<T> *currentState;
    while (openQue.size() > 0) {
      this->numberOfNodesEvaluated++;
      currentState = openQue.top();
      openQue.pop();
      this->addToClosedSet(currentState);
      if (currentState->equals(*(search_able->getGoalState()))) {
        break;
      }
      listOfSuccessors = search_able->getSuccessors(currentState);
      for (int i = 0; i < listOfSuccessors.size(); i++) {
        if (!this->isInClosedSet(listOfSuccessors[i]) && !this->isInOpenSet(listOfSuccessors[i])) {
          (listOfSuccessors[i])->prev = currentState;
          pushToOpenQue(listOfSuccessors[i]);
        } else {
          if (!this->isInOpenSet((listOfSuccessors[i])))
            pushToOpenQue(listOfSuccessors[i]);
          else {
            (listOfSuccessors[i])->costOfTrack = currentState->costOfTrack +
                listOfSuccessors[i]->state->value;
            (listOfSuccessors[i])->prev = currentState;
            //(listOfSuccessors[i])->state->value += currentState->state->value;
            updateOpenQue(listOfSuccessors[i]);
          }
        }
      }
    }
  }
};

#endif //MILESTONE2__BESTFIRSTSEARCH_H_
