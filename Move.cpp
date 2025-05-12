#include "Move.h"

Move::Move(int acc, int power, Type *type, string name)
{
    this->accuracy = acc;
    this->power = power;
    this->type = type;
    this->name = name;
}

string Move::GetName()
{
    return this->name;
}

int Move::GetPower()
{
    return this->power;
}

int Move::GetAccuracy()
{
    return this->accuracy;
}

Type *Move::GetType()
{
    return this->type;
}