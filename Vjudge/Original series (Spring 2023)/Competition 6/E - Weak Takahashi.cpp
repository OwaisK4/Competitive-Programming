#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

bool isValid(char **grid, int x, int y, int H, int W, char wall){
    if (grid[x][y] == wall || x >= H || y >= W){
        return false;
    }
    return true;
}

// int check(char **grid, int **solution, int x, int y, int H, int W, char wall, int count){
//     if (x >= H || y >= W){
//         return 0;
//     }
//     if (isValid(grid, solution, x, y, H, W, wall)){
//         // solution[x][y] = 1;
//         // cout << "Here";
//         int answer;
//         answer = check(grid, solution, x, y + 1, H, W, wall, count + 1) + check(grid, solution, x + 1, y, H, W, wall, count + 1);
//         return answer;
//     }
// }

/*
int check(char **grid, int **solution, int x, int y, int H, int W, char wall, int count){
    if (x >= H || y >= W || grid[x][y] == wall){
        // count--;
        return 1;
    }
    if (isValid(grid, solution, x, y, H, W, wall)){
        solution[x][y] = 1;
        return check(grid, solution, x, y + 1, H, W, wall, count + 1) + check(grid, solution, x + 1, y, H, W, wall, count + 1) - 1;
        // return count;
        solution[x][y] = 0;
    }
}
*/

int check(char **grid, int x, int y, int H, int W, char wall){
    if (x >= H || y >= H || grid[x][y] == wall)
        return 0;
    // if (isValid(grid, x, y, H, W, wall)){
    grid[x][y] = wall;
    cout << "(" << x << ", " << y << ")\n";
    return max(check(grid, x, y+1, H, W, wall) + 1, check(grid, x+1, y, H, W, wall) + 1);
    // }    
}

int main(){
    int H, W;
    cin >> H >> W;
    // char grid[H][W] = {};
    // int solution[H][W] = {};
    char **grid = new char*[H];
    // int **solution = new int*[H];
    for (int i=0; i<H; i++){
        grid[i] = new char[W];
        // solution[i] = new int[W]{};
    }
    for (int i=0; i<H; i++){
        for (int j=0; j<W; j++){
            cin >> grid[i][j];
        }
    }

    int count = check(grid, 0, 0, H, W, '#');
    cout << count;
    
    // for (int i=0; i<H; i++){
    //     for (int j=0; j<W; j++){       
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    
    return 0;
}