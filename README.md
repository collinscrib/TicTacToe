# TicTacToe in C++   
Currently works as an implementation of TicTacToe on the command line. With no command line flags, it plays Player vs. Player TicTacToe with a random starting player (X's or O's). By using command line flags, Player vs Computer can be played and unit tests can be ran on the program. The AI is very dumb, and just guesses randomly for where to play.

**Command line args:** 
* `-a` : Play Player vs. AI
* `-t` : Run unit tests on both a predetermined set, and a set with 2 random game boards.

## **Usage:**
`g++ *.cpp -o TicTacToe` in working directory, then `./TicTacToe <-a/-t>`

## **UML Diagram:**

![alt text](https://i.imgur.com/9ekIKOD.png "TicTacToe UML")

