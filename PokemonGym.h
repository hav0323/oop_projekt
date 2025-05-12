#pragma once
#include <vector>
#include "Person.h"

class PokemonGym
{
private:
    static int gymCount;
    vector<Person *> people;

public:
    PokemonGym();
    ~PokemonGym();

    void AddPerson(Person *person);
    void DisplayAll();

    static int GetGymCount();
};