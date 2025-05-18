#include "pbrt_exporter.h"
#include "procedural.h"

#include <vector>
#include <fstream>
#include <sstream>


namespace pbrt {

    // Constructor
    PBRTExporter::PBRTExporter(Procedural &procedural)
    : procedural(procedural) {}

    void exportInstances(std::vector<std::pair<Vector3f, Vector3f>> &instances, std::string outputFile) { // TODO: Change input type to vector<Transform>

        // std::ofstream outStream(outputFile); // TODO: Create file beforehand 

        // for (const auto& instance : instances) { // TODO: Traverse over list of transform matrices 

        //     auto transformMatrix = buildConcatTransformMatrix(instance.first, instance.second); 

        //     outStream << "AttributeBegin\n";
        //     outStream << "ConcatTransform [ ";
        //     for (float v : transformMatrix) {
        //         outStream << v << " ";
        //     }
        //     outStream << "]\n";
        //     outStream << procedural.getPBRTShapeBlock() << "\n";
        //     outStream << "AttributeEnd\n\n";
        // }
        return;
    }

}