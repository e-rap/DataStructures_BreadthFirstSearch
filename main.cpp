#include "Matrix.h"
#include "Graph.h"
#include "Search.h"
#include <iostream>

int main()
{
  // assignment namespace
  using namespace DepthFirstSearch;

  // load in test data
  std::vector<Matrix> test_matricies = load_test_data("input.txt");

  // run DFS for each matrix
  for (auto test : test_matricies)
  {
    Graph graph{ test };
    RunDFS(graph);
  }
}