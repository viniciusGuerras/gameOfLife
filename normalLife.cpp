#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
const int SIZE = 30;

int countNeighbors(int grid[SIZE][SIZE], int row, int column);

void updateCells(int grid[SIZE][SIZE]){
    int newGrid[SIZE][SIZE] = {};
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            int aux_value = countNeighbors(grid, i, j);
            if(grid[i][j] == 1){
                  if(aux_value < 1 || aux_value > 7) {
                    newGrid[i][j] = 0;
                  }
            }
            else{
                if(aux_value == 4){
                    newGrid[i][j] =1;
                }
        
                if(aux_value > 5){
                    newGrid[i][j] = 2;
                }

            } 
        }
    }
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            grid[i][j] = newGrid[i][j];
        }
    }
}

int countNeighbors(int grid[SIZE][SIZE], int row, int column){
    int total = 0;
    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            if(row + i >= 0 && row + i < SIZE && column + j >= 0 && column + j < SIZE){
                total += grid[row + i][column + j];
            }
        }
    }
    return total -= grid[row][column];
}

void initializeGrid(int grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            grid[i][j] = rand() % 2;
        }
    }
}

void printGrid(int grid[SIZE][SIZE]){
    for(int i=0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            std::cout << (grid[i][j] == 0 ? " " : "*");
        }
        std::cout << std::endl;
    }
}

void visualizeGrid(int grid[SIZE][SIZE]) {
    system("clear");
    printGrid(grid);
    usleep(100000);  // Sleep for 100,000 microseconds (0.1 seconds)
}

void createLife(int generations, int grid[SIZE][SIZE]){
    printGrid(grid);
    std::cout << std::endl;
    for(int i = 0; i < generations; i++){
        updateCells(grid);
        visualizeGrid(grid);
        std::cout << std::endl;
    }
}

int main()
{
    std::srand(std::time(0));  // Set the seed based on current time
    int grid[SIZE][SIZE];
    initializeGrid(grid);
    createLife(50, grid);
    return 0;
}
