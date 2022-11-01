#pragma once
#include <vector>

struct round_move{
    int _score, _col;
    round_move(int score, int old_row): _score(score), _col(old_row) {}
};
struct coord{
    int _x, _y;
    coord(int x, int y): _x(x), _y(y) {}
    coord(): _x(-1), _y(-1) {}
};

template<typename F> // Field
struct dominik {
    char playerchar = -1, enemychar = -2; 
    std::string name;
    coord first_round; int round;

    // returns the column where the player decides to insert his stone
    int play(const F &field){
        if(round == 0){ // Save & make default play
            int col = 3; ++round; 
            F f = field; int row = insert_in_field(f, col, 1);
            first_round._x = col; first_round._y = row;
            return col; 
        }
        if(round == 1){ // Set correct chars
            playerchar = field.stoneat(first_round._x, first_round._y);
            enemychar = (playerchar == 1) ? 2 : 1;
        }

        round_move my_play = get_best_play(field, playerchar);
        
        if(my_play._score == -1) {
            std:: cout << "Error: Couldn't find any old_row to make points. Playing 3 as default" << std::endl;
            return 3;
        }
        if(my_play._score == 4) return my_play._col;

        round_move enemy_play = get_best_play(field, enemychar);
        if(enemy_play._score == 4) return enemy_play._col;
        else return my_play._col;
    }

    dominik(std::string player_name = "dominik"): name(player_name), round(0) {};

private:
    round_move get_best_play(const F &field, char player){
        int max_score = -1, max_col = 0;
        // Try all rows and check for highest combo
        for(int col=0; col<field.width; ++col){
            int row = 0;
            F f = field; // Copy field

            while(row < field.height){
                if(f.stoneat(col, row) != field.none) break;
                ++row;
            }
            --row;
            insert_in_field(f, col, player); 
            int score = gamelogic::best_play(f, col, player);
            if(score > max_score){ max_score = score; max_col = col; }
        }
        
        return round_move(max_score, max_col);
    }
    // Returns col of of stone played
    int insert_in_field(F &field, int col, char player){
        int row = 0;

        while(row < field.height){
            if(field.stoneat(col, row) != field.none) break;
            ++row;
        }
        --row;
        field.rep[col][row] = player;
        return row;
    }
};