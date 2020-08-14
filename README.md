[![Build Status](https://travis-ci.org/oliversno/n-queens.svg?branch=master)](https://travis-ci.org/oliversno/n-queens)

# Installation:

# Genetic Algorithm:
Solving the n-queens problem with the Genetic Algorithm, https://en.wikipedia.org/wiki/Genetic_algorithm.

## Running:
``` $ ./genetic BOARD_SIZE NUM_CHROMOSONES MAX_NUM_ROUNDS ```

If the program finds a perfect solution before MAX_NUM_ROUNDS it will terminate early. Otherwise it will print a graph of the best fitness per round.

# Min Conflict
Solving the n-queens problem with min confllicts algorithm, https://en.wikipedia.org/wiki/Min-conflicts_algorithm.

## Running: 
``` $ ./min_conflict SIZE_OF_BOARD MAX_STEPS ```

If the program finds a perfect solution before MAX_STEPS it will terminate early.
