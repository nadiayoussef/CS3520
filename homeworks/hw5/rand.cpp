#include <ncurses.h>
#include <cstdlib>
#include "rand.hpp"

int roll() const { return 1 + rand() % 5; }

int get_rand() {

    int r = roll();
    
    if (r == ERR)
    {
        return NOCHAR;
    }
    switch (r)
    {
        case 1:
            return LEFT;
            break;
        case 2:
            return RIGHT;
            break;
        case 3:
            return UP;
            break;
        case 4:
            return DOWN;
            break;
        case 5:
            return STOP;
            break;
        default:
            return NOCHAR;
            break;
    }

    return NOCHAR;
}
