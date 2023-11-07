// Casse-Brique-SoulCalibur.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Ball.h"
#include "Brick.h"


int main(int argc, char** argv)
{
    //Création d'une fenêtre 
    sf::RenderWindow oWindow(sf::VideoMode(1460, 880), "SFML");

    //creation d'une balle de jeu
    GameObject oBall;


    //Création d'un cercle de radius (100 base)
    sf::CircleShape oCircle(10.f);
    //la position 
    oCircle.setPosition(0.f, 0.f);
    //Et la couleur
    oCircle.setFillColor(sf::Color::Magenta);



    //Création d'un rectangle 
    sf::RectangleShape oRectangle(sf::Vector2f(100.f, 20.f));
    //la position 
    oRectangle.setPosition(100.f, 100.f);
    //Et la couleur 
    oRectangle.setFillColor(sf::Color::Red);

    // Création d'un canon
    //sf::RectangleShape aRectangle(sf::Vector2f(20.f, 100.f));
    //la position
    //aRectangle.setPosition(100.f, 100.f);
    // et la couleur
    //aRectangle.setFillColor(sf::Color::Red);

    

    sf::Clock oClock;
    float deltaTime = 0;
    //GameLoop
    while (oWindow.isOpen())
    {
        //EVENT
        sf::Event oEvent;
        while (oWindow.pollEvent(oEvent))
        {
            if (oEvent.type == sf::Event::Closed)
                oWindow.close();
        }

        //UPDATE

        oBall.move(deltaTime);

        //DRAW
        oWindow.clear();

        oWindow.draw(oCircle);
        //oWindow.draw(oBall);
        oWindow.draw(oRectangle);
        //oWindow.draw(aRectangle);

        oWindow.display();

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
