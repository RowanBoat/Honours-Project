// Spell Generator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::endl;

string dmgTypes[10]
{ 
    "acid", 
    "cold", 
    "fire", 
    "force", 
    "lightning", 
    "necrotic", 
    "poison", 
    "psychic", 
    "radiant", 
    "thunder" 
};

struct GeneratedSpell
{
    int level = 0;
    int range = 0;
    int duration = 0;
    int dmgDice = 0;
    int numberOfDmgDice = 0;
    int dmgType = 0;
    
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

    // Randomly decide damaging spell's damage and type
    newSpell.dmgDice = rand() % 5 + 2;
    newSpell.dmgDice *= 2;
    newSpell.dmgType = rand() % 10;

    // Converting damage integers to string to be output in "XdY" format
    newSpell.damage = std::to_string(newSpell.numberOfDmgDice) + "d" + std::to_string(newSpell.dmgDice) + " " + dmgTypes[newSpell.dmgType] + " Damage";

    return newSpell;
}

int main()
{
    int numberOfSpells = 0;
    GeneratedSpell spellBuffer;
    std::vector<GeneratedSpell> spells;
    srand(time(NULL));

    std::cout << "Input Number of Spells to be Generated: ";
    std::cin >> numberOfSpells;
    std::cout << "Generating Spells..." << endl;

    for (int i = 0; i < numberOfSpells; i++)
    {
        spellBuffer = generateSpell();
        spells.push_back(spellBuffer);
    }

    // Output generated spells, cout structured as it should be output
    for (int i = 0; i < spells.size(); i++)
    {
        std::cout << endl << "Spell has been generated:" << endl
                  << endl
                  << "             Name: " << spells[i].name << endl
                  << "            Level: " << spells[i].levelStr << endl
                  << "     Casting Time: " << spells[i].castTime << endl
                  << "            Range: " << spells[i].rangeStr << endl
                  << "       Components: " << spells[i].components << endl
                  << "         Duration: " << spells[i].durationStr << endl
                  << "           Damage: " << spells[i].damage << endl
                  << "Additional Effect: " << spells[i].additionalEffectStr << endl;
    }

    ///////////////////////////////////////////
    // TO-DO: ADD WRITE-TO-CSV FUNCTIONALITY //
    ///////////////////////////////////////////

    return 0;
}
