#pragma once
#include <stdexcept>
#include <iostream>

struct playfield {
    const static int width=7;
    const static int height=6;

    // these elements are used to indicate whether a given position
    // in the playing field is taken by a given player
    const static char none=0;
    const static char player1=1;
    const static char player2=2;

    // the internal representation of the field
    char rep[playfield::width][playfield::height]; // TODO: Why not switch height and width here?

    int stoneat(int x, int y) const { return rep[x][y]; }
    void insertat(char val, int x, int y) { rep[x][y] = val; }

    void insert(int col, char player){
        if(col < 0 || col >= width) throw std::invalid_argument("Choose col within field");
        int h = height-1;
        while(h >= 0){
            if(stoneat(col, h) == none) {
                insertat(player, col, h);
                return;
            };
            h--;
        }
        throw std::invalid_argument("Row is already full");

    }

    friend std::ostream& operator<<(std::ostream &os, const playfield& f){
        for(int h=0; h<f.height; ++h){
            for(int col=0; col<f.width; ++col){
                char stone = f.stoneat(col, h);
                std::cout << '|' << f.stoneat(col, h);
            }
            std::cout << '|' << std::endl;
        }
        std::cout << ' ' << std::string(f.width*2 - 1, '_') << ' ' << std::endl;
        for(int i=0; i<f.width; ++i) std::cout << ' ' << i;
        std::cout << std::endl;
    }

    playfield() : rep() {};
};