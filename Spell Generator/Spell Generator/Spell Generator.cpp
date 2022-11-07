// Spell Generator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

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

//////////////////////////////////
// TO-DO: ADD RANGE VALUE ARRAY //
//////////////////////////////////

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

    // Setting spell name, currently set to "[TBD]" but may change later
    newSpell.name = "[TBD]";

    // Converting level int to string, currently defaulting to 0 (cantrips)
    switch (newSpell.level)
    {
        case 0: newSpell.levelStr = "Cantrip"; newSpell.numberOfDmgDice = 1; break;
        case 1: newSpell.levelStr = std::to_string(newSpell.level) + "st"; break;
        case 2: newSpell.levelStr = std::to_string(newSpell.level) + "nd"; break;
        case 3: newSpell.levelStr = std::to_string(newSpell.level) + "rd"; break;
        default: newSpell.levelStr = std::to_string(newSpell.level) + "th"; break;
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
    newSpell.damage = std::to_string(newSpell.numberOfDmgDice) + "d" + std::to_string(newSpell.dmgDice) + " " + dmgTypes[newSpell.dmgType];

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

    return newSpell;
}

int main()
{
    int numberOfSpells = 0;
    GeneratedSpell spellBuffer;
    std::vector<GeneratedSpell> spellsData;
    std::ofstream output("output.csv");
    srand(time(NULL));

    // 2D Vector for spell components to be stored in
    std::vector<std::vector<string>> spells;
    spells.resize(8);

    std::cout << "Input Number of spells to be Generated: ";
    std::cin >> numberOfSpells;
    std::cout << endl << "Generating Spells..." << endl;

    spells[0].push_back("Name");
    spells[1].push_back("Level");
    spells[2].push_back("Casting Time");
    spells[3].push_back("Range");
    spells[4].push_back("Components");
    spells[5].push_back("Duration");
    spells[6].push_back("Damage");
    spells[7].push_back("Additional Effect");

    for (int i = 0; i < numberOfSpells; i++)
    {
        spellBuffer = generateSpell();

        // Output generated spells to command line, cout structured as it should be output
        std::cout << endl << "Spell has been generated:" << endl
                  << endl
                  << "             Name: " << spellBuffer.name << endl
                  << "            Level: " << spellBuffer.levelStr << endl
                  << "     Casting Time: " << spellBuffer.castTime << endl
                  << "            Range: " << spellBuffer.rangeStr << endl
                  << "       Components: " << spellBuffer.components << endl
                  << "         Duration: " << spellBuffer.durationStr << endl
                  << "           Damage: " << spellBuffer.damage << endl
                  << "Additional Effect: " << spellBuffer.additionalEffectStr << endl 
                  << endl;

        // Adds new spell to spells 2D vector for output
        spells[0].push_back(spellBuffer.name);
        spells[1].push_back(spellBuffer.levelStr);
        spells[2].push_back(spellBuffer.castTime);
        spells[3].push_back(spellBuffer.rangeStr);
        spells[4].push_back(spellBuffer.components);
        spells[5].push_back(spellBuffer.durationStr);
        spells[6].push_back(spellBuffer.damage);
        spells[7].push_back(spellBuffer.additionalEffectStr);

        // Stores spell data in vector for future use
        spellsData.push_back(spellBuffer);
    }

    // Output the generated spells to the output.csv file
    if (output.good())
    {
        std::ostream_iterator<std::string> output_iterator(output, ",,");
        for (int i = 0; i < spells.size(); i++)
        {
            std::copy(spells[i].begin(), spells[i].end(), output_iterator);
            output << endl;
        }

        std::cout << "SUCCESS: Output Written To CSV File" << endl;
    }
    else
    {
        std::cout << "ERROR: File Could Not Be Opened" << endl;
    }

    output.close();
    return 0;
}
