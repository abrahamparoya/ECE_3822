#include<iostream>
#include <time.h>
#include "player.cpp"
#include "team.cpp"
using namespace std;

void test_case_1();
void test_case_2();
void test_case_3();

int main(){

    // randomize the random number generator
    srand(time(NULL));

    // pick a test case to run, or create your own
    test_case_1();
    test_case_2();
    test_case_3();

    return 0;
}

// Test ability to create players
void test_case_1(){

    cout << "********** Test Case 1 **********" << endl;

    // create a player
    player alice("Alice Adams");

    // reset player's score to zero
    alice.reset_score();

    // set player's ability (0, 1, or 2)
    alice.set_ability(2);

    // player gets a single turn (score is incremented by a random number)
    alice.play_turn();

    // return the player's score
    // int score = alice.get_score();
    // cout << score << endl;

    // display the player's name and total score
    alice.display();

    cout << endl;
}

// Test ability to create teams
void test_case_2(){

    cout << "********** Test Case 2 **********" << endl;

    // create players by specifying name and skill level
    player* alice = new player("Alice Adams"  , 0);
    player* brett = new player("Brett Booth"  , 2);
    player* cecil = new player("Cecil Cinder" , 1);
    player* luke = new player("LUKE"  , 0);
    player* abe = new player("ABE"  , 2);
    player* em = new player("EMMET" , 1);

    // create team
    team the_dragons("The Dragons");
    team the_knights("The Knights");


    // assign players to teams, set Brett as the captain
    the_dragons.add_player(alice , 0);
    the_dragons.add_player(brett , 1);
    the_dragons.add_player(cecil , 0);
    the_knights.add_player(luke , 0);
    the_knights.add_player(abe , 1);
    the_knights.add_player(em , 0);

    // play five turns
    for (int i = 0 ; i<5 ; i++)
        the_dragons.play_turn();
    for (int i = 0 ; i<5 ; i++)
        the_knights.play_turn();
    
    // display total result
    cout << the_dragons.get_name() << " scored " << the_dragons.get_score() << endl;
    cout << the_knights.get_name() << " scored " << the_dragons.get_score() << endl;

    
    // destroy the players!
    delete alice, brett, cecil;
    delete luke, abe, em;


    cout << endl;
}

// Play a sample game
void test_case_3(){

    cout << "********** Test Case 3 **********" << endl;

    // step 1 create players
    // this time I'll use a loop to make it easier. We'll make 20 players.
    // to make things easier we'll assign them all the same ability level
    player* player_list[20];
    for (int i = 0 ; i<20 ; i++)
        player_list[i] = new player("Generic Name" , 2);
    
    // step 2 create teams
    team the_dragons("The Dragons");
    team the_knights("The Knights");


    // step 3 pick teams (the draft)
    the_dragons.add_player(player_list[0] , 1);     // team 1 gets a captain
    for (int i = 1 ; i < 10 ; i++)
        the_dragons.add_player(player_list[i],0);   // team 1 gets nine normal players

    the_knights.add_player(player_list[10] , 1);    // team 2 gets a captain
    for (int i = 11 ; i < 20 ; i++)
        the_knights.add_player(player_list[i],0);   // team 2 gets nine normal players

    // step 4 - play the game! 5 rounds:
    for (int i = 0 ; i < 5 ; i++){
        the_dragons.play_turn();
        the_knights.play_turn();
    }

    // step 5 - pick the winner
    cout<< the_knights.get_name() << " scored " <<the_knights.get_score()<< endl;
    cout << the_dragons.get_name() << " scored " << the_dragons.get_score() << endl;
    if (the_dragons.get_score() > the_knights.get_score() )
        cout << the_dragons.get_name() << " win!" << endl;
    else if (the_knights.get_score() > the_dragons.get_score() )
        cout << the_knights.get_name() << " win!" << endl;
    else
        cout << "its a tie!" << endl;


    cout << endl;
    }
