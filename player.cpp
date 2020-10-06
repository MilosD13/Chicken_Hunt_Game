#include "player.h"
#include "chicken.h"
#include "splashkit.h"

/* loads all the sounds in the game */
void load_sounds()
{
    load_sound_effect("shot", "shot_f.wav");
    load_sound_effect("empty", "empty.wav");
    load_sound_effect("reload", "reload_f.wav");
}

/* game data contains player data and vector of chickens */
player_data new_player()
{
    load_sounds();
    player_data result;
    bitmap default_bitmap = bitmap_named("aim");

    // on the ship kind selected
    result.player_sprite = create_sprite(default_bitmap);

    // Default score & bullets
    result.bullets =     STARTING_BULLETS;
    result.score =       STARTING_SCORE;
    result.player_time = STARTING_TIME;
    return result;
}

/* draws a player */
void draw_player(const player_data &player_to_draw)
{
    draw_sprite(player_to_draw.player_sprite);
}

/* updates movement of the player */
void update_player(player_data &player_to_update)
{
    update_sprite(player_to_update.player_sprite);
}

/* read user input and update the player based on this interaction. */
void handle_input(player_data &player)
{
    void load_sounds();
    point_2d new_point = mouse_position();
    new_point.x = new_point.x - (sprite_width(player.player_sprite)/2);
    new_point.y = new_point.y - (sprite_height(player.player_sprite)/2);
    sprite_set_position(player.player_sprite, new_point);
    if (mouse_clicked(LEFT_BUTTON))
        player.bullets -= 1;
    if (mouse_clicked(LEFT_BUTTON) && player.bullets >= 0)
        play_sound_effect("shot");
    if (mouse_clicked(LEFT_BUTTON) && player.bullets < 0)
        play_sound_effect("empty");
    if (mouse_clicked(RIGHT_BUTTON))
    {
        play_sound_effect("reload");
        player.bullets = 6;
    }
}

