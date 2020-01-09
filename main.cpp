#include <iostream>
#include "server_side.h"
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "StringReverserSolver.h"


int main() {
  auto cm = new FileCacheManager<string, string>();
  auto *solver = new StringReverserSolver();
  auto *c = new MyTestClientHandler<string, string>(cm, solver);
  MySerialServer<string,string> s;
  s.open(5400, c);
}
