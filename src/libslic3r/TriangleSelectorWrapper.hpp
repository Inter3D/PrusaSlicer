#ifndef SRC_LIBSLIC3R_TRIANGLESELECTORWRAPPER_HPP_
#define SRC_LIBSLIC3R_TRIANGLESELECTORWRAPPER_HPP_

#include "TriangleSelector.hpp"
#include "AABBTreeIndirect.hpp"

namespace Slic3r {

//NOTE: We need to replace the FacetsAnnotation struct for support storage (or extend/add another)
// Problems: Does not support negative volumes, strange usage for supports computed from extrusion -
// expensively converted back to triangles and then sliced again.
// Another problem is weird and very limited interface when painting supports via algorithms


class TriangleSelectorWrapper {
public:
    const TriangleMesh &mesh;
    TriangleSelector selector;
    AABBTreeIndirect::Tree<3, float> triangles_tree;

    TriangleSelectorWrapper(const TriangleMesh &mesh);

    void enforce_spot(const Vec3f &point, const Vec3f& origin, float radius);

};

}

#endif /* SRC_LIBSLIC3R_TRIANGLESELECTORWRAPPER_HPP_ */