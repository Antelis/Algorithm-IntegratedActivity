#ifndef TSP
#define TSP

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <numeric>

using namespace std;


int tripTraveler(const vector<vector<int>> matrix, const vector<int> trip){
  int sum = 0;
  vector<int> node = matrix[trip[0]];
  for(int i = 1; i < trip.size(); i++){
    sum = sum + node[trip[i]];
    node = matrix[trip[i]];
  }

  return sum;
}


void tripPrinter(const vector<int> trip){
  for(int i = 0; i < trip.size() - 1; i++){
    cout << (char)(trip[i] + 65) << " -> ";
  }

  cout << (char)(trip[trip.size() - 1] + 65) << endl;
}


int findMin(const vector<int>& matrix, const vector<bool>& visited) {
  int minIdx = -1;
  int minVal = INT_MAX;

  for (int i = 0; i < matrix.size(); i++) {
    if (!visited[i] && matrix[i] < minVal && matrix[i] != 0) {
      minVal = matrix[i];
      minIdx = i;
    }
  }

  return minIdx;
}


vector<int> nearestNeighbor(const vector<vector<int>> matrix, int startNode) {
  vector<int> trip;
  vector<bool> visited(matrix.size(), false);
  int node = startNode; 

  visited[node] = true;
  trip.push_back(node);

  // Loop until all nodes are visited
  while (!all_of(visited.begin(), visited.end(), [](bool v) { return v; })){
    node = findMin(matrix[node], visited);
    
    if (node != -1){
      visited[node] = true;
      trip.push_back(node);
    } 
    else{
      break;
    }
  }

  trip.push_back(startNode);
  return trip;
}


vector<int> repNearesNeighbor(const vector<vector<int>> matrix){
  vector<int> bestTrip(matrix.size());
  auto bestSum = INT_MAX;

  for(int i = 0; i < matrix.size(); i++){
    vector<int> currTrip = nearestNeighbor(matrix, i);
    auto currSum = tripTraveler(matrix, currTrip);

    if(currSum < bestSum){
      bestTrip = currTrip;
      bestSum = currSum;
    }
  }

  return bestTrip;
}

#endif
