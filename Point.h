//
// Created by tal on 11.1.2020.
//

#ifndef SERVER__POINT_H_
#define SERVER__POINT_H_

class Point {
  int x;
  int y;
 public:
  int getX();
  int getY();
  bool operator ==(Point p2);
};

#endif //SERVER__POINT_H_
