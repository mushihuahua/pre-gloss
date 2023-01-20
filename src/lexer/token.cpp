#include "token.h"

SyntaxToken::SyntaxToken(int type, std::string value, int position){
    this->_type = type;
    this->_value = value;
    this->_position = position;
}

SyntaxToken::SyntaxToken(){}

void SyntaxToken::display(){
    std::cout << "SyntaxToken(" << this->_type << ", '" << this->_value << "', " << this->_position << ")" << std::endl;
}

int SyntaxToken::getType(){
    return this->_type;
}

std::string SyntaxToken::getValue(){
    return this->_value;
}

