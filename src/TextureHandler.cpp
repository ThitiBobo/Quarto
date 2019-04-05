#include "TextureHandler.h"

std::string TextureHandler::START_PIECE_PATH = "piece-";
std::string TextureHandler::END_PATH   = ".png";

std::string TextureHandler::RED    = "R";
std::string TextureHandler::BLUE   = "B";
std::string TextureHandler::BIG    = "G";
std::string TextureHandler::SMALL  = "P";
std::string TextureHandler::FLAT   = "P";
std::string TextureHandler::HOLES  = "T";
std::string TextureHandler::CIRCLE = "C";
std::string TextureHandler::SQUARE = "R";

std::string TextureHandler::TILE1 = "Tile 1";
std::string TextureHandler::TILE2 = "Tile 2";

std::string TextureHandler::PATH_SOFT1 = "images/Soft v1/";
std::string TextureHandler::PATH_SOFT2 = "images/Soft v2/";
std::string TextureHandler::START_PATH = TextureHandler::PATH_SOFT1;


void TextureHandler::setSoftV1(){
    TextureHandler::START_PATH = TextureHandler::PATH_SOFT1;
}

void TextureHandler::setSoftV2(){
    TextureHandler::START_PATH = TextureHandler::PATH_SOFT2;
}

std::string* TextureHandler::getTextureNamePiece(bool color,bool dimension,bool spec,bool shape){
    std::string strColor;
    std::string strDimension;
    std::string strSpec;
    std::string strShape;

    color ? strColor = TextureHandler::RED : strColor = TextureHandler::BLUE;
    dimension ? strDimension = TextureHandler::BIG : strDimension = TextureHandler::SMALL;
    spec ? strSpec = TextureHandler::FLAT : strSpec = TextureHandler::HOLES;
    shape ? strShape = TextureHandler::CIRCLE : strShape = TextureHandler::SQUARE;

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

sf::Texture* TextureHandler::getTexturePiece(bool color,bool dimension,bool spec,bool shape){
    sf::Texture texture;
    std::string *textureName = TextureHandler::getTextureNamePiece(color,dimension,spec,shape);
    if (!texture.loadFromFile(*textureName)){
        //errors
    }
    return new sf::Texture(texture);
}

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

