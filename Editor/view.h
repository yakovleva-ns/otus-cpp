#include "model.h"

class View
{
public:
    void showModel(std::shared_ptr<Model> pModel);

    void hideModel(std::shared_ptr<Model> pModel){};

    void updateView(){};
};

