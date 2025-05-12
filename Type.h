#pragma once
#include <string>
using namespace std;

class Type
{
private:
    string type;

public:
    Type(string type);
    string GetTypeName();
};
