/*food.hpp -------
*
* Filename: food.hpp
* Description:
* Author: Adeel Bhutta
* Maintainer:
* Created: Sat Sep 12 13:21:55 2022
* Last-Updated: September 12 16:01 2022
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
#include <vector>

//4 types of food
//Either Increase or Decrease length of snake
enum Type {Increase, Decrease, Increase1, Increase2}; 
enum Type1 {WillDie};

//Structure to hold properties of food
struct Food {
  int x;
  int y;
  char type;
  struct Food* next;
};

struct Obstacle {
  int x1;
  int y1;
  char type1;
  struct Obstacle* next;
};

typedef struct Food Food; 

//Function prototypes 
void add_new_food(Food* foods, Food* new_food);
bool food_exists(Food* foods, int x, int y);
Food* create_food(int x, int y, enum Type type);
enum Type food_type(Food* foods, int x, int y);
Food* remove_eaten_food(Food* foods, int x, int y);
void draw_food(Food *food);

void add_ob(Obstacle* obstacles, Obstacle* new_obs);
bool ob_exists(Obstacle* obstacles, int x1, int y1);
Obstacle* create_ob(int x1, int y2, Type1 type1); // maybe not accessing right Type
Obstacle* remove_ob(Obstacle* obstacles, int x1, int y1);
void draw_ob(Obstacle *obstacle);
//static int getFoodCount (vector<Food *> &Food, Type type);
