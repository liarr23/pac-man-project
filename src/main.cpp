#include "core/Config.h"
#include "states/MenuState.h"

int main() {
    GameEngine engine;
    engine.pushState(new MenuState());
    engine.run();
    return 0;
}
