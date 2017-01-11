//
// Created by Kraghan on 15/12/2016.
//

#include <iostream>
#include "../../Header/GraphicEngine/GraphicEngine.hpp"

/* explicit */ GraphicEngine::GraphicEngine()
        : m_window(nullptr)
        , m_framerate(60.0)
        , m_delta(0.0)
        , m_currentRender(0.0)
        , m_previousRender(0.0)
        , m_elapsedRender(0.0)
        , m_renderLag(0.0)
        , m_background(nullptr)
        , m_indexResolution(0)
{
    // None
}

/* virtual */ GraphicEngine::~GraphicEngine()
{
    // Deleting window
    delete m_window;
}

void GraphicEngine::loadTextures()
{
    for(unsigned i = 0; i < elements; ++i)
    {
        sf::Texture texture;
        if (!texture.loadFromFile(fileName[i]))
        {
            std::cout << "Can't read : " << fileName[i] << std::endl;
            continue;
        }
        texture.setSmooth(true);
        m_textureMap.insert(std::pair<std::string,sf::Texture>(names[i],texture));
    }
}


void GraphicEngine::init(std::string const& name,
                         unsigned resolution,
                         unsigned spriteCount)
{

    m_indexResolution = resolution;

    // Creating window
    m_window = new sf::RenderWindow(sf::VideoMode(resolutions[m_indexResolution].x,resolutions[m_indexResolution].y),
                                    name,sf::Style::Close);

    // Initializing managers
    m_spriteManager.init(spriteCount);

    // Computing delta
    m_delta = 1 / m_framerate;

    loadTextures();
}

Sprite * GraphicEngine::getSprite()
{
    Sprite* s = m_spriteManager.getFreeDrawable();
    s->setScale(scaleResolutions[m_indexResolution],scaleResolutions[m_indexResolution]);
    return s;
}

void GraphicEngine::render(double factor)
{
    // Checking if its the time to render
    m_currentRender = m_clock.getElapsedTime().asSeconds();
    m_elapsedRender = m_currentRender - m_previousRender;

    m_previousRender = m_currentRender;
    m_renderLag += m_elapsedRender;

    if(m_renderLag < m_delta)
    {
        // It's not yet the time to render
        // Skipping draw frame
        return;
    }

    // It's time to draw
    m_renderLag -= m_delta;

    // Checking the window states
    // If closed, Skipping
    if(!m_window->isOpen()) return;

    // Construct all layers
    // Assemble all drawable into those layers
    constructLayers(factor);

    // Draw call
    // See draw()
    draw();

    // Resetting all layer's size
    // and render state
    prepareLayer();
}

void GraphicEngine::constructLayers(double factor)
{
    // Getting sprites list
    const Sprite * _sprites = m_spriteManager.getDrawableList();
    unsigned _spritesCount  = m_spriteManager.getDrawableCount();

    // Iterating the list
    for(unsigned index = 0; index < _spritesCount; ++index)
    {
        if(!_sprites[index].isVisible()) continue;
        if(m_layers.find((int)_sprites[index].getPosition().y
                         + _sprites[index].getTextureRect().height)
           == m_layers.end())
        {
            std::vector<const Sprite*> toAdd;
            toAdd.push_back(&_sprites[index]);
            m_layers.emplace((int)_sprites[index].getPosition().y
                             + _sprites[index].getTextureRect().height,toAdd);
        }
        else
            m_layers.at((int)_sprites[index].getPosition().y
                        + _sprites[index].getTextureRect().height).push_back
                    (&_sprites[index]);
    }
    for(auto layer : m_layers)
    {
        for(auto sprite : layer.second)
        {
            m_apOrderedSprite.push_back(sprite);
        }
    }
}

void GraphicEngine::prepareLayer()
{
    m_layers.clear();
    m_apOrderedSprite.clear();
}

void GraphicEngine::draw()
{
    // Clearing buffer
    m_window->clear();

    // Drawing background
    if(m_background != nullptr)
    {
        m_window->draw(*m_background);
    }

    for(auto sprite : m_apOrderedSprite)
    {
        // Drawing the content of the current layer
        m_window->draw(*sprite);
    }

    // Swapping buffers
    m_window->display();
}

sf::RenderWindow * GraphicEngine::getWindow() const
{
    return m_window;
}

void GraphicEngine::setFramerate(double framerate)
{
    m_framerate = framerate;

    // Re-computing delta (time step)
    m_delta = 1 / m_framerate;
}

sf::Texture *GraphicEngine::getTextures(std::string identifier)
{
    std::map<std::string,sf::Texture>::iterator it = m_textureMap.find(identifier);
    if(it != m_textureMap.end())
        return &it->second;
    return nullptr;
}

sf::Vector2u GraphicEngine::getResolution()
{
    return resolutions[m_indexResolution];
}

sf::Vector2f GraphicEngine::getSpriteSize(sf::Vector2f size)
{
    return sf::Vector2f(size.x*scaleResolutions[m_indexResolution],
                        size.y*scaleResolutions[m_indexResolution]);
}
