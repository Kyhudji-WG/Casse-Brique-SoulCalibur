// Casse-Brique-SoulCalibur.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "GameObject.cpp"

int main(int argc, char** argv)
{

    //Création d'une fenêtre (640 - 480 base)
    sf::RenderWindow oWindow(sf::VideoMode(1460, 880), "SFML");

    //Création d'un cercle de radius (100 base)
    sf::CircleShape oCircle(10.f);
    //A la position 0, 0
    oCircle.setPosition(0.f, 0.f);
    //Et de couleur verte
    oCircle.setFillColor(sf::Color::Magenta);



    //Création d'un rectangle de taille (50, 50 base)
    sf::RectangleShape oRectangle(sf::Vector2f(100.f, 20.f));
    //A la position 100, 100
    oCircle.setPosition(100.f, 100.f);
    //Et de couleur rouge
    oRectangle.setFillColor(sf::Color::Red);


    // Création d'un canon de taille (50, 50 base)
    // sf::RectangleShape aRectangle(sf::Vector2f(20.f, 100.f));
    // A la position 100, 100
    // aRectangle.setPosition(100.f, 100.f);
    // couleur
    // aRectangle.setFillColor(sf::Color::Red);


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

        //DRAW
        oWindow.clear();

        oWindow.draw(oCircle);
        oWindow.draw(oRectangle);

        oWindow.display();
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
