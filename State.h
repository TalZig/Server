//
// Created by tal on 7.1.2020.
//

#ifndef MILESTONE2__STATE_H_
#define MILESTONE2__STATE_H_
template<typename T>
class State {
 public:
  T* state;
  State<T> *prev;
  bool isDiscovered;
  double costOfTrack;
  State() {}
//  State<T>(T state, double value) : state(state), value(value) {
//    this->isDiscovered = false;
//    this->prev = nullptr;
//  }
  State<T>(T* state1) {
    this->state = state1;
    this->isDiscovered = false;
    this->prev = nullptr;
    costOfTrack = 0;
  }

  void SetPrev(State<T> *prev) {
    State::prev = prev;
  }

  bool equals(State<T> state1) {
    return (state1.state == this->state);
  }
};

#endif //MILESTONE2__STATE_H_
