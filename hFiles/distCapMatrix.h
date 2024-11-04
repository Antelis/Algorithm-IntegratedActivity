#ifndef DISTCAPMATRIX
#define DISTCAPMATRIX

#include <iostream>
using namespace std;

#include <vector>
#include <limits.h>
#include <string>
#include <sstream>


// Matrix Printer Function
// O(N)
void printMatrix(const vector< vector<int> > matrix){
  for(int i = 0; i < matrix.size(); i++){
    for(int j = 0; j < matrix.size(); j++){
      cout << matrix[i][j] << " ";
    }

    cout << endl;
  }
}


// Adds the edges to the input based on the amount of inputs given to the graph
// O(N)
void addEdge(vector<int>& matrix){
  string input;
  cin.ignore();

  getline(cin, input);
  istringstream iss(input);

  vector<int> numbers;
  int number;
  while (iss >> number) {
    numbers.push_back(number);
  }

  // Update the matrix row with the extracted numbers
  for (int n = 0; n < numbers.size(); n++) {
    matrix[n] = numbers[n];
  }
}


// Returns a matrix given by the input
// O(N)
vector< vector<int> > buildMatrix(const int N){  
  // Creates a matrix of infinite weight between all edges
  vector< vector<int> > matrix(N, vector<int>(N, INT_MAX));
  
  for(int i = 0; i < N; i++){
    addEdge(matrix[i]);
  }
  
  return matrix;
}


#endif