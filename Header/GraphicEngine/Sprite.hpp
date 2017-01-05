//
// Created by Kraghan on 15/12/2016.
//

#ifndef BINDINGOFJEANMICHEL_SPRITE_HPP
#define BINDINGOFJEANMICHEL_SPRITE_HPP


#include <SFML/Graphics.hpp>
#include "RenderBase.hpp"

class Sprite : public sf::Drawable, public sf::Transformable, public RenderBase
{
    //------------------------------------------------------------------------------------------------------------------
    /// Public members
    //------------------------------------------------------------------------------------------------------------------
public:
    explicit            Sprite              ();
    explicit            Sprite              (const sf::Texture& texture);
    explicit            Sprite              (const sf::Texture& texture, const sf::IntRect& rectangle);
    virtual             ~Sprite             ();
    void setTexture(const sf::Texture& texture, bool resetRect = false);
    void setTextureRect(const sf::IntRect& rectangle);
    const sf::Texture* getTexture() const;
    const sf::IntRect& getTextureRect() const;
    sf::FloatRect getLocalBounds() const;
    sf::FloatRect getGlobalBounds() const;
    const sf::Vertex * getVertices() const;
    static void release(Sprite *& sprite);

    //------------------------------------------------------------------------------------------------------------------
    /// Protected members
    //------------------------------------------------------------------------------------------------------------------
protected:

    //------------------------------------------------------------------------------------------------------------------
    /// Private members
    //------------------------------------------------------------------------------------------------------------------
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void updatePositions();
    void updateTexCoords();

    const sf::Texture* m_texture;
    sf::Vertex         m_vertices[4];
    sf::IntRect        m_textureRect;
};


#endif //BINDINGOFJEANMICHEL_SPRITE_HPP
