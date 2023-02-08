#include <iostream>
#include <vector>
using namespace std;


class MazeGenerator {
    public:
        vector<vector<char> > maze_grid;
     
        void set_maze(vector<vector<char> > m) {
          maze_grid = m;
        }

        void make_maze(int size) {
            srand(time(NULL));

            if (size < 0) {
                throw invalid_argument("make_maze argument take a positive integer.");
            }

            vector<vector<char> > grid( size , vector<char> (size));

            for(int i = 0; i < size; i++)
            {
                for(int j = 0; j < size; j++)
                {
                    int random = rand() % 100;
                    if(random < 50) {
                        grid[i][j] = '#';
                    }
                    else {
                        grid[i][j] = '.';
                    }
                    
                    if(i == size-1 || i == 0 || j == size-1 || j == 0) {
                        grid[i][j] = '#';                        
                    }
                }
            }
            int rand_exit = rand() % size;
            grid[0][rand_exit] = '.';

            rand_exit = rand() % size;
            grid[size-1][rand_exit] = '.';

            this->set_maze(grid);
        }

        string print_maze() {

            vector<vector<char> > grid = this->maze_grid;
            string grid_string = "";

            for (int i = 0; i < grid.size(); i++)
            {
                for (int j = 0; j < grid[i].size(); j++)
                {
                    string temp(1, grid[i][j]);
                    grid_string += temp;
                    grid_string += " ";
                }    
                grid_string += "\n";
            }
            return grid_string;
            cout << grid_string;
        }
};

int main() {

    MazeGenerator test_maze;
    test_maze.make_maze(5);
    cout << test_maze.print_maze();
    cout << endl;

    MazeGenerator test_maze2;
    test_maze2.make_maze(12);
    cout << test_maze2.print_maze();
    cout << endl;


    MazeGenerator test_maze3;
    test_maze3.make_maze(30);
    cout << test_maze3.print_maze();
    cout << endl;


    MazeGenerator exception_maze;
    try
    {
        exception_maze.make_maze(-5);
    }

    catch (std::invalid_argument& e)
    {
        cerr << e.what() << endl;
    }


    int input;
    cout << "Input maze size: ";
    cin >> input;
    cout << endl;
    MazeGenerator input_maze;
    input_maze.make_maze(input);
    cout << input_maze.print_maze();
    
}