#include "automate.h"

Automate::~Automate()
{
    
}

Automate::Automate()
{
    
}

void Automate::lecture()
{
    Symbole * s;
    while(*(s=lexer.Consulter())!=FIN) 
    {
      s->Affiche();
      cout<<endl;
      lexer.Avancer();
   }
}

void Automate::decalage(Symbole * s, Etat * etat)
{

}

void Automate::reduction(int n, Symbole * s)
{

}

void Automate::accepter()
{

}


// ------ Etats

/** Etat 0 **/
Etat0::transition(Automate & automate, Symbole * s)
{
    switch (*s)
    {
        case INT:
            automate.decalage(s, new Etat3);
            break;
        case OPENPAR:
            automate.decalage(s, new Etat2);
            break;
        case E:
            automate.decalage(s, new Etat1);
            break;
    }
}

Etat0::print() const
{
    cout << "Passage par l'état 0" << endl;
}

/** Etat 1 **/
Etat1::transition(Automate & automate, Symbole * s)
{
    switch (*s)
    {
        case PLUS:
            automate.decalage(s, new Etat4);
            break;
        case MULT:
            automate.decalage(s, new Etat5);
            break;
        case FIN:
            automate.accepter();
    }
}

Etat1::print() const
{
    cout << "Passage par l'état 1" << endl;
}

/** Etat 2 **/
Etat2::transition(Automate & automate, Symbole * s)
{
    switch (*s)
    {
        case INT:
            automate.decalage(s, new Etat3);
            break;
        case OPENPAR:
            automate.decalage(s, new Etat2);
            break;
        case E:
            automate.decalage(s, new Etat6);
    }
}

Etat2::print() const
{
    cout << "Passage par l'état 2" << endl;
}

/** Etat 3 **/
Etat3::transition(Automate & automate, Symbole * s)
{
    switch (*s)
    {
        case PLUS:
        case MULT:
        case CLOSEPAR:
        case END:
            automate.reduction(5, s);
            break;
    }
}

Etat3::print() const
{
    cout << "Passage par l'état 3" << endl;
}

/** Etat 4 **/
Etat4::transition(Automate & automate, Symbole * s)
{
    switch (*s)
    {
        case INT:
            automate.decalage(s, new Etat3);
            break;
        case OPENPAR:
            automate.decalage(s, new Etat2);
            break;
        case E:
            automate.decalage(s, new Etat7);
            break;
    }
}

Etat4::print() const
{
    cout << "Passage par l'état 4" << endl;
}

/** Etat 5 **/
Etat5::transition(Automate & automate, Symbole * s)
{
    switch (*s)
    {
        case INT:
            automate.decalage(s, new Etat3);
            break;
        case OPENPAR:
            automate.decalage(s, new Etat2);
            break;
        case E:
            automate.decalage(s, new Etat8);
            break;
    }
}

Etat5::print() const
{
    cout << "Passage par l'état 5" << endl;
}

/** Etat 6 **/
Etat6::transition(Automate & automate, Symbole * s)
{
    switch (*s)
    {
        case PLUS:
            automate.decalage(s, new Etat4);
            break;
        case MULT:
            automate.decalage(s, new Etat5);
            break;
        case CLOSEPAR:
            automate.decalage(s, new Etat9);
            break;
    }
}

Etat6::print() const
{
    cout << "Passage par l'état 6" << endl;
}

/** Etat 7 **/
Etat7::transition(Automate & automate, Symbole * s)
{
    switch (*s)
    {
        case PLUS:
        case CLOSEPAR:
        case END:
            automate.reduction(2, s);
            break;
        case MULT:
            automate.decalage(s, new Etat5);
            break;
    }
}

Etat7::print() const
{
    cout << "Passage par l'état 7" << endl;
}

/** Etat 8 **/
Etat8::transition(Automate & automate, Symbole * s)
{
    switch (*s)
    {
        case PLUS:
        case MULT:
        case CLOSEPAR:
        case END:
            automate.reduction(3, s);
            break;
    }
}

Etat8::print() const
{
    cout << "Passage par l'état 8" << endl;
}

/** Etat 9 **/
Etat9::transition(Automate & automate, Symbole * s)
{
    switch (*s)
    {
        case PLUS:
        case MULT:
        case CLOSEPAR:
        case END:
            automate.reduction(4, s);
            break;
    }
}

Etat9::print() const
{
    cout << "Passage par l'état 9" << endl;
}