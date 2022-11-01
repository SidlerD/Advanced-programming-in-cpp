#include <stdexcept> 

namespace gamelogic{
    template <typename F>
    int get_col_from_row(F &field, int row){
        int col = 0;
        for(; col < field.height; ++col) {
            if(field.stoneat(row, col) != field.none) return col;
        }
        throw ("Col not found");
    }
    
    // Check vertical
    template <typename F>
    int vertical(F &field, int row, char player){
        int combo = 0, col = get_col_from_row(field, row);
        for(int i=col; i<field.height; ++i){ 
            char stone = field.stoneat(row, i);
            if(stone == player) ++combo;
            else { return combo; }
            if(combo == 4) return 4; // Player won
        }
        return combo;
    }

    // Check horizontal
    template <typename F>
    int horizontal(F &field, int row, char player){
        int left = 0, right = 0,
            col = get_col_from_row(field, row);
        for(int i=row; i < field.width; ++i){
            char stone = field.stoneat(i, col);
            if(stone == player) ++right; 
            else { break; }
            if(right == 4) return 4; // Player won
        }

        for(int i=row; i>=0; --i){
            char stone = field.stoneat(i, col);
            if(stone == player) ++left; 
            else { break; }
            if(left == 4) return 4; // Player won
        }
        return left + right - 1;
    }
    
    // Check cross-down
    template <typename F>
    int down(F &field, int row, char player){
        int left = 0, right = 0,
            col = get_col_from_row(field, row);
        int x = row,
            y = col;
        while(x < field.width && y < field.height){
            if(field.stoneat(x, y) == player) ++right;
            else { break;}
            ++x; ++y;
        }
        x=row; y = col;
        while(x >= 0 && y >= 0){
            if(field.stoneat(x, y) == player) ++left;
            else { break;}
            --x; --y;
        }
        return left + right - 1; // -1 since new chip at (row, col) is counted twice
    }
    // Check cross-up /
    template <typename F>
    int up(F &field, int row, char player){
        int left = 0, right = 0,
            col = get_col_from_row(field, row);
        int x = row,
            y = col;
        while(x < field.width && y >= 0){
            if(field.stoneat(x, y) == player) ++right;
            else { break; }
            ++x; --y;
        }
        x=row; y = col;
        while(x >= 0 && y < field.height){
            if(field.stoneat(x, y) == player) ++left;
            else { break; }
            --x; ++y;
        }
        return left + right - 1;
    }

    // Get the highest possible points after playing chip in row
    template <typename F>
    int best_play(F &field, int row, char player){
        return std::max(
            std::max(
                vertical(field, row, player),
                horizontal(field, row, player)
            ),
            std::max(
                up(field, row, player),
                down(field, row, player)
            )
        );
    }
}