#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person
{
    public:
        Person();
        virtual ~Person();

        //Getters - Setters
        int getId() const { return id; }
        void setId(int i) { id = i; }

        std::string getFirstName() const { return firstName; }
        void setFirstName(const std::string& fn) { firstName = fn; }

        std::string getLastName() const { return lastName; }
        void setLastName(const std::string& ln) { lastName = ln; }

        std::string getBirthDate() const { return birthDate; }
        void setBirthDate(const std::string& bd) { birthDate = bd; }

        //Display parent
        virtual void display() const;
        std::string fullName() const { return firstName + " " + lastName; }

    protected:
        int id;
        std::string firstName;
        std::string lastName;
        std::string birthDate;

    private:
};

#endif // PERSON_H
