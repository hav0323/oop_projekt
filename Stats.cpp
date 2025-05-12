#include "Stats.h"

Stats::Stats(int hp, int at, int spa, int def, int spdef, int speed)
{
    this->hp = hp;
    this->at = at;
    this->spa = spa;
    this->def = def;
    this->spdef = spdef;
    this->speed = speed;
}

int Stats::GetHP()
{
    return this->hp;
}

int Stats::GetAttack()
{
    return this->at;
}

int Stats::GetSpecialAttack()
{
    return this->spa;
}

int Stats::GetDefense()
{
    return this->def;
}

int Stats::GetSpecialDefense()
{
    return this->spdef;
}

int Stats::GetSpeed()
{
    return this->speed;
}