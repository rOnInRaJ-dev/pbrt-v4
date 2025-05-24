#include "procedural.h"

namespace pbrt {
    
    Procedural::Procedural(const std::string &filepath,
                           const std::string &namedMaterial,
                           const std::string &materialType,
                           const std::string &texture,
                           const std::string &bumpMap,
                           const std::string &normalMap)
                        : filepath(filepath),
                        namedMaterial(namedMaterial),
                        materialType(materialType),
                        texture(texture),
                        bumpMap(bumpMap),
                        normalMap(normalMap) {}

    std::string Procedural::constructPbrtShapeBlock() {
        std::string block;
        if (!namedMaterial.empty()) {
            block += "NamedMaterial \"" + namedMaterial + "\"\n";
        }
        block += "Shape \"plymesh\" \"string filename\" [ \"" + filepath + "\" ]";
        return block;
    }
                    
    std::string Procedural::constructPbrtMaterialBlock() {
        std::string block = ""; 

        if (!namedMaterial.empty()) {

            // Define material
            if (!texture.empty()) {
                block += "Texture \"" + namedMaterial + "_diffuse\" \"spectrum\" \"imagemap\"\n";
                block += "    \"string filename\" [ \"" + texture + "\" ]\n\n";
            }
            if (!bumpMap.empty()) {
                block += "Texture \"" + namedMaterial + "_roughness\" \"float\" \"imagemap\"\n";
                block += "    \"string filename\" [ \"" + bumpMap + "\" ]\n\n";
            }
            block += "MakeNamedMaterial \"" + namedMaterial + "\"\n";
            block += "    \"string type\" [\"" + materialType + "\"]\n";
            if (!texture.empty()) {
                block += "    \"texture reflectance\" [\"" + namedMaterial + "_diffuse\"]\n";
            }
            if (!bumpMap.empty()) {
                block += "    \"texture roughness\" [\"" + namedMaterial + "_roughness\"]\n";
            }
            if (!normalMap.empty()) {
                block += "    \"string normalmap\" [ \"" + normalMap + "\" ]\n";
            }
        }

        return block;
    }
}

