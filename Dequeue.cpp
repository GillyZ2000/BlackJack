
#include "Dequeue.h"





//############################### UTILITY FUNCTIONS ###########################################





//#################################### CONSTRUCTORS ###################################################

Dequeue::Dequeue(unsigned capacity) : m_capacity(capacity), m_size(0), m_left(-1),m_right(0)
{
    if (m_capacity != 0)
    {
        this->m_queue = new Card*[m_capacity];
    }
    else
        this->m_queue = nullptr;
}


Dequeue::Dequeue() : m_capacity(MAX_SIZE),m_size(0),m_left(-1),m_right(0)
{
    this->m_queue = new Card*[MAX_SIZE];
}

Dequeue::~Dequeue()
{
    delete[] m_queue;
}




//################################################### METHODS #################################################

bool Dequeue::is_full() const
{
    return m_size == m_capacity;
}

bool Dequeue::is_empty() const
{
    return m_size == 0;
}


void Dequeue::push_back(Card* card)
{
    if (is_full())
    {
        cout << "Queue is Full" << endl;
        return;
    }

    if (is_empty()) // if queue is empty
    {
        m_left = 0;
        m_right = 0;
    }

    else if (m_right == m_capacity - 1)
    {
        m_right = 0;
    }

    else
        m_right++;

    m_queue[m_right] = card;
    m_size++;

}




void Dequeue::push_front(Card* card)
{
    if (is_full())
    {
        cout << "Queue is Full" << endl;
        return;
    }

    if (is_empty()) // if queue is empty
    {
        m_left = 0;
        m_right = 0;
    }


    else if (m_left == 0) // in case of size = 1 , only one value.
    {
        m_left = m_capacity - 1;
    }

    else
        m_left--;

    m_queue[m_left] = card;
    m_size++;

}



void Dequeue::pop_back()

{


    if (is_empty())
    {
        cout << "Queue is empty" << endl;
        return;
    }
    m_queue[m_right] = nullptr;
    m_size--;

    if (m_left == m_right)
    {
        m_right = -1;
        m_left = -1;
    }
    else if (m_right == 0)
    {
        m_right = m_capacity - 1;
    }
    else
        m_right--;




}


void Dequeue::pop_front()
{
    if (is_empty())
    {
        cout << "Queue is empty" << endl;
        return;
    }

    m_queue[m_left] = nullptr;
    m_size--;

    if (m_right == m_left)
    {
        m_right = -1;
        m_left = -1;
    }

    else if (m_left == m_capacity - 1)
    {
        m_left = 0;
    }

    else
        m_left++;



}



Card* Dequeue::get_back() const
{
    return m_queue[m_right];
}

Card* Dequeue::get_front() const
{
    return m_queue[m_left];
}


int Dequeue::size() const
{
    return m_size;
}


void Dequeue::show() const
{
    if (m_capacity == 0)
    {
        cout << "[]";
        return;
    }

    int i;
    cout << "[";

    for (i = 0; i < m_capacity-1; i++)
    {


        cout << *(m_queue[i]) << ",";

    }
    cout << *(m_queue[i]) << "]" << endl;

}


void Dequeue:: show_data() const
{
    cout << "front: " << *(this->get_front()) << "   idx: " << m_left << "   back: " << *(this->get_back()) <<"   idx:"<< m_right <<
         "   size: "<< m_size << "   capacity: " << m_capacity << endl;
}