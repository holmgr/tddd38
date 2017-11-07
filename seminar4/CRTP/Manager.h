/*
 * Manager.h
 */
#ifndef MANAGER_H
#define MANAGER_H
#include "CRN.h"
#include "Date.h"
#include "Employee.h"
#include "Person_Cloneable.h"
#include <map>
#include <string>

namespace IDA_Person
{
   using IDA_Date::Date;

   class Manager : public Person_Cloneable<Employee, Manager>
   {
   public:
      Manager(const std::string& name, 
              const CRN&         crn,
              const Date&        e_date, 
              int                e_number,
              double             salary,
              int                dept)
         : Person_Cloneable<Employee, Manager>{ name, crn, e_date, e_number, salary, dept }
      {}

      ~Manager() = default;

      Manager* clone() const override { return new Manager{ *this }; }

      std::string str() const override;

      void add_department_member(Employee* ep) const;
      void remove_department_member(int e_number) const;
      void print_department_list(std::ostream&) const;

      void raise_salary(double percent) const;

   protected:
      friend Person_Cloneable<Employee, Manager>;
      Manager(const Manager&) = default;

   private:
      Manager& operator=(const Manager&) = delete;
 
      // Manager does not own the Employee objects - no cleanup required
      mutable std::map<int, Employee*> dept_members_;
   };

} // namespace IDA_Person

#endif
