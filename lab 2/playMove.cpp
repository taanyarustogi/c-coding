//
//  playMove.cpp
//  TicTacToe
//
//  Created by Tarek Abdelrahman on 2019-06-07.
//  Modified by Tarek Abdelrahman on 2020-09-17.
//  Copyright © 2019-2020 Tarek Abdelrahman. All rights reserved.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.
//
//  ECE244 Student: write your code for playMove in this file

#include "globals.h"
#include "GameState.h"

void playMove(GameState& game_state) {
    
    if (game_state.get_gameBoard(game_state.get_selectedRow(), game_state.get_selectedColumn()) != 0) {
        game_state.set_moveValid(false);
    }
        
    if (game_state.get_moveValid() == true && game_state.get_turn() == true) {
        game_state.set_gameBoard(game_state.get_selectedRow(), game_state.get_selectedColumn(), 1);
    } else if (game_state.get_moveValid() == true && game_state.get_turn() == false) {
        game_state.set_gameBoard(game_state.get_selectedRow(), game_state.get_selectedColumn(), -1);
    }
    
    if (game_state.get_turn() == true && game_state.get_moveValid() == true) {
        game_state.set_turn(false);
        } else if (game_state.get_turn() == false && game_state.get_moveValid() == true) {
          game_state.set_turn(true);
        }
    
    bool dummy = true;
    for(int i = 0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if (game_state.get_gameBoard(i, j) == 0) {
                dummy = false;
            }
        }
    }
    
    if (game_state.get_gameBoard(2,0) == 1 && game_state.get_gameBoard(1,1) == 1 && game_state.get_gameBoard(0,2) == 1) {
        game_state.set_winCode(8);
    } else if (game_state.get_gameBoard(0,0) == 1 && game_state.get_gameBoard(1,1) == 1 && game_state.get_gameBoard(2,2) == 1) {
        game_state.set_winCode(7);
    } else if (game_state.get_gameBoard(0,2) == 1 && game_state.get_gameBoard(1,2) == 1 && game_state.get_gameBoard(2,2) == 1) {
        game_state.set_winCode(6);
    } else if (game_state.get_gameBoard(0,1) == 1 && game_state.get_gameBoard(1,1) == 1 && game_state.get_gameBoard(2,1) == 1) {
        game_state.set_winCode(5);
    } else if (game_state.get_gameBoard(0,0) == 1 && game_state.get_gameBoard(1,0) == 1 && game_state.get_gameBoard(2,0) == 1) {
        game_state.set_winCode(4);
    } else if (game_state.get_gameBoard(2,0) == 1 && game_state.get_gameBoard(2,1) == 1 && game_state.get_gameBoard(2,2) == 1) {
        game_state.set_winCode(3);
    } else if (game_state.get_gameBoard(1,0) == 1 && game_state.get_gameBoard(1,1) == 1 && game_state.get_gameBoard(1,2) == 1) {
        game_state.set_winCode(2);
    } else if (game_state.get_gameBoard(0,0) == 1 && game_state.get_gameBoard(0,1) == 1 && game_state.get_gameBoard(0,2) == 1) {
        game_state.set_winCode(1);
    } else if (game_state.get_gameBoard(2,0) == -1 && game_state.get_gameBoard(1,1) == -1 && game_state.get_gameBoard(0,2) == -1) {
        game_state.set_winCode(8);
    } else if (game_state.get_gameBoard(0,0) == -1 && game_state.get_gameBoard(1,1) == -1 && game_state.get_gameBoard(2,2) == -1) {
        game_state.set_winCode(7);
    } else if (game_state.get_gameBoard(0,2) == -1 && game_state.get_gameBoard(1,2) == -1 && game_state.get_gameBoard(2,2) == -1) {
        game_state.set_winCode(6);
    } else if (game_state.get_gameBoard(0,1) == -1 && game_state.get_gameBoard(1,1) == -1 && game_state.get_gameBoard(2,1) == -1) {
        game_state.set_winCode(5);
    } else if (game_state.get_gameBoard(0,0) == -1 && game_state.get_gameBoard(1,0) == -1 && game_state.get_gameBoard(2,0) == -1) {
        game_state.set_winCode(4);
    } else if (game_state.get_gameBoard(2,0) == -1 && game_state.get_gameBoard(2,1) == -1 && game_state.get_gameBoard(2,2) == -1) {
        game_state.set_winCode(3);
    } else if (game_state.get_gameBoard(1,0) == -1 && game_state.get_gameBoard(1,1) == -1 && game_state.get_gameBoard(1,2) == -1) {
        game_state.set_winCode(2);
    } else if (game_state.get_gameBoard(0,0) == -1 && game_state.get_gameBoard(0,1) == -1 && game_state.get_gameBoard(0,2) == -1) {
        game_state.set_winCode(1);
    } else {
        game_state.set_winCode(0);
    }
    
    if(game_state.get_winCode() != 0) {
        game_state.set_gameOver(true);
    } else if(dummy == true) {
        game_state.set_gameOver(true);
    }

}

