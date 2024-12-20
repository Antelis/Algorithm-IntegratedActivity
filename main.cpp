#include <iostream>
#include <vector>
// #include <fstream>
// #include <sstream>

#include "hFiles/distCapMatrix.h"
#include "hFiles/tsp.h"
#include "hFiles/maxFlow.h"
#include "hFiles/primMST.h"

using namespace std;

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

  // 1. Calculate optimal way to wire between cities (MST)
  cout << "\nOptimal way to wire between cities: " << endl;
  primMST(distMatrix, N);

  // 2. Find the shortest route for mail delivery (TSP)
  vector<int> trip = repNearestNeighbor(distMatrix);
  cout << "\nShortest route that visits each neighborhood and returns: " << endl;
  tripPrinter(trip, N);

  // 3. Calculate maximum information flow from the initial node to the final node (MaxFlow)
  int maxFlow = fordFulkerson(capMatrix, N);
  cout << "\nThe maximum information flow from initial to final node is: " << maxFlow << endl;

  return 0;
}
