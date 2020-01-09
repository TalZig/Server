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

namespace boot {
template <typename Problem,typename Solution, typename T>
  class Main {
   public:
    Main() {}
    int main1(int argc, char** argv) {
      auto cm = new FileCacheManager<string, string>();
      auto *solver = new StringReverserSolver();
      MyClientHandler<Matrix<pair<int,int>>, State<pair<int,int>>, pair<int,int>> *c = new MyClientHandler<Problem, Solution, T>(cm, solver);
      MySerialServer<string,string> s;
      s.open(atoi(argv[1]), c);
    }
  };
};

#endif //MILESTONE2__BOOT_H_
