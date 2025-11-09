#include "Person.h"

Person::Person(string firstName, string lastName, unsigned short age):
    firstName(firstName), lastName(lastName), age(age){}

Person::~Person()
{
    //dtor
}

void Person::display()
{
    cout<<"----------------------------"<<endl;
    cout<<"Id: "<<id<<endl;
    cout<<"First Name: "<<firstName<<endl;
    cout<<"Last Name: "<<lastName<<endl;
    cout<<"Age: "<<age<<endl;

}
