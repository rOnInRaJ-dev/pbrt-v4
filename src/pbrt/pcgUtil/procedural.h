#ifndef PBRT_PROCEDURAL_MESH
#define PBRT_PROCEDURAL_MESH

#include <string>
#include <pbrt/util/vecmath.h>

namespace pbrt {
    
    class Procedural {
        public:
        Procedural(const std::string& filepath,
                const std::string &namedMaterial = "", // Optional 
                const std::string &materialType = "", 
                const std::string &texture = "",
                const std::string &bumpMap = "",
                const std::string &normalMap = "");

        std::string constructPbrtShapeBlock();
        std::string constructPbrtMaterialBlock();

        private:
        std::string filepath;
        std::string namedMaterial;
        std::string materialType;
        std::string texture;
        std::string bumpMap;
        std::string normalMap;
    };
}

#endif 