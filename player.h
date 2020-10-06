#ifndef CHICKEN_HUNT_PLAYER
#define CHICKEN_HUNT_PLAYER

#include "splashkit.h"
#include <vector>

#define STARTING_SCORE     0
#define STARTING_BULLETS   6
#define STARTING_TIME      50
using namespace std;

/**
 * The player data keeps track of all of the information related to the player.
 *
 * @field   player_sprite   The player's sprite - used to track position and movement
 * @field   score           The current score for the player
 * @field   bullets         Amount of bullets player has
 * @field   player_time     time calculated for totall time
 * @field   time            time left till end of game
 */
struct player_data
{
    sprite  player_sprite;
    int     score;
    int     bullets;
    int     player_time;
    int     time;
};

/* game data contains player data and vector of chickens */
player_data new_player();

/* loads all the sounds in the game */
void load_sounds();

/* draws a player */
void draw_player(const player_data &player_to_draw);

/* updates movement of the player */
void update_player(player_data &player_to_update);

/* read user input and update the player based on this interaction. */
void handle_input(player_data &player);


#endif