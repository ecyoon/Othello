//Eunice & Ruoyun, Othello Player!!!!

#include "player.hpp"
	
/*
 * Constructor for the player; initialize everything here. The side your AI is
 * on (BLACK or WHITE) is passed in as "side". The constructor must finish
 * within 30 seconds.
 */
Player::Player(Side side) {
    // Will be set to true in test_minimax.cpp.
    testingMinimax = false;

    /*
     * TODO: Do any initialization you need to do here (setting up the board,
     * precalculating things, etc.) However, remember that you will only have
     * 30 seconds.
     */
    board = Board();
}

/*
 * Destructor for the player.
 */
Player::~Player() {
}

void Player::set(char data[])
{
    board.setBoard(data);
}

/*
 * Compute the next move given the opponent's last move. Your AI is
 * expected to keep track of the board on its own. If this is the first move,
 * or if the opponent passed on the last move, then opponentsMove will be
 * nullptr.
 *
 * msLeft represents the time your AI has left for the total game, in
 * milliseconds. doMove() must take no longer than msLeft, or your AI will
 * be disqualified! An msLeft value of -1 indicates no time limit.
 *
 * The move returned must be legal; if there are no valid moves for your side,
 * return nullptr.
 */
Move *Player::doMove(Move *opponentsMove, int msLeft) {
    /*
     * TODO: Implement how moves your AI should play here. You should first
     * process the opponent's opponents move before calculating your own move
     */

    //Update board with opponent move.
    board.doMove(opponentsMove, WHITE);

    //Proceed only if there are moves left.
    vector<Move*> valid = board.getValidMoves(BLACK);
    if(valid.size() == 0)
        return nullptr;

    //debugging print statement: prints vector valid
    // for(uint i = 0; i < valid.size(); i++)
    // {
    //     std::cerr << "Move: " << valid[i]->x << ", " << valid[i]->y << std::endl;
    // }
    uint max_index = 0;
    int max = -999999999;

    for(uint i = 0; i < valid.size(); i++)
    {
        Board *new_board = board.copy();
        new_board->doMove(valid[i], BLACK);

        int temp = score(new_board, 4);

        if(temp > max)
        {
            max = temp;
            max_index = i;
        }
        delete new_board;
    }

    Move *pick = valid[max_index];
    deleteVector(valid, max_index);

    board.doMove(pick, BLACK);
    return pick;
}

int Player::score(Board *board, int c)
{
    int min = -9999999;
    Side s = WHITE;
    int sign = -1;

    if(c%2 == 0)
    {
        s = BLACK;
        min = -999999;
        sign = 1;
    }

    if(c == 0)
    {
        return sign*(board->countBlack() - board->countWhite()) + board->addScore(s);
    }

    vector<Move*> valid = board->getValidMoves(s);
    if(valid.size() == 0)
    {
        return sign*(board->countBlack() - board->countWhite()) + board ->addScore(s);
    }


    for(uint i = 0; i < valid.size(); i++)
    {
        Board *t = board->copy();
        t->doMove(valid[i], s);

        int temp = score(t, c - 1);
        if((i%2 == 0 && temp < min) || (i%2 == 1 && temp > min))
        {
            min = temp + t->addScore(s);
        }
        delete t;
    }
    return min;
}


//Prevents memory leaks.
void Player::deleteVector(vector<Move*> m, uint j)
{
    for(uint i = 0; i < m.size(); i++)
    {
        if(i != j)
            delete m[i];
    }
}













