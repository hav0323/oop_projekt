#pragma once
#include "Trainer.h"
#include "Type.h"

class GymLeader : public Trainer
{
private:
    Type *specialty;

public:
    GymLeader(string name, int age, string gender, Type *specialty);
    GymLeader(string name, int age, string gender, Type *specialty, vector<Pokemon *> team);

    void AddPokemon(Pokemon *pokemon);
    void Tostring();

    Type *GetSpecialty();
};