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
#include "Matrix.h"

//template <typename Problem,typename Solution>
class MyClientHandler : public ClientHandler{
  Solver<Matrix, string>* solver;
  CacheManager<string, string>* cm;
 public:
  MyClientHandler(CacheManager<string, string> *cm1, Solver<Matrix, string>* solver1 ) {
    this->cm = cm1;
    this->solver = solver1;
  }

  void handleClient(int socket) {
    vector<string> lines;
    string matrixString = "";
    char buffer[2900];
    while (!server_side::GlobalShouldStop) {
      read(socket, buffer, 1024);
      string line(buffer);
      for (int i = 0; i < sizeof(buffer); i++) {
        buffer[i] = '\0'; // todo flush?
      }
      if (!strcmp(line.c_str(), "end\r\n")) {
 //       server_side::GlobalShouldStop = true;
        break;
      }

      lines.push_back(line);
      matrixString += line;
    }
    //create matrix
    Matrix* matrix = new Matrix(lines);
    string ans;

    if (this->cm->isCacheHaveSol(matrixString)) {
      ans = this->cm->get(matrixString);
    } else {
      ans = this->solver->solve(*matrix);
      this->cm->insert(matrixString, ans);
    }

    send(socket, ans.c_str(), ans.size(), 0);
    close(socket);
  }

  virtual ~MyClientHandler() {
    delete(cm);
    delete(solver);
  }
};

#endif //SERVER__MYCLIENTHANDLER_H_
