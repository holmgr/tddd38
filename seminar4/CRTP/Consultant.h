/*
 * Consultant.h
 */
#ifndef CONSULTANT_H
#define CONSULTANT_H
#include "Person_Cloneable.h"
#include "Employee.h"
#include <string>

namespace IDA_Person
{
   class Consultant final : public Person_Cloneable<Employee, Consultant>
   {
   public:
      using Person_Cloneable<Employee, Consultant>::Person_Cloneable;
      //using Employee::Employee;  // inheriting constructors
 
      ~Consultant() = default;

      Consultant* clone() const override { return new Consultant{ *this }; }

      std::string str() const override;

   protected:
      friend Person_Cloneable<Employee, Consultant>;
      Consultant(const Consultant&) = default;

   private:
      Consultant& operator=(const Consultant&) = delete;
   };

} // namespace IDA_Person

#endif
