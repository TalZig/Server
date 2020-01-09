//
// Created by yoel on 09/01/2020.
//

#ifndef SERVER__MYCLIENTHANDLER_H_
#define SERVER__MYCLIENTHANDLER_H_
#include "ClientHandler.h"

template <typename Problem,typename Solution>
class MyClientHandler : public ClientHandler<Problem, Solution>{

};

#endif //SERVER__MYCLIENTHANDLER_H_
