//
// Created by yoel on 09/01/2020.
//

#ifndef SERVER__MYCLIENTHANDLER_H_
#define SERVER__MYCLIENTHANDLER_H_
#include <vector>
#include "ClientHandler.h"
#include "FileCacheManager.h"
#include "server_side.h"
#include "State.h"

template <typename Problem,typename Solution, typename T>
class MyClientHandler : public ClientHandler<Problem, Solution>{
  Solver<Problem, Solution>* solver;
  CacheManager<Problem, Solution>* cm;
 public:
  MyClientHandler(CacheManager<Problem, Solution> *cm1, Solver<Problem,Solution>* solver1 ) {
    this->cm = cm1;
    this->solver = solver1;
  }

  void handleClient(int socket) {
    vector<string> lines;
    char buffer[2900];
    while (!server_side::GlobalShouldStop) {
      read(socket, buffer, 1024);
      string line(buffer);
      for (int i = 0; i < sizeof(buffer); i++) {
        buffer[i] = '\0';
      }
      if (!strcmp(line.c_str(), "end\r\n")) {
        //GlobalShouldStop = true;
        break;
      }

      lines.push_back(line);
    }

//    if (prob.size() > 0) {
//      string ans;
//      if (this->cm->isCacheHaveSol(prob)) {
//        ans = this->cm->get(prob);
//      } else {
//        ans = this->solver->solve(prob);
//        this->cm->insert(prob, ans);
//      }
//      //write(new_sock, answer.c_str(), answer.size());
//      send(socket, ans.c_str(), ans.size(), 0);
//    }

    //create matrix
    Matrix matrix

    close(socket);
  }

  virtual ~MyClientHandler() {
    delete(cm);
    delete(solver);
  }
};

#endif //SERVER__MYCLIENTHANDLER_H_
