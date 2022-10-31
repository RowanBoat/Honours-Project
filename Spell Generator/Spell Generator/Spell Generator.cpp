// Spell Generator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::endl;

struct GeneratedSpell
{
    int level = 0;
    int range = 0;
    int duration = 0;
    int dmgDice = 8;
    int numberOfDmgDice = 0;
    
    bool hasAdditionalEffect = false;

    string name = "";
    string levelStr = "";
    string castTime = "";
    string rangeStr = "";   
    string components = "";
    string durationStr = "";
    string damage = "";
    string additionalEffectStr = "";
};

GeneratedSpell generateSpell()
{
    GeneratedSpell newSpell;

    /////////////////////////////////////////////
    // TO-DO: ADD CODE TO GENERATE A NEW SPELL //
    /////////////////////////////////////////////

    // Setting spell name, currently set to "[TBD]" but may change later
    newSpell.name = "[TBD]";

    // Deciding whether spell has additional effect, may be expanded upon later
    newSpell.hasAdditionalEffect = rand() % 2;
    if (newSpell.hasAdditionalEffect)
    {
        newSpell.additionalEffectStr = "Yes";
    }
    else
    {
        newSpell.additionalEffectStr = "No";
    }

    // Converting level int to string, currently defaulting to 0 (cantrips)
    if (newSpell.level > 0)
    {
        newSpell.levelStr = std::to_string(newSpell.level);
    }
    else
    {
        newSpell.numberOfDmgDice = 1;
        newSpell.levelStr = "Cantrip";
    }

    newSpell.castTime = "1 action"; // Needs more functionality later, 1 action will do for now

    // Converting range int to string output (currently 0 feet by default)
    if (newSpell.range > 0)
    {
        newSpell.rangeStr = std::to_string(newSpell.range) + " feet";
    }
    else
    {
        newSpell.rangeStr = "Touch"; // 0 foot range is touch range
        // Add "Self" Functionality Later
    }

    newSpell.components = "V S"; // Needs more functionality later

    // Converting spell duration int to string output, currently 0 seconds (Instantaneous) by default
    if (newSpell.duration > 0)
    {
        newSpell.durationStr = std::to_string(newSpell.duration) + " seconds";
    }
    else
    {
        newSpell.durationStr = "Instantaneous";
    }

    // Converting damage integers to string to be output in "XdY" format
    newSpell.damage = std::to_string(newSpell.numberOfDmgDice) + "d" + std::to_string(newSpell.dmgDice) + " [TBD] Damage";

    return newSpell;
}

int main()
{
    srand(time(NULL));
    std::vector<GeneratedSpell> newSpells;

    /////////////////////////////////////////////
    // TO-DO: MODIFY OUTPUT TO CREATE MULTIPLE //
    //        NEW SPELLS INSIDE VECTOR         //
    /////////////////////////////////////////////

    GeneratedSpell spellBuffer;
    spellBuffer = generateSpell();

    // Output generated spells, cout structured as it should be output
    std::cout << "Spell has been generated:" << endl 
              << endl
              << "             Name: " << spellBuffer.name << endl 
              << "            Level: " << spellBuffer.levelStr << endl
              << "     Casting Time: " << spellBuffer.castTime << endl
              << "            Range: " << spellBuffer.rangeStr << endl
              << "       Components: " << spellBuffer.components << endl
              << "         Duration: " << spellBuffer.durationStr << endl
              << "           Damage: " << spellBuffer.damage << endl
              << "Additional Effect: " << spellBuffer.additionalEffectStr << endl;

    ///////////////////////////////////////////
    // TO-DO: ADD WRITE-TO-CSV FUNCTIONALITY //
    ///////////////////////////////////////////

    return 0;
}
