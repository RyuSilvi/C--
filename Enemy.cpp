//
// Created by anime on 26.06.2026.
//
#include "Enemy.h"

Enemy::Enemy(float health) : health{health} {};

    void Enemy::take_damage(float amount) {
        health -= amount;
    }

    bool  Enemy::is_alive() const {
        return health > 0;
    }