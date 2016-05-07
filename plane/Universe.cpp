#include "Universe.hpp"

void Universe::bind(Entity *entity) {
    this->Entities.push_back(entity);
    entity->universe = this;
}

void Universe::bullet_time_on(float duration) {
    float bullet_scale = 0.3;

    time_rate           *= bullet_scale;
    bullet_time_duration = duration;
    bullet_time          = true;
    clock.restart();
}

void Universe::update_bullet_time_mode() {
    if ((bullet_time == true) && (bullet_time_duration > 0)) {
        sf::Time t = clock.getElapsedTime();

        if (t.asSeconds() > bullet_time_duration) {
            time_rate = 1;
        }
    }
}
