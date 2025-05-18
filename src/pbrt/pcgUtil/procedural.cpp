#include "procedural.h"

namespace pbrt {
    
    Procedural::Procedural(std::string &filepath,
                        const std::string &namedMaterial,
                        const std::string &texture,
                        const std::string &bumpMap,
                        const std::string &normalMap)
                        : filepath(filepath),
                        namedMaterial(namedMaterial),
                        texture(texture),
                        bumpMap(bumpMap),
                        normalMap(normalMap) {}

    std::string Procedural::constructPbrtShapeMaterialBlock() {
        std::string result;
        if (namedMaterial.length() > 0) {
            result += "NamedMaterial \"" + namedMaterial + "\"\n";
        }
        result += "Shape \"plymesh\" \"string filename\" [ \"" + filepath + "\" ]";
        return result;
    }

}

