#pragma once

template<typename F> // Field
struct dominik {
    const char playerchar = 2; // TODO: Remove
    std::string name;

    // returns the column where the player decides to insert his stone
    int play(const F &field){
        int max_score = -1, max_row = -1;
        // Try all rows and check for highest combo
        for(int row=0; row<field.width; ++row){
            int col = 0;
            F f = field; // Copy field
            // std::cout << "Before: " << f.stoneat(0,0) << "vs" << field.stoneat(0,0) << ", ";
            // f.rep[0][0] = 1;
            // std::cout << "After: " << f.stoneat(0,0) << "vs" << field.stoneat(0,0) << std::endl;

            while(col < field.height){
                if(f.stoneat(row, col) != field.none) break;
                ++col;
            }
            --col;
            f.insertat(playerchar, row, col); // TODO: This will not work with other fields
            int score = gamelogic::best_play(f, row, playerchar);
            if(score > max_score){ max_score = score; max_row = row; }
        }
        
        if(max_score == -1) throw "Couldn't find any row to make points";
        return max_row;
    }

    dominik(std::string player_name = "dominik"): name(player_name) {};

};