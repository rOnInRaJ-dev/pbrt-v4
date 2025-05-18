#ifndef PBRT_PROCEDURAL_MESH
#define PBRT_PROCEDURAL_MESH

#include <string>

namespace pbrt {
    
    class Procedural {
        public:
        Procedural(std::string& filepath,
                const std::string &namedMaterial = "", // Optional 
                const std::string &texture = "",
                const std::string &bumpMap = "",
                const std::string &normalMap = "");

        std::string constructPbrtShapeMaterialBlock();

        private:
        std::string filepath;
        std::string namedMaterial;
        std::string texture;
        std::string bumpMap;
        std::string normalMap;
    };
}

#endif 