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
        int combo = 0, max_combo = 0,
            col = get_col_from_row(field, row);
        for(int i=col; i<field.height; ++i){ 
            char stone = field.stoneat(row, i);
            if(stone == player) ++combo;
            else { max_combo = std::max(combo, max_combo); combo = 0;}
            if(combo == 4) return 4; // Player won
        }
        return std::max(max_combo, combo);
    }

    // Check horizontal
    template <typename F>
    int horizontal(F &field, int row, char player){
        int combo = 0, max_combo = 0,
            col = get_col_from_row(field, row);
        for(int i=0; i<field.width; ++i){
            char stone = field.stoneat(i, col);
            if(stone == player) ++combo; 
            else { max_combo = std::max(combo, max_combo); combo = 0;}
            if(combo == 4) return 4; // Player won
        }
        return std::max(max_combo, combo);
    }
    // Check cross-down
    template <typename F>
    int down(F &field, int row, char player){
        int combo = 0, max_combo = 0,
            col = get_col_from_row(field, row);
        int closer_edge = std::min(row, col); 
        int x = row - closer_edge,
            y = col - closer_edge;
        while(x < field.width && y < field.height){
            if(field.stoneat(x, y) == player) ++combo;
            else { max_combo = std::max(combo, max_combo); combo = 0;}
            if(combo == 4) return 4;
            ++x; ++y;
        }
        return std::max(max_combo, combo);
    }
    // Check cross-up /
    template <typename F>
    int up(F &field, int row, char player){
        int combo = 0, max_combo = 0,
            col = get_col_from_row(field, row);
        int closer_edge = std::min(row, field.height - col - 1);
        int x = row - closer_edge,
            y = col + closer_edge;
        while(x < field.width && y >= 0){
            if(field.stoneat(x, y) == player) ++combo;
            else { max_combo = std::max(combo, max_combo); combo = 0;}
            if(combo == 4) return 4;
            ++x; --y;
        }
        return std::max(max_combo, combo);
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