//
// Created by tal on 7.1.2020.
//

#ifndef MILESTONE2__BFS_H_
#define MILESTONE2__BFS_H_

#include "iSearcher.h"
#include "list"
#include "queue"
#include "set"

class BFS : public iSearcher<Point> {

  State<Point>* search(Searchable<Point> search_able) {
    this->numberOfNodesEvaluated = 0;
    queue<State<Point>*> queue;

    State<Point>* n = search_able.getInitialState();
    State<Point>* goal = search_able.getGoalState();

    vector<State<Point>*> neighbours;
    //insert ot queue, dont insert to list because it will be removed immediatley
    queue.push(n);
    while (!queue.empty()) {
      this->numberOfNodesEvaluated++;
      n = queue.front();
      queue.pop();

      if (n->equals(*goal)) {
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
 // todo   return search_able.traceBack(search_able.getInitialState(), search_able.getGoalState());
  }
};

#endif //MILESTONE2__BFS_H_
