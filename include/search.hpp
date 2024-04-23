#ifndef SEARCH_H
#define SEARCH_H

#include <tuple>

#include "types.hpp"

class Search
{
 public:
  State initial_state;

  Search(State);
  ~Search();
  std::tuple<State, int> breadth_first_search();
  std::tuple<State, int> iterative_deepening_search();
  std::tuple<State, int> uniform_cost_search();
  std::tuple<State, int> greedy_best_first_search();
  std::tuple<State, int> a_star_search();
};

#endif