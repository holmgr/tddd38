#ifndef PERSON_CLONEABLE_H
#define PERSON_CLONEABLE_H
#include "Person.h"

namespace IDA_Person
{
    template<typename Base, typename Derived>
    class Person_Cloneable : public Base
    {
    private:
        Person_Cloneable() = default;

    public:
        //using Person::Person;
        using Base::Base;
        virtual ~Person_Cloneable() = default;
        Base* clone() const override 
        {
            return new Derived(static_cast<const Derived&>(*this));
        }
    };
} /* IDA_Person */ 
#endif /* PERSON_CLONEABLE_H */
