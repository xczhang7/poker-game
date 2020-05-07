#include <time.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void InitCard(vector<int>& Card)
{
    int card;
        for( int j=0; j<54; j++ ){
            card = j;
            Card.push_back(card);
        }

    }



void DealCard(vector<int>& Card, vector<int>& Player1, vector<int>& Player2, vector<int>& Player3)
{
    srand( (unsigned)time( NULL ) );
    for( int i = 0; i < 54; i++ )
    {
        int iCard = rand() % Card.size();
        switch( i % 3 )
        {
            case 0:
                Player1.push_back(Card[iCard]);
                break;
            case 1:
                Player2.push_back(Card[iCard]);
                break;
            default:
                Player3.push_back(Card[iCard]);
                break;
        }
        if( iCard != Card.size()-1 ){
            Card[iCard] = Card[Card.size()-1];

        }
        Card.pop_back();

    }

}
