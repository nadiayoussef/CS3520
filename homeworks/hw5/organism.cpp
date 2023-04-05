#include <iostream>
#include <ncurses.h>
#include "organism.hpp"
using namespace std;


Organism::Organism() {
    x = 0;
    y = 0;
    time_step = 0;
    move_step = 0;
}

Organism::Organism(int x, int y) {
    this->x = x;
    this->y = y;
    this->time_step = 0;
    this->move_step = 0;
}

void Organism::set_type(char t) {
    this->type = t;
}

void Organism::set_x(int x) {
    this->x = x;
}

void Organism::set_y(int y) {
    this->y = y;
}

char Organism::get_type() {
    return this->type;
}

int Organism::get_x() {
    return this->x;
}

int Organism::get_y() {
    return this->y;
}



void Organism::draw(int x_offset, int y_offset) {
    
    mvprintw(this->get_y() + y_offset, this->get_x() + x_offset, "%c", this->get_type());
  

}

void Organism::move(vector<Organism *> &orgs, int dir) {

    int x = this->get_x();
    int y = this->get_y();

    switch(dir) {

        case UP:
        if(this->get_y() - 1 == 0) {
            y = this->get_y() + 1;
        }
        else {
            y = this->get_y() - 1;
        }
        break;

        case DOWN:
        if(this->get_y() + 1 == height) {
            y = this->get_y() - 1;
        }
        else {
            y = this->get_y() + 1;
        }
        break;

        case RIGHT:
        if(this->get_x() + 1 == width) {
            x = this->get_x() - 1;
        }
        else {
            x = this->get_x() + 1;
        }
        break;

        case LEFT:
        if(this->get_x() - 1 == 0) {
            x = this->get_x() + 1;
        } 
        else {
            x = this->get_x() - 1;
        }
        break;

        case TOPLEFT:
        if (this->get_y() - 1 == 0) {
            if (this->get_x() - 1 <= 1) {
            } else {
                x = this->get_x() - 2;
            }
        } else if (this->get_x() - 1 == 0) {
            if (this->get_y() - 1 <= 1) {
            } else {
                y = this->get_y() - 2;
            }
        } else {
            x = this->get_x() - 1;
            y = this->get_y() - 1;
        }
        break;

        case TOPRIGHT:
        if (this->get_y() - 1 == 0) {
            if (this->get_x() + 1 >= width - 1) {
            } else {
                x = this->get_x() + 2;
            }
        } else if (this->get_x() + 1 == width) {
            if (this->get_y() - 1 <= 1) {
            } 
            else {
                y = this->get_y() - 2;
            }
        } else {
            x = this->get_x() + 1;
            y = this->get_y() - 1;
        }
        break;

        case BOTTOMRIGHT:
        if (this->get_y() + 1 == height) {
            if (this->get_x() + 1 >= width - 1) {
            } else {
                x = this->get_x() + 2;
            }
        } else if (this->get_x() + 1 == width) {
            if (this->get_y() + 1 >= height - 1) {
            } else {
                y = this->get_y() + 2;
            }
        } else {
            x = this->get_x() + 1;
            y = this->get_y() + 1;
        }
        break;

        case BOTTOMLEFT:
        if (this->get_y() + 1 == height) {
            if (this->get_x() - 1 <= 1) {
            } else {
                x = this->get_x() - 2;
            }
        } else if (this->get_x() - 1 == 0) {
            if (this->get_y() + 1 >= height - 1) {
            } else {
                y = this->get_y() + 2;
            }
        } else {
            x = this->get_x() - 1;
            y = this->get_y() + 1;
        }
        break;
    }

    if (exist(orgs, x, y) == -1) {
        this->set_x(x);
        this->set_y(y);
        this->move_step = this->time_step;
    }



    return;

}

void Organism::time_stepFunc(vector<Organism *> &orgs) {}

Queen::Queen() : Organism() {}

Queen::Queen(int x, int y) : Organism() {
    this->set_x(x);
    this->set_y(y);
    this->set_char('Q');
    this->breed_step = 0;
    this->queen_step = 0;
    this->time_step = 0;
    this->move_step = 0;
}

