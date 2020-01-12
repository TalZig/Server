//
// Created by yoel on 08/01/2020.
//

#ifndef MILESTONE2__BOOT_H_
#define MILESTONE2__BOOT_H_
#include <iostream>
#include "server_side.h"
#include "MySerialServer.h"
#include "MyClientHandler.h"
#include "StringReverserSolver.h"
#include "BFS.h"
#include "SearchSolver.h"

namespace boot {
template <typename Problem,typename Solution, typename T>
  class Main {
   public:
    Main() {}
    int main1(int argc, char** argv) {
      CacheManager<string, string>* cm = new FileCacheManager();
      Solver<Matrix, string>* solver = new SearchSolver(new BFS<Point>());
      MyClientHandler<Matrix, string> *c = new MyClientHandler<Problem, Solution>(cm, solver);
      MySerialServer<Matrix,string> s;
      s.open(atoi(argv[1]), c);
    }
  };
};

#endif //MILESTONE2__BOOT_H_
