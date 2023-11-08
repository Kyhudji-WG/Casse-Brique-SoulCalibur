#include "GameObject.h"

GameObject::GameObject() {
    // Initialiser les variables membres si n�cessaire
}

void GameObject::setPosition(float x, float y) {
    m_shape.setPosition(x, y);
}

void GameObject::setShape(const sf::Shape& shape) {
    m_shape = shape;
}

void GameObject::setColor(const sf::Color& color) {
    m_shape.setFillColor(color);
}

void GameObject::draw(sf::RenderWindow& oWindow) {
    oWindow.draw(m_shape);
}

// Impl�mentez d'autres fonctions membres pour g�rer les mouvements, les collisions, etc.
