# MyRPS - A Simple Rock Paper Scissors Game
**NOTE:** This project is purely for academic purposes for satisfying program requirements for [CMPE 135](http://www.cs.sjsu.edu/~mak/CMPE135/index.html) at San Jose State University  

## Prerequisites
Please have [wxWidgets](http://www.cs.sjsu.edu/~mak/tutorials/InstallwxWidgets.pdf) and [Boost](https://www.boost.org/) installed before attempting to build the project.

## How to Run
Run these commands at root of project to compile and run
```bash
make
./bin/main
```

## Assignment Tasks
### v0.1 (Homework 3)
- [x] Implement the first version of the Rock-Paper-Scissors game.
  - [x] Each game has 20 rounds.
  - [x] Prompt the human player for each round’s choice.
  - [x] The computer makes a random choice.  

### v0.2 (Homework 4)
- [x] Add simple machine learning algorithm ([overview found here](https://github.com/drofp/MyRPS/wiki#simple-machine-learning-algorithm-overview))
- [x] Design an interface (abstract class) with pure virtual member functions to represent the computer’s choice algorithm.
  - [x] Implement the interface with the random choice class and with the simple ML choice class.
  - [x] Use a factory class to create algorithm objects.
  - [x] Code to the interface.
- [x] Be able to swap between the two algorithms with minimal changes to the rest of the code.
  - [x] Implement a command-line option, such as -r for random and -m for machine learning. (This is implemented as menu options in our version)
- [x] The ML version must save its frequency data at the end of each game to be read at the start of the next game.

### v1.0 (Homework 5)
- Minimum features
  - [x] Which round
  - [x] A way for the user to enter a choice for each round.
  - [x] The computer’s prediction of the human’s choice for the round.
  - [x] The computer’s choice for the round.
  - [x] Who the winner is (or is it a tie) of the round.
  - [x] The number of human and computer wins, and the number of ties.
- Menu Commands
  - [x] About
  - [x] Exit
  - [x] Start new game
- [x] Provide way for human player to change number of rounds per game
  - [x] Default is 20 rounds per game
