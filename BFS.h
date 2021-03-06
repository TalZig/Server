//
// Created by tal on 7.1.2020.
//

#ifndef MILESTONE2__BFS_H_
#define MILESTONE2__BFS_H_

#include "iSearcher.h"
#include "list"
#include "queue"
#include "set"
template<typename T>
class BFS : public iSearcher<T> {
  State<T> search(Searchable<T> search_able) {
    this->numberOfNodesEvaluated = 0;
    queue<State<T>*> queue;

    State<T>* n = search_able.getInitialState();
    State<T>* goal = search_able.getGoalState();

    vector<State<T>*> neighbours;
    //insert ot queue, dont insert to list because it will be removed immediatley
    queue.push(n);
    while (!queue.empty()) {
      this->numberOfNodesEvaluated++;
      n = queue.front();
      queue.pop();

      if (n->equals(goal)) {
        // todo traceback course
      }

      neighbours = search_able.getSuccessors(n);
      for (int i = 0; i < neighbours.size(); ++i) {
        if(neighbours[i]->isDiscovered == false){
          neighbours[i]->isDiscovered = true;
          neighbours[i]->prev = n;
          queue.push(neighbours[i]);
        }
      }
    }
  }
};

#endif //MILESTONE2__BFS_H_
