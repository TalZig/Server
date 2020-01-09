//
// Created by tal on 7.1.2020.
//

#ifndef MILESTONE2__SEARCHER_H_
#define MILESTONE2__SEARCHER_H_

#include "iSearcher.h"
#include "list"
#include "unordered_map"
#include "hash_set"
using namespace std;
template<typename T>
class Searcher : public iSearcher<T> {
 protected:
  list<State<T>> openList;
  hash<State<T>> closedList;
 public:
  void addToOpenList(T newVal) {
    openList.push_back(newVal);
  }

  void addToClosedList(T newVal) {
    closedList.push_back(newVal);
  }

  State<T> popOpenList(){
    State<T> tempState = openList.front();
    openList.pop_front();
    return tempState;
  }
};

#endif //MILESTONE2__SEARCHER_H_
