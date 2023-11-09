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

    GameObject oBall2(300.f, 200.f, 10.f);

    GameObject oRect(100.f, 100.f, 100.f, 20.f);
    GameObject oRect2(500.f, 100.f, 100.f, 20.f);

    GameObject oRect3(100.f, 600.f, 150.f, 60.f);
    GameObject oRect4(500.f, 600.f, 100.f, 20.f);


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

        oBall.moveBall(deltaTime);

        oRect.moveRect(deltaTime);

        oRect3.moveRect(deltaTime); 

        sf::FloatRect ballRect;
        ballRect = oBall.getBallRect();

 

        if (oRect.OnCollisionEnter(oRect.getRectangleRect(), oRect2.getRectangleRect()))
        {
            std::cout << "collision" << std::endl;
        }
        
        //DRAW
        window.clear();

        oBall.drawCircle(window);
        oBall2.drawCircle(window);
        oRect.drawRect(window);
        oRect2.drawRect(window);

        oRect3.drawRect(window);
        oRect4.drawRect(window);
        

        window.display();

        deltaTime = oClock.restart().asSeconds ();
    }

    return 0;
}



// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
