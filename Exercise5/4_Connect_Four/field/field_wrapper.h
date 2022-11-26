#pragma once
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <map>
#include <cstring> // memcpy
#include "playfield.h"

// struct field_wrapper {
//     char f[playfield::width][playfield::height]; // Pointer because just as value doesn't work since playfield is abstract
//     int width; int height; char none;

//     field_wrapper(const playfield &field): width(field.width), height(field.height), none(field.none)
//     {
//         memcpy (f, field.rep, field.width*field.height*sizeof(char));
//     }; 
//     // field_wrapper(const field_wrapper& field): f(field.f), width(f->width), height(f->height), none(f->none){}; 

//     int stoneat(int x, int y) const { return f[x][y]; }
//     void deleteat(int x, int y) { f[x][y] = playfield::none; }
//     void insertat(char val, int x, int y) { f[x][y] = val; }

//     // returns row where stone was inserted
//     int insert(int col, char player){
//         if(col < 0 || col >= playfield::width) throw std::invalid_argument("Choose col within field!");
//         int h = playfield::height-1;
//         while(h >= 0){
//             if(stoneat(col, h) == playfield::none) {
//                 insertat(player, col, h);
//                 return h;
//             };
//             h--;
//         }
//         return -1;
//         // throw std::invalid_argument("Row is already full!");

//     }

//     friend std::ostream& operator<<(std::ostream &os, const field_wrapper& f){
//         std::map<char, char> m;
//         m = {{0, ' '}, {1, '1'}, {2, '2'}};
//         for(int h=0; h<f.height; ++h){
//             for(int col=0; col<f.width; ++col){
//                 char stone = f.stoneat(col, h);
//                 std::cout << '|' << m[stone];
//             }
//             std::cout << '|' << std::endl;
//         }
//         std::cout << ' ' << std::string(f.width*2 - 1, '_') << ' ' << std::endl;
//         for(int i=0; i<f.width; ++i) std::cout << ' ' << i;
//         std::cout << std::endl;
//     }

// };

// Field util
namespace fu{
    std::string str(const playfield& f){
        std::map<char, char> m;
        std::stringstream ss;
        m = {{0, ' '}, {1, '1'}, {2, '2'}};
        for(int h=0; h<f.height; ++h){
            for(int col=0; col<f.width; ++col){
                char stone = f.stoneat(col, h);
                ss << '|' << m[stone];
            }
            ss << '|' << std::endl;
        }
        ss << ' ' << std::string(f.width*2 - 1, '_') << ' ' << std::endl;
        for(int i=0; i<f.width; ++i) ss << ' ' << i;
        ss << std::endl;

        return ss.str();
    }

    void deleteat(char rep[playfield::width][playfield::height], int x, int y) { rep[x][y] = playfield::none; }
    void insertat(char rep[playfield::width][playfield::height], char val, int x, int y) { rep[x][y] = val; }
    int stoneat(char rep[playfield::width][playfield::height], int x, int y) { return rep[x][y]; }

    int insert(char rep[playfield::width][playfield::height], int col, char player){
        if(col < 0 || col >= playfield::width) throw std::invalid_argument("Choose col within field!");
        int h = playfield::height-1;
        while(h >= 0){
            if(stoneat(rep, col, h) == playfield::none) {
                fu::insertat(rep, player, col, h);
                return h;
            };
            h--;
        }
        return -1;

    }
    
    int insert(playfield &f, int col, char player){
        // if(col < 0 || col >= f.width) throw std::invalid_argument("Choose col within field!");
        // int h = f.height-1;
        // while(h >= 0){
        //     if(f.stoneat(col, h) == f.none) {
        //         fu::insertat(rep, player, col, h);
        //         return h;
        //     };
        //     h--;
        // }
        // return -1;
        return fu::insert(f.rep, col, player);
    }
}