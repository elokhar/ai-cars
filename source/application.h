#pragma once
#include "helpers/debug_draw.h"
#include "car/car.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <box2d/b2_world.h>
#include <memory>

class Application {
public:
    Application();
    void run();
private:
    void processEvents();
    void update(const sf::Time& dt);
    void render();

    int carCount = 50;
	float crossover_chance = 0.6;
	float mutation_chance = 0.4;
    std::unique_ptr<b2World> m_world;
    sf::RenderWindow m_window;
    DebugDraw m_dbgDrawHelper;
    std::vector<std::unique_ptr<Car>> m_car;

};
