#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <variant>
#include "../lexer/token.h"
#include <tuple>
#include <typeinfo>


class SyntaxNode 
{
    
    private:
        int kind;
    
    public:
        SyntaxNode();
        SyntaxNode(TokenType Kind);
        int getKind();
        void setKind(int Kind);

};

class ExpressionNode : public SyntaxNode
{
    public:
        virtual int getVal()=0;
        virtual void getChildren(std::vector<SyntaxNode*> &nodes)=0;
        virtual void printChildren(std::string indent)=0;

};

class BinaryExpressionNode : public ExpressionNode
{
    
    private:
        ExpressionNode* left;
        SyntaxToken binaryOP;
        ExpressionNode* right;
        

    public:
        std::vector<ExpressionNode*> children;
        BinaryExpressionNode();
        BinaryExpressionNode(ExpressionNode* Left, SyntaxToken BinaryOP, ExpressionNode* Right);
        ExpressionNode* getLeft();
        void getChildren(std::vector<SyntaxNode*> &nodes) override;
        void printChildren(std::string indent) override;
        int getVal() override;

};

class NumberNode : public ExpressionNode
{
    private:
        int value;
        std::vector<int> number_children;

    public:
        NumberNode();
        NumberNode(int Value);
        int getVal() override;
        void getChildren(std::vector<SyntaxNode*> &nodes) override;
        void printChildren(std::string indent) override;

};
