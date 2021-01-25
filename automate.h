#pragma once

#include <string>
#include <deque>

#include "symbole.h"
#include "lexer.h"

using namespace std;

class Etat;

class Automate {
   public:
        Automate(string chaine);
        ~Automate();

        void lecture();
        void decalage(Symbole * s, Etat * e);
        void reduction(int n, Symbole * s);
        void accepter();

    protected:
        Lexer lexer;
        deque<Symbole*> symboles;
        deque<Etat*> etats;

        void printEtats();
        void printSymboles();
};

class Etat
{
   public:
        Etat();
        Etat(string name);
        virtual ~Etat();
        void print() const;
        virtual bool transition(Automate & automate, Symbole * s) = 0;

    protected:
        string name;
};

class Etat0 : public Etat
{
    public:
        Etat0();
        ~Etat0() {};
        bool transition(Automate & automate, Symbole * s);
};

class Etat1 : public Etat
{
    public:
        Etat1();
        ~Etat1() {};
        bool transition(Automate & automate, Symbole * s);
};


class Etat2 : public Etat
{
    public:
        Etat2();
        ~Etat2() {};
        bool transition(Automate & automate, Symbole * s);
};


class Etat3 : public Etat
{
    public:
        Etat3();
        ~Etat3() {};
        bool transition(Automate & automate, Symbole * s);
};


class Etat4 : public Etat
{
    public:
        Etat4();
        ~Etat4() {};
        bool transition(Automate & automate, Symbole * s);
};

class Etat5 : public Etat
{
    public:
        Etat5();
        ~Etat5() {};
        bool transition(Automate & automate, Symbole * s);
};

class Etat6 : public Etat
{
    public:
        Etat6();
        ~Etat6() {};
        bool transition(Automate & automate, Symbole * s);
};

class Etat7 : public Etat
{
    public:
        Etat7();
        ~Etat7() {};
        bool transition(Automate & automate, Symbole * s);
};

class Etat8 : public Etat
{
    public:
        Etat8();
        ~Etat8() {};
        bool transition(Automate & automate, Symbole * s);
};

class Etat9 : public Etat
{
    public:
        Etat9();
        ~Etat9() {};
        bool transition(Automate & automate, Symbole * s);
};