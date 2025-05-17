#include "../shapes.h"
#include "../util/mesh.h"

#include <vector>
#include <type_traits>

namespace pbrt {


void printhelloworld() {
    printf("Hello World");

}

// /// Given a mesh and a UV sample, find the corresponding points on the surface
// /// and return them
// std::vector<Point3f> FindSamplesOnMesh(
//     const Shape* shape,
//     const Point2f& sampleUV
// ) {
//     std::vector<Point3f> results;

//     // cast mesh to a triangleMesh (should be easy, all our meshes are triangles)
//     shape->DispatchCPU([&](auto meshPtr) {
//         if constexpr (std::is_same_v<decltype(meshPtr), const TriangleMesh*>) {
//             const TriangleMesh *mesh = meshPtr;
//             // Raw mesh data
//             int nTris             = mesh->nTriangles;
//             const int    *indices = mesh->vertexIndices;
//             const Point2f *uvs    = mesh->uv;
//             const Point3f *Ps     = mesh->p;

//             results.clear();
//             results.reserve(1);  // we should only ever have one hit bc our UVs
//                                  // shouldn't overlap, but it's a vec just in case

//             for (int t = 0; t < nTris; ++t) {
//                 // get three vertex indices of triangle t
//                 int v0 = indices[3*t + 0];
//                 int v1 = indices[3*t + 1];
//                 int v2 = indices[3*t + 2];

//                 // get their UV coords
//                 Point2f uv0 = uvs[v0];
//                 Point2f uv1 = uvs[v1];
//                 Point2f uv2 = uvs[v2];

//                 // solve for barycentric coords in UV space
//                 Vector2f d1  = uv1 - uv0;
//                 Vector2f d2  = uv2 - uv0;
//                 Vector2f duv = sampleUV - uv0;

//                 Float det = d1.x * d2.y - d2.x * d1.y;
//                 // can scale this epsilon as needed
//                 if (std::abs(det) < std::numeric_limits<Float>::epsilon())
//                     continue;

//                 Float invDet = 1 / det;
//                 Float beta   = (duv.x * d2.y - d2.x * duv.y) * invDet;
//                 Float gamma  = (d1.x * duv.y - duv.x * d1.y) * invDet;

//                 // check if it lies inside the triangle
//                 if (beta < 0 || gamma < 0 || beta + gamma > 1)
//                     continue;

//                 // convert to 3D by barycentric interpolation of positions
//                 Float alpha = 1 - beta - gamma;
//                 Point3f p0  = Ps[v0];
//                 Point3f p1  = Ps[v1];
//                 Point3f p2  = Ps[v2];

//                 Point3f sampleP = alpha*p0 + beta*p1 + gamma*p2;
//                 results.push_back(sampleP);
//             }
//         }
//         // else: not a TriangleMesh, do nothing
//     });

//     return results;
// }

}  
