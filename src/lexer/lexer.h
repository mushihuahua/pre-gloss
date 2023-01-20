#pragma once

#include "token.h"

class Lexer{
    // private:
        std::string _text;
        int _position = 0;

        char current();
        void next();
    
    public:
        Lexer(std::string x);
        Lexer();

        SyntaxToken nextToken();
};