#ifndef VORONOI_DIAGRAM_H
#define VORONOI_DIAGRAM_H

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Segment_Delaunay_graph_2.h>
#include <vector>

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef K::Point_2 Point_2;
typedef CGAL::Segment_Delaunay_graph_2<K> SDG2;

// Function to build a Voronoi diagram and return Voronoi cells as polygons
std::vector<std::vector<Point_2>> buildVoronoiDiagram(const std::vector<Point_2>& exchanges);

// Function to print the Voronoi cells
void printVoronoiCells(const std::vector<std::vector<Point_2>>& voronoi_cells);

#endif
