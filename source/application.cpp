#include "application.h"
#include "helpers/imgui_sfml.h"
#include "common.h"

#include <SFML/Window/Event.hpp>
#include <imgui/imgui.h>

Application::Application() :
    m_window(sf::VideoMode(1280, 720), "AI Cars"),
    m_dbgDrawHelper(m_window)
{
    m_window.setFramerateLimit(60);

    b2Vec2 gravity(0.f, 0.f);
    m_world = std::make_unique<b2World>(gravity);
    
    m_dbgDrawHelper.SetFlags(DebugDraw::e_shapeBit);
    m_world->SetDebugDraw(&m_dbgDrawHelper);
}

void Application::run()
{
    im_sf::init(m_window);
    
    sf::Clock clock;
    while (m_window.isOpen()) {
        processEvents();
        update(clock.restart());
        render();
    }

    im_sf::shutdown();
}

void Application::processEvents()
{
    sf::Event e;
    while (m_window.pollEvent(e))
    {
        if (e.type == sf::Event::Closed)
            m_window.close();

        im_sf::processEvents(e);
    }
}

void Application::update(const sf::Time& dt)
{
    m_world->Step(1 / 60.f, 10, 8);
    im_sf::update(dt);
}

void Application::render()
{
    m_window.clear();

    m_world->DebugDraw();

    //ImGui::Begin("Options");
    //ImGui::SliderFloat(STRINGIFY(renderScaleFactor), &renderScaleFactor, 16.f, 36.f);
    //ImGui::End();

    ImGui::ShowDemoWindow();

    im_sf::render();
    m_window.display();
}