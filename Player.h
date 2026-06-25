//
// Created by anime on 26.06.2026.
//

#pragma once

#include "Enemy.h"
#include <string>

class Player {
private:
    float health;

public:
    Player(float health);
    void attack(Enemy& enemy, float dmg);
    void take_damage(float amount);

    [[nodiscard]]
    bool is_alive() const;
    static std::string get_class();
};

#ifndef HELLO_WORLD_PLAYER_H
#define HELLO_WORLD_PLAYER_H

#endif //HELLO_WORLD_PLAYER_H
