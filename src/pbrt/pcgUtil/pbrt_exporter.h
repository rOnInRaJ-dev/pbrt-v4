#ifndef PBRT_EXPORTER
#define PBRT_EXPORTER

#include "procedural.h"

#include <vector>
#include <pbrt/util/vecmath.h>


namespace pbrt {

class PBRTExporter {
    public:
    PBRTExporter(Procedural &procedural);

    void exportInstances(std::vector<std::pair<Vector3f, Vector3f>> instances,
                         std::string outputFile); 
    
    private:
    Procedural procedural;
};

}

#endif
