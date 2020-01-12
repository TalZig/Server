//
// Created by tal on 7.1.2020.
//

#ifndef MILESTONE2__ASTAR_H_
#define MILESTONE2__ASTAR_H_

#include "iSearcher.h"
#include "set"
#include <queue>
template<typename T>
class AStar : public iSearcher<T> {
  priority_queue<State<T>*> open;
  State<T> search(Searchable<T>* search_able) {
    set<State<T>*> open;

    open.insert(search_able->getInitialState());
  }
  double hCost(State<T> state1,State<T> goal){

  }
};

#endif //MILESTONE2__ASTAR_H_
