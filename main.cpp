#include <iostream>
#include "automate.h"


int main(void) {
   string chaine("(1+34)*123");

   Automate automate (chaine);
   automate.lecture();

   return 0;
}

