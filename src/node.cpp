#include "node.hpp"

Node::Node(State state, int depth = 0, int cost = 0)
{
  this->state = state;
  this->depth = depth;
  this->cost = cost;
}

bool Node::operator<(const Node &node) const { return this->cost < node.cost; }

bool Node::operator>(const Node &node) const { return this->cost > node.cost; }

bool Node::is_goal()
{
  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++)
      if (this->state[i][j] == 0) return false;
  return true;
}

int Node::count_zeros()
{
  int count = 0;
  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++)
      if (this->state[i][j] == 0) count++;
  return count;
}

int Node::count_possibilities()
{
  int count = 0;
  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++)
      if (this->state[i][j] == 0)
        for (int k = 1; k <= 9; k++)
          if (this->is_valid(i, j, k)) count++;
  return count;
}

bool Node::is_valid(int row, int col, int value)
{
  for (int i = 0; i < 9; i++) {
    if (this->state[row][i] == value || this->state[i][col] == value)
      return false;
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      int x = (row / 3) * 3 + i, y = (col / 3) * 3 + j;
      if (this->state[x][y] == value) return false;
    }
  }

  return true;
}

std::vector<Node> Node::expand()
{
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (this->state[i][j] == 0) {
        std::vector<Node> children;
        for (int k = 1; k <= 9; k++) {
          if (this->is_valid(i, j, k)) {
            Node child = Node(this->state, this->depth + 1, this->cost + 1);
            child.state[i][j] = k;
            children.push_back(child);
          }
        }
        return children;
      }
    }
  }

  return std::vector<Node>();
}