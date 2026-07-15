#include "model.h"
#include <iostream>


  Model::Model()
  {
      std::cout << "Model create!"<< std::endl;
  }
    
  Model::Model(std::string filename)
  {
      std::cout << "Model create!"<< std::endl;
      loadFromFile(filename);
  }

void Model::show() const 
{
    for (const auto& [id, primitive] : m_mapPrimitives) 
    {
        primitive->draw();
    }
    std::cout << "Model show!"<< std::endl;
}

int Model::addPrimitive(const PtrPrimitive &pPrimitive) 
{
    int last = m_mapPrimitives.size();
    m_mapPrimitives[last] = pPrimitive;
    pPrimitive.get()->setId(last);

    std::cout << "Add primitive, id " << last << std::endl;

    return last;
}

void Model::removePrimitive(int id) 
{
    if (m_mapPrimitives.contains(id)) 
        m_mapPrimitives.erase(id);

    std::cout << "Remove primitive, id" << id << std::endl;
}

void Model::removePrimitive(const PtrPrimitive &pPrimitive) 
{
    int id = pPrimitive.get()->getId();
    removePrimitive(id);
}

bool Model::loadFromFile(const std::string &filename)
{
    std::cout << "Model loaded! \n";
    return true; //or false
}

bool Model::saveToFile(const std::string &filename)
{
    std::cout << "Model export to file!"<< std::endl;
    return true; //or false
}
