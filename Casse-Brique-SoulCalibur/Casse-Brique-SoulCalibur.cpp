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

    GameObject oRect5(350.f, 200.f, 100.f,20.f);

    GameObject oRect(100.f, 100.f, 100.f, 20.f);
    GameObject oRect2(500.f, 100.f, 100.f, 20.f);

    GameObject oRect3(150.f, 250.f, 150.f, 200.f);
    GameObject oRect4(500.f, 600.f, 100.f, 20.f);

    GameObject oCannon(400.f, 500.f, 100.f, 20.f);


    // Création d'un canon
    //sf::RectangleShape aRectangle(sf::Vector2f(20.f, 100.f));
    //la position
    //aRectangle.setPosition(100.f, 100.f);
    // et la couleur
    //aRectangle.setFillColor(sf::Color::Red);



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

        //oBall.moveBall(deltaTime);

        //oRect.moveRect(deltaTime);
        oRect3.moveRect(deltaTime);


        
        if (oRect3.OnCollisionEnter(oRect3.getRectangleRect(), oRect5.getRectangleRect()))
        {
            std::cout << "collision1" << std::endl;
        }
        
        if (oBall.OnCollisionEnter(oBall.getBallRect(), oRect5.getRectangleRect()))
        {
            std::cout << "collision2" << std::endl;
        }
        if (oBall.isOutScreen(oBall.getBallRect(), 800))
        {
            std::cout << "sortie ecran1" << std::endl;
        }
        
        if (oRect.isOutScreen(oRect.getRectangleRect(), 800))
        {
            std::cout << "sortie ecran2" << std::endl;
        }
        
        //DRAW
        window.clear();

        oBall.drawCircle(window);
        oRect.drawRect(window); 
        oRect2.drawRect(window); 
        oRect5.drawRect(window); 

        oRect3.drawRect(window);
        oRect4.drawRect(window);
        

        window.display();

        deltaTime = oClock.restart().asSeconds ();
    }

    return 0;
}

