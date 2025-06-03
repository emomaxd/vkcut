#pragma once

#include <vector>

class Scene {
public:
    Scene();
    
    /* TODO: Follow SoA structure */
    std::vector<int> entities;
    std::vector<int> materials;

    void add_object();
};
