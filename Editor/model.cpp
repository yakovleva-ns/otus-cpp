#include "model.h"
#include <iostream>

  Model::Model()
  {

  }
    
  Model::Model(std::string filename)
  {
      std::cout << "Model create!"<<filename<< std::endl;
  }
void Model::show() const {
    for (const auto& [id, primitive] : m_mapPrimitives) {
        primitive->draw();
    }
    std::cout << "Model show!"<< std::endl;
}

int Model::addPrimitive(PtrPrimitive pPrimitive) 
{
    int last = m_mapPrimitives.size();
    m_mapPrimitives[last] = pPrimitive;
    pPrimitive.get()->setId(last);

    return last;
}

void Model::removePrimitive(int id) 
{
    if (m_mapPrimitives.contains(id)) 
        m_mapPrimitives.erase(id);
}

void Model::removePrimitive(PtrPrimitive pPrimitive) 
{
    int id = pPrimitive.get()->getId();
    removePrimitive(id);
}
