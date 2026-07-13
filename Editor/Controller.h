#include "View.h"

class Controller
{
public:
    bool importFile(std::string filename);
    bool exportFile(std::string filename);

    void createModel();

    int addPrimitive(PtrPrimitive pPrimitive);

    void removePrimitive(int id);
    void removePrimitive(PtrPrimitive pPrimitive);

    void showModel();

private:
    std::shared_ptr<Model> m_pModel; 
    View m_view; 
};

