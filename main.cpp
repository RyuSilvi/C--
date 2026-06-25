#include <iostream>
#include <print>

#include "Player.h"
#include "Enemy.h"

int main() {
    Player player(100.0f);
    Enemy enemy(100.0F);

    std::println("Player has the type{}", Player::get_class());
    while (player.is_alive()) {
        std::print("Damage: ");
        int input;
        std::cin >> input;
        player.attack(enemy,static_cast<float>(input));
        enemy.info();
        if(!enemy.is_alive()) {
            std::print("You won!\n");
            break;
        }
        player.take_damage(10.0f);
        player.info();
    }
    std::print("Game over!\n");
}