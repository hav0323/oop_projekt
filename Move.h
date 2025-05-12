#pragma once
#include "Type.h"
using namespace std;

class Move
{
private:
    int accuracy;
    int power;
    Type *type;
    string name;

public:
    Move(int acc, int power, Type *type, string name);
    string GetName();
    int GetPower();
    int GetAccuracy();
    Type *GetType();
};
