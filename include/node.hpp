#ifndef NODE_H
#define NODE_H

#include "types.hpp"

class Node
{
 public:
  State state;
  int cost = 0;
  int depth = 0;

  Node(State, int);
  bool goal();
  std::vector<Node*> expand();
};

#endif