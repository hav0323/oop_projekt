#include "Pokemon.h"
#include <iostream>
using namespace std;

Pokemon::Pokemon(string name, Type *type1, Type *type2, vector<Move *> moves, Stats *stats)
{
    this->name = name;
    this->stats = stats;
    this->type1 = type1;
    this->type2 = type2;
    if (moves.size() > 4)
    {
        this->moves = {};
        cout << "Too many moves, moves werent incialized" << endl;
    }
    else
    {
        this->moves = moves;
    }
}
Pokemon::Pokemon(string name, Type *type1, vector<Move *> moves, Stats *stats)
{
    this->name = name;
    this->stats = stats;
    this->type1 = type1;
    if (moves.size() > 4)
    {
        this->moves = {};
        cout << "Too many moves, moves werent incialized" << endl;
    }
    else
    {
        this->moves = moves;
    }
}
Pokemon::Pokemon(string name, Type *type1, Type *type2, Stats *stats)
{
    this->name = name;
    this->stats = stats;
    this->type1 = type1;
    this->type2 = type2;
    this->moves = {};
}
Pokemon::Pokemon(string name, Type *type1, Stats *stats)
{
    this->name = name;
    this->stats = stats;
    this->type1 = type1;
    this->moves = {};
}

Pokemon::~Pokemon()
{
    for (Move *move : this->moves)
    {
        delete move;
    }
}

void Pokemon::LearnNewMove(Move *move)
{
    if (this->moves.size() >= 4)
    {
        cout << this->GetName() << " already knows 4 moves." << endl;
    }
    else
    {
        this->moves.push_back(move);
        cout << "Move " << move->GetName() << " has been learned by " << this->GetName() << "." << endl;
    }
}

void Pokemon::ForgetMove(string name)
{
    if (this->moves.empty())
    {
        cout << this->GetName() << " doesn't know any moves." << endl;
        return;
    }
    for (int i = 0; i < this->moves.size(); i++)
    {
        if (this->moves[i]->GetName() == name)
        {
            delete this->moves[i];
            this->moves.erase(this->moves.begin() + i);
            cout << "Move " << name << " has been forgotten by " << this->GetName() << "." << endl;
            return;
        }
    }
    cout << "Move " << name << " not found." << endl;
}

string Pokemon::GetName()
{
    return this->name;
}

Type *Pokemon::GetType1()
{
    return this->type1;
}

Type *Pokemon::GetType2()
{
    return this->type2;
}

Stats *Pokemon::GetStats()
{
    return this->stats;
}

vector<Move *> Pokemon::GetMoves()
{
    return this->moves;
}

void Pokemon::PrintInfo()
{
    cout << "Pokemon: " << this->name << endl;

    if (this->type2 == nullptr)
    {
        cout << "Type: " << this->type1->GetTypeName() << endl;
    }
    else
    {
        cout << "Type: " << this->type1->GetTypeName() << ", " << this->type2->GetTypeName() << endl;
    }

    if (this->stats)
    {
        cout << "Stats:" << endl;
        cout << "  HP: " << this->stats->GetHP() << endl;
        cout << "  Attack: " << this->stats->GetAttack() << endl;
        cout << "  Special Attack: " << this->stats->GetSpecialAttack() << endl;
        cout << "  Defense: " << this->stats->GetDefense() << endl;
        cout << "  Special Defense: " << this->stats->GetSpecialDefense() << endl;
        cout << "  Speed: " << this->stats->GetSpeed() << endl;
    }

    if (!this->moves.empty())
    {
        cout << "Moveset:" << endl;
        for (Move *move : this->moves)
        {
            cout << "  - " << move->GetName()
                 << " [power: " << move->GetPower()
                 << ", accuracy: " << move->GetAccuracy()
                 << ", type: " << move->GetType()->GetTypeName() << "]" << endl;
        }
    }
    else
    {
        cout << "Moveset: No moves learned." << endl;
    }
}