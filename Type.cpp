#include "Type.h"

Type::Type(string type)
{
    this->type = type;
}

string Type::GetTypeName()
{
    return this->type;
}