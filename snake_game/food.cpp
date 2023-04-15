/*food.cpp -------
*
* Filename: food.cpp
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

#include <cstdlib>
#include <ncurses.h>
#include <cstdbool>
#include "food.hpp"


//Create new food
Food* create_food(int x, int y, enum Type type){
    Food* new_food = (Food*)malloc(sizeof(Food));
     
    new_food->x = x;
    new_food->y = y;

    if (type == Increase){
        new_food->type = 'O';
    }
    else if(type == Decrease){
        new_food->type = 'X';
    }
    else if(type == Increase1) {
        new_food->type = '+';
    }
    else if(type == Increase2){
        new_food->type = '-';
    }
    new_food->next = NULL;

    return new_food;
}

//Check if food exists at coordinates
bool food_exists(Food* foods, int x, int y){
    Food* temp = foods;
    while(temp){
        if(temp->x == x && temp->y == y)
            return true;
        temp = temp->next;
    }
    return false;
}

//Add new food to end of food list
void add_new_food(Food* foods, Food* new_food){
    Food* temp = foods;
    while(temp->next) {
        temp = temp->next;
    }
    temp->next = new_food;
}

enum Type food_type(Food* foods, int x, int y) {
    //Implement the code to return the type of the food
    //present at position (x, y)
    Food* temp = foods;
    int count = 0;

    while(temp != NULL) {
        if(temp->x == x && temp->y == y) {

            if(temp->type == 'O') {
                return Increase;
                //mvprintw(14, 5, "Score: ", count + 20);
            }
            else if(temp->type == 'X') {
                return Decrease;
                //mvprintw(16, 5, "Score: ", count - 10);
            }
            else if(temp->type == '+') {
                return Increase1;
            }
            else if(temp->type == '-'){
                return Increase2;
            }       
        }
        temp = temp->next;
    }

    return Increase;
}

// foods: f1 f2 f3 f4 f5 f6 NULL
// temp: f1 f2 f3 f4 f5 f6 NULL
// remove f3
// new_foods: f1 f2 f4 f5 f6 NULL

Food* remove_eaten_food(Food* foods, int x, int y) {
    //Implement the code to remove food at position (x,y).
    //Create a new linked list of type Food containing only the
    //needed food and return this new list
    Food* curr = foods;
    Food* prev = NULL;

    while(curr != NULL) {
        if(curr->x == x && curr->y == y) {
            if(!prev) {
                foods = curr->next;
            }
            else {
                prev->next = curr->next;
            }
        free(curr);
        }
    prev = curr;
    curr = curr->next;
    }
    return foods;
}
// Display all the food
void draw_food (Food *foods)
{   Food* temp = foods;
    start_color();
    init_pair(3, COLOR_CYAN, COLOR_BLACK);
    init_pair(4, COLOR_RED, COLOR_BLACK);

    // if(foods->type == Increase) {
        attron(COLOR_PAIR(3));
    // }
    // else if(foods->type == Decrease) {
        // attron(COLOR_PAIR(4));
    // }

    while(temp) {
        mvprintw(temp->y, temp->x, "%c", temp->type);
        temp = temp->next;
    }
    attroff(COLOR_PAIR(3)); 
    attroff(COLOR_PAIR(4)); 

}

// ---- OBSTACLE SECTION ----

// creating obstacles

Obstacle* create_ob(int x1, int y1, enum Type1 type1){
    Obstacle* new_obs = (Obstacle*)malloc(sizeof(Obstacle));
     
    new_obs->x1 = x1;

    if (type1 == WillDie){
        new_obs->type1 = '|';
    }
    new_obs->next = NULL;

    return new_obs;
}

// checking if obstacle exists

bool ob_exists(Obstacle* obstacles, int x1, int y1){
    Obstacle* temp1 = obstacles;
    while(temp1){
        if(temp1->x1 == x1 && temp1->y1 == y1)
            return true;
        temp1 = temp1->next;
    }
    return false;
}

// adds obstacles

void add_ob(Obstacle* obstacles, Obstacle* new_obs) {
    Obstacle* temp1 = obstacles;
    while(temp1->next) {
        temp1 = temp1->next;
    }
    temp1->next = new_obs;
    
}

// remove obstacles

Obstacle* remove_ob(Obstacle* obstacles, int x1, int y1) {
    //Implement the code to remove food at position (x,y).
    //Create a new linked list of type Food containing only the
    //needed food and return this new list
    Obstacle* curr1 = obstacles;
    Obstacle* prev1 = NULL;

    while(curr1 != NULL) {
        if(curr1->x1 == x1 && curr1->y1 == y1) {
            if(!prev1) {
                obstacles = curr1->next;
            }
            else {
                prev1->next = curr1->next;
            }
        free(curr1);
        }
    prev1 = curr1;
    curr1 = curr1->next;
    }
    return obstacles;
}

// draws the obstacles

void draw_ob (Obstacle *obstacles)
{   Obstacle* temp1 = obstacles;
    while(temp1) {
        mvprintw(temp1->y1, temp1->x1, "%c", temp1->type1);
        temp1 = temp1->next;
    }
}