#include <iostream>
#include "automate.h"

using namespace std;

int main(void) {
   string chaine;
   cout << "Tapez une chaîne à analysée : ";
   cin >> chaine;

   Automate automate (chaine);
   automate.lecture();

   return 0;
}

