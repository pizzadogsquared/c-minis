#ifndef BATTLESHIP_LIB_H
#define BATTLESHIP_LIB_H

//code by Elijah Sprouse

//header files
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

//global constants
#define SIZE 10





/**
 * Name: initializeRandom
 * Process: initialize the random number generator
 * Function input/parameters: None
 * Function output/parameters: None
 * Function output/returned: None
 * Dependencies: stdlib.h - srand
 * 				 time.h - time
 **/
void initializeRandom();





/**
 * Name: printMatrix
 * Process: print the 2D array passed via parameter
 * Function input/parameters:
 * 			matrix[SIZE][SIZE] - a 2D array SIZE by SIZE
 * Function output/parameters: None
 * Function output/returned: None
 * Dependencies: printf() - prints message to user
 **/
void printMatrix(const char matrix[SIZE][SIZE]);





/**
 * Name: buildBoard
 * Process: fill every index in matrix with a single char
 * Function input/parameters:
 * 			board[SIZE][SIZE] - a 2D array SIZE by SIZE
 *			c - a character to fill every element in board[SIZE][SIZE]
 * Function output/parameters: None
 * Function output/returned: 
 *			board[SIZE][SIZE]
 * Dependencies: None
 **/
void buildBoard(char board[SIZE][SIZE], char c);





/**
 * Name: isWater
 * Process: check if the user has missed the ships
 * Function input/parameters:
 * 			board[SIZE][SIZE] - a 2D array SIZE by SIZE
 *			row - user-entered coordinate
 *			col - user-entered coordinate
 * Function output/parameters: None
 * Function output/returned: 
 *			true - the user has missed and didn't hit a ship given coords
 *			false - the user hit a ship with the given coordinates
 * Dependencies: stdbool.h - for bool data type
 **/
bool isWater(const char board[SIZE][SIZE], int row, int col);





/**
 * Name: placeShipHorizontal
 * Process: place a ship on the given board of given length horizontally
 * Function input/parameters:
 * 			board[SIZE][SIZE] - a 2D array SIZE by SIZE
 * 			shipLength - how many horizontal sequential spaces a ship takes
 * Function output/parameters: None
 * Function output/returned: 
 * 			board[SIZE][SIZE]
 * Dependencies: rand() to generate random coordinates to place the ship
 **/
void placeShipHorizontal(char board[SIZE][SIZE], int shipLength);





/**
 * Name: placeShipVertical
 * Process: place a ship on the given board of given length vertically
 * Function input/parameters:
 * 			board[SIZE][SIZE] - a 2D array SIZE by SIZE
 * 			shipLength - how many horizontal sequential spaces a ship takes
 * Function output/parameters: None
 * Function output/returned: 
 * 			board[SIZE][SIZE]
 * Dependencies: rand() to generate random coordinates to place the ship
 **/
void placeShipVertical(char board[SIZE][SIZE], int shipLength);





/**
 * Name: fillBoard
 * Process: places multiple ships of set length in random orientations
 * Function input/parameters:
 * 			board[SIZE][SIZE] - a 2D array SIZE by SIZE
 * Function output/parameters: None
 * Function output/returned: 
 * 			board[SIZE][SIZE]
 * Dependencies:
 * 				rand() to randomly decide whether to place vert. or horiz.
 * 				placeShipHorizontal()
 * 				placeShipVertical()
 **/
void fillBoard(char board[SIZE][SIZE]);





/**
 * Name: shoot
 * Process: changes user board to reflect if the hit was successful
 * Function input/parameters:
 * 			solution[SIZE][SIZE] - the game board containing info on ships
 *			game[SIZE][SIZE] - the game board the user sees and plays on
 *			row - user-entered coordinate reflecting where they want to shoot
 * 			col - user-entered coordinate reflecting where they want to shoot
 * Function output/parameters: None
 * Function output/returned: 
 * 			board[SIZE][SIZE]
 * Dependencies:
 * 				isWater()
 * 				printf() - tells the user if they hit or miss
 **/
void shoot(const char solution[SIZE][SIZE], char game[SIZE][SIZE],
			int row, int col);





/**
 * Name: checkVictory
 * Process: checks to see if all ships are hit
 * Function input/parameters:
 * 			solution[SIZE][SIZE] - the game board containing info on ships
 *			game[SIZE][SIZE] - the game board the user sees and plays on
 * Function output/parameters: None
 * Function output/returned: 
 * 			true - the user has won the game
 * 			false - the user hasn't won the game yet
 * Dependencies: stdbool.h - for bool data type
 **/
bool checkVictory(const char solution[SIZE][SIZE],
					const char game[SIZE][SIZE]);







#endif