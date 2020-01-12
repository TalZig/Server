
#include "boot.h"
#include "Point.h"

int main(int argc, char** argv) {
//  boot::Main<Matrix, string, pair<int,int>> main1;
//  main1.main1(argc,argv);
  CacheManager<string, string>* cm = new FileCacheManager();
  Solver<Matrix,string> *solver = new SearchSolver(new BFS());
  MyClientHandler *c = new MyClientHandler(cm, solver);
  MySerialServer<Matrix,string> s;
  s.open(atoi(argv[1]), c);
}
