// Casse-Brique-SoulCalibur.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Ball.h"
#include "Brick.h"
#include "Canon.h"
#include "Window.h"



int main(int argc, char** argv)
{
    //création de la fenetre
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML");


    //liste de balles
    std::vector <Ball> oBalls; 

    std::vector <Brick> oBricks;

    Brick oBrick(100.f, 100.f, 100.f, 20.f, sf::Color::Red, 3);
    oBricks.push_back(oBrick); 
    Brick oBrick2(500.f, 100.f, 100.f, 20.f, sf::Color::Red, 3);
    oBricks.push_back(oBrick2); 
    Brick oBrick3(620.f, 100.f, 100.f, 20.f, sf::Color::Red, 3);
    oBricks.push_back(oBrick3);



    //creation du canon
    Canon oCanon(400.f, 600.f, 20.f, 100.f, sf::Color::Blue);


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
                    Ball oBall2((oCanon.getPosition().x), (oCanon.getPosition().y) , 10.f, sf::Color::Green);
                    oBall2.setDirection(oCanon.getDirection().y, oCanon.getDirection().x);
                    oBalls.push_back(oBall2);
                }
            }
        }

        //UPDATE

        for (int i = 0; i < oBalls.size(); i++)
        {
            oBalls[i].moveBall(deltaTime);
            oBalls[i].rebond();
        }

        for (int i = 0; i < oBricks.size(); i++)
        {
            //oBricks[i].TakeDamage();
        }
        

        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);


        float angle = atan2(mousePosition.y - oCanon.getPosition().y, mousePosition.x - oCanon.getPosition().x);
        angle = angle * 180 / 3.14159 + 90; // Conversion en degrés
        float pastAngle = angle;
        angle = std::min(75.f, std::max(-75.f, angle));

        //std::cout << pastAngle << std::endl;
        if (pastAngle == angle)
        {
            oCanon.setDirection(mousePosition.y - oCanon.getPosition().y, mousePosition.x - oCanon.getPosition().x);
            oCanon.setRotation(angle); // Rotation du canon
        }
        
        
        //DRAW
        window.clear();

        for (int i = 0; i < oBalls.size(); i++)
        {
            oBalls[i].drawCircle(window);
        }
        for (int i = 0; i < oBricks.size(); i++)
        {
            oBricks[i].drawRect(window);
        }

        
        oCanon.drawRect(window);

        

        window.display();

        deltaTime = oClock.restart().asSeconds ();
    }

    return 0;
}

