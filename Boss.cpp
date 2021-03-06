#include <iostream>
#include "Boss.h"
#include "Employee.h"
using namespace std;
int Boss::getNumberOfEmployees() const {
    return numberOfEmployees;
}
void Boss::setNumberOfEmployees(int numberOfEmployees) {
    Boss::numberOfEmployees = numberOfEmployees;
}

Boss::Boss(int noe, int hw, int sph, int wtd, int wd, string name, string id, Address address) : Employee(hw, sph, wtd,
                                                                                                          wd, name, id,
                                                                                                          address),
                                                                                                 numberOfEmployees(
                                                                                                         noe) {}

Boss::Boss() : Employee() {}

Boss::Boss(const Boss &b) : Employee(b) {
    numberOfEmployees = b.numberOfEmployees;
}

ostream &operator<<(ostream &os, const Boss &boss) {
    os << static_cast<const Employee &>(boss) << " number Of Employees is:\t" << boss.numberOfEmployees;
    return os;
}
istream &operator>>(istream &in, Boss &b) {
    cout << "Number of employee is : \n";
    in >> b.numberOfEmployees >> static_cast< Employee &>(b);
    return in;
}

Boss &Boss::operator=(const Boss &boss) {
    numberOfEmployees = boss.numberOfEmployees;
    Employee::operator=(boss);
    return *this;
}

double Boss::calculateSalary() const {
    return Employee::calculateSalary() * (1.15);
}
