#pragma once

#include "etat.h"
#include "symbole.h"
#include "lexer.h"

#include <string>
#include <stack>

using namespace std;


class Automate {
   public:
        Automate();
        ~Automate();

        void lecture();
        void decalage(Symbole * s, Etat * e);
        void reduction(int n, Symbole * s);
        void accepter();

    protected:
        Lexer lexer;
        stack<Symbole> symboles;
        stack<Etat> etats;        
};