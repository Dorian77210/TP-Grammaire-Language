#include "expr.h"

// Expr
Expr::Expr() : Symbole (E) {}
Expr::Expr(const Expr & _expr) : Symbole (_expr.ident) {}
Expr::~Expr() {}


// ExprBin
ExprBin::ExprBin(Expr *_first, Expr *_second): first (_first), second (_second) {}
ExprBin::ExprBin(const ExprBin & _expr) : first (_expr.first), second (_expr.second) {}
ExprBin::~ExprBin() 
{
    delete first;
    delete second;
}

// Nombre
Nombre::Nombre(double _value) : Expr (), value (_value) {}
Nombre::Nombre(const Nombre & nombre) : Expr(), value (nombre.value) {}
Nombre::~Nombre() {}

double Nombre::eval()
{
    return value;
}

// ExprPlus
ExprPlus::ExprPlus(Expr *_first, Expr *_second) : ExprBin (_first, _second) {}
ExprPlus::ExprPlus(const ExprPlus & _expr) : ExprBin(_expr.first, _expr.second) {}
ExprPlus::~ExprPlus() 
{
    delete first;
    delete second;
}
double ExprPlus::eval()
{
    return first->eval() + second->eval(); 
}

// ExprMult
ExprMult::ExprMult(Expr *_first, Expr *_second) : ExprBin (_first, _second) {}
ExprMult::ExprMult(const ExprMult & _expr) : ExprBin (_expr.first, _expr.second) {}
ExprMult::~ExprMult() 
{
    delete first;
    delete second;
}
double ExprMult::eval()
{
    return first->eval() * second->eval();
}