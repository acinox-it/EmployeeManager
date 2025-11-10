#ifndef EMPLOYE_H
#define EMPLOYE_H

#include "Person.h"

class Employe: public Person
{
    public:
        Employe();
        virtual ~Employe();

        //Getters - Setters
        std::string getPosition() const { return position; }
        void setPosition(const std::string& p) { position = p; }

        double getSalary() const { return salary; }
        void setSalary(double s) { salary = s; }

        int getJoinedYear() const { return joinedYear; }
        void setJoinedYear(int y) { joinedYear = y; }

        double calculateBonus() const;
        int calculateSeniority(int currentYear) const;

        //Polymorph Person::display()
        void display() const override;

    protected:
        std::string position;
        double salary;
        int joinedYear;

    private:
};

#endif // EMPLOYE_H
