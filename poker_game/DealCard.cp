#include <time.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum em_CardClass_t
{
    hearts = 0,
    Spade,
    Clubs,
    Diamonds,
    King
};

struct st_Card_t{
    em_CardClass_t _emCardClass;
    int _uCardIndex;

};

void InitCard(vector<st_Card_t>& Card)
{
    st_Card_t card;
    for( int i=0; i<King; i++ ){
        card._emCardClass = (em_CardClass_t)i;
        for( int j=1; j<14; j++ ){
            card._uCardIndex = j;
            Card.push_back(card);
        }

    }
    card._emCardClass = King;
    card._uCardIndex = 1;
    Card.push_back(card);
    card._uCardIndex = 2;
    Card.push_back(card);

}


void DealCard(vector<st_Card_t>& Card, vector<st_Card_t>& Player1, vector<st_Card_t>& Player2, vector<st_Card_t>& Player3)
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

void SortCard(vector<st_Card_t>& Player)
{
    st_Card_t tmp;
    for( int i=0; i<Player.size()-1; i++ )
    {
        for( int j=i+1; j<Player.size(); j++ )
        {
            if( Player[i]._uCardIndex <= Player[j]._uCardIndex )
            {
                continue;

            }
            tmp = Player[i];
            Player[i] = Player[j];
            Player[j] = tmp;

        }
    }
}

void PrintPlayerCard(const string& sPlayerName,const vector<st_Card_t>& vtPlayer)
{
    cout << sPlayerName << " cards:" << endl;
    for( int i=0; i< vtPlayer.size(); i++ )
    {
        switch( vtPlayer[i]._emCardClass ){
            case hearts:
                cout << "♥";
                break;
            case Spade:
                cout << "♠";
                break;
            case Clubs:
                cout << "♣";
                break;
            case Diamonds:
                cout << "♦";
                break;
            default:
                cout << "King";
                break;}
        cout << vtPlayer[i]._uCardIndex<< " ";

    }
    cout << endl << endl;
}


int main()
{
vector<st_Card_t> Card;
vector<st_Card_t> Player1;
vector<st_Card_t> Player2;
vector<st_Card_t> Player3;
InitCard(Card);
DealCard(Card, Player1, Player2, Player3);
SortCard(Player1);
SortCard(Player2);
SortCard(Player3);
PrintPlayerCard("Player1", Player1);
PrintPlayerCard("Player2", Player2);
PrintPlayerCard("Player3", Player3);
}
