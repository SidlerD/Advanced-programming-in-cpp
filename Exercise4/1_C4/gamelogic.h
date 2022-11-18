#include <stdexcept> 

namespace gamelogic{
    template <typename F>
    int get_row_from_col(F &field, int col){
        int row = 0;
        for(; row < field.height; ++row) {
            if(field.stoneat(col, row) != field.none) return row; // TODO: If col is full, this should return that
        }
        throw ("Col not found"); // Should not happen since stone was dropped in that col
    }
    
    // Check vertical
    template <typename F>
    int vertical(F &field, int col, char player){
        int combo = 0, row = get_row_from_col(field, col);
        for(int y=row; y<field.height; ++y){ 
            char stone = field.stoneat(col, y);
            if(stone == player) ++combo;
            else { return combo; }
            if(combo == 4) return 4; // Player won
        }
        return combo;
    }

    // Check horizontal
    template <typename F>
    int horizontal(F &field, int col, char player){
        int left = 0, right = 0,
            row = get_row_from_col(field, col);
        for(int x=col; x < field.width; ++x){
            char stone = field.stoneat(x, row);
            if(stone == player) ++right; 
            else { break; }
            if(right == 4) return 4; // Player won
        }

        for(int x=col; x>=0; --x){
            char stone = field.stoneat(x, row);
            if(stone == player) ++left; 
            else { break; }
            if(left == 4) return 4; // Player won
        }
        return left + right - 1;
    }
    
    // Check cross-down
    template <typename F>
    int down(F &field, int col, char player){
        int left = 0, right = 0,
            row = get_row_from_col(field, col);
        int x = col,
            y = row;
        while(x < field.width && y < field.height){
            if(field.stoneat(x, y) == player) ++right;
            else { break;}
            ++x; ++y;
        }
        x=col; y = row;
        while(x >= 0 && y >= 0){
            if(field.stoneat(x, y) == player) ++left;
            else { break;}
            --x; --y;
        }
        return left + right - 1; // -1 since new chip at (row, col) is counted twice
    }
    // Check cross-up /
    template <typename F>
    int up(F &field, int col, char player){
        int left = 0, right = 0,
            row = get_row_from_col(field, col);
        int x = col,
            y = row;
        while(x < field.width && y >= 0){
            if(field.stoneat(x, y) == player) ++right;
            else { break; }
            ++x; --y;
        }
        x=col; y = row;
        while(x >= 0 && y < field.height){
            if(field.stoneat(x, y) == player) ++left;
            else { break; }
            --x; ++y;
        }
        return left + right - 1;
    }

    // Get the highest possible points after playing chip in col
    template <typename F>
    int best_play(F &field, int col, char player){
        return std::max(
            std::max(
                vertical(field, col, player),
                horizontal(field, col, player)
            ),
            std::max(
                up(field, col, player),
                down(field, col, player)
            )
        );
    }
}