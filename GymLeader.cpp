#include "GymLeader.h"
#include <iostream>
using namespace std;

GymLeader::GymLeader(string name, int age, string gender, Type *specialty)
    : Trainer(name, age, gender)
{
    this->specialty = specialty;
}

GymLeader::GymLeader(string name, int age, string gender, Type *specialty, vector<Pokemon *> team)
    : Trainer(name, age, gender, team)
{
    this->specialty = specialty;

    vector<Pokemon *> validTeam;
    for (Pokemon *pokemon : team)
    {
        if (pokemon->GetType1() == this->specialty || pokemon->GetType2() == this->specialty)
        {
            validTeam.push_back(pokemon);
        }
        else
        {
            cout << "Pokemon " << pokemon->GetName() << " does not match the Gym Leader's specialty type and was not added." << endl;
        }
    }

    if (validTeam.empty())
    {
        cout << "No valid Pokémon were added to the team. The team is empty." << endl;
    }
}

void GymLeader::AddPokemon(Pokemon *pokemon)
{
    if (pokemon->GetType1() == this->GetSpecialty() || pokemon->GetType2() == this->GetSpecialty())
    {
        this->team.push_back(pokemon);
        cout << "Pokemon " << pokemon->GetName() << " added to " << this->GetName() << "'s team." << endl;
    }
    else
    {
        cout << "Pokemon " << pokemon->GetName() << " does not match the Gym Leader's specialty type and was not added." << endl;
    }
}

void GymLeader::Tostring()
{
    cout << "Gym Leader: " << this->GetName() << ", Age: " << this->GetAge() << ", Gender: " << this->GetGender() << endl;
    cout << "Specialty Type: " << this->GetSpecialty()->GetTypeName() << endl;
    cout << "Team: " << endl;
    for (Pokemon *pokemon : this->GetTeam())
    {
        cout << "- " << pokemon->GetName() << endl;
    }
}

Type *GymLeader::GetSpecialty() {
    return this->specialty;
}

GymLeader::~GymLeader()
{
    for (Pokemon *pokemon : this->team)
    {
        delete pokemon;
    }
    delete this->specialty;
}