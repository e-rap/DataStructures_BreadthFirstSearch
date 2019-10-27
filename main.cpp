#include "Matrix.h"
#include "Graph.h"
#include "Node.h"
#include "Search.h"
#include <iostream>

int main()
{
  // assignment namespace
  using namespace BreadthFirstSearch;

  using Node = Node<int>;

  // load in test data
  std::vector<Matrix> test_matricies = load_test_data("input.txt");

  // run BFS for each matrix
  for (auto test : test_matricies)
  {
    Graph graph{ test };
    RunBFS(graph);
  }
}