//
// Created by tal on 7.1.2020.
//

#ifndef MILESTONE2__SEARCHABLE_H_
#define MILESTONE2__SEARCHABLE_H_
#include "State.h"
#include "list"
using namespace std;
template <typename T>
class Searchable {
  State<T> *initialState;
  State<T> *goalState;
 public:
  State<T>* getInitialState () {
    return initialState;
  }

  State<T>* getGoalState(){
    return goalState;
  }
  virtual list<State<T>*> getSuccessors(State<T>*) = 0;
};

#endif //MILESTONE2__SEARCHABLE_H_
