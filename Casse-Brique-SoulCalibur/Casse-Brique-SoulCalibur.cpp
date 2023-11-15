#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Brick.h"

int main(int argc, char** argv)
{
    // Création de la fenêtre
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML");


    //liste balles 
    std::vector <GameObject> oBalls;

    //liste Brick 
    std::vector <GameObject> oBricks;
    // Création de rectangles
    Brick oBrick(100.f, 100.f, 60.f, 20.f,sf::Color::Yellow, 1);
    oBricks.push_back(oBrick);

    Brick oBrick2(200.f, 100.f, 60.f, 20.f, sf::Color::Magenta, 2);
    oBricks.push_back(oBrick2);

    Brick oBrick3(300.f, 100.f, 60.f, 20.f, sf::Color::Red, 3);
    oBricks.push_back(oBrick3);

    Brick oBrick4(400.f, 100.f, 60.f, 20.f, sf::Color::Red, 3);
    oBricks.push_back(oBrick4);

    Brick oBrick5(500.f, 100.f, 60.f, 20.f, sf::Color::Red, 3);
    oBricks.push_back(oBrick5);

    Brick oBrick6(100.f, 150.f, 60.f, 20.f, sf::Color::Red, 3);
    oBricks.push_back(oBrick6);

    Brick oBrick7(200.f, 150.f, 60.f, 20.f, sf::Color::Red, 3);
    oBricks.push_back(oBrick7);

    Brick oBrick8(300.f, 150.f, 60.f, 20.f, sf::Color::Red, 3);
    oBricks.push_back(oBrick8);

    Brick oBrick9(400.f, 150.f, 60.f, 20.f, sf::Color::Red, 3);
    oBricks.push_back(oBrick9);

    Brick oBrick10(500.f, 150.f, 60.f, 20.f, sf::Color::Red, 3);
    oBricks.push_back(oBrick10);

    Brick oBrick11(100.f, 200.f, 60.f, 20.f, sf::Color::Red, 3);
    oBricks.push_back(oBrick11);

    Brick oBrick12(200.f, 200.f, 60.f, 20.f, sf::Color::Red, 3);
    oBricks.push_back(oBrick12);

    Brick oBrick13(300.f, 200.f, 60.f, 20.f, sf::Color::Red, 3);
    oBricks.push_back(oBrick13);

    Brick oBrick14(400.f, 200.f, 60.f, 20.f, sf::Color::Red, 3);
    oBricks.push_back(oBrick14);

    Brick oBrick15(500.f, 200.f, 60.f, 20.f, sf::Color::Red, 3);
    oBricks.push_back(oBrick15);

    Brick oBrick16(600.f, 100.f, 60.f, 20.f, sf::Color::Red, 3);
    oBricks.push_back(oBrick16);

    Brick oBrick17(700.f, 100.f, 60.f, 20.f, sf::Color::Red, 3);
    oBricks.push_back(oBrick17);

    Brick oBrick18(600.f, 150.f, 60.f, 20.f, sf::Color::Red, 3);
    oBricks.push_back(oBrick18);

    Brick oBrick19(700.f, 150.f, 60.f, 20.f, sf::Color::Red, 3);
    oBricks.push_back(oBrick19);

    Brick oBrick20(600.f, 200.f, 60.f, 20.f, sf::Color::Red, 3);
    oBricks.push_back(oBrick20);

    Brick oBrick21(700.f, 200.f, 60.f, 20.f, sf::Color::Red, 3);
    oBricks.push_back(oBrick21);

    /*
    GameObject oBrick(100.f, 100.f, 70.f, 20.f);
    GameObject oBrick2(250.f, 100.f, 70.f, 20.f);
    GameObject oBrick3(400.f, 100.f, 70.f, 20.f);
    GameObject oBrick4(550.f, 100.f, 70.f, 20.f);
    GameObject oBrick5(100.f, 200.f, 70.f, 20.f);
    GameObject oBrick6(250.f, 200.f, 70.f, 20.f);
    GameObject oBrick7(400.f, 200.f, 70.f, 20.f);
    GameObject oBrick8(550.f, 200.f, 70.f, 20.f);
    GameObject oBrick9(100.f, 300.f, 70.f, 20.f);
    GameObject oBrick10(250.f, 300.f, 70.f, 20.f);
    GameObject oBrick11(400.f, 300.f, 70.f, 20.f);
    GameObject oBrick12(550.f, 300.f, 70.f, 20.f);
    GameObject oBrick13(700.f, 100.f, 70.f, 20.f);
    GameObject oBrick14(700.f, 200.f, 70.f, 20.f);
    GameObject oBrick15(700.f, 300.f, 70.f, 20.f);
    */

    // Création du canon
    GameObject oCannon(400.f, 600.f, 20.f, 100.f, sf::Color::Cyan);
    

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
            if (oEvent.type == sf::Event::MouseButtonReleased) {
                if (oEvent.mouseButton.button == sf::Mouse::Left)
                {
                    // position + direction des balle 
                    GameObject oBall2((oCannon.getPosition().x), (oCannon.getPosition().y), 10.f, sf::Color::Green);
                    oBall2.setDirection(oCannon.getDirection().y, oCannon.getDirection().x);
                    oBalls.push_back(oBall2);


                }
            }
        }

        // UPDATE

      

        for (int i = 0; i < oBalls.size(); i++)
        {
            oBalls[i].moveBall(deltaTime);
            oBalls[i].rebond();
        }

        /*
        
        for (int i = 0; i < oBricks.size(); ++i) 
        {
            if ( oBalls.IsColliding( oBricks[i]) )
            {

            }
        }

        */

        // Calcul de l'angle entre le canon et la position de la souris
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

        float angle = atan2(mousePosition.y - oCannon.getPosition().y, mousePosition.x - oCannon.getPosition().x);
        angle = angle * 180 / 3.14159 + 90; // Conversion en degrés
        float pastAngle = angle;
        angle = std::min(75.f, std::max(-75.f, angle));

        //std::cout << pastAngle << std::endl;
        if (pastAngle == angle)
        {
            oCannon.setDirection(mousePosition.y - oCannon.getPosition().y, mousePosition.x - oCannon.getPosition().x);
            oCannon.setRotation(angle); // Rotation du canon
        }

        // DRAW
        window.clear();

        for (int i = 0; i < oBalls.size(); i++)
        {
            oBalls[i].drawCircle(window);
        }

        for (int i = 0; i < oBricks.size(); i++)
        {
            oBricks[i].drawRect(window);
        }

        /*
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
        oBrick13.drawRect(window);
        oBrick14.drawRect(window);
        oBrick15.drawRect(window);
        */
        oCannon.drawRect(window);

        window.display();

        deltaTime = oClock.restart().asSeconds();
    }

    return 0;
}
