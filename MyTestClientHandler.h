//
// Created by tal on 6.1.2020.
//

#ifndef MILESTONE2__MYTESTCLIENTHANDLER_H_
#define MILESTONE2__MYTESTCLIENTHANDLER_H_
#include "ClientHandler.h"
#include "FileCacheManager.h"
template <typename Problem, typename Solution>
class MyTestClientHandler : public ClientHandler<Problem,Solution> {
  Solver<Problem, Solution>* solver;
  CacheManager<Problem, Solution>* cm;
 public:
  MyTestClientHandler(CacheManager<Problem, Solution> *cm1, Solver<Problem,Solution>* solver1 ) {
    this->cm = cm1;
    this->solver = solver1;
  }
  void handleClient(Problem prob, Solution *ans) {
    string temp;
    if (this->cm->isCacheHaveSol(prob)) {
      *ans = this->cm->get(prob);
    } else {
      temp = this->solver->solve(prob);
      *ans = temp;
      this->cm->insert(prob, *ans);
    }
  }
  ~MyTestClientHandler() {
    delete(cm);
    delete(solver);
  }

};

#endif //MILESTONE2__MYTESTCLIENTHANDLER_H_
