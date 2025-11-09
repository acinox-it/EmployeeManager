#include <iostream>
#include "Person.h"


using namespace std;

int main()
{
    Person* loui = new Person("loui","sahraoui",21);
    loui->display();

    Person* rahaf = new Person("rahaf","sahraoui",8);
    rahaf->display();

    delete loui;
    delete rahaf;


    return 0;
}
