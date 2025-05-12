#pragma once
#include "Person.h"
#include <vector>
#include "Pokemon.h"

class Trainer : public Person
{
private:
    string name;
    int age;
    string gender;
protected:
    vector<Pokemon *> team;

public:
    Trainer(string name, int age, string gender);
    Trainer(string name, int age, string gender, vector<Pokemon *> team);
    ~Trainer();

    void AddPokemon(Pokemon *pokemon);
    void Tostring();

    string GetName();
    int GetAge();
    string GetGender();
    vector<Pokemon *> GetTeam();
};