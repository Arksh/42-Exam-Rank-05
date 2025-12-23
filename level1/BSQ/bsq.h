/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbetul <fbetul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:39:16 by fatkeski          #+#    #+#             */
/*   Updated: 2025/07/31 23:05:16 by fbetul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
#define BSQ_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_elements
{
	int n_lines;		// number of lines in the map
	char empty;			// character representing empty space
	char obstacle;		// character representing an obstacle
	char full;			// character representing the full square

} t_elements;

typedef struct s_map
{
	char** grid;		// 2D array representing the map
	int width;			// width of the map
	int height;			// height of the map
} t_map;

typedef struct s_square
{
	int size;			// size of the largest square
	int i;				// starting row index of the largest square
	int j;				// starting column index of the largest square
} t_square;

int execute_bsq(FILE* file);
int convert_file_pointer(char* name);

#endif
