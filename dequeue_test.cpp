#include <iostream>
#include "Dequeue.h"
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
using namespace std;
/*
void test1()
{
    Dequeue d1(5);
    d1.show_data();
    d1.show();

    d1.push_front(5);
    d1.show_data();
    d1.show();
    d1.push_front();
    d1.show_data();
    d1.show();
    d1.push_back(6);
    d1.show_data();
    d1.show();
    d1.push_front(7);
    d1.show_data();
    d1.show();
    d1.push_back(8);
    d1.show_data();
    d1.show();
    d1.push_back(999);
    d1.show_data();
    d1.show();

    cout << "-----------------------------------------" << endl;
// -------------------------------
    d1.pop_back();
    d1.show_data();
    d1.show();
    d1.pop_back();
    d1.show_data();
    d1.show();
    d1.pop_front();
    d1.show_data();
    d1.show();
    d1.pop_front();
    d1.show_data();
    d1.show();
    d1.pop_back();
    d1.show_data();
    d1.show();
    d1.pop_back();
    d1.show_data();
    d1.show();


}

*/

void test2()
{
    Card* cards_arr= new Card[6];
    Card** cards_ptr_arr= new Card*[6];
    Dequeue deck(5);
    for(int i=0; i<6 ;i++)
    {
      cards_ptr_arr[i] = &cards_arr[i];
    }
    for(int i=0; i<6 ;i++)
    {
        deck.push_back(cards_ptr_arr[i]);
        deck.show();
        deck.show_data();
    }
    cout << ".........." << endl << endl;
    for(int i=0; i<5; i++)
    {
        deck.pop_front();
        deck.show();
        deck.show_data();
    }
    cout << ".........." << endl << endl;

}
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif












