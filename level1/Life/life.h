/* ************************************************************************** */
/*                                                                            */

/*                                                        :::      ::::::::   */

/*   life.h                                             :+:      :+:    :+:   */

/*                                                    +:+ +:+         +:+     */

/*   By: fbetul <fbetul@student.42.fr>              +#+  +:+       +#+        */

/*                                                +#+#+#+#+#+   +#+           */

/*   Created: 2025/08/01 03:20:24 by fbetul            #+#    #+#             */

/*   Updated: 2025/08/01 03:30:24 by fbetul           ###   ########.fr       */

/*                                                                            */

/* ************************************************************************** */



#ifndef LIFE
# define LIFE

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define ALIVE 'O'
# define DEAD ' '



/**
 * @brief Represents the state and configuration of a Life game instance.
 *
 * Contains the dimensions, control parameters and the mutable game board used
 * by the simulation routines
 */
typedef struct s_game
 {
	int width;		// Game board width (number of columns).
	int height;		// Game board height (number of rows).
	int turn;		// Number of simulated turns/iterations.
	int i;			// Vertical position cursor for user input.
	int j;			// Horizontal position cursor for user input.
	int draw;		// Flag indicating whether drawing mode is active (1) or not (0).
	char** board;	// Pointer to the 2D array representing the game board.
}	t_game;

/**
 * @brief Initialize the game state and required resources from command-line arguments.
 *
 * @param game Pointer to the t_game structure to initialize.
 * @param argv Command-line arguments containing width, height, and iterations.
 * @return Returns 0 on success, or -1 if memory allocation fails.
 */
int init_game(t_game* game, char* argv[]);

/**
 * @brief Fill the game board based on user input from standard input.
 * @param game Pointer to the t_game structure containing the game state.
 */
void fill_board(t_game* game);

/**
 * @brief Count the number of alive neighbors for a given cell on the board.
 * @param game Pointer to the t_game structure containing the game state.
 * @param i Row index of the cell.
 * @param j Column index of the cell.
 * @return Returns the count of alive neighbors.
 */
int count_neighbors(t_game* game, int i, int j);

/**
 * @brief Advance the game state by one iteration according to the rules of Conway's Game of Life.
 * @param game Pointer to the t_game structure containing the game state.
 * @return Returns 0 on success.
 */
int play(t_game* game);

/**
 * @brief Print the current state of the game board to standard output.
 * @param game Pointer to the t_game structure containing the game state.
 */
void print_board(t_game* game);

/**
 * @brief Free the memory allocated for the game board.
 * @param game Pointer to the t_game structure containing the game state.
 */
void free_board(t_game* game);



#endif