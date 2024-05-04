#ifndef NODE_H
#define NODE_H

#include "types.hpp"

class Node
{
 public:
  State state;
  int cost;
  int depth;

  Node(State, int, int);
  bool is_goal();
  int count_zeros();
  int count_possibilities();
  std::vector<Node> expand();

  bool operator<(const Node&) const;
  bool operator>(const Node&) const;

 private:
  bool is_valid(int, int, int);
};

#endif