//
// Created by Kraghan on 15/12/2016.
//

#ifndef BINDINGOFJEANMICHEL_GRAPHICENGINE_HPP
#define BINDINGOFJEANMICHEL_GRAPHICENGINE_HPP


#include <string>
#include <map>
#include "../Tools/Singleton.hpp"
#include "DrawableManager.hpp"
#include "Sprite.hpp"

class GraphicEngine : public Singleton < GraphicEngine >
{
    //------------------------------------------------------------------------------------------------------------------
    /// Public members
    //------------------------------------------------------------------------------------------------------------------
public:
    explicit            GraphicEngine              ();
    virtual             ~GraphicEngine             ();
    void                init                       ( std::string const& name,
                                                      unsigned resolution,
                                                      unsigned spriteCount);
    Sprite  *           getSprite                  ();
    void                render                     (double factor);
    sf::RenderWindow *  getWindow                  () const;
    void                setFramerate               (double framerate);
    sf::Texture*        getTextures                (std::string identifier);
    sf::Vector2u        getResolution              ();
    sf::Vector2f        getSpriteSize              (sf::Vector2f size);

    //------------------------------------------------------------------------------------------------------------------
    /// Protected members
    //------------------------------------------------------------------------------------------------------------------
protected:

    //------------------------------------------------------------------------------------------------------------------
    /// Private members
    //------------------------------------------------------------------------------------------------------------------
private:
    sf::RenderWindow *  m_window;
    DrawableManager<Sprite> m_spriteManager;
    std::map<std::string,sf::Texture> m_textureMap;
    void                loadTextures                ();
    double              m_framerate;
    double              m_delta;

    sf::Clock           m_clock;
    void                draw                        ();
    void                constructLayers             (double factor);
    void                prepareLayer                ();
    double              m_currentRender;
    double              m_previousRender;
    double              m_elapsedRender;
    double              m_renderLag;
    Sprite*             m_background;
    std::vector<const Sprite*> m_apOrderedSprite;
    std::map<int,std::vector<const Sprite*>> m_layers;

    const std::string   texturePath                 = "../res/Texture/";

    static const unsigned int  elements             = 10;

    const std::string   fileName[elements]          =
    {
            texturePath+"Angle.png",
            texturePath+"Angle_BL.png",
            texturePath+"Angle_BR.png",
            texturePath+"Angle_TR.png",
            texturePath+"Wall.png",
            texturePath+"Wall_B.png",
            texturePath+"Wall_R.png",
            texturePath+"Wall_L.png",
            texturePath+"Jean-Michel_spritesheet.png",
            texturePath+"obstacle.png"
    };
    const std::string   names[elements]             =
    {
            "ANGLE_TL",
            "ANGLE_BL",
            "ANGLE_BR",
            "ANGLE_TR",
            "WALL_TOP",
            "WALL_BOTTOM",
            "WALL_RIGHT",
            "WALL_LEFT",
            "PLAYER",
            "OBSTACLE"
    };

    unsigned            m_indexResolution;

    const sf::Vector2u  resolutions [3]             =
    {
            sf::Vector2u(960,576),
            sf::Vector2u(1280,768),
            sf::Vector2u(1600,960)
    };

    const float         scaleResolutions[3]         =
    {
            0.6f,
            0.8f,
            1.0f
    };
};


#endif //BINDINGOFJEANMICHEL_GRAPHICENGINE_HPP
