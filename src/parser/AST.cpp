#include "AST.h"

std::string enumString(int e){
    switch (e)
    {
    case 0:
        return "NumberToken";
    case 1:
        return "WhitespaceToken";
    case 2:
        return "PlusToken";
    case 3:
        return "MinusToken";
    case 4:
        return "MultiplyToken";
    case 5:
        return "DivideToken";
    case 6:
        return "LPARENToken";
    case 7:
        return "RPARENToken";
    case 8:
        return "EOFToken";
    case 9:
        return "UnknownToken";
    case 10:
        return "BinaryExpression";
    case 11:
        return "NumberExpression";    
    default:
        return "non existent";
    }
}

SyntaxNode::SyntaxNode(){}

SyntaxNode::SyntaxNode(TokenType Kind){
    kind = Kind;
}

int SyntaxNode::getKind(){ return kind; }
void SyntaxNode::setKind(int Kind){ kind = Kind; }

BinaryExpressionNode::BinaryExpressionNode(){}

BinaryExpressionNode::BinaryExpressionNode(ExpressionNode* Left, SyntaxToken BinaryOP, ExpressionNode* Right){
    left = Left;
    binaryOP = BinaryOP;
    setKind(BinaryExpression);
    right = Right;
}

ExpressionNode* BinaryExpressionNode::getLeft(){ return left; }

void BinaryExpressionNode::getChildren(std::vector<SyntaxNode*> &nodes){
    nodes.push_back(left);
    nodes.push_back(right);
    left->getChildren(nodes);
}

void BinaryExpressionNode::printChildren(std::string indent){
    std::cout << indent << enumString(getKind()) << std::endl;

    indent += "    ";

    left->printChildren(indent);
    std::cout << indent << enumString(binaryOP.getType()) << std::endl;
    right->printChildren(indent);
}

int BinaryExpressionNode::getVal(){
    return 0;
}

NumberNode::NumberNode(){}

NumberNode::NumberNode(int Value){
    value = Value;
    setKind(NumberExpression);
}

int NumberNode::getVal(){ return value; }

void NumberNode::getChildren(std::vector<SyntaxNode*> &nodes){
    nodes.push_back(new NumberNode(value));
}

void NumberNode::printChildren(std::string indent){
    std::cout << indent << enumString(getKind()) << std::endl;

    indent += "    ";    

    std::cout << indent << enumString(NumberToken) << " " << getVal() << std::endl;
}