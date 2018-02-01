/*********************************************************************
** Program name: Ant Program
** Author: Romano Garza
** Date: 04/16/2017
** Description: Main file for Ant Program. Program constructs a version
** of Langston's ant. 
*********************************************************************/


#include "menu.hpp"



void introduction();

/**********************************************************************
** Description: Introduction of the program occurs first. Then the menu
** function gets called. When finished, goodbye message is displayed
**********************************************************************/

int main()
{

    introduction();
    menu();
    
    
    std::cout << std::endl << "See Ya!" << std::endl;
    
    
    
    return 0;
}



/**********************************************************************
** Description: introduces the program
**********************************************************************/

void introduction()
{
    std::cout << "This  program lets  you choose: the  size of  a randomized" << std::endl;
    std::cout << "Langston's ant matrix, the number  of  steps you  want the" << std::endl;
    std::cout << "ant to take and the ant  starting location. When ready you" << std::endl;
    std::cout << "can enter 1 and watch it go..." << std::endl << std::endl;

}




