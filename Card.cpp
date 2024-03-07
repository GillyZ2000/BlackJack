

#include "Card.h"


using namespace std;



Card::Card(){
    m_val = toss_val();
}



Card::Card(const Card& other)
{
    if(m_cards_cnt< DECK_SIZE-1 && m_cards_hist[other.m_val])
    {
        m_val = other.m_val;
        m_cards_cnt++;
        m_cards_hist[m_val]++;
    }
}

Card::~Card(){}




bool Card::is_legal(int num)
{
    return (m_cards_hist[num] <= MAX_APPEARANCES) && (num > 0);
}


int Card::toss_val()
{
    m_cards_cnt++;
    int rand_val = 0;
    while (!is_legal(rand_val)){
        mt19937 gen(time(0)); // Seed with current time
        uniform_int_distribution<> distrib(1, 13);
        rand_val = distrib(gen);
    }
    return rand_val;
}


const char* Card::card_to_str() const
{
    char c;
    if((m_val < NUM_VAL) && (m_val > MIN_VAL))
    {
        char temp= ('9'-'0')+ m_val;

        return to_str(temp);
    }
    else if(m_val == NUM_VAL)
    {
      return "10";
    }
    else if(m_val == J_VAL)
    {
        return "J";
    }
    else if(m_val == Q_VAL)
    {
        return "Q";
    }
    else if(m_val == K_VAL)
    {
        return "K";
    }
    else
    {
        return "A";
    }
}

const char* Card:: to_str(char c) const
{
    const char* s = "c";
    return s;
}

ostream& operator<<(ostream &os, const Card& c)
{
    c.print(os);
    return os;
}