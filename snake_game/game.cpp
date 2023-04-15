/*game.cpp -------
*
* Filename: game.cpp
* Description:
* Author: Adeel Bhutta
* Maintainer:
* Created: Sat Sep 12 13:16:12 2022
* Last-Updated: September 12 16:51 2022
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

/*Copyright (c) 2022 Adeel Bhutta
*
* All rights reserved.
*
* Additional copyrights may follow
*/
#include <ncurses.h>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "snake.hpp"
#include "food.hpp"
#include "game_window.hpp"
#include "key.hpp"
#include "game.hpp"
void generate_points(int *food_x, int *food_y, int width, int height, int x_offset, int y_offset){
    *food_x = rand() % width + x_offset;
    *food_y = rand() % height + y_offset;
}

void game() {

    enum State state = INIT; // Set the initial state
    static int x_max, y_max; //Max screen size variables
    static int x_offset, y_offset; // distance between the top left corner of your screen and the start of the board
    gamewindow_t *window; // Name of the board
    Snake *snake; // The snake
    Food *foods,*new_food; // List of foods (Not an array)
    Obstacle *obstacles, *new_obs;

    // scoreboard

    // static int getFoodCount(vector<Snake> &snake, Food *foods) {
    //     int count = 0;
    //     for (int i=0; i < snake.size(); i++) {
    //         if (snake[i]->get_char() == Increase) {
    //             count + 20;
    //             } else {
    //                 count - 10;
    //                 }
    //                 return count;
    //     }
    // }


    const int height = 30;
    const int width = 70;
    char ch;
    int init_dir;

    struct timespec timeret;
    timeret.tv_sec = 0;
    timeret.tv_nsec = 999999999/4;

    int scoreboard = 0;

    while(state != EXIT){
        switch(state){
            case INIT:
                initscr();
                start_color();
                nodelay(stdscr, TRUE); //Dont wait for char
                noecho(); // Don't echo input chars
                getmaxyx(stdscr, y_max, x_max);
                keypad(stdscr, TRUE); // making keys work
                curs_set(0); // hide cursor
                timeout(100);

                // Setting height and width of the board
                x_offset = (x_max / 2) - (width / 2);
                y_offset = (y_max / 2) - (height / 2);
            
                //Init board
                window = init_GameWindow(x_offset, y_offset, width, height);
                draw_Welcomewindow(window);
            // draw_Gamewindow(window);

                // Init snake
                snake = init_snake(x_offset + (width / 2), y_offset + (height / 2));
                init_dir = RIGHT;
                //snake = move_snake(snake, direction);
            
                // Init foods
                int food_x, food_y, food_w, food_z, i; // extra foods created, maybe not needed here
                enum Type type;
                enum Type1 type1;

            //Generate 20 foods
            generate_points(&food_x, &food_y, width, height, x_offset, y_offset);
            type = (rand() > RAND_MAX/2) ? Increase : Decrease; // Randomly deciding type of food
            foods = create_food(food_x, food_y, type);
            for(i = 1; i < 20; i++){
                generate_points(&food_x, &food_y, width, height, x_offset, y_offset);
                while (food_exists(foods,food_x, food_y))
                    generate_points(&food_x, &food_y, width, height, x_offset, y_offset);
                type = (rand() > RAND_MAX/2) ? Increase : Decrease;
                new_food = create_food(food_x, food_y, type);
                add_new_food(foods, new_food);
            }
                //}

                // Checks if 's' key was entered
                // If so, starts the game

                // beginner game
                ch = get_char();
                if(ch == 's') {
                    state = ALIVE;
                }

                // hard game
                if(ch == 'h') {
                    state = ALIVEHARD;
                }

                // advanced game
                if(ch == 'a') {
                    state = ALIVEADVANCED;
                }

                break;

            case ALIVE:
                ch = get_char();


                // while or if(ch != LEFT, RIGHT, UP, DOWN) {
                //     move_snake(snake, RIGHT);
                // }

                //snake = move_snake(snake, LEFT);
                /* Write your code here */
                // Moving the


                // snake should automatically move 
                // snake should move in random left or right direction
                // put code for randomizer whether it is left or right 
                // have a loop and snake should start moving one step at a time
                // have a counter so snake can move to a maximum of half width
                // until arrow keys are pressed, snake moves in one direction
                // speed of snake, need to put a timer which controls its speed
                // timer says let the snake move x amount of time per second - init speed
                // then increase by 1.5 after 100 points achieved, will have to reduce the
                // timer so snake moves faster 


                // Draw everything on the screen
                clear();
                mvprintw(20,20, "Key entered: %c", ch);
                draw_Gamewindow(window);
                draw_snake(snake);
                draw_food(foods);
                //move_snake(snake, (rand() > RAND_MAX/2) ? RIGHT : LEFT);

                //mvprintw(40, 40, "points: "); 
                if(ch == RIGHT && init_dir != LEFT) {
                    snake = move_snake(snake, RIGHT);
                    init_dir = RIGHT;
                }
                if(ch == LEFT && init_dir != RIGHT) {
                    snake = move_snake(snake, LEFT);
                    init_dir = LEFT;
                }
                if(ch == UP && init_dir != DOWN) {
                    snake = move_snake(snake, DOWN);
                    init_dir = UP;
                }
                if(ch == DOWN && init_dir != UP) {
                    snake = move_snake(snake, UP);
                    init_dir = DOWN;
                }
                if(ch == NOCHAR) {
                    snake = move_snake(snake, NOCHAR);
                }

                if(food_exists(foods, snake->x, snake->y)) {
                    
                    //increases or decreases snake length
                    if(food_type(foods, snake->x, snake->y) == Increase) { // add Inc1, Inc2
                        // Snake* inc = create_tail(snake->x, snake->y);
                        // inc->next = snake;
                        // snake = inc;
                        add_tail(snake);
                        scoreboard = scoreboard + 20;
                    }
                    else if(food_type(foods, snake->x, snake->y) == Decrease) {
                        snake = remove_tail(snake);
                        scoreboard = scoreboard - 10;
                    }

                    // removes the eaten food
                    foods = remove_eaten_food(foods, snake->x, snake->y);
                    //add_new_food(foods, new_food);

                    //creates and adds a new food
                    generate_points(&food_x, &food_y, width, height, x_offset, y_offset);
                    while (food_exists(foods,food_x, food_y))
                        generate_points(&food_x, &food_y, width, height, x_offset, y_offset);
                    type = (rand() > RAND_MAX/2) ? Increase : Decrease;
                    //type = (rand() > RAND_MAX/2) ? Increase1 : Increase2;
                    new_food = create_food(food_x, food_y, type);
                    add_new_food(foods, new_food);
                }

                if(ch == 'q') {
                    state = DEAD; // was state = EXIT but wanted to test DEAD
                }
                if(ch == 'p') {
                    state = PAUSE;
                }
                if(scoreboard >= 100 && scoreboard % 100==0) {
                    timeret.tv_nsec = timeret.tv_nsec * 1.5;
                }
            
                mvprintw(8, 6, "Score: %d ", scoreboard);
                refresh();
                break;

            case DEAD:
            clear();
                draw_Endwindow(window); // has to be used when game over occurs
                break;

            case PAUSE:
            clear();
                draw_Pausewindow(window);
                refresh();
                while(1) {
                    if(getch() == 'p') {
                        state = ALIVE;
                        break;
                    }
                }
                break;
        }

        // mvprintw(8, 6, "Score: %d ", scoreboard);
        refresh();
        nanosleep(&timeret, NULL);

    }
}