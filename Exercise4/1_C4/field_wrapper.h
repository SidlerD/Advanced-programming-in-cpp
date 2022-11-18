#pragma once
#include <stdexcept>
#include <iostream>

template <typename F>
struct field_wrapper {
    F f; int width; int height; char none;

    field_wrapper(const F field): f(field), width(f.width), height(f.height), none(f.none){}; // Copies field
    field_wrapper(const field_wrapper<F>& field): f(field.f), width(f.width), height(f.height), none(f.none){}; // Copies field
    field_wrapper(): f(), width(f.width), height(f.height), none(f.none){}; // Creates new field

    int stoneat(int x, int y) const { return f.stoneat(x, y); }
    void deleteat(int x, int y) { f.rep[x][y] = f.none; }
    void insertat(char val, int x, int y) { f.rep[x][y] = val; }

    // returns row where stone was inserted
    int insert(int col, char player){
        if(col < 0 || col >= f.width) throw std::invalid_argument("Choose col within field");
        int h = f.height-1;
        while(h >= 0){
            if(f.stoneat(col, h) == f.none) {
                insertat(player, col, h);
                return h;
            };
            h--;
        }
        throw std::invalid_argument("Row is already full");

    }

    friend std::ostream& operator<<(std::ostream &os, const field_wrapper<F>& f){
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

};