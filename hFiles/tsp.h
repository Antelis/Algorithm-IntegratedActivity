#ifndef TSP
#define TSP

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <numeric>

using namespace std;

// Function to calculate the total cost of a given trip
int tripTraveler(const vector<vector<int>> matrix, const vector<int> trip){
  int sum = 0;
  vector<int> node = matrix[trip[0]];

  // Loop through each node in the trip, adding edge weights to the sum
  for(int i = 1; i < trip.size(); i++){
    sum = sum + node[trip[i]];
    node = matrix[trip[i]];
  }

  return sum;
}

// Function to print the trip generated from start to end
void tripPrinter(const vector<int> trip, int N){
  // Check if the path found visist each vertex
  if (trip.size() != N) {
    cout << "There is no direct connection between each neighborhood," << endl;
    cout << "no complete path was found" << endl;
  }
  
  for(int i = 0; i < trip.size() - 1; i++){
    // +65 to convert int indices to corresponding uppercase letters in ASCII encoding
    cout << (char)(trip[i] + 65) << " -> ";
  }

  cout << (char)(trip[trip.size() - 1] + 65) << endl;
}

// Function to find the index of the minimum value that has not been visited and is > 0
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

// Function that uses a nearest neighbor heuristic to generate a path that visits
// each node starting from `startNode` and returning to it
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

// Function that iterates over each possible starting node to find the best trip
// (the one with the minimum trip cost) using the nearest neighbor heuristic
// Time complexity: O(n^3) because nearestNeighbor (O(n^2)) is called n times
vector<int> repNearestNeighbor(const vector<vector<int>> matrix){
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
