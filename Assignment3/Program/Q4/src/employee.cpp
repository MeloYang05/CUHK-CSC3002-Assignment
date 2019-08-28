/*
 * File: employee.cpp
 * ------------------
 * This file provides a stub implementation of the employee.h interface.
 */

#include <string>
#include "employee.h"
#include "strlib.h"
using namespace std;

/*
 * Implementation Notes: getName
 * -------------------------------
 * This is a public mothod which can be used for all the sub class of the Employee.
 * It will return the name of the employee.
 */

std::string Employee::getName(){
    return name;
}

/*
 * Implementation Notes: ~Employee deconstructor
 * ---------------------------------------------
 * It is used to free the memory.
 */

Employee::~Employee(){}

/*
 * Implementation Notes: HourlyEmployee constructor
 * -------------------------------------------------
 * If there's no argument, the name is set to be an empty string, hoursWorked and hourlyRate
 * are both set to 0.
 */

HourlyEmployee::HourlyEmployee(){
    name=" ";
    hoursWorked=0;
    hourlyRate=0;
}

/*
 * Implementation Notes: HourlyEmployee constructor
 * ------------------------------------------------
 * If there is an argument, the name is set to it, hoursWorked and hourlyRate
 * are both set to 0.
 */

HourlyEmployee::HourlyEmployee(std::string new_name){
    name=new_name;
    hoursWorked=0;
    hourlyRate=0;
}

/*
 * Implementation Notes: getPay
 * -----------------------------
 * In HourlyEmployee subclass, getPay method returns hourlyRate*hoursWorked
 */

double HourlyEmployee::getPay(){
    return hourlyRate*hoursWorked;
}

/*
 * Implementation Notes: setHourlyRate
 * -----------------------------------
 * Set the hourlyRate to the given value
 */

void HourlyEmployee::setHourlyRate(double rate){
    hourlyRate=rate;
}

/*
 * Implementation Notes: setHoursWorked
 * -------------------------------------
 * Set the hoursWorked to the given value
 */

void HourlyEmployee::setHoursWorked(double hours){
    hoursWorked=hours;
}

/*
 * Implementation Notes: CommissionEmployee constructor
 * -------------------------------------------------
 * If there's no argument, the name is set to be an empty string, baseSalary, salesVolume
 * and commissionRate are both set to 0.
 */

CommissionedEmployee::CommissionedEmployee(){
    name=" ";
    baseSalary=0;
    commissionRate=0;
    salesVolume=0;
}

/*
 * Implementation Notes: CommissionEmployee constructor
 * -------------------------------------------------
 * If there is an argument, the name is set to it, baseSalary, salesVolume
 * and commissionRate are both set to 0.
 */

CommissionedEmployee::CommissionedEmployee(std::string new_name){
    name=new_name;
    baseSalary=0;
    commissionRate=0;
    salesVolume=0;
}

/*
 * Implementation Notes: getPay
 * -----------------------------
 * In CommisionedEmployee subclass, getPay method returns baseSalary+commissionRate*salesVolume
 */

double CommissionedEmployee::getPay(){
    return baseSalary+commissionRate*salesVolume;
}

/*
 * Implementation Notes: setBaseSalary
 * -------------------------------------
 * Set the baseSalary to the given value
 */

void CommissionedEmployee::setBaseSalary(double salary){
    baseSalary=salary;
}

/*
 * Implementation Notes: setCommissionRate
 * -------------------------------------
 * Set the commissionRate to the given value
 */

void CommissionedEmployee::setCommissionRate(double rate){
    commissionRate=rate;
}

/*
 * Implementation Notes: setSalesVolume
 * -------------------------------------
 * Set the salesVolume to the given value
 */

void CommissionedEmployee::setSalesVolume(double volume){
    salesVolume=volume;
}

/*
 * Implementation Notes: SalariedEmployee constructor
 * -------------------------------------------------
 * If there's no argument, the name is set to be an empty string, and salary is set to 0.
 */

SalariedEmployee::SalariedEmployee(){
    name=" ";
    salary=0;
}

/*
 * Implementation Notes: SalariedEmployee constructor
 * -------------------------------------------------
 * If there is an argument, the name is set to be an empty string, and salary is set to 0.
 */

SalariedEmployee::SalariedEmployee(std::string new_name){
    name=new_name;
    salary=0;
}

/*
 * Implementation Notes: getPay
 * -----------------------------
 * In SalariedEmployee subclass, getPay method returns salary
 */

double SalariedEmployee::getPay(){
    return salary;
}

/*
 * Implementation Notes: setSalary
 * -------------------------------------
 * Set the salary to the given value
 */

void SalariedEmployee::setSalary(double value){
    salary=value;
}
