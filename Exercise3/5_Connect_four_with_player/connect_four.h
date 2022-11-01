#pragma once
#include "playfield.h"
#include "gamelogic.h"
#include <iostream>

template <typename P, typename E, typename F>
class connect_four{
    P player1; char player1_char = 1;
    E player2; char player2_char = 2;
    F field;
    
    bool check_move(int col){
        bool res = false;
        if(col >= field.width || col < 0) res = false;
        else if (field.stoneat(col, 0) == field.none) res = true;

        if(!res) std::cout << "Invalid move!" << std::endl;
        return res;
    }

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

public:
    connect_four(): player1("Player 1"), player2("Player 2") { };

    void run(){
        for(;;){
            // Player1
            bool move_possible = false; int col;
            while(!move_possible){
                col = player1.play(field);
                move_possible = check_move(col);
            }
            bool game_won = make_move(col, player1_char);
            std::cout << field;
            if(game_won) {
                std::cout << std::endl << player1.name << " won";
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
                std::cout << std::endl << player2.name << " won";
                return;
            }
        }
    }
};