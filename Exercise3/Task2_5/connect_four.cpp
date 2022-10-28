// #include "playfield.h"
// #include <iostream>

// template <typename P, typename E, typename F>
// class connect_four{
//     P player1;
//     E player2;
//     F field;

    
//     bool check_move(int row){
//         //TODO: Implement
//         return true;
//     }

//     bool make_move(int row){
//         //TODO: Implement
//         return true;
//     }

// public:
//     connect_four() { 
//         std::cout << "hey";
//     };

//     void run(){
//             for(;;){
//                 // Player1
//                 bool move_possible = false; int row;
//                 while(!move_possible){
//                     row = player1.play(field);
//                     move_possible = check_move(row);
//                 }
//                 bool game_won = make_move(row);
//                 if(game_won) return;

//                 // Player2
//                 move_possible = false;
//                 while(!move_possible){
//                     int row = player2.play(field);
//                     move_possible = check_move(row);
//                 }
//                 game_won = make_move(row);
//                 if(game_won) return;
//             }
//         }

//     };