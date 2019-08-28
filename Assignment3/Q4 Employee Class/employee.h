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

#endif
