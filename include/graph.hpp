#ifndef GRAPH_H
#define GRAPH_H

#include <tuple>

#include "types.hpp"

class Graph
{
 public:
  State initial_state;

  Graph(State);
  std::tuple<State, int> breadth_first_search();
  std::tuple<State, int> iterative_deepening_search();
  std::tuple<State, int> uniform_cost_search();
};

#endif