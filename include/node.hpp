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
  ~Node();
  bool goal();
  std::vector<Node> expand();

  bool operator<(const Node& node) const;
  bool operator>(const Node& node) const;
};

#endif