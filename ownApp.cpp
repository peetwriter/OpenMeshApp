#include <iostream>
// -------------------- OpenMesh
#include <OpenMesh/Core/IO/MeshIO.hh>
#include <OpenMesh/Core/Mesh/PolyMesh_ArrayKernelT.hh>
// ----------------------------------------------------------------------------
typedef OpenMesh::PolyMesh_ArrayKernelT<> MyMesh;
// ----------------------------------------------------------------------------
// Build a simple cube and write it to std::cout
int main()
{
    MyMesh mesh;
    // generate vertices

    mesh.add_vertex(MyMesh::Point(-1, -1, 0));
    mesh.add_vertex(MyMesh::Point( 1, -1, 1));
    mesh.add_vertex(MyMesh::Point( 1, 2, 1));
    mesh.add_vertex(MyMesh::Point(-1, 1, 1));
    mesh.add_vertex(MyMesh::Point(-1, -1, -1));
    mesh.add_vertex(MyMesh::Point( 2, -1, -1));
    mesh.add_vertex(MyMesh::Point( 1, 1, -1));
    mesh.add_vertex(MyMesh::Point(-1, 1, -1));
    mesh.add_vertex(MyMesh::Point(-1, 2, -1));
    // generate (quadrilateral) faces

    try
    {
        if ( !OpenMesh::IO::write_mesh(mesh, "outputnew.off") )
        {
            std::cerr << "Cannot write mesh to file 'output.off'" << std::endl;
            return 1;
        }
    }
    catch( std::exception& x )
    {
        std::cerr << x.what() << std::endl;
        return 1;
    }
    return 0;
}
