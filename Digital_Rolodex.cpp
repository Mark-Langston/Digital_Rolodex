#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>

// Base class for Person
class Person {
protected:
    std::string name;
    std::string phoneNumber;
    std::string emailAddress;
public:
    Person(const std::string& name, const std::string& phoneNumber, const std::string& emailAddress)
        : name(name), phoneNumber(phoneNumber), emailAddress(emailAddress) {}

    virtual std::string toString() const {
        return "Person named " + name + " has phone number " + phoneNumber + " and can be reached at " + emailAddress;
    }

    virtual ~Person() = default;
};

// Student subclass of person
class Student : public Person {
private:
    std::string year;
public:
    Student(const std::string& name, const std::string& phoneNumber, const std::string& emailAddress, const std::string& year)
        : Person(name, phoneNumber, emailAddress), year(year) {}

    std::string toString() const override {
        return Person::toString() + " is in the " + year + " year";
    }
};

// Employee subclass of person
class Employee : public Person {
private:
    double salary;
public:
    Employee(const std::string& name, const std::string& phoneNumber, const std::string& emailAddress, double salary)
        : Person(name, phoneNumber, emailAddress), salary(salary) {}

    std::string toString() const override {
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(2);
        oss << salary;
        return Person::toString() + " earns " + oss.str() + " annually";
    }
};

// Faculty subclass of employee
class Faculty : public Employee {
private:
    std::string title;
public:
    Faculty(const std::string& name, const std::string& phoneNumber, const std::string& emailAddress, double salary, const std::string& title)
        : Employee(name, phoneNumber, emailAddress, salary), title(title) {}

    std::string toString() const override {
        return Employee::toString() + " is a/an " + title;
    }
};

// Staff subclass of employee
class Staff : public Employee {
private:
    std::string role;
public:
    Staff(const std::string& name, const std::string& phoneNumber, const std::string& emailAddress, double salary, const std::string& role)
        : Employee(name, phoneNumber, emailAddress, salary), role(role) {}

    std::string toString() const override {
        return Employee::toString() + " handles " + role;
    }
};

int main() {
    // Program intro
    std::cout << "Digital Rolodex\n" << "\n";

    // Vector for people
    std::vector<Person*> people;

    // Creates instances of people
    people.push_back(new Person("Susan", "800-555-1212", "susan@quirkymail.com"));
    people.push_back(new Student("Jerry", "123-456-7890", "jerjer@nat.edu", "sophomore"));
    people.push_back(new Employee("Larry", "333-444-5555", "larry@threestooges.org", 123456.00));
    people.push_back(new Faculty("Linda", "987-654-3210", "lindalou@whoknew.edu", 150000.00, "adjunct professor"));
    people.push_back(new Staff("Jane", "567-123-6565", "jane@whizkid.com", 100000.00, "registration"));

    for (const auto& person : people) {
        std::cout << person->toString() << std::endl;
    }

    for (auto& person : people) {
        delete person;
    }

    return 0;
}