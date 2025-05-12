#pragma once

class Stats
{
private:
    int hp;
    int at;
    int spa;
    int def;
    int spdef;
    int speed;

public:
    Stats(int hp, int at, int spa, int def, int spdef, int speed);

    int GetHP();
    int GetAttack();
    int GetSpecialAttack();
    int GetDefense();
    int GetSpecialDefense();
    int GetSpeed();
};
