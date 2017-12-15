#include <stdio.h>
#include <ctime>
#include <iostream>
#include <ufcfgl-30-1.h>
#include "2048.h"
#include <graphics.h>
#include <sstream>
using namespace uwe;

void Game::Draw_Board(){
    int roffset = 10;
    int rsize = (Game::SCR_WIDTH-(roffset*(Game::BOARD_WIDTH+1)))/Game::BOARD_WIDTH;
    uwe::setColour(Colours::lightgrey);
    std::string score1; // move integer value into a string so we can use drawText
    std::stringstream sscore;
    sscore << "Your score: " << score;
    score1 = sscore.str();
    uwe::setColour(Colours::black);
    drawFilledRect(0,0,Game::SCR_WIDTH,Game::SCR_HEIGHT-Game::SCR_WIDTH);
    uwe::setColour(Colours::white);
    Font("Arial", 36, Font::bold);
    drawText("2048 GAME",270,30,100,50);
    drawText(score1,100,50,400,50);
    for(int i = 0;i < Game::BOARD_WIDTH; i++){
        for(int j = 0; j < Game::BOARD_WIDTH; j++){
            std::string printStr;
            int posx = roffset*(i+1)+(rsize*i);
            int posy = Game::SCR_HEIGHT-Game::SCR_WIDTH+roffset*(j+1)+(rsize*j);
            std::stringstream sstr; // move integer value into a string so we can use drawText
            sstr << board[j][i];
            uwe::setColour(Colours::grey);
            printStr = sstr.str();
            if (board[j][i] == 0){ // generate the tiles
                uwe::setColour(Colours::grey);
                drawFilledRect(posx,posy,rsize,rsize);
            } else if (board[j][i] == 2){
                uwe::setColour(Colours::lightgrey);
                drawFilledRect(posx,posy,rsize,rsize);
                uwe::setColour(Colours::black);
                drawText(printStr,posx+rsize/2,posy+rsize/2,100,1);
            } else if (board[j][i] == 4){
                uwe::setColour(Colours::darkgrey);
                drawFilledRect(posx,posy,rsize,rsize);
                uwe::setColour(Colours::black);
                drawText(printStr,posx+rsize/2,posy+rsize/2,100,1);
            }
            else if (board[j][i] == 8){
                uwe::setColour(Colours::blue);
                drawFilledRect(posx,posy,rsize,rsize);
                uwe::setColour(Colours::black);
                drawText(printStr,posx+rsize/2,posy+rsize/2,100,1);
            }
            else if (board[j][i] == 16){
                uwe::setColour(Colours::yellow);
                drawFilledRect(posx,posy,rsize,rsize);
                uwe::setColour(Colours::black);
                drawText(printStr,posx+rsize/2,posy+rsize/2,100,1);
            }
            else if (board[j][i] == 32){
                uwe::setColour(Colours::purple);
                drawFilledRect(posx,posy,rsize,rsize);
                uwe::setColour(Colours::black);
                drawText(printStr,posx+rsize/2,posy+rsize/2,100,1);
            }
            else if (board[j][i] == 64){
                uwe::setColour(Colours::violet);
                drawFilledRect(posx,posy,rsize,rsize);
                uwe::setColour(Colours::black);
                drawText(printStr,posx+rsize/2,posy+rsize/2,100,1);
            }
            else if (board[j][i] == 128){
                uwe::setColour(Colours::white);
                drawFilledRect(posx,posy,rsize,rsize);
                uwe::setColour(Colours::black);
                drawText(printStr,posx+rsize/2,posy+rsize/2,100,1);
            }
            else if (board[j][i] == 256){
                uwe::setColour(Colours::orange);
                drawFilledRect(posx,posy,rsize,rsize);
                uwe::setColour(Colours::black);
                drawText(printStr,posx+rsize/2,posy+rsize/2,100,1);
            }
            else if (board[j][i] == 512){
                uwe::setColour(Colours::green);
                drawFilledRect(posx,posy,rsize,rsize);
                uwe::setColour(Colours::black);
                drawText(printStr,posx+rsize/2,posy+rsize/2,100,1);
            }
            else if (board[j][i] == 1024){
                uwe::setColour(Colours::lightblue);
                drawFilledRect(posx,posy,rsize,rsize);
                uwe::setColour(Colours::black);
                drawText(printStr,posx+rsize/2,posy+rsize/2,100,1);
            }
            else if (board[j][i] == 2048){
                uwe::setColour(Colours::black);
                drawFilledRect(posx,posy,rsize,rsize);
                uwe::setColour(Colours::white);
                drawText(printStr,posx+rsize/2,posy+rsize/2,100,1);
            }
        }
    }
    
}
void Game::Check_Win_Lose(){
    bool win = false;
    bool lose = true;
    for(int i = 0;i < Game::BOARD_WIDTH; i++){
        for(int j = 0; j < Game::BOARD_HEIGHT; j++){
            if(board[i][j] == 0){
                lose = false;
            }
            if (board[i][j] == 2048){ // check if we made 2048... like that's going to happen in my lifetime
                win = true;
            }
        }
    }
    for(int i = 0;i < Game::BOARD_WIDTH; i++){
        for(int j = 0; j < Game::BOARD_HEIGHT-1; j++){
            if((board[j][i] != 0) && (board[j][i] == board[j+1][i])){ // check if we can add tiles vertically
                lose  = false;
            }
        }
    }
    for(int i = 0;i < Game::BOARD_WIDTH-1; i++){
        for(int j = 0; j < Game::BOARD_HEIGHT; j++){
            if((board[j][i] != 0) && (board[j][i] == board[j][i+1])){ // check if we can add tiles horizontally
                lose  = false;
            }
        }
    }
    if (win == true){
        std::cout << "You win!!!" << std::endl;
        /*uwe::setColour(Colours::black);
        drawFilledRect(0,Game::SCR_HEIGHT/2-50,Game::SCR_WIDTH,100);
        uwe::setColour(Colours::white);
        drawText("You win!!!",100,50,300,50);
        system("pause");*/
    }
    if (lose == true){
        std::cout << "You lose!!!" << std::endl;
        //uwe::setColour(Colours::black);
        //drawFilledRect(0,Game::SCR_HEIGHT/2-50,Game::SCR_WIDTH,100);
        //uwe::setColour(Colours::white);
        //drawText("You Lose!!! Hahahahaha!!!!",100,50,300,50);
    }
}
void Game::Add_New_Number(){
    // add new number to the board into a random position
    while (true){
        int x = random_index();
        int y = random_index();
        if (board[x][y] == 0){
            board[x][y] = random_number();
            break;
        }
    }
}
void Game::Start_Board(){
    // generate two random numbers and place them on the board
    int x1 = random_index();
    int y1 = random_index();
    board[x1][y1] = random_number();
    int x2 = random_index();
    int y2 = random_index();
    if ((x1 == x2) && (y1 == y2)){ // it happend few times to randomly generate the same coordinates
        x2 = random_index();
        y2 = random_index();
    }
    board[x2][y2] = random_number();
}
void Game::Push_Tiles(){ // push tiles up
    for(int i = 0;i < Game::BOARD_WIDTH; i++){
            for(int j = 0; j < Game::BOARD_HEIGHT; j++){
                if(!board[j][i]){
                    for(int k = j + 1; k < Game::BOARD_WIDTH; k++){
                        if(board[k][i]){
                            board[j][i] = board[k][i];
                            board[k][i] = 0;
                            break;
                        }
                        }
                    }
                }
        }
}
void Game::Add_Tiles(){
    for(int i = 0; i < Game::BOARD_WIDTH; i++){
            for(int j = 0; j < Game::BOARD_HEIGHT - 1; j++){
                if((board[j][i] != 0) && (board[j][i] == board[j+1][i])){
                    board[j][i] += board[j+1][i];
                    score += board[j][i];
                    board[j+1][i] = 0;			
                    }
                }
        }
}
void Game::Rotate_Clockwise(int times){
    for (int count = 0; count < times; count++){
        for (int i = 0; i < Game::BOARD_WIDTH; i++){
                for (int j = 0; j < Game::BOARD_HEIGHT; j++){
                    bck_board[i][j] = board[i][j]; // move the board to a backup board
                }
            }
        for (int i = 0; i < Game::BOARD_WIDTH; i++){
                for (int j = 0; j < Game::BOARD_HEIGHT; j++){
                    board[i][Game::BOARD_HEIGHT-1-j] = bck_board[j][i]; // do one rotation clockwise
                }
            }
    }
}
void Game::Rotate_Counterclockwise(int times){
    for (int count = 0; count < times; count++){
        for (int i = 0; i < Game::BOARD_WIDTH; i++){
                for (int j = 0; j < Game::BOARD_HEIGHT; j++){
                    bck_board[i][j] = board[i][j]; // move the board to a backup board
                }
            }
        for (int i = 0; i < Game::BOARD_WIDTH; i++){
                for (int j = 0; j < Game::BOARD_HEIGHT; j++){
                    board[i][j] = bck_board[j][Game::BOARD_WIDTH-1-i]; // do one rotation counterclockwise
                }
            }
    }
}

int Game::random_number(){ // generate randomly numbers 2 or 4 to place on the grid
    int number;
    int x = rand() % 100;
    if (x < 90){
        number = 2;
    }
    else{
        number = 4;
    }
    return number;
}

int Game::random_index(){ // generate random position on the grid
    int index = rand() % Game::BOARD_WIDTH;
    return index;
}

int Game::Check_Max(){ // show your current score
    int max = 2;
    for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(board[i][j] > max)
				max = board[i][j];
        }
    }
    return max;
}