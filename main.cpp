#include <stdio.h>
#include <iostream>
extern int yyparse();
using namespace std;

int yyerrornum = 0;

int main(int argc, char **argv)
{
  cout << "ha comenzado..." << endl << endl ;
   if (yyparse() == 0 && yyerrornum == 0) { 
    cout << "ha finalizado BIEN..." << endl << endl ;
  }
  else {
    cout << "ha finalizado MAL..." << endl << endl ;
  }
  return 0;
}
