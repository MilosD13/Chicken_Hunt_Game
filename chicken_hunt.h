#ifndef CHICKEN_HUNT
#define CHICKEN_HUNT

#include "player.h"
#include "chicken.h"
#include "splashkit.h"
#include <vector>

using std::vector;
using namespace std;

#define CHICKEN_OCCURRENCE 0.006

/* game data contains player data and vector of ducks */
struct game_data
{
    player_data player;
    vector<chicken_data> chickens;
};

/* loops trough the game */
void game_loop(player_data &player, vector<chicken_data> &chickens, game_data &game);

/* updates the game */
void update_game(player_data &player, vector<chicken_data> &chickens);

/* draws player and ducks on screen */
void draw_game(player_data &player, vector<chicken_data> &chickens, game_data &game);

/* combines whole game in one statement to be used in main */
game_data new_game();

/* load the game images, sounds, etc. */
void load_resources();

/* handles time remaining till end of game */
void update_time(player_data &player);

/* draws game over and displays score */
void game_over(game_data &game);

#endif