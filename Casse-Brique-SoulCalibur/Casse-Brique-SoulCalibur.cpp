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

    GameObject oRect(100.f, 100.f, 100.f, 20.f);
    GameObject oRect2(500.f, 100.f, 100.f, 20.f);


    //creation du canon
    GameObject oCannon(400.f, 500.f, 100.f, 20.f);
    oCannon.setRotation(90);



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
        }

        //UPDATE

        oBall.moveBall(deltaTime);

        oRect.moveRect(deltaTime);

        
        if (oRect.OnCollisionEnter(oRect.getRectangleRect(), oRect2.getRectangleRect()))
        {
            std::cout << "collision1" << std::endl;
        }
        
        if (oBall.isOutScreen(oBall.getBallRect(), 800))
        {
            std::cout << "sortie ecran1" << std::endl;
        }
        
        //DRAW
        window.clear();

        oBall.drawCircle(window);
        oRect.drawRect(window); 
        oRect2.drawRect(window); 
        
        oCannon.drawRect(window);

        window.display();

        deltaTime = oClock.restart().asSeconds ();
    }

    return 0;
}

