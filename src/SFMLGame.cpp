#include "SFMLGame.h"
#include <iostream>

SFMLGame::SFMLGame()
{
    window  = new sf::RenderWindow(sf::VideoMode(790, 410), "Quarto Game");
    currentCoords = NULL;
    boardCoords = NULL;
    reserveCoords = NULL;

    initcomponents();
}

SFMLGame::~SFMLGame()
{
    //dtor
}

void SFMLGame::lunch(){
    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                cout << "clic :";
                currentCoords = reserve->onClick(&event);
                if(currentCoords != NULL){
                    cout << currentCoords[0] << currentCoords[1] << endl;
                    // vérifie si c'est la meme case
                    if(reserveCoords != NULL){
                        if(currentCoords[0] == reserveCoords[0] && currentCoords[1] == reserveCoords[1]){
                            reserveCoords = NULL;
                            reserve->discolorCase(currentCoords[0],currentCoords[1]);
                        }else{
                            reserveCoords = new int[2];
                            reserveCoords[0] = currentCoords[0];
                            reserveCoords[1] = currentCoords[1];
                            reserve->colorCase(reserveCoords[0],reserveCoords[1]);
                        }
                    }else{
                            reserveCoords = new int[2];
                            reserveCoords[0] = currentCoords[0];
                            reserveCoords[1] = currentCoords[1];
                            reserve->colorCase(reserveCoords[0],reserveCoords[1]);
                        }
                }

            }
        }
        window->clear();
        board->draw();
        reserve->draw();
        window->display();
    }
}

void SFMLGame::initcomponents(){

    //board
    board = new SFMLGrid(1);
    board->setRenderWindow(window);
    board->setPosition(new sf::Vector2f(0 + 40,0 + 40));

    //reserve
    reserve = new SFMLGrid(1);
    reserve->setRenderWindow(window);
    reserve->setPosition(new sf::Vector2f(332 + 80,0 + 40));

    //pion
    int number[16][4] ={
        {0,0,0,0},
        {0,0,0,1},
        {0,0,1,0},
        {0,0,1,1},
        {0,1,0,0},
        {0,1,0,1},
        {0,1,1,0},
        {0,1,1,1},
        {1,0,0,0},
        {1,0,0,1},
        {1,0,1,0},
        {1,0,1,1},
        {1,1,0,0},
        {1,1,0,1},
        {1,1,1,0},
        {1,1,1,1}
         };

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            SFMLPion* pion = new SFMLPion(number[i * 4 + j][0],number[i * 4 + j][3],number[i * 4 + j][2],number[i * 4 + j][1],1);
            pion->setRenderWindow(window);
            reserve->addPion(i,j,pion);
        }
    }
}


