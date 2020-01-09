//
// Created by tal on 6.1.2020.
//

#ifndef MILESTONE2__SERVER_SIDE_H_
#define MILESTONE2__SERVER_SIDE_H_
#include <sys/socket.h>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include "ClientHandler.h"
using namespace std;
namespace server_side {
template<typename Problem,typename Solution>
class Server {
 public:
  virtual void open(int port, ClientHandler<Problem,Solution>* c) = 0;
  virtual void stop() = 0;
};

};

#endif //MILESTONE2__SERVER_SIDE_H_
