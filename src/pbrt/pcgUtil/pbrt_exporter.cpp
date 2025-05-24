#include "pbrt_exporter.h"
#include "procedural.h"

#include <vector>
#include <fstream>
#include <sstream>


namespace pbrt {

    // Constructor
    PBRTExporter::PBRTExporter(Procedural &procedural)
    : procedural(procedural) {}

    void PBRTExporter::exportInstances(std::vector<Transform> instanceTransforms, std::string outputFile) { 

        std::ofstream outStream(outputFile); // TODO: Create file beforehand 

        Transform scaler = Scale(0.4f, 0.4f, 0.4f);
        for (size_t i = 0; i < instanceTransforms.size(); ++i) {
            outStream << "AttributeBegin\n";

            Transform &transform = instanceTransforms[i];

            // Testing only
            transform = transform * scaler;
           
            auto transformMatrix = transform.GetMatrix();

            outStream << "ConcatTransform [ ";
            for (int row = 0; row < 4; ++row) {
                for (int col = 0; col < 4; ++col) {
                    outStream << transformMatrix[col][row] << " ";  // TODO: Is row-major order correct?
                }
            }
            outStream << "]\n";

            outStream << procedural.constructPbrtShapeBlock() << "\n";
            outStream << "AttributeEnd\n\n";
        }

        return;
    }

}