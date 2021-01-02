#include "splashkit.h"
#include "player.h"
#include "chicken.h"

/**
 * The chicken bitmap function converts a chicken kind into a
 * bitmap that can be used.
 *
 *
 * @param kind  The kind of chicken you want the bitmap of
 * @return      The bitmap matching this chicken kind
 */
bitmap chicken_bitmap(chicken_kind kind)
{
    switch (kind)
    {
    case S_CHICKEN:
        return bitmap_named("ani_chicken_s");
    case L_CHICKEN:
        return bitmap_named("ani_chicken");
    default:
        return bitmap_named("ani_chicken_l");
    }
}

/* creates a chicken at x y positon of the screen with random movement speed */
chicken_data new_chicken()
{
    chicken_data result;
    // Defines random bitmap
    result.kind = static_cast<chicken_kind>(rnd(0, 3));

    // Create random sprite and random speed for it
    if (result.kind == 2)
    {
        result.chicken_sprite = create_sprite("ani_chicken", "chicken");
        sprite_start_animation(result.chicken_sprite, 0);
        sprite_set_dx(result.chicken_sprite, rnd() * 4 + 2);
    }
    else if (result.kind == 0)
    {
        result.chicken_sprite = create_sprite("ani_chicken_s", "chicken_s");
        sprite_start_animation(result.chicken_sprite, 0);
        sprite_set_dx(result.chicken_sprite, rnd() * 4 + 2);
    }
    else
    {
        result.chicken_sprite = create_sprite("ani_chicken_l", "chicken_l");
        sprite_start_animation(result.chicken_sprite, 0);
        sprite_set_dx(result.chicken_sprite, rnd() * 4 + 2);
    }
    float random_x = rnd(-20, -10);
    float random_y = rand() % 500;
    sprite_set_x(result.chicken_sprite, random_x);
    sprite_set_y(result.chicken_sprite, random_y);

    return result;
}

/* draws the chicken to the screen. */
void draw_chicken(const chicken_data &chicken_to_draw)
{
    draw_sprite(chicken_to_draw.chicken_sprite);
}

/* applies update movements of our chicken */
void update_chicken(chicken_data &chicken_to_update)
{
    // Applies update movements of our power
    update_sprite(chicken_to_update.chicken_sprite);
}

//applies power to the user when colided with user
void apply_chicken_collision(chicken_data &chickens, player_data &player)
{
    switch (chickens.kind)
    {
    case S_CHICKEN:
        player.score += S_CHICKEN_ADD_SCORE;
        break;
    case L_CHICKEN:
        player.score += L_CHICKEN_ADD_SCORE;
        break;
    case M_CHICKEN:
        player.score += M_CHICKEN_ADD_SCORE;
        break;
    }
}

/* checks for colision between player and chicken */
void check_chicken_collision(player_data &player, vector<chicken_data> &chickens)
{
    for (int i = 0; i < chickens.size(); i++)
    {
        if (sprite_collision(chickens[i].chicken_sprite, player.player_sprite) && mouse_clicked(LEFT_BUTTON) && player.bullets > 0)
        {
            sprite_set_dx(chickens[i].chicken_sprite, 0);
            apply_chicken_collision(chickens[i], player);
            chickens.erase(chickens.begin() + i);
        }
    }
}