# Digital Rolodex

This project is a Digital Rolodex implemented in C++. It allows for the creation and management of various types of contacts, including generic persons, students, employees, faculty, and staff.

## Features

- **Person**: Basic contact with a name, phone number, and email address.
- **Student**: Extends `Person` with an additional year attribute.
- **Employee**: Extends `Person` with an additional salary attribute.
- **Faculty**: Extends `Employee` with an additional title attribute.
- **Staff**: Extends `Employee` with an additional role attribute.

## Usage

To compile and run the program, use the following commands:

```bash
g++ -o DigitalRolodex DigitalRolodex.cpp
./DigitalRolodex
