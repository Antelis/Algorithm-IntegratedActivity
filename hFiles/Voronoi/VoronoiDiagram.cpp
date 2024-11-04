#include "VoronoiDiagram.h"
#include <iostream>

std::vector<std::vector<Point_2>> buildVoronoiDiagram(const std::vector<Point_2>& exchanges) {
    SDG2 sdg;
    for (const auto& exchange : exchanges) {
        sdg.insert(exchange);
    }

    std::vector<std::vector<Point_2>> voronoi_cells;
    for (auto it = sdg.finite_edges_begin(); it != sdg.finite_edges_end(); ++it) {
        SDG2::Edge edge = *it;
        SDG2::Face_handle face = edge.first;

        std::vector<Point_2> polygon;
        if (face->has_vertex(0) && face->has_vertex(1) && face->has_vertex(2)) {
            for (int i = 0; i < 3; ++i) {
                SDG2::Vertex_handle vh = face->vertex(i);
                polygon.push_back(vh->point());
            }
            voronoi_cells.push_back(polygon);
        }
    }
    return voronoi_cells;
}

void printVoronoiCells(const std::vector<std::vector<Point_2>>& voronoi_cells) {
    std::cout << "Voronoi cells:\n";
    for (const auto& cell : voronoi_cells) {
        std::cout << "[ ";
        for (const auto& point : cell) {
            std::cout << "(" << point.x() << ", " << point.y() << ") ";
        }
        std::cout << "]\n";
    }
}
