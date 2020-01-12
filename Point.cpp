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
Point::Point(int x, int y, double value) {
  this->y = y;
  this->x = x;
  this->value =value;
}
void Point::setX(int x) {
  this->x = x;
}
void Point::SetY(int y) {
  this->y = y;
}
void Point::setPoint(Point p2) {
  this->x = p2.getX();
  this->y = p2.getY();
  this->value = p2.getValue();
}
