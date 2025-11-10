#include "Employe.h"
#include <iostream>

using namespace std;

Employe::Employe() : salary(0.0), joinedYear(0) {}

Employe::~Employe() {}

double Employe::calculateBonus() const {
    double base = salary * 0.05;
    double seniority = (salary * 0.01) * (calculateSeniority(2025));
    return base + seniority;
}

int Employe::calculateSeniority(int currentYear) const {
    if (joinedYear == 0) return 0;
    return currentYear - joinedYear;
}

void Employe::display() const
{
    Person::display();
    cout<<"Post: "<<position<<endl;
    cout<<"Salaire: "<<salary<<endl;
    cout<<"Annee d'entree: " << joinedYear<<endl;
    cout<<"Bonus estime: "<<calculateBonus()<<endl;

}
