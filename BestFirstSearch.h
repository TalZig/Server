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
  priority_queue<State<T>> openQue;
  set<State<T>> closedSet;
  set<State<T>> openSet;
  list<State<T>> listOfSuccessors;

  void pushToOpenQue(State<T> state) {
    openSet.insert(state);
    openQue.push(state);
  }

  void addToClosedSet(T newVal) {
    closedSet.push_back(newVal);
  }

  bool isInClosedSet(State<T> state) {
    return (closedSet.find(state) != closedSet.end());
  }
  bool isInOpenSet(State<T> state) {
    return (openSet.find(state) != openSet.end());
  }
  State<T> popOpenList() {
    State<T> tempState = openQue.front();
    openQue.pop_front();
    openSet.erase(tempState);
    return tempState;
  }
  void updateOpenQue(State<T> state) {
    stack<State<T>> tempStack;
    while (!openQue.empty()) {
      tempStack.push(popOpenList());
    }
    while (!tempStack.empty()) {
      openQue.push(tempStack.top());
      openSet.insert(tempStack.top());
      tempStack.pop();
    }
  }
 public:
  State<T> search(Searchable<T> search_able) override {
    pushToOpenQue(search_able.getInitialState());
    addToOpenList(search_able.getInitialState());
    State<T> currentState;
    while (openQue.size() > 0) {
      currentState = openQue.top();
      currentState.value = -currentState.value;
      openQue.pop();
      this->addToClosedSet(currentState);
      if (currentState.equals(search_able.getGoalState())) {
        break;
      }
      listOfSuccessors = search_able.getSuccessors(currentState);
      while (!listOfSuccessors.empty()) {
        typename list<State<T>>::iterator it = listOfSuccessors.begin();
        if (!this->isInClosedSet(*it) && !this->isInOpenSet(*it)) {
          (*it).prev = currentState;
          pushToOpenQue(*it);
        } else {
          if (!this->isInOpenSet((*it)))
            pushToOpenQue(*it);
          else {
            (*it).value -= currentState.value;
            (*it).prev = currentState;
            (*it).value += currentState.value;
            updateOpenQue((*it));
          }
        }
        listOfSuccessors.pop_front();
      }
    }
  }
};

#endif //MILESTONE2__BESTFIRSTSEARCH_H_
