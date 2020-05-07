# Poker game：simplified "Dou dizhu"

## Team members
@xczhang7 UID：3035639290 e-mail: xczhang7@connect.hku.hk

@Dora-Deng UID : 3035692424 e-mail: u3569242@connect.hku.hk

## Project description
The game "Dou dizhu" is a popular poker game in China. It has relatively simple and understandable rules. See wikipedia for the full version of the rules: https://en.wikipedia.org/wiki/Dou_dizhu.

However, in this project, we will ignore most of the special rules. Players will play under simplified rules of "Dou dizhu". 

Here is the special changes we made:

1. Players will no longer be divided into landowners and peasants. A total of 54 CARDS will be dealt equally among three players. The order of action now is randomly assigned before the game begins. 
2. The list of poker hands remains the same. And the conditions for determining the winner remain the same. A player wins when he has no more CARDS in his hand.
3. Our game allows multiple players to participate. After entering the program, the player should first enter the number of participants in the game, up to three. Since the game takes at least three people to start, the missing parts will be replaced by computer players.
4. To protect the game's fairness, players' CARDS will not be displayed on the screen. Instead, the information will be stored in corresponding files. For example, player1's hand CARDS will be stored in a file called "player1.txt". Then players take turns looking at their files. 

The game flow is as follows: 

1. Enter three player names, such as "player-Deng" and "player-Zhang". Separate the names with Spaces when input. 
3. Generate the order of playing cards. Each player's rank is displayed on the screen in the format "username: int".
4. Players take turns opening a file with information about their hand.
5. In this game, The cards 2,3,4,5,6,7,8,9,10,J,Q,K,A,grey joker and colour joker are represented respectively by 2,3,4,5,6,7,8,9,0,J,Q,K,A,G and C. After the players' order is generated, a list will be printed on the screen for easy reference.
6. Players take turns playing CARDS. The Numbers entered should be separated by Spaces. If the player chooses not to play this turn, type 0.
7. When a player's hand is empty, print "username wins!" on the screen.


## List of functions correspond to the coding requirement

1. We have two functions in our plan that correspond to requirement 1: the function that generate the order of players playing their cards, and the function that deals the cards (From the Numbers 1 to 54, 18 are randomly placed in a file, the next 18 in a second file, and the rest in a third file). 
2. We use data structure "Player" to store the imformation of players（player's name, and his corresponding file that stores his hands）: </br> struct Player{</br> string player_name, file_name;</br> };</br>The game winner and the state of play are also stored in this data structure: the game is going on when the three files containing the hands are not empty. When a file is empty, game over, and the winner is the player corresponding to the empty file.
3. Each time a player plays a valid card, the file that stores his hands will be updated. 
4. Create files called "Player1.txt", "Player2.txt" and "Player3.txt", each file store the cards the player own into it.
5. Split the program into multiple files. Main.cpp should have the main function, each of other files should have a function.
