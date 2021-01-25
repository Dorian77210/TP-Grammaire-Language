#pragma once

#include <string>
#include <iostream>

#include "symbole.h"

using namespace std;

class Expr : public Symbole
{
    public:
        Expr();
        Expr(const Expr & _expr);
        ~Expr();

        virtual double eval() = 0;
};

class ExprBin : public Expr
{
    public:
        ExprBin(Expr *_first, Expr *_second);
        ExprBin(const ExprBin & _expr);
        ~ExprBin();
        virtual double eval() = 0;

    protected:
        Expr *first;
        Expr *second;
};

class Nombre : public Expr
{
    public:
        Nombre(double _value);
        Nombre(const Nombre & _nombre);
        ~Nombre();
        double eval();
    protected:
        double value;
};

class ExprPlus : public ExprBin
{
    public:
        ExprPlus(Expr *_first, Expr *_second);
        ExprPlus(const ExprPlus & _expr);
        ~ExprPlus();
        double eval();
};

class ExprMult : public ExprBin
{
    public:
        ExprMult(Expr *_first, Expr *_second);
        ExprMult(const ExprMult & _expr);
        ~ExprMult();
        double eval();
};