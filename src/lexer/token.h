#pragma once

#include<iostream>
#include<string>

enum TokenType{
    NumberToken,
    WhitespaceToken,
    PlusToken,
    MinusToken,
    MultiplyToken,
    DivideToken,
    LPARENToken,
    RPARENToken,
    EOFToken,
    UnknownToken,
    BinaryExpression,
    NumberExpression
};

class SyntaxToken{
    // private:
        int _type, _position;
        std::string _value;

    public:
        SyntaxToken(int type, std::string value, int position);
        SyntaxToken();
        void display();
        int getType();
        std::string getValue();
};