
#include "boot.h"
#include "Point.h"
#include "MyParallelServer.h"

int main(int argc, char** argv) {
//  boot::Main<Matrix, string, pair<int,int>> main1;
//  main1.main1(argc,argv);

  CacheManager<string, string>* cm = new FileCacheManager();
  Solver<Matrix,string> *solver = new SearchSolver(new AStar<Point>());
  MyClientHandler *c = new MyClientHandler(cm, solver);
  MyParallelServer<Matrix,string> s;
  s.open(atoi(argv[1]), c);
}
