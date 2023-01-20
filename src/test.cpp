#include "lexer/lexer.h"
#include "lexer/token.h"
#include "parser/parser.h"
#include "parser/AST.h"


int main()
{
    // std::vector<SyntaxNode*> children;
    SyntaxToken a = SyntaxToken(TokenType::PlusToken, "+", 0);
    SyntaxToken b = SyntaxToken(TokenType::MultiplyToken, "*", 0);
    SyntaxToken c = SyntaxToken(TokenType::DivideToken, "/", 0);
    NumberNode* right = new NumberNode(6);
    NumberNode* right2 = new NumberNode(7);
    NumberNode* left3 = new NumberNode(8);
    BinaryExpressionNode* left2 = new BinaryExpressionNode(left3, c, right2);
    BinaryExpressionNode* left = new BinaryExpressionNode(left2, b, right2);
    BinaryExpressionNode* root = new BinaryExpressionNode(left, a, right);
    root->printChildren("");

    // for(int i = 0;i < children.size();i++){
    //     std::cout << indent << enumString((children)[i]->getKind()) << std::endl;
    //     indent += "    ";
    // }

}