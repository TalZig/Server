//
// Created by yoel on 14/01/2020.
//

#ifndef SERVER__MYPARALLELSERVER_H_
#define SERVER__MYPARALLELSERVER_H_
#include <thread>
#include "server_side.h"
#include <string.h>
#include "vector"
struct dataForClient{
  ClientHandler* client;
  int socket;
};
template<typename Problem, typename Solution>
void playThread(dataForClient data) {
  data.client->handleClient(data.socket);
}
void start(int port, ClientHandler *c) {
  int s = socket(AF_INET, SOCK_STREAM, 0);
  struct sockaddr_in serv;
  serv.sin_addr.s_addr = INADDR_ANY;
  serv.sin_port = htons(port);
  serv.sin_family = AF_INET;
  bool *isTimeOut = new bool;
  *isTimeOut = false;
  timeval timeout;
  timeout.tv_sec = 50;
  timeout.tv_usec = 0;

  bind(s, (sockaddr *) &serv, sizeof(serv));
  setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeout, sizeof(timeout));

  while (!server_side::GlobalShouldStop) {
    try {
      int new_sock;
      listen(s, 20000);
      struct sockaddr_in client;
      socklen_t clilen = sizeof(client);
      new_sock = accept(s, (struct sockaddr *) &client, &clilen);
      cout << "Server connected" << endl;
      if (*isTimeOut) {
        if (new_sock < 0) {
          if (errno == EWOULDBLOCK) {
            cout << "timeout of Serial!" << endl;
            break;
          } else {
            perror("other error");
            break;
          }
        }
      }
      server_side::threads.push_back(new thread);
      ClientHandler *client_handler = c;
      /*server_side::threads[server_side::threads.size() - 1] = */
      //thread thr1;
      //thr1(playThread, new_sock, client_handler);
      //thr1.join();
      dataForClient data;
      data.client = client_handler;
      data.socket = new_sock;
      server_side::threads[server_side::threads.size() - 1] = thread(playThread, data);
      //server_side::threads[server_side::threads.size() - 1]->detach();
    } catch (...) {
      cout << "connection with client stopped" << endl;
    }
  }
  while (!server_side::threads.empty()) {
    if (server_side::threads.front()->joinable())
      server_side::threads.front()->join();
    delete server_side::threads.front();
  }
  delete isTimeOut;
}

template<typename Problem, typename Solution>
class MyParallelServer : server_side::Server<Problem, Solution> {
  bool shouldStop = false;
 public:
  void open(int port, ClientHandler *c) override {
    server_side::GlobalShouldStop = false;
    thread thr(start < Problem, Solution > , port, c);
    thr.join();
  }
  void stop() override {
    server_side::GlobalShouldStop = true;
    if (this->thr1.joinable()) {
      this->thr1.join();
    }
  }
};

#endif //SERVER__MYPARALLELSERVER_H_
