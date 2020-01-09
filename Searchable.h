//
// Created by tal on 7.1.2020.
//

#ifndef MILESTONE2__SEARCHABLE_H_
#define MILESTONE2__SEARCHABLE_H_
#include "State.h"
#include "list"
#include "vector"
using namespace std;
template <typename T>
class Searchable {
 protected:
  State<T> *initialState;
  State<T> *goalState;
 public:
  State<T>* getInitialState () {
    return initialState;
  }

  State<T>* getGoalState(){
    return goalState;
  }

  virtual vector<State<T>*> getSuccessors(State<T>*) = 0;

  virtual string traceBack(State<T> *init, State<T> *goal) {
    return "";
  }
};

#endif //MILESTONE2__SEARCHABLE_H_
