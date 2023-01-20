#include "parser.h"

Parser::Parser(Lexer* _lexer){
    lexer = _lexer;

    do {
        current_token = lexer->nextToken();

        if(current_token.getType() != TokenType::WhitespaceToken && current_token.getType() != TokenType::UnknownToken){
            _tokens.push_back(current_token);
        }

    } while(current_token.getType() != TokenType::EOFToken);

    current_token = _tokens[0];
}

SyntaxToken Parser::peek(int offset){
    int index = _position + offset;

    if(index >= _tokens.size()-1){
        return _tokens[_tokens.size()-1];
    }
    return _tokens[index];
}

void Parser::consumeToken(TokenType type){
    SyntaxToken token = _tokens[_position];
    if(token.getType() == type){
        // current_token = lexer->nextToken();
        _position++;
       current_token = _tokens[_position];
    }else{
        throw 5;
    }
}

int Parser::factor(){
    SyntaxToken token = current_token;
    if(token.getType() == TokenType::NumberToken){ 
        consumeToken(TokenType::NumberToken);
        return std::stoi(token.getValue()); 
    }
    if(token.getType() == TokenType::LPARENToken){
        consumeToken(TokenType::LPARENToken);
        int result = expr();
        consumeToken(TokenType::RPARENToken);
        return result;
    }
    return 0;
}

int Parser::term(){
    int value = factor();

    while((current_token.getType() == TokenType::MultiplyToken ||
          current_token.getType() == TokenType::DivideToken)){

              if(current_token.getType() == TokenType::MultiplyToken){
                  consumeToken(TokenType::MultiplyToken);
                  value = value * factor();
              }else{
                  consumeToken(TokenType::DivideToken);
                  value = value / factor();
              }
          }
    return value;          
}

int Parser::expr(){
    int result = term();

    while((current_token.getType() == TokenType::PlusToken ||
          current_token.getType() == TokenType::MinusToken)){

              if(current_token.getType() == TokenType::PlusToken){
                  consumeToken(TokenType::PlusToken);
                  result = result + term();
              }else{
                  consumeToken(TokenType::MinusToken);
                  result = result - term();
              }
          }
    return result; 
}





