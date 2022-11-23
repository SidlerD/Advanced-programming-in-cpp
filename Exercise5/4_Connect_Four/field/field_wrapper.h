#pragma once
#include <stdexcept>
#include <iostream>
#include <map>
#include "playfield.h"

struct field_wrapper {
    playfield *f; // Pointer because just as value doesn't work since playfield is abstract
    int width; int height; char none;

    field_wrapper(const playfield &field): f(&field), width(f->width), height(f->height), none(f->none){}; // Copies field
    field_wrapper(playfield &field): f(&field), width(f->width), height(f->height), none(f->none){}; // Copies field
    field_wrapper(const field_wrapper& field): f(field.f), width(f->width), height(f->height), none(f->none){}; // Copies field
    field_wrapper(): f(), width(f->width), height(f->height), none(f->none){}; // Creates new field

    int stoneat(int x, int y) const { return f->stoneat(x, y); }
    void deleteat(int x, int y) { f->rep[x][y] = f->none; }
    void insertat(char val, int x, int y) { f->rep[x][y] = val; }

    // returns row where stone was inserted
    int insert(int col, char player){
        if(col < 0 || col >= f->width) throw std::invalid_argument("Choose col within field!");
        int h = f->height-1;
        while(h >= 0){
            if(f->stoneat(col, h) == f->none) {
                insertat(player, col, h);
                return h;
            };
            h--;
        }
        return -1;
        // throw std::invalid_argument("Row is already full!");

    }

    friend std::ostream& operator<<(std::ostream &os, const field_wrapper& f){
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