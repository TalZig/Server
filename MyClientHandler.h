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
    char buffer[10000];
    while (!server_side::GlobalShouldStop) {
      read(socket, buffer, 10000);
      //cout << buffer <<endl;
      string line(buffer);
      matrixString += line;

//      lines = buffToLines(buffer, strlen(buffer));

      for (int i = 0; i < sizeof(buffer); i++) {
        buffer[i] = '\0';
      }

      string temp = matrixString.substr(matrixString.size()-4,3);
      if (!strcmp(temp.c_str(), "end")) {
        break;
      }
//
//      lines.push_back(line);


    }
    //cout<<matrixString<<endl;
    //split matrixstring to lines
    matrixString = matrixString.substr(0,matrixString.size()-4);
    auto find = matrixString.find_first_of('\n');
    while (find != string::npos) {
      string line = matrixString.substr(0,find);
      matrixString = matrixString.substr(find + 1,matrixString.size() - (find+1));
      lines.push_back(line);
      find = matrixString.find('\n');
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
    cout<<ans <<endl;
    cout<<ans.c_str()<<endl;
    close(socket);
    ans = "";
  }

  vector<string> buffToLines(char* buff, int size) {
    vector<string> lines;
    string line = "";
    int i = 0;

    while (i<size) {
      while (buff[i] != '\r' && buff[i] != '\n') {
        line += buff[i];
        i++;
      }
      if (i>0 && buff[i-1] == '\r')
        i+=2;
      else
        i++;
      line += '\n';
      lines.push_back(line);
      line = "";
    }
    return lines;
  }

  virtual ~MyClientHandler() {
    delete(cm);
    delete(solver);
  }
};

#endif //SERVER__MYCLIENTHANDLER_H_
