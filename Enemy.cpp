//
// Created by anime on 26.06.2026.
//
#include "Enemy.h"

#include <iostream>
#include <ostream>
#include <print>

Enemy::Enemy(float health) : health{health} {};

    void Enemy::take_damage(float amount) {
        health -= amount;
    }

    bool  Enemy::is_alive() const {
        return health > 0;
    }

    void Enemy::info() const {
        std::println("Enemy HP{}",health);
    }