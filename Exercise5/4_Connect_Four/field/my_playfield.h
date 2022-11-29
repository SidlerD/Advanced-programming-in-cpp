#pragma once
#include <stdexcept>
#include <iostream>
#include <map>
#include "playfield.h"

struct my_playfield: playfield {
    const static int width=7;
    const static int height=6;

    // these elements are used to indicate whether a given position
    // in the playing field is taken by a given player
    const static char none=0;
    const static char player1=1;
    const static char player2=2;

    // the internal representation of the field
    char rep[playfield::width][playfield::height]; 


    my_playfield(const playfield &field)
    {
        for(int x=0; x < field.width; ++x){
            for(int y=0; y < field.height; ++y){
                insertat(field.stoneat(x,y), x, y);
            }
        }
    }; 
    my_playfield(): rep() {}

    int stoneat(int x, int y) const { return rep[x][y]; }
    void deleteat(int x, int y) { rep[x][y] = playfield::none; }
    void insertat(char val, int x, int y) { rep[x][y] = val; }

    // returns row where stone was inserted
    int insert(int col, char player){
        if(col < 0 || col >= playfield::width) throw std::invalid_argument("Choose col within field!");
        int h = playfield::height-1;
        while(h >= 0){
            if(stoneat(col, h) == playfield::none) {
                insertat(player, col, h);
                return h;
            };
            h--;
        }
        return -1;
        // throw std::invalid_argument("Row is already full!");

    }

    friend std::ostream& operator<<(std::ostream &os, const my_playfield& f){
        std::map<char, char> m;
        m = {{0, ' '}, {1, '1'}, {2, '2'}};
        for(int h=0; h<f.height; ++h){
            for(int col=0; col<f.width; ++col){
                char stone = f.stoneat(col, h);
                std::cout << '|' << m[stone];
            }
            std::cout << '|' << std::endl;
        }
        std::cout << ' ' << std::string(f.width*2 - 1, '_') << ' ' << std::endl;
        for(int i=0; i<f.width; ++i) std::cout << ' ' << i;
        std::cout << std::endl;
    }

};