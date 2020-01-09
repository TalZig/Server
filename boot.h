//
// Created by yoel on 08/01/2020.
//

#ifndef MILESTONE2__BOOT_H_
#define MILESTONE2__BOOT_H_
#include <iostream>
#include "server_side.h"
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "StringReverserSolver.h"

namespace boot {
  class Main {
    int main(int argc, char** argv) {
      auto cm = new FileCacheManager<string, string>();
      auto *solver = new StringReverserSolver();
      auto *c = new MyTestClientHandler<string, string>(cm, solver);
      MySerialServer<string,string> s;
      s.open(atoi(argv[0]), c);
    }
  };
};

#endif //MILESTONE2__BOOT_H_
