#include "primitive.h"
#include <unordered_map>

class Model
{
public:
    int addPrimitive(PtrPrimitive pPrimitive);

    void removePrimitive(PtrPrimitive pPrimitive);
    void removePrimitive(int id);

    void show() const;

private:
    std::unordered_map<int, PtrPrimitive> m_mapPrimitives;
};

