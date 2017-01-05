#include "../Header/GameEngine/GameEngine.hpp"

int main() {
    GameEngine gameEngine = GameEngine();
    gameEngine.init();
    gameEngine.start();
    return EXIT_SUCCESS;
}