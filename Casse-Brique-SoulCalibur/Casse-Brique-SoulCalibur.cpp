#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameObject.h"

int main(int argc, char** argv)
{
    // Création de la fenêtre
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML");

    // Création d'une balle de jeu
    GameObject oBall(150.f, 200.f, 10.f);

    // Création de rectangles
    GameObject oBrick(100.f, 100.f, 70.f, 20.f);
    GameObject oBrick2(250.f, 100.f, 70.f, 20.f);
    GameObject oBrick3(400.f, 100.f, 70.f, 20.f);
    GameObject oBrick4(550.f, 100.f, 70.f, 20.f);
    GameObject oBrick5(100.f, 200.f, 70.f, 20.f);
    GameObject oBrick6(250.f, 200.f, 70.f, 20.f);
    GameObject oBrick7(400.f, 200.f, 70.f, 20.f);
    GameObject oBrick8(550.f, 200.f, 70.f, 20.f);
    GameObject oBrick13(550.f, 200.f, 70.f, 20.f);
    GameObject oBrick9(100.f, 300.f, 70.f, 20.f);
    GameObject oBrick10(250.f, 300.f, 70.f, 20.f);
    GameObject oBrick11(400.f, 300.f, 70.f, 20.f);
    GameObject oBrick12(550.f, 300.f, 70.f, 20.f);
    GameObject oBrick14(550.f, 200.f, 70.f, 20.f);

    // Création du canon
    GameObject oCannon(400.f, 499.f, 20.f, 100.f);
    

    // Initialisation du temps
    sf::Clock oClock;
    float deltaTime = 0;

    // GameLoop
    while (window.isOpen())
    {
        // EVENT
        sf::Event oEvent;
        while (window.pollEvent(oEvent))
        {
            if (oEvent.type == sf::Event::Closed)
                window.close();
        }

        // UPDATE
        oBall.moveBall(deltaTime);

        // Calcul de l'angle entre le canon et la position de la souris
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

        float angle = atan2(mousePosition.y - oCannon.getPosition().y, mousePosition.x - oCannon.getPosition().x);
        angle = angle * 180 / 3.14159 + 90; // Conversion en degrés
        float pastAngle = angle;
        angle = std::min(75.f, std::max(-75.f, angle));

        std::cout << pastAngle << std::endl;
        if (pastAngle == angle)
        {
            oCannon.setRotation(angle); // Rotation du canon
        }

        // DRAW
        window.clear();

        oBall.drawCircle(window);
        oBrick.drawRect(window);
        oBrick2.drawRect(window);
        oBrick3.drawRect(window);
        oBrick4.drawRect(window);
        oBrick5.drawRect(window);
        oBrick6.drawRect(window);
        oBrick7.drawRect(window);
        oBrick8.drawRect(window);
        oBrick9.drawRect(window);
        oBrick10.drawRect(window);
        oBrick11.drawRect(window);
        oBrick12.drawRect(window);

        oCannon.drawRect(window);

        window.display();

        deltaTime = oClock.restart().asSeconds();
    }

    return 0;
}
