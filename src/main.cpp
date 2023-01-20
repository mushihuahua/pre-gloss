#include "lexer/lexer.h"
#include "lexer/token.h"
#include "parser/parser.h"

int main()
{
    while(true){
        std::string input;
        
        std::cout << "> " ;
        getline(std::cin, input);

        if(input.empty() || input == "exit"){
            std::cout << "";
            return 0;
        }

        Lexer lexer(input);
        Parser parser(&lexer);

    try{
        int num = parser.expr();
        std::cout << num << std::endl;
    }catch(int ex){
        std::cout << "[ERROR]: Syntax Error" << std::endl;
        break;
    }
        Lexer lexer2(input);

        while(true){
            SyntaxToken token = lexer2.nextToken();

            if(token.getType() == TokenType::EOFToken){
                break;
            }

            token.display();
        }
    }
}