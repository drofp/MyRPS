# MyRPS - A Simple Rock Paper Scissors Game
**NOTE:** This project is purely for academic purposes for satisfying program requirements for [CMPE 135](http://www.cs.sjsu.edu/~mak/CMPE135/index.html) at San Jose State University  

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
- [ ] Add simple machine learning algorithm ([overview found here](https://github.com/drofp/MyRPS/wiki#simple-machine-learning-algorithm-overview))
- [ ] Design an interface (abstract class) with pure virtual member functions to represent the computer’s choice algorithm.
  - [ ] Implement the interface with the random choice class and with the simple ML choice class.
  - [ ] Use a factory class to create algorithm objects.
  - [ ] Code to the interface.
- [ ] Be able to swap between the two algorithms with minimal changes to the rest of the code.
  - [ ] Implement a command-line option, such as -r for random and -m for machine learning. (This is implemented as menu options in our version)
- [ ] The ML version must save its frequency data at the end of each game to be read at the start of the next game.

## Future Improvements
- [ ] How the opposing (i.e., human) player’s choices are obtained.
  - [ ] How the computer makes its choices (it may not always be random).

