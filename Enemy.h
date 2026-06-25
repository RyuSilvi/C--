//
// Created by anime on 26.06.2026.
//

#pragma once

class Enemy {
    private:
        float health;
    public:
        Enemy(float health);
        void take_damage(float amount);
        bool is_alive() const;

};

#ifndef HELLO_WORLD_ENEMY_H
#define HELLO_WORLD_ENEMY_H

#endif //HELLO_WORLD_ENEMY_H