#ifndef SFMLCASE_H
#define SFMLCASE_H
#include "TextureHandler.h"
#include "SFMLPion.h"
#include <SFML/Graphics.hpp>
#include <ostream>
using namespace std;

/*
    La classe SFMLCase permet de représenter une instance
    d'une case de Quarto de façon graphique avec (ou non)
    ue pièce. gère l'affichage, la position et la texture
*/
class SFMLCase
{
    public:
        // ctor avec sa couleur et son style
        SFMLCase(bool,bool);
        // dtor
        virtual ~SFMLCase();
        // dessine la case
        void draw();
        // déplace la case par rapport à sa position actuelle
        void move(sf::Vector2f*);
        // ajoute une pièce à la case
        void addPion(SFMLPion*);
        // enlève la pièce
        SFMLPion* removePion();
        // Colorie la case
        void color();
        // Décolorie la case
        void discolor();
        // Calcule si la case à été cliquer
        bool onClick(sf::Event*);

        // Modifie la position de la case
        void setPosition(sf::Vector2f*);
        // Modifie la position de la case par rapport
        // au centre
        void setCenterPosition(sf::Vector2f*);
        // configure l'instance de RenderWindow pour l'affichage
        void setRenderWindow(sf::RenderWindow*);

        // Obtient la taille de la case
        const sf::Vector2u& getSize();
        // Obtient la position de la case
        const sf::Vector2f& getPosition();
        // Obtient la position central de la pièce
        sf::Vector2f* getCenterPosition();
        // Obtient le pion de la case
        SFMLPion* getPion();

    private:
        // pion de la case
        SFMLPion* pion;
        // position de la case
        sf::Vector2f *position;
        // position central de la case
        sf::Vector2f *centerPosition;
        // texture de la case
        sf::Texture *texture;
        // sprite de la case
        sf::Sprite *sprite;
        // instance RenderWindow
        sf::RenderWindow *window;

        // Calcule la position central de la case
        sf::Vector2f* localCenterPosition();
};

#endif // SFMLCASE_H
