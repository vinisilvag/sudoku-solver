#include "graph.hpp"

#include <iostream>
#include <queue>
#include <stack>

#include "node.hpp"

Graph::Graph(State initial_state) { this->initial_state = initial_state; }

std::tuple<State, int> Graph::breadth_first_search()
{
  int expansions = 0;
  Node *start = new Node(this->initial_state, 0, 0);
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
}
std::tuple<State, int> Graph::iterative_deepening_search()
{
  int expansions = 0;
  Node *start = new Node(this->initial_state, 0, 0);
  if (start->goal()) {
    return {start->state, expansions};
  }

  int limit = 0;

  while (true) {
    std::stack<Node *> frontier;
    frontier.push(start);

    while (!frontier.empty()) {
      Node *node = frontier.top();
      frontier.pop();
      expansions += 1;

      if (node->goal()) return {node->state, expansions};

      if (node->depth < limit) {
        std::vector<Node *> children = node->expand();
        for (Node *child : children) frontier.push(child);
      }
    }

    limit += 1;
  }
}

std::tuple<State, int> Graph::uniform_cost_search()
{
  int expansions = 0;
  Node *start = new Node(this->initial_state, 0, 0);
  if (start->goal()) {
    return {start->state, expansions};
  }

  std::priority_queue<Node *, std::vector<Node *>, std::greater<Node *>>
    frontier;
  frontier.push(start);

  // while (!frontier.empty()) {
  //   Node *node = frontier.top();
  //   frontier.pop();
  //   expansions += 1;

  //   if (node->goal()) return {node->state, expansions};

  //   std::vector<Node *> children = node->expand();
  //   for (Node *child : children) {
  //     // update cost
  //     frontier.push(child);
  //   }
  // }
}