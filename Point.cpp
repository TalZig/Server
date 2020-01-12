//
// Created by tal on 11.1.2020.
//

#include "Point.h"
int Point::getX() {
  return x;
}
int Point::getY() {
  return y;
}
bool Point::operator==(Point p2) {
  return(this->x == p2.getX() && this->y == p2.getY());
}
