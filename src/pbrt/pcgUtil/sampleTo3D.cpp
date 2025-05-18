#include "../util/mesh.h"  // for TriQuadMesh
#include <vector>
#include <limits>
#include <pbrt/pbrt.h>
#include <pbrt/shapes.h>
#include <pbrt/util/mesh.h>


namespace pbrt {
    std::vector<Point3f> FindSamplesOnMesh(
    const TriQuadMesh *mesh,
    const Point2f    &sampleUV
) {
    std::vector<Point3f> results;
    const std::vector<int>    &idx = mesh->triIndices;
    const std::vector<Point2f> &uvs = mesh->uv;
    const std::vector<Point3f> &P   = mesh->p;

    int nTris = idx.size() / 3;
    results.reserve(1);

    for (int t = 0; t < nTris; ++t) {
        int v0 = idx[3*t + 0],
            v1 = idx[3*t + 1],
            v2 = idx[3*t + 2];

        // UV coords
        Point2f uv0 = uvs[v0],
                uv1 = uvs[v1],
                uv2 = uvs[v2];

        // barycentric in UV
        Vector2f d1  = uv1 - uv0,
                 d2  = uv2 - uv0,
                 duv = sampleUV - uv0;
        Float det = d1.x * d2.y - d2.x * d1.y;
        if (std::abs(det) < std::numeric_limits<Float>::epsilon())
            continue;
        Float invDet = 1 / det;
        Float b      = (duv.x * d2.y - d2.x * duv.y) * invDet;
        Float g      = (d1.x * duv.y - duv.x * d1.y) * invDet;
        if (b < 0 || g < 0 || b + g > 1)
            continue;

        // interpolate in 3D
        Float a    = 1 - b - g;
        Point3f p0 = P[v0],
                p1 = P[v1],
                p2 = P[v2];
        results.push_back(a*p0 + b*p1 + g*p2);
    }
    return results;
}

}  