#pragma once
#include "view.h"

class Controller
{
public:
    bool importFile(const std::string& filename);
    bool exportFile(const std::string& filename);

    void createModel();

    int addPrimitive(const PtrPrimitive &pPrimitive);

    void removePrimitive(int id);
    void removePrimitive(const PtrPrimitive &pPrimitive);

    void showModel();

private:
    std::shared_ptr<Model> m_pModel; 
    View m_view; 
};



