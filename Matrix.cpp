#include "Matrix.h"
#include <fstream>
#include <sstream>

namespace BreadthFirstSearch
{
  std::vector<Matrix> load_test_data(std::string file_name)
  {
    std::ifstream test_file{};
    test_file.open(file_name, std::ios::in);
    std::string line;

    // first line is number of test cases
    std::getline(test_file, line);
    size_t num_testcases{ static_cast<size_t>(std::stoi(line)) };
    std::vector<Matrix> output;
    for (size_t i{ 0 }; i < num_testcases; ++i)
    {
      // get size of matrix
      std::getline(test_file, line);
      size_t matrix_size{ static_cast<size_t>(std::stoi(line)) };

      // get matrix data
      std::getline(test_file, line);
      std::istringstream iss(line);
      std::string item;
      char deliminator = ' '; // space deliminator
      std::vector<int> data;
      while (std::getline(iss, item, deliminator))
      {
        data.push_back(std::stoi(item));
      }

      // generate matrix and add to output
      output.push_back(generate_matrix(matrix_size, data));
    }
    test_file.close();
    return output;
  }

  Matrix generate_matrix(size_t N, std::vector<int> data)
  {
    Matrix output{};
    output.resize(N);
    for (size_t i{ 0 }; i < N; ++i)
    {
      for (size_t j{ 0 }; j < N; ++j)
      {
        output[i].push_back(data[i * N + j]);
      }
    }
    return output;
  }

} // BreadthFirstSearch


