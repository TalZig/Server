//
// Created by tal on 7.1.2020.
//

#ifndef MILESTONE2__SEARCHER_H_
#define MILESTONE2__SEARCHER_H_

#include "iSearcher.h"
#include "list"
#include "unordered_map"
#include "set"
#include "Solver.h"
#include "BestFirstSearch.h"
using namespace std;
template<typename Problem,typename Solution,typename T>
class SearchSolver : public Solver<Problem,Solution> {
 protected:
  iSearcher<T> *searcher_;
 public:

  SearchSolver(BestFirstSearch<string> *searcher) : searcher_(searcher) {}
  Solution solve(Problem problem) override {
    return nullptr;
  }
 public:

};

#endif //MILESTONE2__SEARCHER_H_
