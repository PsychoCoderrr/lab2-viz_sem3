#pragma once
#include <string>
typedef std::string PersonId;
class Person
{
  private:
    PersonId id;
    std::string firstName;
    std::string middleName;
    std::string lastName;

  public:
    Person()
    {
        id = "";
        firstName = "";
        middleName = "";
        lastName = "";
    }

    Person(PersonId id, std::string firstName, std::string middleName, std::string lastName)
    {
        this->id = id;
        this->firstName = firstName;
        this->middleName = middleName;
        this->lastName = lastName;
    }

    Person(const Person &man)
    {
        this->id = man.id;
        this->firstName = man.firstName;
        this->middleName = man.middleName;
        this->lastName = man.lastName;
    }

    PersonId GetId()
    {
        return this->id;
    }

    std::string GetFirstName()
    {
        return this->firstName;
    }

    std::string GetMiddleName()
    {
        return this->middleName;
    }

    std::string GetLastName()
    {
        return this->lastName;
    }

    friend std::istream &operator>>(std::istream &in, Person &person)
    {
        std::cout << "Enter first name: ";
        in >> person.firstName;
        std::cout << "Enter middle name: ";
        in >> person.middleName;
        std::cout << "Enter last name: ";
        in >> person.lastName;
        std::cout << "Enter id: ";
        in >> person.id;
        return in;
    }

    friend std::ostream &operator<<(std::ostream &out, const Person &man)
    {
        return out << man.firstName << " " << man.middleName << " " << man.lastName << " " << man.id << std::endl;
    }

    bool operator==(Person man)
    {
        if ((id == man.GetId()) && (middleName == man.GetMiddleName()) && (firstName == man.GetFirstName()) &&
            (lastName == man.GetLastName()))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