void Queen::create(vector<Organism *> &orgs) {

    int count = 0;

    for (int i = this->get_x() - 1;  i <= this->get_x() + 1; i++ ) {
        for (int j = this->get_y() - 1;  j <= this->get_y() + 1; j++ ) {
            if (i > 0 && i < width && j > 0 && j < height) {
                if (exist(orgs, i, j) == -1) {
                    Female *female9 = new Female(i, j);
                    orgs.push_back(female9);
                    count++;
                }
            }
        }
    }

    for (int i = this->get_x() - 2;  i <= this->get_x() + 2; i++ ) { // changed to 2
        for (int j = this->get_y() - 2;  j <= this->get_y() + 2; j++ ) {
            if (i > 0 && i < width && j > 0 && j < height) {
                if (exist(orgs, i, j) == -1) {
                    if (count <= 8) {
                        Female *female9 = new Female(i, j);
                        orgs.push_back(female9);
                        count++;
                    }
                    else if (count <= 10) {
                        Male *male9 = new Male(i, j);
                        orgs.push_back(male9);
                        count++;
                    }   
                }
            }
        }
    }

    this->breed_step = this->time_step;
}

void Queen::time_stepFunc(vector<Organism *> &orgs) {
    

    this->time_step++;

    if (this->time_step - this->queen_step >= 25) {
        this->breed(orgs);
    }

    if (this->time_step - this->queen_step >= 35 && this->time_step - this->breed_step == 10) {
        this->spawn_queen(orgs);

    }

    if (this->time_step - this->breed_step >= 60) {
        
        int j = exist(orgs, this->get_x(), this->get_y(), 'Q');
        if (j >= 0) {
            orgs.erase(orgs.begin()+j);
            return;
        }

    }

    if (this->queen_step >= 35) {
        int dir = get_rand();
        this->move(orgs, dir);
    }
}

void Queen::breed(vector<Organism *> &orgs) {

    for (int i = this->get_x() - 1;  i <= this->get_x() + 1; i++ ) {
        for (int j = this->get_y() - 1;  j <= this->get_y() + 1; j++ ) {
            if (i > 0 && i < width && j > 0 && j < height) {
                int m = exist(orgs, i, j, 'o');
                if (m >= 0) {
                    this->create(orgs);
                    this->breed_step = this->time_step;
                }
            }
        }
    }

}

void Queen::spawn_queen(vector<Organism *> &orgs) {

    for (int i = this->get_x() - 1;  i <= this->get_x() + 1; i++ ) {
        for (int j = this->get_y() - 1;  j <= this->get_y() + 1; j++ ) {
            if (i > 0 && i < width && j > 0 && j < height) {
                if (exist(orgs, i, j) == -1) {
                    Queen *queen = new Queen(i, j);
                    orgs.push_back(queen);
                    this->queen_step = this->time_step;
                    return;
                }
            }
        }
    }

    for (int i = this->get_x() - 2;  i <= this->get_x() + 2; i++ ) { // changed to 2
        for (int j = this->get_y() - 2;  j <= this->get_y() + 2; j++ ) {
            if (i > 0 && i < width && j > 0 && j < height) {
                if (exist(orgs, i, j) == -1) {
                    Queen *queen = new Queen(i, j);
                    orgs.push_back(queen);
                    this->queen_step = this->time_step;
                    return;
                }
            }
        }
    }
}


void Queen::init_queen(int count, vector<Organism *> &orgs) {

    int x, y;
    int i = 0;

    while (i < count) {

        x = getRandom(width - 1);
        y = getRandom(height - 1);

        if (exist(orgs, x, y) == -1) {
            Queen *queen = new Queen(x, y);
            //queen->create(orgs);
            orgs.push_back(queen);
            i++;
        }

    }
}

Female::Female() : Organism() {}

Female::Female(int x, int y) : Organism() {
    //Organism(x, y);
    this->set_x(x);
    this->set_y(y);
    this->set_char('w');
}

void Female::init_female(int count, vector<Organism *> &orgs) {

    int x, y;
    int i = 0;

    while (i < count) {

        x = getRandom(width - 1);
        y = getRandom(height - 1);

        if (exist(orgs, x, y) == -1) {
            Female *female = new Female(x, y);
            orgs.push_back(female);
            i++;
        }
    }
}

