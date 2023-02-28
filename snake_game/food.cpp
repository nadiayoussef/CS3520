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

    while(temp != NULL) {
        if(temp->x == x && temp->y == y) {

            if(temp->type == 'O') {
                return Increase;
            }
            else if(temp->type == 'X') {
                return Decrease;
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
    while(temp) {
        mvprintw(temp->y, temp->x, "%c", temp->type);
        temp = temp->next;
    }
}