/*********************************************************************
** Program name: Ant Program
** Author: Romano Garza
** Date: 04/16/2017
** Description: File that contains a displayMenu, menu, and processRequest
** functions. 
*********************************************************************/

#include "menu.hpp"


void displayMenu()
{
    std::cout << std::endl << "            Langston's Ant Menu" << std::endl <<std::endl;
    std::cout << "***Extra Credit: if you  want the ant to start at a random" << std::endl;
    std::cout << "spot, simply start the program without entering a location" << std::endl;
    std::cout << "for the ant. " << std::endl << std::endl;
    std::cout << "1.  Start Program" <<std::endl;
    std::cout << "2.  Enter # of Rows and Columns" <<std::endl;
    std::cout << "3.  Enter # of steps" <<std::endl;
    std::cout << "4.  Enter the Ant's starting location" << std::endl;
    std::cout << "5.  Quit Program" << std::endl <<std::endl;
}

/**********************************************************************
** Description:  Menu displays  the menu, and then  based on  the  user
** choice the program will either start ask  the user to enter the # of
** rows and columns, ask the user to enter the # of ant moves, ask  the 
** user to enter the ant location or quit. It is required that the user 
** enter  the # of  rows and  columns  and the #  of  ant moves  before
** starting the program (ant location is not necessary as it can  start
** out randomly). If the user wants to enter the ant starting location, 
8* they must first specify the board size.
**********************************************************************/

void menu()
{
    int rows = -1;                              //all variables are initialized to 0 so
    int columns = -1;                           //they can be checked that the user has
    int antRow = -1;                            //entered something into them
    int antCol = -1;
    int moves = -1;
    int choice;
    do
    {
        displayMenu();
        
        do
        {
            printf("Enter your choice: ");
        }while ((get_int(&choice) != 0) || (choice<=0) || (choice >5));
        
        if (choice != 5)
        {
            switch (choice)
            {
                case 1:
                {
                    //request is processed only if # of rows
                    //columns and moves are all >= 0.
                    
                    if((rows <= 0) ||(columns <= 0) ||(moves <= 0))
                    {
                        
                        std::cout << std::endl;
                        std::cout << "*******************************";
                        std::cout << "*******************************" << std::endl;
                        std::cout << "Woah, EZ there! You can't start";
                        std::cout << " without entering a value for: ";
                        std::cout << std::endl;
                        
                        if(rows < 0)
                        {
                            std::cout << "    # of rows" <<std::endl;
                        }
                        if(columns < 0)
                        {
                            std::cout << "    # of columns" << std::endl;
                        }
                        if(moves < 0)
                        {
                            std::cout << "    # of steps" << std::endl;
                        }
                        std::cout << "*******************************";
                        std::cout << "*******************************" << std::endl;
                    }
                    else if((antRow < 0) ||(antCol < 0))
                    {
                        std::cout << std::endl;
                        std::cout << "Note: Ant starting location";
                        std::cout << " is random!" << std::endl << std::endl;
                        processRequest(rows, columns, antRow, antCol, moves);
                    }
                    else
                    {
                        processRequest(rows, columns, antRow, antCol, moves);
                    }
                    break;
                    
                }
                case 2:
                    
                {
                    //user is not allowed out of bounds choices
                    do
                    {
                        printf("Enter the # of rows for your build (<=80): ");
                    }while((get_int(&rows) !=0 ) || (rows > 80) || (rows<=0));
                    
                    do
                    {
                        printf("Enter the # of columns for your build (<=80): ");
                    }while((get_int(&columns) !=0) || ((columns > 80) || (columns <=0))) ;
                    
                    break;
                }
                case 3:
                {
                    do
                    {
                        printf("Enter the # of times you want the ant to move: ");
                    }while((get_int(&moves) !=0) || (moves<=0));
                    break;
                }
                case 4:
                {
                    //user is not allowed to choose a starting
                    //location without specifying the size of
                    //the board
                    
                    if((rows < 0) ||(columns < 0))
                    {
                        std::cout << std::endl;
                        std::cout << "********************************************";
                        std::cout << "************************" << std::endl;
                        std::cout << "Woah, EZ there! You can't choose a location ";
                        std::cout << "without first choosing: " <<std::endl;
                        
                        
                        if(rows < 0)
                        {
                            std::cout << "    # of rows" <<std::endl;
                        }
                        if(columns < 0)
                        {
                            std::cout << "    # of columns" << std::endl;
                        }
                        std::cout << "********************************************";
                        std::cout << "************************" << std::endl;
                    }
                    else
                    {
                        //user is not allowed out of bounds choices
                        do
                        {
                            printf("Enter the row where the ant will start (first row is 0): ");
                        }while((get_int(&antRow) != 0) || ((antRow < 0 )  || (antRow >= rows)));
                        
                        do
                        {
                            printf("Enter the column where the ant will start (first column is 0): ");
                        }while((get_int(&antCol) !=0) || ((antCol < 0 ) || (antCol >= columns)));
                        
                    }
                    break;
                }
                {
                    
                }
            }
        }
        
    }while(choice!=5);
    
}

/**********************************************************************
 ** Description: processRequest builds a board to the specifications of
 ** the user, and calls startAnt if the user did not  enter  a starting
 ** location or if the user did  enter  a starting  location, it calls
 ** writeMatrix and antMove.
 **********************************************************************/

void processRequest(int rows, int columns, int antRow, int antCol,int moves)
{
    int** board = new int*[rows];
    for(int i = 0; i < rows; ++i)
    {
        board[i] = new int[columns];
    }
    
    writeMatrix(board, rows, columns);
    
    if(antRow <=0 || antCol <=0)
    {
        startAnt(board, rows, columns, moves);              //NOTE: startAnt will eventually call writeMatrix and antMove
    }
    else
    {
        antMove(board, rows, columns, antRow, antCol, moves);
    }
    
    for(int i = 0; i < rows; ++i)
    {
        delete [] board[i];
    }
    delete [] board;
}

