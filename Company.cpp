
#include "Company.h"

Company::Company(int budget, Boss *boss, Employee **array) {
    this->budget = budget;
    this->boss = new Boss(*boss);
    employeeArray = new Employee *[boss->getNumberOfEmployees()];
    for (int i = 0; i < boss->getNumberOfEmployees(); ++i) {
        employeeArray[i] = new Employee(*array[i]);
    }

}

Company::Company(const Company &c) {
    budget = c.budget;
    boss = new Boss(*c.boss);
    employeeArray = new Employee *[boss->getNumberOfEmployees()];
    for (int i = 0; i < boss->getNumberOfEmployees(); ++i) {
        employeeArray[i] = new Employee(*(c.employeeArray[i]));
    }

}

Company::~Company() {
    for (int i = 0; i < boss->getNumberOfEmployees(); ++i)
        delete employeeArray[i];
    delete employeeArray;
}

ostream &operator<<(ostream &os, const Company &company) {
    auto *temp = new Company(company);
    bool flag = true;
    //sort by name
    while (flag) {

        flag = false;
        for (int i = 0; i < temp->boss->getNumberOfEmployees() - 1; ++i) {
            if (temp->employeeArray[i]->getName() > temp->employeeArray[i + 1]->getName()) {
                std::swap(temp->employeeArray[i], temp->employeeArray[i + 1]);
                flag = true;
            }
        }
    }
    //sort by id
    flag = true;
    while (flag) {
        flag = false;
        for (int i = 0; i < temp->boss->getNumberOfEmployees() - 1; ++i) {
            if (temp->employeeArray[i]->getId().substr(0, 2) < temp->employeeArray[i + 1]->getId().substr(0, 2)) {
                std::swap(temp->employeeArray[i], temp->employeeArray[i + 1]);
                flag = true;
            }
        }
    }
    //print sorted temp
    os << *(temp->boss) << endl << "efficiency:\t" <<  temp->boss->efficiency() << endl << "salary by Advantages:\t" << temp->boss->calculateSalary() << endl << endl;
    for (int i = 0; i < temp->boss->getNumberOfEmployees(); ++i) {
        os << *(temp->employeeArray[i]) << endl;
        os << "efficiency:\t" <<  temp->employeeArray[i]->efficiency() << endl << "salary by Advantages:\t" << temp->employeeArray[i]->calculateSalary() << endl << endl;

    }
    return os;
}

int Company::getBudget() const {
    return budget;
}

void Company::setBudget(int budget) {
    Company::budget = budget;
}

Boss *Company::getBoss() const {
    return boss;
}

void Company::setBoss(Boss *boss) {
    Company::boss = boss;
}

Employee **Company::getEmployeeArray() const {
    return employeeArray;
}

void Company::setEmployeeArray(Employee **employeeArray) {
    Company::employeeArray = employeeArray;
}

istream &operator>>(istream &in, Company &c) {
    in >> c.budget;
    in >> *c.boss;
    for (int i = 0; i < c.boss->getNumberOfEmployees(); ++i) {
        in >> *c.employeeArray[i];
    }
    return in;
}

Employee *Company::maxEfficiency() {
    Employee *temp = employeeArray[0];
    for (int i = 1; i < boss->getNumberOfEmployees(); ++i) {
        if (employeeArray[i]->efficiency() > temp->efficiency()) {
            temp = new Employee(*employeeArray[i]);
        }
    }
    return temp;
}

double Company::averageEfficiency() {
    double sum = 0;
    for (int i = 0; i < boss->getNumberOfEmployees(); ++i)
        sum += (employeeArray[i]->efficiency());
    return sum / boss->getNumberOfEmployees();
}

void Company::ChangeBoss() {

    if (boss->efficiency() < 40.0) {
        Employee *max = maxEfficiency();
        for (int i = 0; i < boss->getNumberOfEmployees(); ++i) {
            if (employeeArray[i]->efficiency() == max->efficiency()) {
                int numberOfEmployee = boss->getNumberOfEmployees();
                Employee *temp = boss;
                boss = static_cast<Boss *>(employeeArray[i]);
                employeeArray[i] = temp;
                boss->setNumberOfEmployees(numberOfEmployee);
                break;
            }
        }
    }
}

void Company::gift() {
    for (int i = 0; i < boss->getNumberOfEmployees(); ++i) {
        if (stoi(employeeArray[i]->getId().substr(0, 2)) < 90)
            employeeArray[i]->setHourWork(employeeArray[i]->getHourWork() + 5);
    }
    Employee* em=maxEfficiency();//em= employeeArray max
    em->setHourWork(em->getHourWork()+10);
}

void Company::payForService() {
    for (int i = 0; i <boss->getNumberOfEmployees() ; ++i) {
        if(employeeArray[i]->getAddress().getCity()!="Tehran")
            employeeArray[i]->setHourWork(employeeArray[i]->getHourWork() + 5);
    }
}

bool Company::isEnoughBudget() {
    double sum=0;
    for (int i = 0; i < boss->getNumberOfEmployees(); ++i) {
        sum+=employeeArray[i]->calculateSalary();
    }
    if (sum<=budget)
        return true;
    else
        return false;

}

ofstream Company::writeOnFile() {
    ofstream write("Details file.txt");
    write << boss->getName() << "  " << boss->getId() << "  " << boss->efficiency() << " "
          << boss->calculateSalary() << endl;
    for (int i = 0; i < boss->getNumberOfEmployees(); ++i) {
        write << employeeArray[i]->getName() << " " << employeeArray[i]->getId() << " " << employeeArray[i]->efficiency() << "  "
              << employeeArray[i]->calculateSalary() << endl;
    }
    return write;
}


