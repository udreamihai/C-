/**
 * File: main.cpp
 * Author: Mihai Udrea
 * Date: 15-11-2017
 * Desc: Graphic version of 2048 game. 
 * Copyright: University of West of England 2017
 */
#include <stdio.h>
#include <iostream>
#include <ctime>
#include "2048.h"
#include <sstream>

// include the UFCFGL301's standard library
#include <ufcfgl-30-1.h>

// uncomment if you want to use the graphics library
#include <graphics.h>

using namespace uwe;

/**
 * main routine, implements ...
 * @return      success
 */



int main(void){
    initialiseGraphics(Game::SCR_WIDTH,Game::SCR_HEIGHT);
    Game game2048;
    srand(time(0));
    int board[Game::BOARD_WIDTH][Game::BOARD_HEIGHT] = {0};
    game2048.Start_Board();
    loop(
        [&](){
            game2048.Draw_Board();
        },
        [&](keyPress keyPress){
        int code = keyPress.getKeyCode();
        if (code == keyPress::upKey){
            // up arrow key
            // move tiles up
            game2048.Push_Tiles();
            // add the matching tiles
            game2048.Add_Tiles();
            for (int z = 0; z < Game::BOARD_HEIGHT; z++){
                // move tiles up to the edge
                game2048.Push_Tiles();
            }
            // add new number to the board
            game2048.Add_New_Number();
            game2048.Check_Win_Lose();
        }
        if (code == keyPress::downKey){
            // down arrow
            game2048.Rotate_Clockwise(2);
            game2048.Push_Tiles();
            game2048.Add_Tiles();
            for (int z = 0; z < Game::BOARD_HEIGHT; z++){
                // move tiles up to the edge
                game2048.Push_Tiles();
            }
            game2048.Rotate_Counterclockwise(2);
            // add new number to the board
            game2048.Add_New_Number();
            game2048.Check_Win_Lose();
        }                          
        if (code == keyPress::rightKey){
            // right arrow
            game2048.Rotate_Counterclockwise(1);
            game2048.Push_Tiles();
            game2048.Add_Tiles();
            for (int z = 0; z < Game::BOARD_HEIGHT; z++){
                // move tiles up to the edge
                game2048.Push_Tiles();
            }
            game2048.Rotate_Clockwise(1);
            // add new number to the board
            game2048.Add_New_Number();
            game2048.Check_Win_Lose();
        }                          
        if (code == keyPress::leftKey){
            // left arrow
            // move tiles left
            game2048.Rotate_Clockwise(1);
            game2048.Push_Tiles();
            game2048.Add_Tiles();
            for (int z = 0; z < Game::BOARD_HEIGHT; z++){
                // move tiles up to the edge
                game2048.Push_Tiles();
            }
            game2048.Rotate_Counterclockwise(1);
            // add new number to the board
            game2048.Add_New_Number();
            game2048.Check_Win_Lose();
        }
            return false;
        });
    return 0;
}