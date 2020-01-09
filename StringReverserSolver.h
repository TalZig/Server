//
// Created by yoel on 08/01/2020.
//

#ifndef MILESTONE2__STRINGREVERSERSOLVER_H_
#define MILESTONE2__STRINGREVERSERSOLVER_H_

#include "Solver.h"
#include "string"
using namespace std;
class StringReverserSolver : public Solver<string, string> {
 public:
  string solve(string problem) override;
};

#endif //MILESTONE2__STRINGREVERSERSOLVER_H_
