
#include <cstdlib>
#include <ncurses.h>
#include "grid.hpp"
using namespace std;


grid *init_grid(int upper_left_x, int upper_left_y, int width, int height)
{
	grid *g;
	g = (grid *) malloc(sizeof(grid));
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


grid *init_grid(int upper_left_x, int upper_left_y, int width, int height)
{
	grid *g;
	g = (grid *) malloc(sizeof(grid));
	g->upper_left_x = upper_left_x;
	g->upper_left_y = upper_left_y;
	g->width = width;
	g->height = height;
	g->draw_char = '#';
}




void draw_grid(grid *r)
{
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
}