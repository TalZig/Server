//
// Created by tal on 7.1.2020.
//

#ifndef MILESTONE2__STATE_H_
#define MILESTONE2__STATE_H_
template<typename T>
class State {
 public:
  T state;
  double value;
  State<T> *prev;
  bool isDiscovered;
  State(T state1, double value1) {
    this->state = state1;
    this->value = value;
    this->isDiscovered = false;
    this->prev = nullptr;
  }

  void SetPrev(State<T> *prev) {
    State::prev = prev;
  }

  bool operator<(State<T> state1) {
    //its the opposite because in searches the smaller is better than the bigger
    return (this->value > state1.value);
  }

  bool equals(State<T> state1) {
    return (state1.state == this->state);
  }
};

#endif //MILESTONE2__STATE_H_
