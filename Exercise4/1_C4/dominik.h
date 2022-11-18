#pragma once
#include <vector>
#include "field_wrapper.h"

namespace game{
    // Column played and score achieved by play
    struct move{
        int score, col;
        move(int score, int col): score(score), col(col) {}
    };
    struct coord{
        int x, y;
        coord(int x, int y): x(x), y(y) {}
        coord(): x(-1), y(-1) {}
    };
}



template<typename I, class F = field_wrapper<I>> // Field
struct dominik {
    char playerchar = -1, enemychar = -2; 
    std::string name;
    game::coord first_round; int round;

    // returns the column where the player decides to insert his stone
    int play(const I &field){
        if(round == 0){ // Save & make default play
            F f(field);
            int col = 3; ++round; 
            int row = f.insert(col, 1);
            first_round.x = col; first_round.y = row;
            return col; 
        }
        if(round == 1){ // Set correct chars
            playerchar = field.stoneat(first_round.x, first_round.y);
            enemychar = (playerchar == 1) ? 2 : 1;
        }

        game::move my_play = get_best_play(field, playerchar);
        
        if(my_play.score == -1) {
            std:: cout << "Error: Couldn't find any col to make points. Playing 3 as default" << std::endl;
            return 3;
        }
        if(my_play.score == 4) return my_play.col;

        game::move enemy_play = get_best_play(field, enemychar);
        if(enemy_play.score == 4) return enemy_play.col;
        else return my_play.col;
    }

    dominik(std::string player_name = "dominik"): name(player_name), round(0) {};

private:
    game::move get_best_play(const F &f, char player){
        int max_score = -1, max_col = 0;
        F field(f);

        // Try all cols and check for highest combo
        for(int col=0; col<field.width; ++col){
            int row = field.insert(col, player);
            int score = gamelogic::best_play(field, col, player);
            if(score > max_score){ max_score = score; max_col = col; }
            field.deleteat(col, row); // Reset field
        }
        
        return game::move(max_score, max_col);
    }

    int get_row_from_col(const F &field, int col){
        int row = 0;

        while(row < field.height){
            if(field.stoneat(col, row) != field.none) break;
            ++row;
        }
        return --row;
    }
};