#include <iostream>
#include "automate.h"

using namespace std;

int main(void) {
   string chaine("1+2*3");

   Automate automate (chaine);
   automate.lecture();

   return 0;
}

