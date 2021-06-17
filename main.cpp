#include <iostream>
#include "Address.h"
#include "Company.h"
#include "Boss.h"
#include "Person.h"
#include "Employee.h"
using namespace std;
int main() {

    Boss *boss = new Boss( 10, 20000, 25, 30,15,"Ali Akhalqi", "87*x83880", *(new Address("Iran", "Tehran", "Elahiye")));

   Employee **employee = new Employee *[boss->getNumberOfEmployees()];
    employee[0] = new Employee(7, 8700, 19,17,"behnam bani", "87*ox19280", *(new Address("Iran", "qom", "navvab")) );
    employee[1] = new Employee( 4, 11000, 22,9,"Hossein khalse", "98*a01203", *(new Address("Iran", "karaj", "gohardasht")));
    employee[2] = new Employee( 9, 7100, 35,18,"nima yektayi", "98*aq93727", *(new Address("Iran", "esfahan", "lale")));
    employee[3] = new Employee( 9, 5200, 10,7,"reyhane salmani", "92*a12320", *(new Address("Iran", "tehran", "ferdosi")));
    employee[4] = new Employee( 14, 5700, 10,9,"nazanin ahmadi", "93*r97320", *(new Address("Iran", "shiraz", "jomhori")));
    employee[5] = new Employee( 6, 12500, 16,14,"kimia azdi", "95*x97220", *(new Address("Iran", "mashhad", "eram")));
    employee[6] = new Employee(13, 3250, 12,3,"mohaddese aghayi", "93*cx32321", *(new Address("Iran", "mazandaran", "jomhori")));
    employee[7] = new Employee( 5, 6500, 14,12,"zahra shiri", "94*w13228", *(new Address("Iran", "mashahd", "emam_reza")));
    employee[8] = new Employee(5, 15200,28, 20,"Mohammad abdi", "91*a89232", *(new Address("Iran", "qom", "tohid")));
    employee[9] = new Employee( 11, 3000, 25,22,"fatemeh maleki", "85*qq73328", *(new Address("Iran", "esfahan", "jolfa")));
    Company company(1000000, boss, employee);
    cout << "The company before the change of chairman:" << endl << endl;
    cout << company << endl;
    cout << "ـــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــ" << endl;

    cout << "Is the asset sufficient to pay?" << endl;
    if (company.isEnoughBudget())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    company.ChangeBoss();
    cout << "ـــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــ" << endl;
    cout << "he company after the change of chairman:" << endl << endl;
    cout << company << endl;
    cout << "ـــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــــ" << endl;
    cout << "maximum of efficiency rate:" << endl;
    cout << *company.maxEfficiency();
    cout << "Details saved successfully..."<<endl;
    company.writeOnFile();

    return 0;
}
