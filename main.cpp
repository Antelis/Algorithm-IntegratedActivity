#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "hFiles/tsp.h"
#include "hFiles/distMatrix.h"
#include "hFiles/VoronoiDiagram.h"

using namespace std;

// Usen el input.sh para compilar todo
// Ahi escriban los comandos que se necesiten para cmake 
// Se corre haciendo ./run.sh

// Function to read points from the input file
vector<Point_2> readPointsFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return {};
    }

    int N;
    file >> N; // Read the number of exchanges
    vector<Point_2> exchanges;

    // Read the distance matrix and convert it to points
    vector<vector<int>> matrix(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            file >> matrix[i][j];
            if (i == j) continue;
            exchanges.emplace_back(i, j);
        }
    }
    
    return exchanges;
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> matrix = buildMatrix(N);
    printMatrix(matrix);
    cout << "\n\n";

    vector<int> trip = repNearesNeighbor(matrix);
    tripPrinter(trip);

    // Read points from test1.txt
    vector<Point_2> exchanges = readPointsFromFile("z");

    // Build and print Voronoi cells
    vector<vector<Point_2>> voronoi_cells = buildVoronoiDiagram(exchanges);
    printVoronoiCells(voronoi_cells);

    return 0;
}
