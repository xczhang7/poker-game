#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void sortCards(int *, int);
void showCards(int *, int);
void changeCard(int);
int getOneCard();

int Cards[55] = { 0 };
int main()
{
    int i;
    int Player_A[19] = { NULL };
    int Player_B[19] = { NULL };
    int Player_C[19] = { NULL };

    
    for (i = 1; i <= 18; i++)//为三个玩家分别发牌
    {
        Player_A[i] = getOneCard();
        Player_B[i] = getOneCard();
        Player_C[i] = getOneCard();
    }
        sortCards(Player_A, 19);
        sortCards(Player_B, 19);
        sortCards(Player_C, 19);
    puts("Player_A:");//打印A的牌
        showCards(Player_A, 18);
    puts("\nPlayer_B:");//打印B的牌
        showCards(Player_B, 18);
    puts("\nPlayer_C:");//打印C的牌
        showCards(Player_C, 18);
    
    puts("");

    return 0;
}
int getOneCard()//通过随机数取得一张没用过的牌
{
    int iRandNum;
    srand(time(0));//取时间随机数
    iRandNum = rand() % 54 + 1;
    while (Cards[iRandNum] == 1)//被用过的牌会重新取随机数
    {
        iRandNum = rand() % 54 + 1;
    }
    Cards[iRandNum] = 1;
    return iRandNum;
}
void showCards(int *Player, int Count)
{
    int i;
    for (i = 1; i <= Count; i++)
    {
        if (Player[i] == 53)
        {
            printf("Joker1 ", Player[i]);
        }
        else if (Player[i] == 54)
        {
            printf("Jocker2 ", Player[i]);
        }
        else if (Player[i] % 4 == 0)
        {
            changeCard(Player[i]);
        }
        else if ((Player[i] + 1) % 4 == 0)
        {

            changeCard(Player[i]);
        }
        else if (Player[i] % 2 == 0)
        {

            changeCard(Player[i]);
        }
        else
        {

            changeCard(Player[i]);
        }
    }
}
void changeCard(int Card)
{
    Card /= 4.00;
    switch (Card)
    {
    case 0:printf("3 "); break;
    case 1:printf("4 "); break;
    case 2:printf("5 "); break;
    case 3:printf("6 "); break;
    case 4:printf("7 "); break;
    case 5:printf("8 "); break;
    case 6:printf("9 "); break;;
    case 7:printf("10 "); break;
    case 8:printf("J "); break;
    case 9:printf("Q "); break;
    case 10:printf("K "); break;
    case 11:printf("A "); break;
    case 12:printf("2 "); break;
    }
}
void sortCards(int *Nums, int Length)
{
    int i, j, iTemp;
    for (i = 1; i <= Length - 1; i++)
    {
        for (j = 1; j <= Length - 2; j++)
        {
            if (Nums[j]>Nums[j + 1])
            {
                iTemp = Nums[j];
                Nums[j] = Nums[j + 1];
                Nums[j + 1] = iTemp;
            }
        }
    }
}
