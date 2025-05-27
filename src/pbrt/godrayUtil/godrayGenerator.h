// godray_generator.h
#ifndef PBRT_PCGUTIL_GODRAY_GENERATOR_H
#define PBRT_PCGUTIL_GODRAY_GENERATOR_H

#include <string>
#include <pbrt/pbrt.h>
#include <pbrt/shapes.h>
#include <pbrt/util/mesh.h>

namespace pbrt {

enum class GodrayMode { ELLIPSE, CONE };

void initGodrayFile(const std::string &filename);

void generateGodray(const Vector3f &start,
    const Vector3f &end,
    Float minorRadius
);

void finishGodrayFile();


} // namespace pbrt

#endif // PBRT_PCGUTIL_GODRAY_GENERATOR_H

