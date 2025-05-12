#include <iostream>
#include "Pokemon.h"
#include "Trainer.h"
#include "GymLeader.h"
#include "PokemonGym.h"
#include "Type.h"
#include "Stats.h"
#include "Move.h"

using namespace std;

int main()
{
    Type *fire = new Type("Fire");
    Type *water = new Type("Water");
    Type *flying = new Type("Flying");
    Type *electric = new Type("Electric");
    Type *rock = new Type("Rock");
    Type *ground = new Type("Ground");
    Type *poison = new Type("Poison");
    Type *fighting = new Type("Fighting");

    Stats *charizardStats = new Stats(78, 84, 109, 78, 85, 100);
    Stats *blastoiseStats = new Stats(79, 83, 85, 100, 105, 78);
    Stats *pikachuStats = new Stats(35, 55, 50, 40, 50, 90);
    Stats *onixStats = new Stats(35, 45, 30, 160, 45, 70);
    Stats *croagunkStats = new Stats(48, 61, 61, 40, 40, 50);

    Move *flamethrower = new Move(90, 90, fire, "Flamethrower");
    Move *fly = new Move(70, 95, flying, "Fly");
    Move *hydroPump = new Move(110, 80, water, "Hydro Pump");
    Move *thunderbolt = new Move(90, 100, electric, "Thunderbolt");
    Move *rockThrow = new Move(90, 50, rock, "Rock Throw");
    Move *earthquake = new Move(100, 100, ground, "Earthquake");
    Move *poisonJab = new Move(100, 80, poison, "Poison Jab");
    Move *brickBreak = new Move(100, 75, fighting, "Brick Break");

    Pokemon *charizard = new Pokemon("Charizard", fire, flying, {flamethrower, fly}, charizardStats);
    Pokemon *blastoise = new Pokemon("Blastoise", water, {hydroPump}, blastoiseStats);
    Pokemon *pikachu = new Pokemon("Pikachu", electric, {thunderbolt}, pikachuStats);
    Pokemon *onix = new Pokemon("Onix", rock, ground, {rockThrow, earthquake}, onixStats);
    Pokemon *croagunk = new Pokemon("Croagunk", poison, fighting, {poisonJab, brickBreak}, croagunkStats);

    cout << "=== Pokémon Info ===" << endl;
    charizard->PrintInfo();
    cout << endl;
    blastoise->PrintInfo();
    cout << endl;

    Trainer *ash = new Trainer("Ash Ketchum", 10, "Male");
    ash->AddPokemon(pikachu);
    ash->AddPokemon(blastoise);

    Trainer *brock = new Trainer("Brock", 15, "Male", {onix, croagunk});

    cout << "=== Trainer Info ===" << endl;
    ash->Tostring();
    cout << endl;
    brock->Tostring();
    cout << endl;

    GymLeader *blaine = new GymLeader("Blaine", 55, "Male", fire);
    blaine->AddPokemon(charizard);
    blaine->AddPokemon(blastoise);

    GymLeader *koga = new GymLeader("Koga", 50, "Male", poison);
    Trainer *Blue = koga; 
    

    Stats *mukStats = new Stats(105, 105, 65, 100, 100, 50);
    Move *sludgeBomb = new Move(90, 100, poison, "Sludge Bomb");
    Move *gunkShot = new Move(120, 80, poison, "Gunk Shot");

    Pokemon *muk = new Pokemon("Muk", poison, {sludgeBomb, gunkShot}, mukStats);

    koga->AddPokemon(muk);

     

    cout << "=== Gym Leader Info ===" << endl;
    blaine->Tostring();
    cout << endl;

    PokemonGym *gym = new PokemonGym();
    gym->AddPerson(ash);
    gym->AddPerson(blaine);
    gym->AddPerson(brock);

    cout << "=== Pokémon Gym Info ===" << endl;
    gym->DisplayAll();
    cout << endl;

    cout << "=== Forgetting a Move ===" << endl;
    charizard->ForgetMove("Fly");
    charizard->PrintInfo();
    cout << endl;

    
    cout << "=== Polymorphism Showcase ===" << endl;
    vector<Person *> people;
    people.push_back(ash);
    people.push_back(brock);
    people.push_back(blaine);

    for (Person *person : people)
    {
        person->Tostring(); 
        cout << endl;
    }

    
    PokemonGym *gym1 = new PokemonGym();
    PokemonGym *gym2 = new PokemonGym();

    gym1->AddPerson(ash);
    gym1->AddPerson(blaine);

    gym2->AddPerson(brock);
    gym2->AddPerson(koga);

    cout << "=== Gym 1 Info ===" << endl;
    gym1->DisplayAll();
    cout << endl;

    cout << "=== Gym 2 Info ===" << endl;
    gym2->DisplayAll();
    cout << endl;

    

    
    return 0;
}