#pragma once

#include <SFML/Graphics.hpp>

class GameObject {
public:
    GameObject(); // Constructeur
    void setPosition(float x, float y);
    void setShape(const sf::Shape& shape);
    void setColor(const sf::Color& color);
    void draw(sf::RenderWindow& window);

    // Autres fonctions membres pour la gestion des mouvements, des collisions, etc.
    // ...

private:
    sf::Shape m_shape;
};


