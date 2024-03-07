
#ifndef UNTITLED2_PLAYER_H
#define UNTITLED2_PLAYER_H

#include <cstring>
#include <ostream>
#include "Card.h"

using namespace std;

class Player {
private:
    const static int DECK = 52;
    char* m_name;
    unsigned long m_roundsWon;
    unsigned long m_roundsLost;
    unsigned int m_total;

    void print(std::ostream &os) const{
        os<< m_name;

    }

public:

    Player(const char* name);

    Player(const Player& other);

    ~Player();

    Player& operator=(const Player& other);

    friend ostream &operator<<(ostream &os, const Player& p);


};



#endif //UNTITLED2_PLAYER_H
