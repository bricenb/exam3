/* Copyright Bricen Bennett 2020 csce240 */

#include <inc/employee.h>
#include <iostream>
using std::cout;
using std::endl;
namespace exam3 {
Demographic::Demographic(const std::string& first_name,
                         const std::string& last_name,
                         const std::string& date_of_birth) {
  first = first_name;
  last = last_name;
  date = date_of_birth;
}

const std::string Demographic::first_name() const {
  return first;
}

const std::string Demographic::last_name() const {
  return last;
}

const std::string Demographic::date_of_birth() const {
  return date;
}

Demographic::~Demographic() {}

Employee::Employee(const std::string& first_name,
                   const std::string& last_name,
                   const std::string& date_of_birth,
                   const std::string& employee_id) : Demographic(first_name,
                                                   last_name, date_of_birth) {
  id = employee_id;
}

const std::string Employee::employee_id() const {
  return id;
}

Employee::~Employee() {}

HourlyEmployee::HourlyEmployee(const std::string& first_name,
               const std::string& last_name,
               const std::string& date_of_birth,
               const std::string& employee_id,
               double pay_rate) : Employee(first_name,
                                           last_name,
                                           date_of_birth,
                                           employee_id) {
  rate = pay_rate;
}

HourlyEmployee::~HourlyEmployee() {}

double HourlyEmployee::pay_rate() const {
  return rate;
}

double HourlyEmployee::CalculatePay(double hours) const {
  return hours * rate;
}

SalaryEmployee::SalaryEmployee(const std::string& first_name,
                               const std::string& last_name,
                               const std::string& date_of_birth,
                               const std::string& employee_id,
                               double salary) : Employee(first_name,
                                                         last_name,
                                                         date_of_birth,
                                                         employee_id) {
  salary_rate = salary;
}

SalaryEmployee::~SalaryEmployee() {}

double SalaryEmployee::pay_rate() const {
  return salary_rate;
}

double SalaryEmployee::CalculatePay(double percentage) const {
  return percentage * salary_rate;
}


}  // namespace exam3
