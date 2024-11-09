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
void printMatrix(const vector<vector<int>> matrix){
  for(int i = 0; i < matrix.size(); i++){
    for(int j = 0; j < matrix.size(); j++){
      cout << matrix[i][j] << " ";
    }

    cout << endl;
  }
}


// Reads a row of integers from input and stores them in the provided vector
void addEdge(vector<int>& row) {
    string input;
    getline(cin, input);
    istringstream iss(input);

    int number;
    int idx = 0;
    while (iss >> number) {
        row[idx++] = (number >= 0) ? number : 0; //Line added to make sure there are no negatuve values
    }
}


// Returns a matrix given by the input
// O(N**2)
vector< vector<int> > buildMatrix(const int N){  
  vector< vector<int> > matrix(N, vector<int>(N, INT_MAX));
  
  for(int i = 0; i < N; i++){
    addEdge(matrix[i]);
  }
  
  return matrix;
}


#endif