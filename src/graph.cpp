#include "graph.hpp"

#include <queue>

#include "node.hpp"

Graph::Graph(State initial_state) { this->initial_state = initial_state; }

std::tuple<State, int> Graph::breadth_first_search()
{
  int expansions = 0;
  Node *start = new Node(this->initial_state, 0);
  if (start->goal()) {
    return {start->state, expansions};
  }

  std::queue<Node *> frontier;
  frontier.push(start);

  while (!frontier.empty()) {
    Node *node = frontier.front();
    frontier.pop();
    expansions += 1;

    std::vector<Node *> children = node->expand();
    for (Node *child : children) {
      if (child->goal()) return {child->state, expansions};
      frontier.push(child);
    }
  }

  return {start->state, expansions};
}