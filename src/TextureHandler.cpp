#include "TextureHandler.h"

// début du nom du fichier d'une pièce
std::string TextureHandler::START_PIECE_PATH = "piece-";
// fin du nom du fichier d'une pièce
std::string TextureHandler::END_PATH   = ".png";

// caractérisques des pièces pour le nom du fichier
std::string TextureHandler::RED    = "R";
std::string TextureHandler::BLUE   = "B";
std::string TextureHandler::BIG    = "G";
std::string TextureHandler::SMALL  = "P";
std::string TextureHandler::FLAT   = "P";
std::string TextureHandler::HOLES  = "T";
std::string TextureHandler::CIRCLE = "C";
std::string TextureHandler::SQUARE = "R";

// nom du fichier pour les cases du plateau
std::string TextureHandler::TILE1 = "Tile 1";
std::string TextureHandler::TILE2 = "Tile 2";

// chemin pour les textures SoftV1
std::string TextureHandler::PATH_SOFT1 = "images/Soft v1/";
// chemin pour les textures SoftV2
std::string TextureHandler::PATH_SOFT2 = "images/Soft v2/";
// chemin choisie pour les textures
std::string TextureHandler::START_PATH = TextureHandler::PATH_SOFT1;

// paramétre le style en SoftV1
void TextureHandler::setSoftV1(){
    TextureHandler::START_PATH = TextureHandler::PATH_SOFT1;
}

// paramétre le style en SoftV2
void TextureHandler::setSoftV2(){
    TextureHandler::START_PATH = TextureHandler::PATH_SOFT2;
}

// Obtient le nom du fichier pour une pièce avec ses attributs
std::string* TextureHandler::getTextureNamePiece(bool color,bool dimension,bool spec,bool shape){
    std::string strColor;
    std::string strDimension;
    std::string strSpec;
    std::string strShape;

    color ? strColor = TextureHandler::RED : strColor = TextureHandler::BLUE;
    dimension ? strDimension = TextureHandler::BIG : strDimension = TextureHandler::SMALL;
    spec ? strSpec = TextureHandler::FLAT : strSpec = TextureHandler::HOLES;
    shape ? strShape = TextureHandler::CIRCLE : strShape = TextureHandler::SQUARE;

    // compose le nom du fichier avec le chemin
    std::string *result = new std::string(
        TextureHandler::START_PATH +
        TextureHandler::START_PIECE_PATH +
        strColor +
        strDimension +
        strSpec +
        strShape +
        TextureHandler::END_PATH);
    return result;
}

// Obtient la texture d'une pièce avec ses attribtus
sf::Texture* TextureHandler::getTexturePiece(bool color,bool dimension,bool spec,bool shape){
    sf::Texture texture;
    std::string *textureName = TextureHandler::getTextureNamePiece(color,dimension,spec,shape);
    if (!texture.loadFromFile(*textureName)){
        //errors
    }
    return new sf::Texture(texture);
}

// Obtient la texture d'une case de Quarto claire
sf::Texture* TextureHandler::getTextureTileLigth(){
    sf::Texture texture;
    std::string *textureName = new std::string(
        TextureHandler::START_PATH +
        TextureHandler::TILE1 +
        TextureHandler::END_PATH);

    if (!texture.loadFromFile(*textureName)){
        //errors
    }
    return new sf::Texture(texture);
}

// Obtient la texture d'une case de Quarto sombre
sf::Texture* TextureHandler::getTextureTileDark(){
    sf::Texture texture;
    std::string *textureName = new std::string(
        TextureHandler::START_PATH +
        TextureHandler::TILE2 +
        TextureHandler::END_PATH);

    if (!texture.loadFromFile(*textureName)){
        //errors
    }
    return new sf::Texture(texture);
}

