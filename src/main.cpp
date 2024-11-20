#include <iostream>
#include "../includes/rules.h"
#include <algorithm>
#include <array>
#include "../includes/screen.h"


int main(){
   G screen;
   std::array<std::array<int, WIN_HEIGHT>, WIN_WIDTH> display {};
   std::array<std::array<int, WIN_HEIGHT>, WIN_WIDTH> swap {}; 

   for(auto& row : display){
      std::generate(row.begin(), row.end(), []() {return rand()%2 == 0 ? 1 : 0;});
   }

   while(true){
      for (int i = 0; i < WIN_WIDTH; ++i){
         for (int j = 0; j < WIN_HEIGHT; ++j){
            swap[i][j] = isAlive(display, i, j) ? 1 : 0;
         }
      }
      // Draw
      for (int i = 0; i < WIN_WIDTH; ++i){
         for (int j = 0; j < WIN_HEIGHT; ++j){
            if(swap[i][j]){
               screen.drawpixel(i, j);
            }
         }
      }

      std::copy(swap.begin(), swap.end(), display.begin());
      screen.update();
      SDL_Delay(20);
      screen.input();
      screen.clearpixels();
   }

   return 0;
}