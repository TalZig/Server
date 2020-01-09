//
// Created by tal on 7.1.2020.
//

#ifndef MILESTONE2__SEARCHABLE_H_
#define MILESTONE2__SEARCHABLE_H_
#include "State.h"
template <typename T>
class Searchable {
  State<T> initialState;
  State<T> goalState;
 public:
  State<T> getInitialState () {
    return initialState;
  }

  State<T> getGoalState(){
    return goalState;
  }
};

#endif //MILESTONE2__SEARCHABLE_H_
