#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <iostream>
#include "Person.h"

using namespace std;

class Employe: public Person
{
    public:
        Employe(const Person &person, string position, double salary, unsigned short joinedDate);
        virtual ~Employe();
        double calculateBonus();
        void display() override;

    protected:

    private:
        string position;
        double salary;
        unsigned short joinedDate;

};

#endif // EMPLOYE_H
