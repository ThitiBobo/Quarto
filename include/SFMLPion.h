#ifndef SFMLPION_H
#define SFMLPION_H
#include "TextureHandler.h"
#include <SFML/Graphics.hpp>

/*
    La classe SFMLPion représente une instance d'un pion
    de Quarto de façons graphique, gère son affichage, son style,
    ses textures et sa position.
*/
class SFMLPion
{
    public:
        // ctor avec ses attributs et son style
        SFMLPion(bool,bool,bool,bool,bool);
        // dtor
        virtual ~SFMLPion();
        // Affiche le pion
        void draw();
        // Permet de déplacer le pion par rapport à
        // sa position actuelle
        void move(sf::Vector2f*);

        // Modifie la position par rapport au coin
        // supérieur gauche
        void setPosition(sf::Vector2f*);
        // Modifie la position par rapport au centre
        void setCenterPosition(sf::Vector2f*);
        // Définie l'instance de RenderWindow window
        void setRenderWindow(sf::RenderWindow*);

        // Obtient la taille
        const sf::Vector2u& getSize();
        // Obtient la position par rapport au coin
        // supérieur gauche
        const sf::Vector2f& getPosition();
        // Obient la position par rapport au centre
        sf::Vector2f* getCenterPosition();

    private:
        // position de la pièce
        sf::Vector2f *position;
        // position de la pièce par rapport au centre
        sf::Vector2f *centerPosition;
        // texture de la pièce
        sf::Texture *texture;
        // sprite de la pièce
        sf::Sprite *sprite;
        // instance de RenderWindow
        sf::RenderWindow *window;

        // Permet de calculer la position central
        // de la pièce de façon relatif
        sf::Vector2f* localCenterPosition();
};

#endif // SFMLPION_H
