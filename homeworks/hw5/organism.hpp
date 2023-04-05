#include <iostream>
#include <ncurses.h>
#include <vector>
using namespace std;

static int x_max, y_max, x_offset, y_offset;
const int width = 100;
const int height = 100;

class Organism {
    private:
    char type;
    //position
    int x;
    int y;

    public:
    // Constructors
    Organism();
    Organism(int x, int y);
    // Setters
    void set_type(char t);
    void set_x(int x);
    void set_y(int y);
    // Gettrs
    char get_type();
    int get_x();
    int get_y();

    int time_step;
    int move_step;

    virtual void move(vector<Organism*> &orgs, int dir);
    virtual void draw(int x, int y);
    Organism breed(vector<Organism*> &orgs);
    virtual void time_stepFunc(vector<Organism*> &orgs);
    static int exists (vector<Organism *> &orgs, int x, int y);

    
};



class Queen : public Organism {
    public:
    int queen_step;
    int breed_step;
    // Constructors
    Queen();
    Queen(int x, int y);

    void create(vector<Organism *> &orgs);
    void init_queen(int i, vector<Organism *> &orgs);
    void breed(vector<Organism *> &orgs);
    void spawn_queen(vector<Organism *> &orgs);
    void time_stepFunc(vector<Organism *> &orgs);

};

class Female : public Organism {

    void create(vector<Organism *> &orgs);
    void init_female(int i, vector<Organism *> &orgs);
    void breed(vector<Organism *> &orgs);
    void spawn_female(vector<Organism *> &orgs);
    void time_stepFunc(vector<Organism *> &orgs);

};

class Male : public Organism {

    void create(vector<Organism *> &orgs);
    void init_male(int i, vector<Organism *> &orgs);
    void breed(vector<Organism *> &orgs);
    void spawn_male(vector<Organism *> &orgs);
    void time_stepFunc(vector<Organism *> &orgs);

};

class Doodlebug : public Organism {

    void create(vector<Organism *> &orgs);
    void init_doodlebug(int i, vector<Organism *> &orgs);
    void breed(vector<Organism *> &orgs);
    void spawn_doodlebug(vector<Organism *> &orgs);
    void time_stepFunc(vector<Organism *> &orgs);

};