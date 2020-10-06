#include "splashkit.h"
#include "chicken_hunt.h"
#include "chicken.h"
#include "player.h"

/**
 * Entry point.
 * Manages the initialisation of data, the event loop, and quitting.
 */
int main()
{
    open_window("Chicken Hunt", 800, 800);
    new_game();

    return 0;
}