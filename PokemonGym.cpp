#include "PokemonGym.h"
#include <iostream>
using namespace std;

int PokemonGym::gymCount = 0;

PokemonGym::PokemonGym()
{
    gymCount++;
}

PokemonGym::~PokemonGym()
{
    for (Person *person : people)
    {
        delete person;
    }
    gymCount--;
}

void PokemonGym::AddPerson(Person *person)
{
    people.push_back(person);
}

void PokemonGym::DisplayAll()
{
    for (Person *person : people)
    {
        person->Tostring();
    }
}
int PokemonGym::GetGymCount()
{
    return gymCount;
}