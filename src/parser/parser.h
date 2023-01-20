#pragma once

#include<iostream>
#include<string>
#include<vector>
#include "../lexer/lexer.h"

class Parser{
    
    Lexer* lexer;
    SyntaxToken current_token;
    std::vector<SyntaxToken> _tokens = {};
    int _position = 0;
    
public:
    Parser(Lexer* _lexer);
    void consumeToken(TokenType type);
    SyntaxToken peek(int offset);
    int factor();
    int term();
    int expr();
    // SyntaxToken current = Peek(0);
};