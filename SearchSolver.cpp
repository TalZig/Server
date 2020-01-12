//
// Created by tal on 7.1.2020.
//

#include "SearchSolver.h"
SearchSolver::SearchSolver(iSearcher<Point> *searcher) : searcher_(searcher) {}
string SearchSolver::solve(Matrix problem) {
  State<Point>* goal = this->searcher_->search(problem);
  return problem.traceBack(problem.getGoalState(), goal);
}
