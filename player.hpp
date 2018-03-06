#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <iostream>
#include "common.hpp"
#include "board.hpp"
using namespace std;

class Player {

public:
    Player(Side side);
    ~Player();

    Board board;
    Side p_side = WHITE;

    void deleteVector(vector<Move*> m, uint j);

    Move *doMove(Move *opponentsMove, int msLeft);
    int score(Board *board, int c);
    void set(char data[]);

    // Flag to tell if the player is running within the test_minimax context
    bool testingMinimax;
};

#endif
