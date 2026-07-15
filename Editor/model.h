#pragma once
#include "primitive.h"
#include <unordered_map>

class Model
{
public:

    Model();
    Model(std::string filename);
    int addPrimitive(const PtrPrimitive &pPrimitive);

    void removePrimitive(const PtrPrimitive &pPrimitive);
    void removePrimitive(int id);

    bool loadFromFile(const std::string &filename);
    bool saveToFile(const std::string &filename);

    void show() const;

private:
    std::unordered_map<int, PtrPrimitive> m_mapPrimitives;
};

