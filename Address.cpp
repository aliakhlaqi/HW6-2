#include "Address.h"
Address::Address() {
    country="";
    city="";
    street="";

}


const string &Address::getCountry() const {
    return country;
}

void Address::setCountry(const string &country) {
    Address::country = country;
}

const string &Address::getCity() const {
    return city;
}

void Address::setCity(const string &city) {
    Address::city = city;
}

const string &Address::getStreet() const {
    return street;
}

void Address::setStreet(const string &street) {
    Address::street = street;
}

Address::Address(string country , string city, string street) {
    setCountry(country);
    setCity(city);
    setStreet(street);
}

ostream &operator<<(ostream & out, const Address & a) {
    out<<"The country:\t"<<a.getCountry()<<endl<<"The City:\t"<<a.getCity()<<endl<<"The street:\t"<<a.getStreet()<<endl;
    return out;
}

istream &operator>>(istream & in, Address & a) {
    cout<<"country--city--street:\n";
    in>>a.country>>a.city>>a.street;
    return in;
}