#pragma once
#include "gamelogic.h"
#include "../field/my_playfield.h"
#include <iostream>
#include "../../../Exercise4/3_Range/range.h"

template <typename P, typename E>
class connect_four{
    P player1; char player1_char = 1;
    E player2; char player2_char = 2;
    my_playfield field;
    
    bool check_move(int col){
        bool res = false;
        if(col >= field.width || col < 0) res = false;
        else if (field.stoneat(col, 0) == field.none) res = true;

        if(!res) std::cout << "Invalid move!" << std::endl;
        return res;
    }

    // returns true if game is over after move
    bool make_move(int col, char player){
        field.insert(col, player);

        // Check vertical
        int combo = gamelogic::vertical(field, col, player);
        if(combo >= 4) return true;
        // Check horizontal
        combo = gamelogic::horizontal(field, col, player);
        if(combo >= 4) return true;
        // Check cross-down
        combo = gamelogic::down(field, col, player);
        if(combo >= 4) return true;
        // Check cross-up /
        combo = gamelogic::up(field, col, player);
        if(combo >= 4) return true;
        
        return false;
    }

    bool isfull(){
        for(int col: range(0, field.width)) {
            if(field.stoneat(col, 0) == field.none) return false;
        }
        return true;
    }
public:
    connect_four() { };

    void run(){
        bool move_possible = false; int col;
        for(;;){
            // Player1
            move_possible = false;
            while(!move_possible){
                col = player1.play(field);
                move_possible = check_move(col);
            }
            bool game_won = make_move(col, player1_char);
            std::cout << field;
            if(game_won) {
                std::cout << std::endl << "Player 1 won";
                return;
            } else if(isfull()){
                std::cout << std::endl << "Field is full, game is a tie";
                return;
            }

            // Player2
            move_possible = false;
            while(!move_possible){
                col = player2.play(field);
                move_possible = check_move(col);
            }
            game_won = make_move(col, player2_char);
            std::cout << field;
            if(game_won){
                std::cout << std::endl << "Player 2 won";
                return;
            } else if(isfull()){
                std::cout << std::endl << "Field is full, game is a tie";
                return;
            }
        }
    }
};