/* game_window.cpp -------
 *
 * Filename: game_window.cpp
 * Description:
 * Author: Adeel Bhutta
 * Maintainer:
 * Created: Tue Sep  6 14:10:06 2022
 * Last-Updated: June 4 11:00 2022
 * Keywords:
 * Compatibility:
 *
 */

/* Commentary:
 *
 *
 *
 */

/* Change log:
 *
 *
 */

/* Copyright (c) 2022 Adeel Bhutta
 *
 * All rights reserved.
 *
 * Additional copyrights may follow
 */

/* Code: */
#include <iostream>
#include <cstdlib>
#include <ncurses.h>
#include "game_window.hpp"

gamewindow_t *init_GameWindow(int upper_left_x, int upper_left_y, int width, int height)
{
    gamewindow_t *g;
    g = (gamewindow_t *) malloc(sizeof(gamewindow_t));
    g->upper_left_x = upper_left_x;
    g->upper_left_y = upper_left_y;
    g->width = width;
    g->height = height;
    g->draw_char = '*';
    g->color[0] = 0;
    g->color[1] = 0;
    g->color[2] = 255;
    return (g);
}

void draw_Gamewindow(gamewindow_t *r)
{
    start_color();
    init_pair(2, COLOR_MAGENTA, COLOR_BLACK);
    attron(COLOR_PAIR(2));
    int row_counter, column_counter;

    // Draw Top of room
    for (row_counter = r->upper_left_x;
         row_counter <= (r->upper_left_x + r->width);
         row_counter++) {
        mvprintw(r->upper_left_y, row_counter, "%c", r->draw_char);
    }

    // Draw left side of room
    for (column_counter = r->upper_left_y;
         column_counter <= (r->upper_left_y + r->height);
         column_counter++) {
        mvprintw(column_counter, r->upper_left_x, "%c", r->draw_char);
    }

    // Draw right side of room
    for (column_counter = r->upper_left_y;
         column_counter <= (r->upper_left_y + r->height);
         column_counter++) {
        mvprintw(column_counter, (r->upper_left_x + r->width), "%c", r->draw_char);
    }

    // Draw Bottom of room
    for (row_counter = r->upper_left_x;
         row_counter <= (r->upper_left_x + r->width);
         row_counter++) {
        mvprintw(r->upper_left_y + r->height, row_counter, "%c", r->draw_char);
    }
    attroff(COLOR_PAIR(2));

}

// welcome window with directions

void draw_Welcomewindow(gamewindow_t *w) {

    char message[] = "Welcome to the Snake Game!\nThe mission is to move the snake with the arrow keys to eat the good food that grows it.\n"
                     "Try to avoid eating the food the shrinks " \
                     "its size.\nIf the snake is shrinks too much, touches the walls, or eats itself, the snake dies and game ends.\n\n             Press S to start!";
   
    mvprintw(w->height/2, w->width/2, "%s", message);
    // int ch;
    // ch = getch();
    // initscr();  
    // cbreak();
    // keypad(stdscr, TRUE);    

// press f1 to change game window and start game

    // if((ch = getch()) != KEY_F(1)) {
    //  changeGameWindow(w->width, w->height, w->upper_left_x, w->upper_left_y, w);
    // }
    // endwin();
}

void draw_Pausewindow(gamewindow_t *w) {
    char message[] = "Game paused.\nPress p again to resume.";
    mvprintw(w->height/2, w->width/2, "%s", message);
  
}

// end window 

void draw_Endwindow(gamewindow_t *w) {
    char message[] = "Game ended! You quit :(";
    mvprintw(w->height/2, w->width/2, "%s", message);
}

gamewindow_t *changeGameWindow(int upper_left_x, int upper_left_y, int width, int height, gamewindow_t *r)
{
    r->upper_left_x = upper_left_x;
    r->upper_left_y = upper_left_y;

    if (width < 10)
        r->width = 10;
    else
        r->width = width;

    if (height < 10)
        r->height = 10;
    else
        r->height = height;

    return (r);
}

void undraw_Gamewindow(gamewindow_t *r)
{
    int row_counter, column_counter;

    // Undraw Top of room
    for (row_counter = r->upper_left_x;
         row_counter <= (r->upper_left_x + r->width);
         row_counter++) {
        mvprintw(r->upper_left_y, row_counter, " ");
    }

    // Undraw left side of room
    for (column_counter = r->upper_left_y;
         column_counter<=(r->upper_left_y + r->height);
         column_counter++) {
        mvprintw(column_counter, r->upper_left_x, " ");
    }

    // Undraw right side of room
    for (column_counter = r->upper_left_y;
         column_counter <= (r->upper_left_y + r->height);
         column_counter++) {
        mvprintw(column_counter, (r->upper_left_x + r->width), " ");
    }

    // Undraw Bottom of room
    for (row_counter = r->upper_left_x;
         row_counter <= (r->upper_left_x + r->width);
         row_counter++) {
        mvprintw(r->upper_left_y + r->height, row_counter, " ");
    }
}
/* room.c ends here */