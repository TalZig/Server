//
// Created by tal on 7.1.2020.
//

#ifndef MILESTONE2__SEARCHER_H_
#define MILESTONE2__SEARCHER_H_

#include "iSearcher.h"
#include "list"
#include "unordered_map"
#include "set"
using namespace std;
template<typename T>
class SearchSolver : public iSearcher<T> {
 protected:
  list<State<T>> openList;
  set<State<T>> closedSet;
 public:
  const set<State<T>> &GetClosedList() const {
    return closedSet;
  }
 public:

};

#endif //MILESTONE2__SEARCHER_H_
