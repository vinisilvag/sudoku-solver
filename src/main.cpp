#include <chrono>
#include <fstream>
#include <iostream>
#include <tuple>
#include <vector>

#include "graph.hpp"
#include "types.hpp"

std::tuple<char *, State> parse_arguments(char *argv[]);

void display_solution(State &);

void dump_to_csv(int, int);

int main(int argc, char *argv[])
{
  if (argc - 1 != 10) {
    std::cerr << "Expected " << 10
              << " arguments (algorithm + 9 Sudoku lines), received "
              << argc - 1 << ".\n";
    return EXIT_FAILURE;
  }

  auto [algorithm, initial_state] = parse_arguments(argv);
  Graph graph = Graph(initial_state);

  State solution;
  int expansions;

  auto start = std::chrono::high_resolution_clock::now();
  switch (*algorithm) {
    case 'B':
      tie(solution, expansions) = graph.breadth_first_search();
      break;
    case 'I':
      tie(solution, expansions) = graph.iterative_deepening_search();
      break;
    case 'U':
      tie(solution, expansions) = graph.uniform_cost_search();
      break;
    case 'A':
      tie(solution, expansions) = graph.a_star_search();
      break;
    case 'G':
      tie(solution, expansions) = graph.greedy_best_first_search();
      break;
    default:
      std::cerr << "Unknown algorithm: " << *algorithm << ".\n";
      return EXIT_FAILURE;
  }
  auto end = std::chrono::high_resolution_clock::now();
  int time =
    std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

  std::cout << expansions << " " << time << "\n";
  display_solution(solution);

  // dump_to_csv(expansions, time);

  return EXIT_SUCCESS;
}

std::tuple<char *, State> parse_arguments(char *argv[])
{
  char *algorithm = argv[1];
  std::vector<std::vector<int>> initial_state(9, std::vector<int>(9));

  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++) initial_state[i][j] = argv[i + 2][j] - '0';

  return {algorithm, initial_state};
}

void display_solution(State &state)
{
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) std::cout << state[i][j];
    std::cout << " ";
  }
  std::cout << "\n";
}

void dump_to_csv(int expansions, int time)
{
  std::cout << expansions << "," << time << "\n";
}