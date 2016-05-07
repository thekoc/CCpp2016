#include "Universe.hpp"

void Universe::bind(Entity *entity) {
    this->Entities.push_back(entity);
    entity->universe = this;
}
