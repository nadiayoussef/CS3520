// #include <ncurses.h>

#define GRID_WIDTH 100
#define GRID_HEIGHT 100


struct grid
{
  int upper_left_x;
  int upper_left_y;
  int width;
  int height;
  char draw_char;
};

typedef struct grid grid;

grid *init_grid(int, int, int, int);

void draw_grid(grid *);