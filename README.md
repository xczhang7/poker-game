# Poker game：simplified "Dou dizhu"

## Background
This is a group project for ENGG1340. Our goal is to produce a simple poker game in c++. The reason we chose "Dou dizhu" is that it's popular in China and its rules are simple enough. 

## The basic functions
The game "Dou dizhu" is a popular poker game in China. It has relatively simple and understandable rules. See wikipedia for the full version of the rules: https://en.wikipedia.org/wiki/Dou_dizhu.
However, in this project, we will ignore most of the special rules. Players will play under simplified rules of "Dou dizhu".
1. Players will no longer be divided into landowners and peasants. A total of 54 CARDS will be dealt equally among three players. The order of action now is randomly assigned before the game begins. 
2. The list of poker hands remains the same. 
3. Our game allows multiple players to participate. After entering the program, the player should first enter the number of participants in the game, up to three. Since the game takes at least three people to start, the missing parts will be replaced by computer players.
***
To protect the game's fairness, players' CARDS will not be displayed on the screen. Instead, the information will be stored in corresponding files. For example, player1's hand CARDS will be stored in a file called "player1.txt". Then players take turns looking at their files. 

