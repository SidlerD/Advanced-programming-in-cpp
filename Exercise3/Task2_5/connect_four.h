#pragma once
#include "playfield.h"
#include "gamelogic.h"
#include <iostream>

template <typename P, typename E, typename F>
class connect_four{
    P player1; char player1_char = 1;
    E player2; char player2_char = 2;
    F field;
    
    bool check_move(int row){
        bool res = false;
        if(row >= field.width || row < 0) res = false;
        else if (field.stoneat(row, 0) == field.none) res = true;

        if(!res) std::cout << "Invalid move!" << std::endl;
        return res;
    }

    bool make_move(int row, char player){
        field.insert(row, player);

        // Check vertical
        int combo = gamelogic::vertical(field, row, player);
        if(combo >= 4) return true;
        // Check horizontal
        combo = gamelogic::horizontal(field, row, player);
        if(combo >= 4) return true;
        // Check cross-down
        combo = gamelogic::down(field, row, player);
        if(combo >= 4) return true;
        // Check cross-up /
        combo = gamelogic::up(field, row, player);
        if(combo >= 4) return true;
        
        return false;
    }

public:
    connect_four(): player1("Player 1"), player2("Player 2") { };

    void run(){
        for(;;){
            // Player1
            bool move_possible = false; int row;
            while(!move_possible){
                row = player1.play(field);
                move_possible = check_move(row);
            }
            bool game_won = make_move(row, player1_char);
            std::cout << field;
            if(game_won) {
                std::cout << std::endl << player1.name << " won";
                return;
            }
            // Player2
            move_possible = false;
            while(!move_possible){
                row = player2.play(field);
                move_possible = check_move(row);
            }
            game_won = make_move(row, player2_char);
            std::cout << field;
            if(game_won){
                std::cout << std::endl << player2.name << " won";
                return;
            }
        }
    }

    };