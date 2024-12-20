#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;
 
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include <CGAL/Voronoi_diagram_2.h>
#include <CGAL/Delaunay_triangulation_adaptation_traits_2.h>
#include <CGAL/Delaunay_triangulation_adaptation_policies_2.h>
 
// Type definitions for CGAL's data types
typedef CGAL::Exact_predicates_inexact_constructions_kernel                  K;
typedef CGAL::Delaunay_triangulation_2<K>                                    DT;
typedef CGAL::Delaunay_triangulation_adaptation_traits_2<DT>                 AT;
typedef CGAL::Delaunay_triangulation_caching_degeneracy_removal_policy_2<DT> AP;
typedef CGAL::Voronoi_diagram_2<DT,AT,AP>                                    VD;
 
// Type definitions for specific objects in the Voronoi diagram
typedef AT::Site_2                    Site_2;
typedef AT::Point_2                   Point_2;
 
// Definitions for Voronoi diagram's result types
typedef VD::Locate_result             Locate_result;
typedef VD::Vertex_handle             Vertex_handle;
typedef VD::Face_handle               Face_handle;
typedef VD::Halfedge_handle           Halfedge_handle;
typedef VD::Ccb_halfedge_circulator   Ccb_halfedge_circulator;
 
// Function to print the endpoint of a halfedge (either source or target)
void print_endpoint(Halfedge_handle e, bool is_src) {
  cout << "\t";
  if ( is_src ) {
    if ( e->has_source() )  cout << e->source()->point() << endl;
    else  cout << "point at infinity" << endl;
  } else {
    if ( e->has_target() )  cout << e->target()->point() << endl;
    else  cout << "point at infinity" << endl;
  }
}

// 4. Use Voronoi diagram to determine closest exchange for a new service contract
int main()
{
  ifstream ifs("data/test2.cin"); // update to use different test cases
  assert( ifs );
 
  VD vd;
 
  Site_2 t;
  while ( ifs >> t ) { vd.insert(t); }
  
  ifs.close();
 
  assert( vd.is_valid() );
 
  ifstream ifq("data/test2.cin"); // update to use different test cases
  assert( ifq );
 
  Point_2 p;
  while ( ifq >> p ) {
    cout << "Plant in position (" << p.x() << "," << p.y() << ") " << flush;
    cout << endl;

    Locate_result lr = vd.locate(p); // Locate the Voronoi cell that contains the point p
    Face_handle* f = get_if<Face_handle>(&lr); // Get the face (polygon) that contains the point
    
    cout << "Points of the polygon (in counterclockwise order):" << endl;
    // Get the circular list of edges (halfedges) that define the polygon's boundary
    Ccb_halfedge_circulator ec_start = (*f)->ccb();
    Ccb_halfedge_circulator ec = ec_start;

    // Iterate through the edges of the Voronoi polygon and print their endpoints
    do {
      print_endpoint(ec, false);
    } while ( ++ec != ec_start );

    cout << endl;
  }

  ifq.close();
 
  return 0;
}