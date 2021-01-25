#pragma once

#include <string>
#include "automate.h";

using namespace std;


class Etat
{
   public:
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
        Etat0() : Etat("Etat0") {};
        ~Etat0() {};
};

class Etat1 : public Etat
{
    public:
        Etat1() : Etat("Etat1") {};
        ~Etat1() {};
}


class Etat2 : public Etat
{
    public:
        Etat2() : Etat("Etat2") {};
        ~Etat2() {};
}


class Etat3 : public Etat
{
    public:
        Etat3() : Etat("Etat3") {};
        ~Etat3() {};
}


class Etat4 : public Etat
{
    public:
        Etat4() : Etat("Etat4") {};
        ~Etat4() {};
}

class Etat5 : public Etat
{
    public:
        Etat5() : Etat("Etat5") {};
        ~Etat5() {};
}

class Etat6 : public Etat
{
    public:
        Etat6() : Etat("Etat6") {};
        ~Etat6() {};
}

class Etat7 : public Etat
{
    public:
        Etat7() : Etat("Etat7") {};
        ~Etat7() {};
}

class Etat8 : public Etat
{
    public:
        Etat8() : Etat("Etat8") {};
        ~Etat8() {};
}

class Etat9 : public Etat
{
    public:
        Etat9() : Etat("Etat9") {};
        ~Etat9() {};
}