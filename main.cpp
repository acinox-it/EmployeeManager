#include <iostream>
#include "Person.h"
#include "Employe.h"


using namespace std;

int main()
{
    //Person louiBase("loui","sahraoui",21); without keyword const
    //louiBase->display();
    //Employe* louiEmployee = new Employe(louiBase, "Manager", 2550.0, 2023);
    //louiEmployee->display();


    Person* rahaf = new Person("rahaf","sahraoui",8);
    rahaf->display();

    Employe* loui = new Employe(Person("loui","sahraoui",21), "Manager", 2550.0, 2023);
    loui->display();



    delete rahaf;
    delete loui;


    return 0;
}
