#include <iostream>
using namespace std;

#include <vector>

#include "distMatrix.h"
#include "tsp.h"

// Usen el input.sh para compilar todo
// Ahi escriban los comandos que se necesiten para cmake 
// Se corre haciendo ./run.sh

int main(){

  int N;
  cin >> N;

  vector<vector<int>> matrix = buildMatrix(N);
  printMatrix(matrix);
  cout << "\n\n";
  vector<int> trip = repNearesNeighbor(matrix);
  tripPrinter(trip);
  

  return 0;
}