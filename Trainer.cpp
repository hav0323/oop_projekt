#include "Trainer.h"
#include <iostream>
using namespace std;

Trainer::Trainer(string name, int age, string gender) : Person()
{
    this->name = name;
    this->age = age;
    this->gender = gender;
    this->team = {};
}

Trainer::Trainer(string name, int age, string gender, vector<Pokemon *> team) : Person()
{
    this->name = name;
    this->age = age;
    this->gender = gender;
    this->team = team;
}

Trainer::~Trainer()
{
    for (Pokemon *pokemon : this->team)
    {
        delete pokemon;
    }
}

void Trainer::AddPokemon(Pokemon *pokemon)
{
    this->team.push_back(pokemon);
}

void Trainer::Tostring()
{
    cout << "Trainer: " << this->GetName() << ", Age: " << this->GetAge() << ", Gender: " << this->GetGender() << endl;
    cout << "Team: " << endl;
    for (Pokemon *pokemon : this->GetTeam())
    {
        cout << "- " << pokemon->GetName() << endl;
    }
}

string Trainer::GetName() 
{
    return this->name;
}

int Trainer::GetAge() 
{
    return this->age;
}

string Trainer::GetGender() 
{
    return this->gender;
}

vector<Pokemon *> Trainer::GetTeam() 
{
    return this->team;
}
