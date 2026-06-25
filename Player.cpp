//
// Created by anime on 26.06.2026.
//
#include "Player.h"

#include <print>
#include <string>

Player::Player(float health) : health(health) {}

void Player::attack(Enemy& enemy, float dmg) {
    enemy.take_damage(dmg);
}
void Player::take_damage(float amount) {
    health -= amount;
}



bool Player::is_alive() const {
    return health > 0;
}
std::string Player::get_class() {
    return "Player";
}
void Player::info() const{
    std::println("Player HP{}",health);
}