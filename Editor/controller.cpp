#include "controller.h"
#include <iostream>

bool Controller::importFile(std::string filename) 
{
    Model loadedModel(filename);
    m_pModel.reset(new Model(loadedModel));
    std::cout << "Model loaded! \n";

    return true; // or false
}


bool Controller::exportFile(std::string filename) 
{
    std::cout << "Model export to file!"<< filename << std::endl;
    return true; // or false
}


void Controller::createModel() 
{
    m_pModel.reset(new Model());
    std::cout << "Model create!"<< std::endl;
}


int Controller::addPrimitive(PtrPrimitive primitive) {
    if (m_pModel)
    {
        int id = m_pModel->addPrimitive(primitive);
        std::cout << "Add primitive, id " << id << std::endl;
        return id;
    }
    std::cout << "Model not exist"<< std::endl;
    return -1;
}


void Controller::removePrimitive(int id) {
    if (m_pModel)
    {
        m_pModel->removePrimitive(id);
        std::cout << "Remove primitive, id" << id << std::endl;
    }
}

void Controller::showModel() {
    if (m_pModel)
        m_view.showModel(m_pModel);
}
