#include <iostream>
#ifndef HW6_2_PERSON_H
#define HW6_2_PERSON_H
using namespace std;
#include "Address.h"
class Person {
protected:
    string name;
    string id;
    Address address;
public:
    Person();

    Person(string name, string id, Address address);

    Person(const Person &);

    const string &getName() const;

    void setName(const string &name);

    const string &getId() const;

    void setId(const string &id);

    const Address &getAddress() const;

    void setAddress(const Address &address);

    Person &operator=(const Person &);

    friend ostream &operator<<(ostream &, const Person &);

    friend istream &operator>>(istream &, Person &);

    virtual bool validate();


};


#endif //HW6_2_PERSON_H
