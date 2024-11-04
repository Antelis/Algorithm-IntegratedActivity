#include <iostream>
using namespace std;

#include <vector>

#include "hFiles/tsp.h"
#include "hFiles/distCapMatrix.h"

// Usen el input.sh para compilar todo
// Ahi escriban los comandos que se necesiten para cmake 
// Se corre haciendo ./run.sh

// chmod +x run.sh
// ./run.sh

int main(){
  int N;
  cin >> N;
  cin.ignore();

  // Get the distance matrix
  vector<vector<int>> distMatrix = buildMatrix(N);
  cout << "\nDistance matrix: " << endl;
  printMatrix(distMatrix);

  cin.ignore();

  // Get the capacity matrix
  vector<vector<int>> capMatrix = buildMatrix(N);
  cout << "\nCapacity matrix: " << endl;
  printMatrix(capMatrix);


  // 2. Find the shortest route for mail delivery (TSP)
  vector<int> trip = repNearesNeighbor(distMatrix);
  cout << "\nShortest route that visits each neighborhood and returns: " << endl;
  tripPrinter(trip);


  // 3. Calculate maximum flow from node 0 to node N-1


  return 0;
}