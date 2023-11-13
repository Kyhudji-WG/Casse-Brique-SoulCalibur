// Casse-Brique-SoulCalibur.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
//#include "Ball.h"
//#include "Brick.h"
#include "Window.h"



int main(int argc, char** argv)
{
    //création de la fenetre
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML");

    //creation d'une balle de jeu
    GameObject oBall(150.f, 200.f, 10.f);

    //liste de balles
    std::vector <GameObject> oBalls;

    GameObject oRect(100.f, 100.f, 100.f, 20.f, sf::Color::Red);
    GameObject oRect2(500.f, 100.f, 100.f, 20.f, sf::Color::Red);


    //creation du canon
    GameObject oCannon(400.f, 600.f, 100.f, 20.f, sf::Color::Blue);


    float minAngle = -75.f;
    float maxAngle = 75.f;

    sf::Clock oClock;
    float deltaTime = 0;
    
    //GameLoop
    while (window.isOpen())
    {
        //EVENT
        sf::Event oEvent; 
        while (window.pollEvent(oEvent)) 
        {
            if (oEvent.type == sf::Event::Closed) 
                window.close(); 
            if (oEvent.type == sf::Event::MouseButtonReleased)
            {
                if (oEvent.mouseButton.button == sf::Mouse::Left)
                {
                    //GameObject oBall2(oCannon.getPosition().x, oCannon.getPosition().y, 10.f);
                    GameObject oBall2((oCannon.getPosition().x), (oCannon.getPosition().y), 10.f);
                    oBalls.push_back(oBall2);
                }
            }
        }

        //UPDATE

        oBall.moveBall(deltaTime);

        oRect.moveRect(deltaTime);

        for (int i = 0; i < oBalls.size(); i++)
        {
            oBalls[i].moveBall(deltaTime);
        }

        
        if (oRect.OnCollisionEnter(oRect.getRectangleRect(), oRect2.getRectangleRect()))
        {
          // std::cout << "collision1" << std::endl;
        }
        
        if (oBall.isOutScreen(oBall.getBallRect(), 800))
        {
           //std::cout << "sortie ecran1" << std::endl;
        }
        

        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

        
        // Calculer l'angle entre la position de la souris et la position de l'objet
        float angle = std::atan2(mousePosition.y - oCannon.getPosition().y, mousePosition.x - oCannon.getPosition().x);
        angle = angle * 180 / 3.14159265358979323846; // Convertir en degrés
        angle = std::min(75.f, std::max(-75.f, angle)); // restreindre l'angle
        // Appliquer l'angle comme rotation à l'objet
        oCannon.setRotation(angle);
        
        
        //DRAW
        window.clear();

        oBall.drawCircle(window);

        for (int i = 0; i < oBalls.size(); i++)
        {
            oBalls[i].drawCircle(window);
        }

        oRect.drawRect(window); 
        oRect2.drawRect(window); 
        
        oCannon.drawRect(window);

        window.display();

        deltaTime = oClock.restart().asSeconds ();
    }

    return 0;
}

