#include<list>

#include "controller.h"
#include "objects_primitive.h"


int main() {
    Controller controller;
    controller.createModel();

    controller.addPrimitive(std::make_shared<Cube>());
    controller.addPrimitive(std::make_shared<Cube>());
    controller.addPrimitive(std::make_shared<Line>());
    controller.addPrimitive(std::make_shared<Triangle>());
    controller.addPrimitive(std::make_shared<Polygon>());

    controller.showModel();
    controller.exportFile(std::string("model.model"));

    return 0;
}
