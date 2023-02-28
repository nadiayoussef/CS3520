#include <iostream>
using namespace std;

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

//Two types of food
//Either Increase or Decrease length of snake
enum Type {Increase, Decrease}; 

//Structure to hold properties of food
struct Food {
  int x;
  int y;
  char type;
  struct Food* next;
};

typedef struct Food Food;

//Function prototypes 
void add_new_food(Food* foods, Food* new_food);
bool food_exists(Food* foods, int x, int y);
Food* create_food(int x, int y, enum Type type);
enum Type food_type(Food* foods, int x, int y);
Food* remove_eaten_food(Food* foods, int x, int y);
void draw_food(Food *food);


#include <cstdlib>
#include <ncurses.h>
#include <cstdbool>


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
    char c_type;
    Type t;
    Food* temp = foods;

    while(temp != NULL) {
        if(temp->x == x && temp->y == y) {
            c_type = temp->type;
            break;
        }
        temp = temp->next;
    }

    if(c_type == 'O') {
        t = Increase;
    }
    else if(c_type == 'X') {
        t = Decrease;
    }

    return t;
}
// foods: f1 f2 f3 f4 f5 f6 NULL
// temp: f1 f2 f3 f4 f5 f6 NULL
// remove f3
// new_foods: f1 f2 f4 f5 f6 NULL
/**/
Food* remove_eaten_food(Food* foods, int x, int y) {
    //Implement the code to remove food at position (x,y).
    //Create a new linked list of type Food containing only the
    //needed food and return this new list
    Food* temp = foods;
    Food* new_foods;

    while(temp != NULL) {
        if(food_exists(temp, x, y)) {
            add_new_food(new_foods, temp->next);
            temp = (temp->next)->next;
        }
        else {
            add_new_food(new_foods, temp);
            temp = temp->next;
        }
    }

    // while(temp != NULL) {
    //     if(food_exists(temp, x, y)) {
    //         temp = temp->next;
    //         while(temp->next != NULL){
    //             temp->next = (temp->next)->next;
    //         }
    //     }
    // }
    
    return new_foods;

}

/*
Food* remove_eaten_food(Food* foods, int x, int y)
{
  Food* temp;
  Food* prev;
  temp = *foods;
  prev = *foods;

  while (temp != NULL) {
    if (food_exists(temp, x, y)) {
      *foods = (*foods)->next;
      free(temp);
    }
    else {
      if (i == position - 1 && temp) {
        prev->next = temp->next;
        free(temp);
      }
      else {
        prev = temp;
 
        // Position was greater than
        // number of nodes in the list
        if (prev == NULL)
          break;
        temp = temp->next;
      }
    }
  }

  return foods;
}
*/






// Display all the food
void draw_food (Food *foods)
{   Food* temp = foods;
    while(temp) {
        mvprintw(temp->y, temp->x, "%c", temp->type);
        temp = temp->next;
    }
}


int main(void) {
    struct Food* foods;
    foods = create_food(3, 3, Increase);
    struct Food* new_food;
    for(int i = 4; i < 8; i++) {
        new_food = create_food(i, i, Increase);
        add_new_food(foods, new_food);
    }
    Type t = food_type(foods, 4, 4);
    if(t == Increase) {
        cout << "increase" << endl;
    }
    else {
        cout << "decrease" << endl;
    }

    if(food_exists(foods, 4, 4)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

    new_food = create_food(10, 10, Decrease);
    add_new_food(foods, new_food);
    t = food_type(foods, 10, 10);
    if(t == Increase) {
        cout << "increase" << endl;
    }
    else if (t == Decrease) {
        cout << "decrease" << endl;
    }



    // // cout << food_exists(foods, 4, 4);
    //foods = remove_eaten_food(foods, 4, 4);
    // // cout << food_exists(foods, 4, 4);

    // if(food_exists(foods, 4, 4)) {
    //     cout << "true" << endl;
    // }
    // else {
    //     cout << "false" << endl;
    // }

    
}