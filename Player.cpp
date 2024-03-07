
#include "Player.h"

Player::Player(const char* name): m_roundsLost(0), m_roundsWon(0), m_total(0)
{
    if(name)
    {
        m_name = new char[strlen(name)];
        strcpy(m_name, name);
    }
    else
        m_name = nullptr;
}

Player::Player(const Player &other):m_roundsWon(other.m_roundsWon), m_roundsLost(other.m_roundsLost),
                                    m_total(other.m_total)
{
    delete []m_name;
    m_name = nullptr;
    if(other.m_name)
    {
        m_name = new char[strlen(other.m_name)];
        strcpy(m_name, other.m_name);
    }
    else
        m_name = nullptr;
}

Player::~Player()
{
    if(m_name)
        delete []m_name;
}

Player &Player::operator=(const Player &other)
{
    delete []m_name;
    m_name = nullptr;
    if(other.m_name)
    {
        m_name = new char[strlen(other.m_name)];
        strcpy(m_name, other.m_name);
    }
    m_roundsWon = other.m_roundsWon;
    m_roundsLost = other.m_roundsLost;
    m_total = other.m_total;
    return *this;
}

ostream& operator<<(ostream &os, const Player& p)
{
    p.print(os);
    return os;
}