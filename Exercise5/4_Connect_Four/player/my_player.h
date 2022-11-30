#pragma once
#include <vector>
#include <stdexcept>
#include "../field/playfield.h"
#include "../field/my_playfield.h"
#include "player.h"
#include "../game/gamelogic.h"

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



struct my_player: player{
    char playerchar = -1, enemychar = -2; 
    std::string name;
    game::coord first_round; int round;

    // returns the column where the player decides to insert his stone
    virtual int play(const playfield &field){
        my_playfield f(field);
        if(round == 0){ // Save & make default play
            int col = 3; ++round; 
            int row = f.insert(col, '0');
            first_round.x = col; first_round.y = row;

            return col; 
        }
        if(round == 1){ // Set correct chars
            playerchar = f.stoneat(first_round.x, first_round.y);
            enemychar = (playerchar == 1) ? 2 : 1;
        }

        game::move my_play = get_best_play(f, playerchar);
        
        if(my_play.score == -1) {
            std:: cout << "Error: Couldn't find any col to make points. Playing 3 as default" << std::endl;
            return 3;
        }
        if(my_play.score == 4) return my_play.col;

        game::move enemy_play = get_best_play(f, enemychar);
        if(enemy_play.score == 4) return enemy_play.col;
        else return my_play.col;
    }

    my_player(std::string player_name = "my_player"): name(player_name), round(0) {};
    // virtual ~player() { free(name); }

private:
    game::move get_best_play(my_playfield &f, char player){
        int max_score = -1, max_col = -1;

        // Try all cols and check for highest combo
        for(int col=0; col<f.width; ++col){
            int row = f.insert(col, player);
            if(row == -1) continue;
            
            int score = gamelogic::best_play(f, col, player);
            if(score > max_score){ max_score = score; max_col = col; }
            f.deleteat(col, row); // Reset field
        }
        
        if(max_score == -1) throw std::runtime_error("Field seems to be full, no play possible");
        return game::move(max_score, max_col);
    }
};