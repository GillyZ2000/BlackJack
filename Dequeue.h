#include <iostream>
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include "Card.h"

using namespace std;


#ifndef _DEQUEUE_H_
#define _DEQUEUE_H_

#define MAX_SIZE 52


//########################################## CLASS ##########################################################


class Dequeue
{

private:							//attributes , members
    unsigned m_size;
    unsigned m_capacity;
    Card** m_queue;
    int m_left;  //front -> first out
    int m_right; //rear - > last out


public:
    Dequeue(unsigned capacity);	// constructor
    Dequeue();//  Default constructor
    ~Dequeue();

    void push_back(Card* card);
    void push_front(Card* card);

    void pop_back();
    void pop_front();

    Card* get_back() const;
    Card* get_front() const;

    bool is_full() const;
    bool is_empty() const;
    int size() const;

    void show()const;
    void show_data() const;



};


//########################################## FUNCTIONS #################################################################



#endif