#pragma once
#include <vector>
#include "Move.h"
#include "Stats.h"
#include "Type.h"
#include <iostream>
using namespace std;

class Pokemon
{
private:
    vector<Move *> moves;
    Type *type1;
    Type *type2;
    Stats *stats;
    string name;

public:
    Pokemon(string name, Type *type1, Type *type2, vector<Move *> moves, Stats *stats);
    Pokemon(string name, Type *type1, vector<Move *> moves, Stats *stats);
    Pokemon(string name, Type *type1, Type *type2, Stats *stats);
    Pokemon(string name, Type *type1, Stats *stats);

    void LearnNewMove(Move *move);
    void ForgetMove(string name);

    string GetName();
    Type *GetType1();
    Type *GetType2();
    Stats *GetStats();
    vector<Move *> GetMoves();

    void PrintInfo();

    ~Pokemon();
};