void Female::time_stepFunc(vector<Organism *> &orgs) {

    this->time_step++;

    if (this->time_step - this->move_step > 5) {
        int j = exist(orgs, this->get_x(), this->get_y(), 'w');
        if (j >= 0) {
            orgs.erase(orgs.begin()+j);
            return;
        }
    }

    int dir = get_rand();
    this->move(orgs, dir);
}

Doodlebug::Doodlebug() : Organism() {}

Doodlebug::Doodlebug(int x, int y) : Organism () {
    this->set_x(x);
    this->set_y(y);
    this->set_char('X');
    this->eatStep = 0;
    this->time_step = 0;
    this->move_step = 0;
}

void Doodlebug::create(vector<Organism *> &orgs) {

    for (int i = this->get_x() - 1;  i <= this->get_x() + 1; i++ ) {
        for (int j = this->get_y() - 1;  j <= this->get_y() + 1; j++ ) {
            if (i > 0 && i < width && j > 0 && j < height) {
                if (exist(orgs, i, j) == -1) {
                    Doodlebug *doodlebug = new Doodlebug(i, j);
                    orgs.push_back(doodlebug);
                    return;
                }
            }
        }
    }
}

void Doodlebug::time_stepFunc(vector<Organism *> &orgs) {

    this->time_step++;

    int dir = get_rand();
    int x, y;
    x = this->get_x();
    y = this->get_y();

    switch(dir) {

        case UP:
            y--;
            break;

        case DOWN:
            y++;
            break;

        case RIGHT:
            x++;
            break;

        case LEFT:
            x--;
            break;

    }

    int i = exist(orgs, x, y);

    if (i >= 0) {
        if (!(orgs[i]->get_type() == 'X')) {
            orgs.erase(orgs.begin()+i);
            this->eatStep = this->time_step;
        }
    }
    
    if (this->time_step - this->eatStep > 10) {
        int j = exist(orgs, this->get_x(), this->get_y(), 'X');
        if (j >= 0) {
            orgs.erase(orgs.begin()+j);
            return;
        }
    }

    if (this->time_step % 10 == 0) {
        this->create(orgs);
    }

    this->move(orgs, dir);

}

void Doodlebug::init_doodlebug(int count, vector<Organism *> &orgs) {

    int x, y;
    int i = 0;

    while (i < count) {

        x = getRandom(width - 1);
        y = getRandom(height - 1);

        if (exist(orgs, x, y) == -1) {
            Doodlebug *doodlebug = new Doodlebug(x, y);
            orgs.push_back(doodlebug);
            i++;
        }
    }
}



Male::Male() : Organism() {

}

Male::Male(int x, int y) : Organism() {
    this->set_x(x);
    this->set_y(y);
    this->set_char('o');
}

void Male::init_male(int count, vector<Organism *> &orgs) {

    int x, y;
    int i = 0;

    while (i < count) {

        x = getRandom(width - 1);
        y = getRandom(height - 1);

        if (exist(orgs, x, y) == -1) {
            Male *male = new Male(x, y);
            orgs.push_back(male);
            i++;
        }
    }
}

void Male::time_stepFunc(vector<Organism *> &orgs) {
    
    this->time_step++;

    if (this->time_step - this->move_step > 5) {
        int j = exist(orgs, this->get_x(), this->get_y(), 'o');
        if (j >= 0) {
            orgs.erase(orgs.begin()+j);
        }
    }

    int dir = get_rand();
    this->move(orgs, dir);
}


static int exist (vector<Organism *> &orgs, int x, int y) {
    for (int i=0; i < orgs.size(); i++) {
        if (orgs[i]->get_x() == x && orgs[i]->get_y() == y) {
            return i;
        }
    }

    return -1;
}

static int exist (vector<Organism *> &orgs, int x, int y, char type) {
    for (int i=0; i < orgs.size(); i++) {
        if (orgs[i]->get_x() == x && orgs[i]->get_y() == y && orgs[i]->get_type() == type) {
            return i;
        }
    }

    return -1;
}