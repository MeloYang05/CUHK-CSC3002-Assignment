/*
 * File: employee.h
 * ----------------
 * This file provides a skeletal interface for an Employee class with three
 * subclasses: HourlyEmployee, CommissionedEmployee, and SalariedEmployee.
 * Lines marked with // comments are excluded from the abbreviated listing.
 */

#ifndef _employee_h
#define _employee_h

#include <string>

/*
 * Class: Employee
 * ---------------
 * This class defines the root of the Employee hierarchy.  Employee is
 * an abstract class, which means that there are no objects whose primary
 * type is Employee.  Every object is constructed as one of the subclasses.
 * The getPay method is declared using the virtual keyword, which means
 * that it can be overridden by its subclasses.  The "= 0" notation at the
 * end of the prototype marks getPay as a "pure virtual" method, which
 * is implemented only in the subclasses.
 */

class Employee {

public:

    std::string getName();

    virtual ~Employee();

    virtual double getPay()=0;

protected:

    std::string name;
};

/*
 * Class: HourlyEmployee
 * ----------------------
 * This class defines hourly payed emplyoy, which is a subclass of employee.
 * The get pay method depends on the hoursWorked and hourlyRate, which are
 * defined in the private part of the class.
 */

class HourlyEmployee : public Employee {

public:

    HourlyEmployee();

    HourlyEmployee(std::string new_name);

    virtual double getPay();

    void setHourlyRate(double rate);

    void setHoursWorked(double hours);

private:

    double hoursWorked;

    double hourlyRate;
};

/*
 * Class: CommissionedEmployee
 * ----------------------
 * This class defines commissioned payed emplyoy, which is a subclass of employee.
 * The get pay method depends on the base salary, commision rate and sales volume, which
 * are defined in the private part of the class.
 */

class CommissionedEmployee : public Employee {

public:

    CommissionedEmployee();

    CommissionedEmployee(std::string new_name);

    virtual double getPay();

    void setBaseSalary(double salary);

    void setCommissionRate(double rate);

    void setSalesVolume(double volume);

private:

    double baseSalary;

    double commissionRate;

    double salesVolume;
};

/*
 * Class: SalariedEmployee
 * ----------------------
 * This class defines salary payed emplyoy, which is a subclass of employee.
 * The get pay method depends on the salary only, which are defined in the
 * private part of the class.
 */

class SalariedEmployee : public Employee {

public:

    SalariedEmployee();

    SalariedEmployee(std::string new_name);

    virtual double getPay();

    void setSalary(double value);

private:

    double salary;
};

#endif
