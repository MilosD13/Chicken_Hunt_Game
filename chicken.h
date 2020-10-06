#ifndef CHICKEN_HUNT_CHICKEN
#define CHICKEN_HUNT_CHICKEN
#include "splashkit.h"
#include "player.h"
#include <vector>

using namespace std;

#define S_CHICKEN_ADD_SCORE          100
#define M_CHICKEN_ADD_SCORE          50
#define L_CHICKEN_ADD_SCORE          10
#define CHICKEN_COUNTER              200

/**
 * Different options for the kind of chicken.
 * Adjusts the image used.
 */
enum chicken_kind
{
    S_CHICKEN,
    M_CHICKEN,
    L_CHICKEN
};

/**
 * The chicken data keeps track of all of the information related to the chicken.
 *
 * @field   chicken_sprite  The chicken's sprite - used to track position and movement
 * @field   kind            Option of diferent chickens
 * @field   chicken_speed   Speed of chicken
 */
struct chicken_data
{
    sprite          chicken_sprite;
    chicken_kind    kind;
    int             chicken_speed;
};

/**
 * The chicken bitmap function converts a chicken kind into a
 * bitmap that can be used.
 *
 *
 * @param kind  The kind of chicken you want the bitmap of
 * @return      The bitmap matching this chicken kind
 */
bitmap chicken_bitmap(chicken_kind kind);

/* creates a chicken at x y positon of the screen with random movement speed */
chicken_data new_chicken();

/* draws the chicken to the screen. */
void draw_chicken(const chicken_data &chicken_to_draw);

/* applies update movements of our chicken */
void update_chicken(chicken_data &chicken_to_update);

/* checks for colision between player and chicken */
void check_chicken_collision(player_data &player, vector<chicken_data> &chickens);

#endif