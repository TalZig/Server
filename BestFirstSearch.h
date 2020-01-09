//
// Created by tal on 7.1.2020.
//

#ifndef MILESTONE2__BESTFIRSTSEARCH_H_
#define MILESTONE2__BESTFIRSTSEARCH_H_
#include "Searcher.h"
#include "queue"
template<typename T>
class BestFirstSearch : public Searcher<T>{
    priority_queue<State<T>> openQue;
  State<T> search(Searchable<T> search_able) override {
    openQue.push(search_able.getInitialState());
    State<T> currentState = search_able.getInitialState();
    currentState.value = -currentState.value;
    openQue.push(currentState);
    addToOpenList(search_able.getInitialState());
    while(openQue.size() > 0){
      State<T> currentState = openQue.top();
      openQue.pop();
      this->addToClosedList(currentState);
      if(currentState.state == )
    }
  }
};

#endif //MILESTONE2__BESTFIRSTSEARCH_H_
