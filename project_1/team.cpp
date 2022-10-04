#ifndef _TEAM_
#define _TEAM_
#include <vector>
#include "player.cpp"
using namespace std;


// Creates a class called team.  
//
class team{

    // Declaration of variables used within the class
    //
    private:
        string teamName;
        vector<player> teamMembers;
        int teamScore;
        player teamCaptain;
        bool hasCaptain;

    // Declaration of variables used outside of the class
    //
    public:
    team(string name){
        teamName = name;
        teamScore = 0;
        teamMembers = {};
        hasCaptain = false;
    }

    // Adds a player to a team. 
    //
    void add_player(player* newMember, int captain_status){

        // First it checks if the user is trying to add multiple captains to a team. 
        // If there is already captain and trying to add a captain returns message.
        //
        if(captain_status == 1 and hasCaptain == true){
        cout << teamName << "already has a captain!" << endl;
        return;
        }

        // If above conditions met, the player is added to the team.
        //
        teamMembers.push_back(*newMember);
        
        // Updates current captain status of a team. If the team does not have a captain
        // and the current player being added is a captain it changes the captain status of 
        // the team.
        //
        if(hasCaptain == false and captain_status == 1){
            hasCaptain = true;
            captain_status = 1;
            }
    }

    // Plays a turn for a team.
    //
    void play_turn(){
        // Finds number of members for a team.
        //
        int nummembers = teamMembers.size();

        // Loops for team size.
        //
        for(int i = 0; i < nummembers; i++){
            // Captain of a player is  checked.
            int status = teamMembers[i].captain_status;
            // If a captain, two turns are played.
            //
            if(status== 1){
                teamMembers[i].play_turn();
                teamMembers[i].play_turn();
            }
            // If not a captain, one turn is played.
            //
            else{
                teamMembers[i].play_turn();

            }
        }
    }
    // Function returns team score.
    //
    int get_score(){

        int nummembers = teamMembers.size();

        // Loops for the length of team and adds together all of the player
        // scores.
        //
        for(int i = 0; i < nummembers; i++){
            teamScore += teamMembers[i].get_score();
            }
        return teamScore; 
    }

 
    // Returns team name.
    //
    string get_name(){
      return teamName;  
    }

};

#endif

//
// End of file
