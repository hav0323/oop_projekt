#pragma once
#include <string>
using namespace std;

class Person
{
public:
    virtual ~Person() {}
    virtual void Tostring() = 0;
};
