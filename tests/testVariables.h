
#pragma once


#include "ItemType.h"
#include "Status.h"
#include "Bag.cpp"
#include "Item.cpp"
#include "StatusItem.cpp"
#include "HpAndPpItem.cpp"
#include "PokeType.h"
#include "Pokemon.cpp"
#include "Attack.cpp"
#include "Trainer.cpp"

#include <vector>
#include <iostream>

namespace testVariables {
    
    
    std::string pokemonName1 = "Pikachu";
    PokeType pokemonType1 = ELECTRIC;
    int pokemonMaxHp1 = 90;
    
    std::string pokemonName2 = "Charmander";
    PokeType pokemonType2 = FIRE;
    int pokemonMaxHp2 = 80;
    
    std::string pokemonName3 = "Squirtle";
    PokeType pokemonType3 = WATER;
    int pokemonMaxHp3 = 75;
    
    std::string pokemonName4 = "Bulbasaur";
    PokeType pokemonType4 = GRASS;
    int pokemonMaxHp4 = 80;
    
    std::string pokemonName5 = "Eevee";
    PokeType pokemonType5 = NORMAL;
    int pokemonMaxHp5 = 90;
    
    std::string pokemonName6 = "Grovyle";
    PokeType pokemonType6 = GRASS;
    int pokemonMaxHp6 = 160;
    
    std::string pokemonName7 = "Weedle";
    PokeType pokemonType7 = BUG;
    int pokemonMaxHp7 = 50;
    
    
    //---------------------------------------------------
    
    std::string attackName1 = "Thunderbolt";
    PokeType attackType1 = ELECTRIC;
    int attackBaseDamage1 = 30;
    int attackMaxPp1 = 15;
    
    std::string attackName2 = "Fireball";
    PokeType attackType2 = FIRE;
    int attackBaseDamage2 = 35;
    int attackMaxPp2 = 20;
    
    std::string attackName3 = "Watergun";
    PokeType attackType3 = WATER;
    int attackBaseDamage3 = 25;
    int attackMaxPp3 = 15;
    
    std::string attackName4 = "Leafblade";
    PokeType attackType4 = GRASS;
    int attackBaseDamage4 = 20;
    int attackMaxPp4 = 10;
    
    std::string attackName5 = "Leafblade";
    PokeType attackType5 = GRASS;
    int attackBaseDamage5 = 20;
    int attackMaxPp5 = 10;
    
    //---------------------------------------------------
    
    std::string itemName1 = "Potion";
    std::string itemDescription1 = "Heal 20 damage";
    int itemRestoreAmount1 = 20;
    ItemType itemRestoreType1 = HP;
    
    std::string itemName2 = "Ether";
    std::string itemDescription2 = "Restore 15 PP";
    int itemRestoreAmount2 = 15;
    ItemType itemRestoreType2 = PP;
    
    std::string itemName3 = "Super Potion";
    std::string itemDescription3 = "Heal 60 damage";
    int itemRestoreAmount3 = 60;
    ItemType itemRestoreType3 = HP;
    
    std::string itemName4 = "Awaken";
    std::string itemDescription4 = "Wakes up an asleep Pokemon";
    Status itemStatus4 = ASLEEP;
    
    std::string itemName5 = " Paralyz Heal";
    std::string itemDescription5 = "Cures paralysis";
    Status itemStatus5 = PARALYZED;
    
    
    //---------------------------------------------------
    
    Attack attack1;
    Attack attack2;
    Attack attack3;
    Attack attack4;
    Attack attack5;
    
    Item *item1 = nullptr;
    Item *item2 = nullptr;
    Item *item3 = nullptr;
    Item *item4 = nullptr;
    Item *item5 = nullptr;

    Bag bag1;
    Bag bag2;
    
    Pokemon *pokemon1;
    Pokemon *pokemon2;
    Pokemon *pokemon3;
    Pokemon *pokemon4;
    Pokemon *pokemon5;
    Pokemon *pokemon6;
    Pokemon *pokemon7;
    
    Trainer trainer1;
    Trainer trainer2;
    
    //---------------------------------------------------
    
    struct Init{
        Init(){
            
            
            attack1 = Attack(attackName1, attackType1, attackBaseDamage1, attackMaxPp1);
            attack2 = Attack(attackName2, attackType2, attackBaseDamage2, attackMaxPp2);
            attack3 = Attack(attackName3, attackType3, attackBaseDamage3, attackMaxPp3);
            attack4 = Attack(attackName4, attackType4, attackBaseDamage4, attackMaxPp4);
            attack5 = Attack(attackName5, attackType5, attackBaseDamage5, attackMaxPp5);
            
            
            item1 = new HpAndPpItem(itemName1, itemDescription1, itemRestoreAmount1, itemRestoreType1);
            item2 = new HpAndPpItem(itemName2, itemDescription2, itemRestoreAmount2, itemRestoreType2);
            item3 = new HpAndPpItem(itemName3, itemDescription3, itemRestoreAmount3, itemRestoreType3);
            item4 = new StatusItem(itemName4, itemDescription4, itemStatus4);
            item5 = new StatusItem(itemName5, itemDescription5, itemStatus5);
        
            
            bag1 = Bag(3);
            bag2 = Bag(5);
            
            bag1.addItem(item1);
            bag1.addItem(item3);
            bag1.addItem(item5);
            
            bag2.addItem(item1);
            bag2.addItem(item2);
            bag2.addItem(item4);
            bag2.addItem(item5);
            
            
            pokemon1 = new Pokemon(pokemonName1, pokemonType1, " ", pokemonMaxHp1);
            pokemon2 = new Pokemon(pokemonName2, pokemonType2, " ", pokemonMaxHp2);
            pokemon3 = new Pokemon(pokemonName3, pokemonType3, " ", pokemonMaxHp3);
            pokemon4 = new Pokemon(pokemonName4, pokemonType4, " ", pokemonMaxHp4);
            pokemon5 = new Pokemon(pokemonName5, pokemonType5, " ", pokemonMaxHp5);
            pokemon6 = new Pokemon(pokemonName6, pokemonType6, " ", pokemonMaxHp6);
            pokemon7 = new Pokemon(pokemonName7, pokemonType7, " ", pokemonMaxHp7);
            
            
            pokemon1->addAttack(attack1);
            pokemon1->addAttack(attack2);
            pokemon1->addAttack(attack4);
            
            trainer1.addPokemon(pokemon1);
            trainer1.addPokemon(pokemon2);
            trainer1.addPokemon(pokemon3);
            trainer1.addPokemon(pokemon4);
            trainer1.addPokemon(pokemon5);
            trainer1.addPokemon(pokemon6);
            
            trainer2.addPokemon(pokemon1);
            trainer2.addPokemon(pokemon2);
            trainer2.addPokemon(pokemon4);
            
        
        }
    } init_;

}