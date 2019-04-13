#ifndef TEXTUREHANDLER_H
#define TEXTUREHANDLER_H
#include <string>
#include <SFML/Graphics.hpp>

/*
    La classe TextureHandler propose plusieurs méthodes statique permettant
    la gestion du chargement des différentes images et textures pour le
    jeu du Quarto.
*/
class TextureHandler
{
    public:
        // Obtient le nom du fichier pour une pièce donnée
        // avec ses caractéristiques
        static std::string* getTextureNamePiece(bool,bool,bool,bool);
        //Obtient la texture pour une pièce donnée avec ses caractéristiques
        static sf::Texture* getTexturePiece(bool,bool,bool,bool);
        // Obtient la texture pour une pièce donnée avec le nom du fichier
        static sf::Texture* getTexturePiece(std::string*);
        // Obtient la texture d'une case de plateau claire
        static sf::Texture* getTextureTileLigth();
        // Obtient la texture d'une case de plateau sombre
        static sf::Texture* getTextureTileDark();
        // permet de paramétrer le styles des textures en SoftV1
        static void setSoftV1();
        // permet de paramétrer le styles des textures en SoftV2
        static void setSoftV2();

    private:
        // les noms des fichier et chemins des ressources
        static std::string START_PIECE_PATH;
        static std::string END_PATH;
        static std::string RED;
        static std::string BLUE;
        static std::string BIG;
        static std::string SMALL;
        static std::string FLAT;
        static std::string HOLES;
        static std::string CIRCLE;
        static std::string SQUARE;

        static std::string TILE1;
        static std::string TILE2;

        static std::string PATH_SOFT1;
        static std::string PATH_SOFT2;
        static std::string START_PATH;


};

#endif // TEXTUREHANDLER_H
