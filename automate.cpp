#include <iostream>

#include "automate.h"

Automate::~Automate()
{
    
}

Automate::Automate(string name) : lexer(name)
{

}

// (1+34)*123
void Automate::lecture()
{
    etats.push_back(new Etat0);
    Symbole * s;
    while(*(s=lexer.Consulter())!=FIN) 
    {
      Etat* topEtat = etats.back();
      if (!topEtat->transition(*this, s))
      {
          cout << "Erreur dans l'automate à l'état : ";
          topEtat->print();
          cout << " avec le symbole : ";
          s->Affiche();
          
          return;
      }
   }

    bool accepter = false;
    Symbole* fin = new Symbole(FIN);

    while (!accepter)
    {
        if (symboles.size() == 1 && *symboles.back() == E)
        {
            accepter = true;
        }
        else
        {
            Etat* topEtat = etats.back();
            topEtat->transition(*this, fin);
        }
        
    }

    cout << "Fin de l'automate, succès !" << endl;
}

void Automate::decalage(Symbole * s, Etat * etat)
{
    symboles.push_back(s);
    etats.push_back(etat);
    if (s->isTerminal())
    {
        lexer.Avancer ();
    }

    cout << "Décalage : ";
    printEtats();
    cout << endl;
    printSymboles();
    cout << endl << endl;
}

void Automate::reduction(int n, Symbole * s)
{
    for (int i (0); i < n; ++i)
    {
        delete (etats.back());
        etats.pop_back();
        delete (symboles.back());
        symboles.pop_back();
    }

    cout << "Réduction : ";
    printEtats();
    cout << endl;
    printSymboles();
    cout << endl << endl;

    Symbole * newS = new Symbole(E);
    etats.back()->transition(*this, newS);
}

void Automate::printEtats()
{
    cout << "Pile des états : " << endl;
    for(auto iter = etats.begin(); iter != etats.end(); ++iter) 
    {
        Etat* e = *iter;
        e->print();
    }

    cout << endl;
}

void Automate::printSymboles()
{
    cout << "Pile des symboles : " << endl;
    for(auto iter = symboles.begin(); iter != symboles.end(); ++iter) 
    {
        Symbole* s = *iter;
        s->Affiche();
    }

    cout << endl;
}

void Automate::accepter()
{
    cout << "Fin de l'automate" << endl;
}


// ------ Etats

Etat::~Etat()
{
    
}

Etat::Etat()
{

}

Etat::Etat(string _name)
    : name (_name)
{
    
}

void Etat::print() const
{
    cout << name << endl;
}

/** Etat 0 **/
Etat0::Etat0()
    : Etat ("Etat0")
{

}

bool Etat0::transition(Automate & automate, Symbole * s)
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
        default:
            return false;
    }

    return true;
}

/** Etat 1 **/
Etat1::Etat1()
    : Etat ("Etat1")
{

}

bool Etat1::transition(Automate & automate, Symbole * s)
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
        default:
            return false;
    }

    return true;
}

/** Etat 2 **/
Etat2::Etat2()
    : Etat ("Etat2")
{

}

bool Etat2::transition(Automate & automate, Symbole * s)
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
        default:
            return false;
    }

    return true;
}

/** Etat 3 **/
Etat3::Etat3()
    : Etat ("Etat3")
{

}

bool Etat3::transition(Automate & automate, Symbole * s)
{
    switch (*s)
    {
        case PLUS:
        case MULT:
        case CLOSEPAR:
        case FIN:
            automate.reduction(1, s);
            break;
        default: 
            return false;
    }

    return true;
}

/** Etat 4 **/
Etat4::Etat4()
    : Etat ("Etat4")
{

}

bool Etat4::transition(Automate & automate, Symbole * s)
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
        default:
            return false;
    }

    return true;
}

/** Etat 5 **/
Etat5::Etat5()
    : Etat ("Etat5")
{

}

bool Etat5::transition(Automate & automate, Symbole * s)
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
        default:
            return false;
    }

    return true;
}

/** Etat 6 **/
Etat6::Etat6()
    : Etat ("Etat6")
{

}

bool Etat6::transition(Automate & automate, Symbole * s)
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
        default:
            return false;
    }

    return true;
}

/** Etat 7 **/
Etat7::Etat7()
    : Etat ("Etat7")
{

}

bool Etat7::transition(Automate & automate, Symbole * s)
{
    switch (*s)
    {
        case PLUS:
        case CLOSEPAR:
        case FIN:
            automate.reduction(3, s);
            break;
        case MULT:
            automate.decalage(s, new Etat5);
            break;
        default:
            return false;
    }

    return true;
}

/** Etat 8 **/
Etat8::Etat8()
    : Etat ("Etat8")
{

}

bool Etat8::transition(Automate & automate, Symbole * s)
{
    switch (*s)
    {
        case PLUS:
        case MULT:
        case CLOSEPAR:
        case FIN:
            automate.reduction(3, s);
            break;
        default:
            return false;
    }

    return true;
}

/** Etat 9 **/
Etat9::Etat9()
    : Etat ("Etat9")
{

}

bool Etat9::transition(Automate & automate, Symbole * s)
{
    switch (*s)
    {
        case PLUS:
        case MULT:
        case CLOSEPAR:
        case FIN:
            automate.reduction(3, s);
            break;
        default:
            return false;
    }

    return true;
}