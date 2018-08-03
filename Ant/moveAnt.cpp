/*********************************************************************
 ** Program name: Langston's Ant Program
 ** Author: Romano Garza
 ** Date: 04/16/2017
 ** Description: This file contains the functions needed for the Langs
 ** -ton's Ant Program: startAnt, writeMatrix, antMove and printMatrix.
 *********************************************************************/

/*
 Sources:
 For use of random:
 http://stackoverflow.com/questions/17618264/srand-time-null-causes-compiler-warning-implicit-conversion-loses-integer-p
 */

#include "moveAnt.hpp"

/**********************************************************************
** Description: startAnt gets called  when the user does  not specify a
** starting place for the ant. It takes a pointer to a 2-d array(board),
** along with the # of rows,  columns, and moves. A number is generated
** by rand(), the number is between 0 and one less than the size of the
** rows or columns. The user  is told  the starting ant row and column.
** Then, writeMatrix gets passed the board, and # of rows, and columns.
** After writeMatrix writes to the matrix, antMove gets passed the board,
** # rows, columns, and moves along with the randomized ant location.
**********************************************************************/

void startAnt(int **board, int rows, int columns, int moves)
{
    int antRow = rand()%(rows);
    int antCol = rand()%(columns);
    antMove(board, rows, columns, antRow, antCol, moves);
}


/**********************************************************************
** Description: writeMatrix takes a pointer to a 2-d array(board), and
** the # of rows and columns. To randomly write the board with "blank"
** and "black" spaces, rand() is utilized to generate a random number,
** if the number is divisible by 2, 0 is written to the space to rep.
** a blank space, and if it's not, 1 is written to the space to rep. a
** black space.
**********************************************************************/

void writeMatrix(int **board, int rows, int columns)
{
    srand(static_cast<unsigned int>(time(NULL)));


    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<columns; j++)
        {
            if(((rand()%2)== 0))
            {
                board[i][j] = 0;
            }
            else
            {
                board[i][j] = 1;
            }
        }
    }

}


/**********************************************************************
** Description: antMove takes all of the necessary arguments to   carry
** out the process of moving the ant: the board, # of rows and columns,
** ant row and column, and # of moves. The ant is initially facing  the
** top of the matrix (north).  If the ant's location is a 0 ("blank") t
** -hen the location value gets changed to 1 "black".  It must travel 1
** index location to the right. Thus, if the ant is facing  north, then
** it is now facing the direction east and will move one column forward
** in this direction. Therefore, everytime the ant is at a 0 ("blank"),
** it needs to turn clock wise once and move forward. So the switch sta
** -tement for 0 operates in this fashion, i.e. if at 0 and facing north
** ,face east, if facing east, face south, if facing south, face west,
** if facing west, face north. The opposite occurs when the ant is at a
** 1 ("black"), it needs to turn counter clock wise once. So the switch
** statement for 1 operates in this fashion: if  at 1 and facing north,
** face west,  if facing west, face south,  if facing south, face east,
** if facing east, face north.  Each time the ant moves a new direction
** east  or south, it's new  location  is calculated based on the fact
** the new ant column or  row will  be the remainder of the current ant
** column (or row) + 1 divided by the total number of columns. When the
** ant neeeds to go north or west, to prevent  the aunt from  traveling
** off the board when it is going west or north, if/else statements are
** utilized.
**********************************************************************/

void antMove(int **board, int rows, int columns, int antRow, int antCol, int moves)
{

    enum direction {n, e, s, w};
    direction antDir = n;

    int moveCount = 0;

    std::cout << "Starting Ant Row   : " << antRow << std::endl;
    std::cout << "Starting Ant Column: " << antCol << std::endl << std::endl;

    while(moveCount < moves)
    {

        std::cout << "MOVE: " << moveCount + 1 << std::endl;
        std::cout << "ANT DIRECTION: ";
        if(antDir == n)
        {
            std::cout << "∧";
        }
        else if(antDir == s)
        {
            std::cout << "V";
        }
        else if(antDir == e)
        {
            std::cout << ">";
        }
        else if(antDir == w)
        {
            std::cout << "<";
        }


        if ( board[antRow][antCol] == 0)
        {
            std::cout << " on an empty space, moving right ";
            printMatrix(board, rows, columns, antRow, antCol);
            board[antRow][antCol] = 1;
            moveCount++;
            switch(antDir)
            {
                case n:
                {
                    antDir = e;
                    antCol = ((antCol + 1)%columns);
                    break;
                }
                case e:
                {
                    antDir = s;
                    antRow =((antRow + 1)%rows);
                    break;
                }
                case s:
                {
                    antDir = w;
                    if ((antCol - 1) < 0)
                    {
                        antCol = (columns - 1);
                    }
                    else
                    {
                        antCol = (antCol -1);
                    }
                    break;
                }
                case w:
                {
                    antDir = n;
                    if ((antRow - 1) < 0)
                    {
                        antRow= (rows - 1);
                    }
                    else
                    {
                        antRow = (antRow -1);
                    }
                    break;
                }
            }
        }
        else
        {
            std::cout << " on a black space, moving left"; 
            printMatrix(board, rows, columns, antRow, antCol);
            board[antRow][antCol] = 0;
            moveCount++;
            switch(antDir)
            {
                case n:
                {
                    antDir = w;
                    if ((antCol - 1) < 0)
                    {
                        antCol = (columns - 1);
                    }
                    else
                    {
                        antCol = (antCol -1);
                    }
                    break;
                }
                case e:
                {
                    antDir = n;
                    if ((antRow - 1) < 0)
                    {
                        antRow= (rows - 1);
                    }
                    else
                    {
                        antRow = (antRow -1);
                    }
                    break;
                }
                case w:
                {
                    antDir = s;
                    antRow =((antRow + 1)%rows);
                    break;
                }
                case s:
                {
                    antDir = e;
                    antCol = ((antCol + 1)%columns);
                    break;
                }
            }
        }

    }

}

/**********************************************************************
** Description: printMatrix simply prints the board, given the board
** sizes and ant locations.
**********************************************************************/
void printMatrix(int **board, int rows, int columns, int antRow, int antCol)
{
    std::cout << std::endl;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            if((i == antRow) && (j == antCol))
            {
                std::cout << '@';
            }
            else if(board[i][j] == 0)
            {
                std::cout << ' ';
            }
            else if(board[i][j] == 1)
            {
                std::cout << '#';
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
