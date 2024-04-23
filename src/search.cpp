#include "search.hpp"

#include <iostream>
#include <queue>
#include <stack>

#include "node.hpp"

Search::Search(State initial_state) { this->initial_state = initial_state; }

Search::~Search() {}

std::tuple<State, int> Search::breadth_first_search()
{
  int expansions = 0;
  Node start = Node(this->initial_state, 0, 0);
  if (start.goal()) return {start.state, expansions};

  std::queue<Node> frontier;
  frontier.push(start);

  while (!frontier.empty()) {
    Node node = frontier.front();
    frontier.pop();
    expansions += 1;

    std::vector<Node> children = node.expand();
    for (Node child : children) {
      if (child.goal()) return {child.state, expansions};
      frontier.push(child);
    }
  }

  std::cerr << "Breadth-first Search failed to find the solution (should be "
               "unreachable)\n";
  std::exit(EXIT_FAILURE);
}

std::tuple<State, int> Search::iterative_deepening_search()
{
  int expansions = 0;
  Node start = Node(this->initial_state, 0, 0);
  if (start.goal()) return {start.state, expansions};

  int limit = 0;

  while (true) {
    std::stack<Node> frontier;
    frontier.push(start);

    while (!frontier.empty()) {
      Node node = frontier.top();
      frontier.pop();
      expansions += 1;

      if (node.goal()) return {node.state, expansions};

      if (node.depth < limit) {
        std::vector<Node> children = node.expand();
        for (Node child : children) frontier.push(child);
      }
    }

    limit += 1;
  }

  std::cerr << "Iterative Deepening Search failed to find the solution (should "
               "be unreachable)\n";
  std::exit(EXIT_FAILURE);
}

std::tuple<State, int> Search::uniform_cost_search()
{
  int expansions = 0;
  Node start = Node(this->initial_state, 0, 0);
  if (start.goal()) return {start.state, expansions};

  std::priority_queue<Node, std::vector<Node>, std::greater<Node>> frontier;
  frontier.push(start);

  while (!frontier.empty()) {
    Node node = frontier.top();
    frontier.pop();
    expansions += 1;

    if (node.goal()) return {node.state, expansions};

    std::vector<Node> children = node.expand();
    for (Node child : children) {
      child.cost = node.cost + 1;
      frontier.push(child);
    }
  }

  std::cerr << "Uniform-Cost Search failed to find the solution (should be "
               "unreachable)\n";
  std::exit(EXIT_FAILURE);
}

std::tuple<State, int> Search::greedy_best_first_search()
{
  std::cerr << "Greedy Best-first Search failed to find the solution (should "
               "be unreachable)\n";
  std::exit(EXIT_FAILURE);
}

std::tuple<State, int> Search::a_star_search()
{
  std::cerr << "A* failed to find the solution (should be unreachable)\n";
  std::exit(EXIT_FAILURE);
}