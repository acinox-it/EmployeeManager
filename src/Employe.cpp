#include "Employe.h"

Employe::Employe(const Person &person, string position, double salary, unsigned short joinedDate):
    Person(person), position(position), salary(salary), joinedDate(joinedDate) {}

Employe::~Employe()
{
    //dtor
}

double Employe::calculateBonus()
{
    double base = salary * 0.1; // Employee Position
    double anciennete = salary * (2025-joinedDate) * 0.05;
    return base + anciennete;
}

void Employe::display()
{
    Person::display();
    cout<<"Position: "<<position<<endl;
    cout<<"Salary: "<<salary<<endl;
}
