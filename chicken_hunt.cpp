#include "splashkit.h"
#include "chicken_hunt.h"
#include "chicken.h"
#include <vector>
#include <iostream>

using std::vector;
using namespace std;

/* load the game images, sounds, etc. */
void load_resources()
{
    load_resource_bundle("game_bundle", "chicken_hunt.txt");
}

/* handles time remaining till end of game */
void update_time(player_data &player)
{
    int count;
    count = current_ticks() / 1000;
    player.time = player.player_time - count;
    if (player.time < 1)
        player.time = 0;
}

/* updates the game */
void update_game(player_data &player, vector<chicken_data> &chickens)
{
    for (int i = 0; i < chickens.size(); i++)
    {
        update_chicken(chickens[i]);
    }
    if (rnd() < CHICKEN_OCCURRENCE)
    {
        chickens.push_back(new_chicken());
    }
    update_player(player);
    check_chicken_collision(player, chickens);
    update_time(player);
}

/* draws and manages the HUD. */
void draw_hud(player_data player)
{
    int shells [6] = {720,680,640,600,560,520};
    //parameters that show score, and time left
    draw_text("SCORE: " + to_string(player.score), COLOR_BLACK, 10,0, option_to_screen());
    draw_text("TIME LEFT: " + to_string(player.time), COLOR_BLACK, 10,10, option_to_screen());
    if (player.bullets == 6)
    {
        for (int i = 0; i < 6; i++)
        draw_bitmap("shell",shells[i],690);
    }
        if (player.bullets == 5)
    {
        for (int i = 0; i < 5; i++)
        draw_bitmap("shell",shells[i],690);
    }
        if (player.bullets == 4)
    {
        for (int i = 0; i < 4; i++)
        draw_bitmap("shell",shells[i],690);
    }
        if (player.bullets == 3)
    {
       for (int i = 0; i < 3; i++)
        draw_bitmap("shell",shells[i],690);
    }
        if (player.bullets == 2)
    {
        for (int i = 0; i < 2; i++)
        draw_bitmap("shell",shells[i],690);
    }
        if (player.bullets == 1)
    {
        for (int i = 0; i < 1; i++)
            draw_bitmap("shell",shells[i],690);
    }
}

/* draws game over and displays score */
void game_over(game_data &game)
{
    draw_text("GAME OVER", COLOR_RED, "Bebedera.ttf", 40, (screen_width() / 2) - 125, (screen_height() / 2) - 80, option_to_screen());
    draw_text("SCORE: " + to_string(game.player.score), COLOR_RED, "Bebedera.ttf", 35, (screen_width() / 2) - 125, (screen_height() / 2) - 20, option_to_screen());
}

/* draws player and chicken */
void draw_game(player_data &player, vector<chicken_data> &chickens,game_data &game)
{
    bitmap background = load_bitmap("field", "field.png");
    draw_bitmap(background, 0,0, option_to_screen());
     if (game.player.time < 1)
    game_over(game);
    else
    {
        for (int i = 0; i < chickens.size(); i++)
        draw_chicken(chickens[i]);
    }
    draw_hud(player);
    draw_player(player);
}

/* loops trough the game */
void game_loop(player_data &player, vector<chicken_data> &chickens,game_data &game)
{
    chicken_data new_c = new_chicken();
    chickens.push_back(new_c);

    while (not quit_requested())
    {
        //Handle input to adjust player movement
        process_events();
        handle_input(player);
        update_game(player, chickens);

        //Redraw everything
        clear_screen(COLOR_WHITE);
        draw_game(player, chickens,game);

        //Refreshes the screen
        refresh_screen(60);
    }
}

/* combines whole game in one statement to be used in main */
game_data new_game()
{
    load_resources();
    game_data game;
    game.player = new_player();
    game_loop(game.player, game.chickens, game);
    return game;
}