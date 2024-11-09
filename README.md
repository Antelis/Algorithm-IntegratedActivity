# Integrated Activity 2
On this activity we: 

1.- Implemented Prim's algorithm to calculate the optimal way to wire between cities (hFiles/primMST.h). 

2.- Implemented Repetitive Nearest Neighbor algorithm to find the shortest route for mail delivery (hFiles/tsp.h).

3.- Implemented Ford-Fulkerson's method with Edmonds-Karp's algorithm to calculate maximum information flow from the initial node to the final node (hFiles/maxFlow.h).

4.- Implemented Voronoi Diagram's algorithm using CGAL library to visualize then determine the closest exchange for a new service contract (hFiles/voronoi4).

## To run
* Open the terminal and navigate to your desired path
* Clone the repository
  
``git clone https://github.com/Antelis/Algorithm-IntegratedActivity``

* For point 1 trough 3,
  
``chmod +x run.sh``

``./run.sh``

* For point 4,
  * Install CGAL
  * Navigate to the folder
    
    ``cd voronoi4``
    
  * Set up CGAL
    
    ``cgal_create_CMakeLists -s voronoi``
    
    ``-DCMAKE_BUILD_TYPE=Release .``
    
  * Compile and run
    
    ``make``
    
    ``./voronoi``

## To test
* For point 1 trough 3:
  * Open run.sh file and modify with the test wanted
    
  ``test=testFiles/test1.txt``
  
* For point 4:
  * Open voronoi4/voronoi.cpp and modify with the test wanted
    
  ``ifstream ifs("data/test2.cin");``

  ``ifstream ifq("data/test2.cin");``
  
## Authors
Adela Alejandra Solorio Alcázar

Gustavo García Téllez

Andrés Benjamín Antelis Moreno

## References
[Voronoi Diagram algorithm CGAL](https://doc.cgal.org/latest/Voronoi_diagram_2/index.html#Chapter_2D_Voronoi_Diagram_Adaptor)
