#ifndef TEXTUREHANDLER_H
#define TEXTUREHANDLER_H
#include <string>
#include <SFML/Graphics.hpp>


class TextureHandler
{
    public:
        static std::string* getTextureNamePiece(bool,bool,bool,bool);
        static sf::Texture* getTexturePiece(bool,bool,bool,bool);
        static sf::Texture* getTexturePiece(std::string*);
        static sf::Texture* getTextureTileLigth();
        static sf::Texture* getTextureTileDark();
        static void setSoftV1();
        static void setSoftV2();

    private:
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
