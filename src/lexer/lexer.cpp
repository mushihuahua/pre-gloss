#include "lexer.h"

char Lexer::current(){
    if(_position >= _text.length()){
        return '\0';
    }
    return _text[_position];
}

void Lexer::next(){
    _position++;
}

Lexer::Lexer(std::string x){
    _text = x;
}

Lexer::Lexer(){}

SyntaxToken Lexer::nextToken(){
    if(_position >= _text.length()){
        return SyntaxToken(TokenType::EOFToken, "NULL", _position);
    }

    if(isdigit(current())){
        int start = _position;

        while(isdigit(current())){
            next();
        }
        int length = _position - start;
        // digit SyntaxToken
        std::string dt = _text.substr(start, length);
        return SyntaxToken(TokenType::NumberToken, dt, start);
    }
    if(isblank(current())){
        int start = _position;

        while(isblank(current())){
                next();
            }
        int length = _position - start;
        // space SyntaxToken
        std::string st = _text.substr(start, length);
        return SyntaxToken(TokenType::WhitespaceToken, st, start);                   
    }
    switch (current())
    {
    case '+':
        next();
        return SyntaxToken(TokenType::PlusToken, "+", _position-1);
    case '-':
        next();
        return SyntaxToken(TokenType::MinusToken, "-", _position-1);
    case '*':
        next();
        return SyntaxToken(TokenType::MultiplyToken, "*", _position-1);
    case '/':
        next();
        return SyntaxToken(TokenType::DivideToken, "/", _position-1);
    case '(':
        next();
        return SyntaxToken(TokenType::LPARENToken, "(", _position-1);
    case ')':
        next();
        return SyntaxToken(TokenType::RPARENToken, ")", _position-1);
    }

    next();
    return SyntaxToken(TokenType::UnknownToken, "NULL", _position);
}


