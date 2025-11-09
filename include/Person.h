#ifndef PERSON_H
#define PERSON_H
#include <iostream>

using namespace std;

class Person
{
    public:
        Person(string firstName, string lastName, unsigned short age);
        virtual ~Person();
        virtual void display();

    protected:
        unsigned short id = 0;
        string firstName;
        string lastName;
        unsigned short age;

    private:
};

#endif // PERSON_H
