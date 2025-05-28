#include <pbrt/godrayUtil/godrayGenerator.h>

#include <pbrt/pbrt.h>
#include <pbrt/shapes.h>
#include <pbrt/util/mesh.h>
#include <fstream>
#include <algorithm>
#include <cmath>
#include "godrayGenerator.h"
#include <fstream>
#include <cmath>
#include <algorithm>

namespace pbrt {

static std::ofstream godrayOut;

void initGodrayFile(const std::string &filename) {
    godrayOut.close();
    godrayOut.open(filename, std::ios::out | std::ios::trunc);
}

void generateGodray(
    const Vector3f &start,
    const Vector3f &end,
    Float minorRadius
) {
    if (!godrayOut.is_open()) { return; }

    Vector3f distance = end - start;
    Float length = Length(distance);
    Float halfLength = 0.5f * length;
    Vector3f midpoint = (start + end) * 0.5f;
    Vector3f up = Vector3f(0,1,0);
    Vector3f axis = Cross(up, distance);

    Float cosA = Dot(up, distance) / (Length(up) * length);
    cosA = Clamp(cosA, -1, 1);
    
    Float ang = std::acos(cosA) * 180.f / M_PI;
    axis = Normalize(axis);

    godrayOut << "AttributeBegin\n"
    << "  Material \"interface\"\n"
    << "  MediumInterface \"godray\" \"\"\n"
    << "  Translate " << midpoint.x << " " << midpoint.y << " " << midpoint.z << "\n"
    << "  Rotate "    << ang    << " "
        << axis.x << " "
        << axis.y << " "
        << axis.z << "\n"
    << "  Scale "     << minorRadius << " "
        << halfLength        << " "
        << minorRadius << "\n"
    << "  Shape \"sphere\" \"float radius\" [1]\n"
    << "AttributeEnd\n";
}

void finishGodrayFile() {
    if (godrayOut.is_open()) godrayOut.close();
}


}
