#include "grid.hpp"
#include "simulation.hpp"
#include "organism.hpp"
#include "rand.hpp"
#include <cstdlib>
#include <cstdio>
#include <ncurses.h>
#include <ctime>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

void simulation() {
    enum State state = INIT;
    grid *grid_base;
    Queen *queen = new Queen();
    Organism *org = new Organism();
    Female *female = new Female();
    Doodlebug *doodlebug = new Doodlebug();
    Male *male = new Male();

    vector<Organism *> orgs;
    int ch;
    int timeStepCount = 0;

    struct timespec timeret;
    timeret.tv_sec = 0;
    timeret.tv_nsec = 999999999/4;


    static int get_org_count (vector<Organism *> &orgs, char type) {
    
    int count = 0;
    for (int i = 0; i < orgs.size(); i++) {
        if (orgs[i]->get_type() == type) {
            count++;
        }
    }

    return count;
}

    while(state != EXIT) {
        switch(state) {
        case INIT:

            int input_queen;
            int input_female;
            int input_male;
            int input_doodle;

            while(true) {
                cout << endl << "input an integer number of queen ants from 1-20 and press enter." << endl;
                cin >> input_queen;
                if (input_queen > 0 && input_queen <= 20) {
                    break;
                } else {
                    cout << "inavlid entry. please try again \n" << endl;
                }
            }

            while(true) {
                cout << endl << "input an integer number of female ants from 1-50 and press enter." << endl;
                cin >> input_female;
                if (input_female > 0 && input_female <= 50) {
                    break;
                } else {
                    cout << "inavlid entry. please try again \n" << endl;
                }
            }

            while(true) {
                cout << endl << "input an integer number of male ants from 1-20 and press enter." << endl;
                cin >> input_male;
                if (input_male > 0 && input_male <= 20) {
                    break;
                } else {
                    cout << "inavlid entry. please try again \n" << endl;
                }
            }

            while(true) {
                cout << endl << "input an integer number of doodlebugs from 1-50 and press enter." << endl;
                cin >> input_doodle;
                if (input_doodle > 0 && input_doodle <= 50) {
                    break;
                } else {
                    cout << "inavlid entry. please try again \n" << endl;
                }
            }

            clear();
            initscr();
            start_color();
            nodelay(stdscr, TRUE);
            noecho(); 
            getmaxyx(stdscr, y_max, x_max);
            keypad(stdscr, TRUE); 
            curs_set(0); 
            timeout(100);


            x_offset = (x_max / 2) - (width / 2);
            y_offset = (y_max / 2) - (height / 2);


            queen->init_queen(input_queen, orgs);
            doodlebug->init_doodlebug(input_doodle, orgs);
            female->init_female(input_female, orgs);
            male->init_male(input_male, orgs);
            
            state = ALIVE;

        case ALIVE:

            clear();
   

            timeStepCount++;

            mvprintw(14, 5, "Q = %d and w = %d and o = %d and X = %d", get_org_count(orgs, 'Q'),
                get_org_count(orgs, 'w'), get_org_count(orgs, 'o'), get_org_count(orgs, 'X'));
            mvprintw(16, 5, "TimeStepCount = %d", timeStepCount);
           
            grid_base = init_grid(x_offset, y_offset, width, height);
            draw_Grid(grid_base); 
            
            for (int i = 0; i < orgs.size(); i++) {
                if (orgs[i]->get_type() == 'X') {
                    orgs[i]->draw(x_offset, y_offset);
                    orgs[i]->time_stepFunc(orgs);
                }
            }


            for (int i = 0; i < orgs.size(); i++) {
                if (orgs[i]->get_type() == 'Q' || orgs[i]->get_type() == 'w' || orgs[i]->get_type() == 'o') {
                orgs[i]->draw(x_offset, y_offset);
                orgs[i]->time_stepFunc(orgs);
                }
            }


            break;
        

        case DEAD:
            endwin();
            break;
        }

        refresh();
        nanosleep(&timeret, NULL);
    }

}
