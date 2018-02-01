/*********************************************************************
 ** Program name: Ant Program
 ** Author: Romano Garza
 ** Date: 04/16/2017
 ** Description: Contains the funciton prototypes for moveAnt.cpp
 *********************************************************************/

#include <iostream>
#include <ctime>
#include <stdio.h>
#include <cstdlib>


#ifndef MOVEANT_HPP
#define MOVEANT_HPP


void startAnt(int **board, int rows, int columns, int moves);
void antMove(int **board, int rows, int columns, int antRow, int antCol, int moves);
void printMatrix(int **board, int rows, int columns, int antRow, int antCol);
void writeMatrix(int **board, int rows, int columns);

#endif
