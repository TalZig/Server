//
// Created by tal on 7.1.2020.
//

#ifndef MILESTONE2__STATE_H_
#define MILESTONE2__STATE_H_
template <typename T>
class State {
  T state;
  int value;
  State<T> prev;
  bool operator<(State<T> state1){
    return (this->value < state1.value);

  }
  bool equals(State<T> state1){
    return(state1.state == this->state);
  }
};

#endif //MILESTONE2__STATE_H_
