/* snake.cpp -------
 *
 * Filename: snake.cpp
 * Description:
 * Author: Adeel Bhutta
 * Maintainer:
 * Created: Sun Sep 13 9:12:30 2022
 * Last-Updated: September 13 22:40 2022
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

#include <cstring>
#include <cstdbool>
#include <cstdlib>
#include "snake.hpp"
#include "key.hpp"
#include <ncurses.h>

#define SNAKE_PAIR 1

// Initialize snake
Snake *init_snake(int x, int y)
{
  Snake *head = create_tail(x, y);
  Snake *tail1 = create_tail(x - 1, y);
  Snake *tail2 = create_tail(x - 2, y);
  tail1->next = tail2;
  head->next = tail1;
  return head;
}

// Creates one tail
Snake *create_tail(int x, int y)
{
  Snake *snake = new Snake;
  snake->color[0] = 0;
  snake->color[1] = 0;
  snake->color[2] = 255;
  /* snake->color = {0, 0, 255}; */
  snake->symbol = '#';
  snake->next = NULL;
  snake->x = x;
  snake->y = y;
  return snake;
}

// Moves the snake in the input direction
Snake *move_snake(Snake *snake, int direction)
{
  // TODO
  Snake *new_head = new Snake;

  // maybe add while(snake) like in other functions below?


  // Set the new head to have the x and y coordinates as the existing head of the snake
  new_head->x = snake->x;
  new_head->y = snake->y;

  switch (direction)
  {
  case UP:
    // Write code to make the new head go up by 1 cell
    if(snake->y + 1 != (snake->next)->y) {
      //new_head->y += direction;
      new_head->y = new_head->y + 1;
    }
    break;
  case DOWN:
    // Write code to make the new head go down by 1 cell
    if(snake->y - 1 != (snake->next)->y) {
      // new_head->y =- direction;
      new_head->y = new_head->y - 1;
    }
    break;
  case RIGHT:
    // Write code to make the new head go right by 1 cell
    if(snake->x + 1 != (snake->next)->x) {
      // new_head->x =+ direction;
      new_head->x = new_head->x + 1;
    }
    break;
  case LEFT:
    // Write code to make the new head go left by 1 cell
    if(snake->x - 1 != (snake->next)->x) {
      // new_head->x =- direction;
      new_head->x = new_head->x - 1;
    }
  break;

  // case NOCHAR:
  //   // checks if moving down
  //   if(snake->y + 1 != (snake->next)->y) {
  //           new_head->y = new_head->y - 1;
  //   }
  //   // checks if moving up
  //   if(snake->y - 1 != (snake->next)->y) {
  //     new_head->y = new_head->y + 1;
  //   }
  //   // checks if moving left
  //   if(snake->x + 1 != (snake->next)->x) {
  //     new_head->x = new_head->x - 1;
  //   }
  //   // checks if moving right
  //   if(snake->x - 1 != (snake->next)->x) {
  //     new_head->x = new_head->x + 1;
  //     }
  //   break;
  }
   
 

  // Set new head as the new head of the entire snake
  // Add all the features (color and symbol) to the new cell
  // Delete the tail from the snake: HINT - there is a remove tail function below
  new_head->next = snake;
  new_head->speed = snake->speed;
  new_head->color[0] = snake->color[0];
  new_head->color[1] = snake->color[1];
  new_head->color[2] = snake->color[2];
  new_head->symbol = snake->symbol;
  remove_tail(new_head);
 
  return new_head;
}

Snake *remove_tail(Snake *snake)
{
  Snake *end = snake;
  while (end->next->next)
    end = end->next;
  free(end->next);
  end->next = NULL;
  return snake;
}

// draws the snake on the board
void draw_snake(Snake *snake)
{
  while (snake)
  {
    start_color();
    init_color(COLOR_GREEN, snake->color[0], snake->color[1], snake->color[2]);
    init_pair(SNAKE_PAIR, COLOR_GREEN, COLOR_BLACK);
    attron(COLOR_PAIR(SNAKE_PAIR));
    mvprintw(snake->y, snake->x, "%c", snake->symbol);
    snake = snake->next;
    attroff(COLOR_PAIR(SNAKE_PAIR));
  }
 
}

// checks if it eats itself, if it does, then return true
bool eat_itself(Snake *snake)
{
  // TODO for Milestone 2 only
}

// Returns the length of a given snake
int len(Snake* snake) {
  int count = 0;
  while(snake) {
    count++;
  }
  return count;
}