   In this project, you will code up a simple game I have invented.

Each PLAYER has:
    - a name
    - an ability level (0, 1, or 2)
    - a player status (0: normal ; 1: captain)
    - a score

Each TEAM has:
    - a name
    - a group of players
    - a total team score
    - exactly one captain

Whenever a player has a turn, they get a random score:
    - ability level 0: score is equally likely to be 0, 1, 2, or 3
    - ability level 1: score is equally likely to be 2, 3, 4, or 5
    - ability level 2: score is equally likely to be 4, 5, 6, or 7

Whenever a TEAM has a turn
    - every "normal" player on the team gets a turn
    - the captain gets two turns

A competition goes as follows:
    - players are created
    - two teams are created
    - a draft is conducted in which each team picks players
    - the competition has 5 rounds
        - during each round, each team gets a turn (see above)
    - at the end, team with the highest score wins

You should write the classes for player and team so that all three test cases work.
For best results, start small. Get "player" to work, then team, then the game.
Likewise, for "player", start with the constructor and then work up from three
Test as you go.

Note: 
    min + (rand() % (int)(max - min + 1))
    ... generates a random integer between min and max, inclusive

Feel free to add other helper functions or features or whatever if that helps.

The "vector" data type in C++ can be very helpful here

Use the submit file to submit, as usual.
