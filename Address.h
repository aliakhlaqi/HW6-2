#include <iostream>
using namespace std;
#ifndef HW6_2_ADDRESS_H
#define HW6_2_ADDRESS_H
class Address {
private:
    string country;
    string city;
    string street;
public:
    Address();

    const string &getCountry() const;

    void setCountry(const string &country);

    const string &getCity() const;

    void setCity(const string &city);

    const string &getStreet() const;

    void setStreet(const string &street);

    Address(string, string, string);

    friend ostream &operator<<(ostream &, const Address &);

    friend istream &operator>>(istream &, Address &);

};


#endif //HW6_2_ADDRESS_H
