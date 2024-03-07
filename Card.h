
#ifndef UNTITLED2_CARD_H
#define UNTITLED2_CARD_H


#include <iostream>
#include "Card.h"
#include <ctime>
#include <random>
#include <iostream>
#include <crtdbg.h>

using namespace std;


class Card
{
private:
    static int const DECK_SIZE = 52;
    static int const MIN_VAL = 1;
    static int const MAX_VAL =13;
    static int const NUM_VAL = 10;
    static int const MAX_APPEARANCES = 4;

    static int const J_VAL= 11;
    static int const Q_VAL= 12;
    static int const K_VAL= 13;



    static int m_cards_cnt;
    static int m_cards_hist[MAX_VAL - MIN_VAL +1];

    int m_val;

    void print(ostream &os) const
    {
        os<< card_to_str();
    }




public:

    Card();

    Card(const Card& other);

    ~Card();


    static int toss_val();

    static bool is_legal(int num);

    friend ostream& operator<<(ostream &os, const Card& c);

    const char* card_to_str() const;

    const char* to_str(char c) const;

};




#endif

