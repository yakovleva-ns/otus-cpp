#include "Controller.h"
#include <iostream>

bool Controller::importFile(const std::string& filename) 
{
    m_pModel.reset(new Model());
    return m_pModel->loadFromFile(filename);
}


bool Controller::exportFile(const std::string& filename) 
{
    return m_pModel->saveToFile(filename);
}


void Controller::createModel() 
{
    m_pModel.reset(new Model());
}


int Controller::addPrimitive(const PtrPrimitive &pPrimitive) {
    if (m_pModel)
    {
        int id = m_pModel->addPrimitive(pPrimitive);
        return id;
    }
    std::cout << "Model not exist"<< std::endl;
    return -1;
}


void Controller::removePrimitive(int id) {
    if (m_pModel)
    {
        m_pModel->removePrimitive(id);
    }
}

void Controller::showModel() {
    if (m_pModel)
        m_view.showModel(m_pModel);
}
