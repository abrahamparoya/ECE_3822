#ifndef _PLAYER_
#define _PLAYER_
#include <time.h>
#include <iostream>

using namespace std;

// Creates the player class that holds player variables.
//
class player
{

private:
    string Name;
    int Ability_lvl;
    int Player_status;
    int Player_score;

public:
    int captain_status;

    // Player constructor that takes just the name.
    //
    player(string name)
    {
        Name = name;
        Ability_lvl = 0;
        Player_status = 0;
        Player_score = 0;
    }

    // Player constructor that takes both name and ability lvl.
    //
    player(string name, int ability_lvl)
    {
        Name = name;
        Ability_lvl = ability_lvl;
        Player_status = 0;
        Player_score = 0;
    }
    player() = default;

    // Resets score by setting player score to zero.
    //
    void reset_score()
    {
        player::Player_score = 0;
    }

    // Sets player ability by setting input to Ability_lvl. Checks to make sure
    // the input is within the parameters 0-2.
    //
    void set_ability(int x)
    {

        if (x >= 0 && x <= 2)
        {

            player::Ability_lvl = x;
        }
        else
            cout << "Error! Player ability must be between 0 and 2." << endl;

        return;
    }

    // Returns players ability level.
    //
    int get_ability()
    {
        return Ability_lvl;
    }

    // Plays a turn by activating the case statement that aligns with the players
    // ability level.
    //
    void play_turn()
    {

        int y = player::Ability_lvl;

        switch (y)
        {
        case 0:
            player::Player_score += (0 + (rand() % (int)4));
            break;
        case 1:
            player::Player_score += (2 + (rand() % (int)4));
            break;
        case 2:
            player::Player_score += (4 + (rand() % (int)4));
            break;
        default:
            cout << "Invalid Ability level!" << endl;
        }
    }

    // Returns a players score.
    //
    int get_score()
    {
        int z;
        z = player::Player_score;
        return z;
    }

    // Displays a players name and score.
    //
    void display()
    {

        cout << player::Name << ": " << player::Player_score << endl;

        return;
    }
};

#endif

//
// End of file.
