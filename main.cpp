#include "graph.h"
using namespace std;

//Zach Li
//Test program for table ADT. The test program is managed by menu class. 
//The table class manages the ADT. The manager function calls functions in menu
//class to interact with user.

void manager(table & newT, menu & newM)
{
   newM.intro();
   newM.establish(newT);
   do{
      newM.display();
      newM.choose();
      newM.process(newT);
   }while(newM.cont());
}

int main(){
   menu new_menu;
   int size;
   
   cout<<"Please enter the graph size: \n";
   cin>>size;
   cin.ignore(100,'\n');
   table new_table(size);
   
   manager(new_table, new_menu);
 
   return 0;
}
