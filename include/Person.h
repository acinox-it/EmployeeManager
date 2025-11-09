#ifndef PERSON_H
#define PERSON_H
#include <iostream>

using namespace std;

class Person
{
    public:
        Person(string firstName, string lastName, unsigned short age);
        virtual ~Person();
        void display();

    protected:

    private:
        unsigned short id = 0;
        string firstName;
        string lastName;
        unsigned short age;
};

#endif // PERSON_H
