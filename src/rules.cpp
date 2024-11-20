#include <iostream>
#include "../includes/rules.h"

bool isAlive(std::array<std::array<int, WIN_HEIGHT>,  WIN_WIDTH>& grid, const int x, const int y){
   int alive =0;
   // testing top left
   if (x > 0 && y > 0 && grid[x-1][y-1] == 1){
      alive++;
   }
   //testing middle top 
   if (y > 0 && grid[x][y-1] == 1){
      alive++;
   }
   // testing top right
   if(x < WIN_WIDTH && y > 0 && grid[x+1][y-1]){
      alive++;
   }
   // testing middle left
   if(x > 0 && grid[x-1][y] == 1){
      alive++;
   }
   // testing middle right
   if(x < WIN_WIDTH && grid[x+1][y] == 1){
      alive++;
   }
   //test bottom left
   if(x > 0 && y < WIN_HEIGHT && grid[x-1][y+1] == 1){
      alive++;
   }
   // testing middle bottom
   if(y < WIN_HEIGHT && grid[x][y+1] == 1){
      alive++;
   }
   // testing right bottom
   if(x < WIN_WIDTH && y < WIN_HEIGHT && grid[x+1][y+1] == 1){
      alive++;
   }

   // die if less than 2 alive
   if(grid[x][y] == 1 && alive < 2) return false;

   // live if 2 or 3 lives
   if(grid[x][y] == 1 && (alive == 2 || alive == 3)) return true;

   // die if more than 3 live
   if(grid[x][y] == 1 && alive > 3) return false;

   // if die and exactly 3 lives -> live
   if (grid[x][y] == 0 && alive == 3) return true;
   
   return false;
}