#include "node.hpp"

Node::Node(State state, int depth = 0, int cost = 0)
{
  this->state = state;
  this->depth = depth;
  this->cost = cost;
}

Node::~Node() {}

bool Node::operator<(const Node &node) const { return this->cost < node.cost; }

bool Node::operator>(const Node &node) const { return this->cost > node.cost; }

bool Node::goal()
{
  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++)
      if (this->state[i][j] == 0) return false;
  return true;
}

std::vector<Node> Node::expand()
{
  std::vector<Node> children;

  std::pair<int, int> coords = {-1, -1};
  for (int i = 0; i < 9 && coords.first == -1; i++) {
    for (int j = 0; j < 9 && coords.second == -1; j++) {
      if (this->state[i][j] == 0) {
        coords = {i, j};
      }
    }
  }

  if (coords.first == -1 || coords.second == -1) return children;

  std::vector<int> possibilities = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  // row and column
  for (int i = 0; i < 9; i++) {
    if (this->state[coords.first][i] != 0)
      possibilities.erase(
        remove(
          possibilities.begin(), possibilities.end(),
          this->state[coords.first][i]
        ),
        possibilities.end()
      );
    if (this->state[i][coords.second] != 0)
      possibilities.erase(
        remove(
          possibilities.begin(), possibilities.end(),
          this->state[i][coords.second]
        ),
        possibilities.end()
      );
  }

  // 3x3 square
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      int x = (coords.first / 3) * 3, y = (coords.second / 3) * 3;
      if (this->state[x + i][y + j] != 0)
        possibilities.erase(
          remove(
            possibilities.begin(), possibilities.end(),
            this->state[x + i][y + j]
          ),
          possibilities.end()
        );
    }
  }

  for (int value : possibilities) {
    auto [i, j] = coords;
    Node child = Node(this->state, this->depth + 1, 0);
    child.state[i][j] = value;
    children.push_back(child);
  }

  return children;
}