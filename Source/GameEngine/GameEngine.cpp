//
// Created by Kraghan on 15/12/2016.
//

#include "../../Header/GameEngine/GameEngine.hpp"

/* Explicit */ GameEngine::GameEngine()
: m_isRunning(false)
, m_window(nullptr)
, m_game()
{
    // None
}

/* Virtual */ GameEngine::~GameEngine()
{
    // None
}

void GameEngine::init()
{
    SettingsParser settingsParser = SettingsParser();

    //Init graphic engine
    GraphicEngine::Instance()->init("The Binding of Jean-Michel",settingsParser.getResolution(),1500);
    m_window = GraphicEngine::Instance()->getWindow();
    GraphicEngine::Instance()->setFramerate(60.0);

    // Init physic engine
    PhysicEngine::Instance()->init(500);
}

void GameEngine::start()
{
    if(m_isRunning)
        return;
    m_game.init();
    m_isRunning = true;
    gameLoop();
}

void GameEngine::gameLoop()
{
    sf::Clock clock;
    double lag = 0.0;
    double previous = clock.getElapsedTime().asSeconds();

    while(m_isRunning)
    {
        double current = clock.getElapsedTime().asSeconds();
        double elapsed = current - previous;
        previous = current;

        lag += elapsed;

        // Processing inputs
        processInput();

        while(lag >= SECONDS_PER_UPDATE)
        {
            // Updating
            update(SECONDS_PER_UPDATE);

            // Retrieve elapsed time
            lag -= SECONDS_PER_UPDATE;
        }

        // Rendering
        GraphicEngine::Instance()->render(lag / SECONDS_PER_UPDATE);
    }
}

void GameEngine::processInput()
{
    // Creating the receiver event object
    sf::Event event;

    // Event loop
    while(m_window->pollEvent(event))
    {
        // The user wants to exit the game
        if (event.type == sf::Event::Closed)
        {
            m_isRunning = false;
        }

        StateMachine::Instance()->activeState()->onPollEvent(event);
    }
}

void GameEngine::update(double dt)
{
    PhysicEngine::Instance()->update(dt);
    StateMachine::Instance()->update(dt);
}
