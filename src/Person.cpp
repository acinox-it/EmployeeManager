#include "Person.h"
#include <iostream>

using namespace std;

Person::Person() : id(0) {}

Person::~Person() {}

void Person::display() const
{
    cout<<"----------------------------"<<endl;
    cout<<"Id: "<<id<<endl;
    cout<<"Prenom: "<<firstName<<endl;
    cout<<"Nom: "<<lastName<<endl;
    cout<<"Date de naissance: "<<birthDate<<endl;
    cout<<endl;
}
