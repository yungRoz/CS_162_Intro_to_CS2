/*********************************************************************
** Program name: Ant Program
** Author: Romano Garza
** Date: 04/16/2017
** Description: Files contains get_int, a function that checks user 
** input for integer validation.
*********************************************************************/


#include "integerValidation.hpp"

#define EPRINT(fmt, ...)    fprintf(stderr, fmt, ##__VA_ARGS__)

#ifdef VERBOSE
#define VPRINT(rsn) EPRINT("ERROR: %s from %s (%d)", rsn, __PRETTY_FUNCTION__, __LINE__)
#else
#define VPRINT(rsn) ((void)0)
#endif

/**********************************************************************
** Description: get_int function takes in user input address and checks
** if the user entered something and also if the user input is an int-
** eger. In the event that both scenarios are met, the function returns
** a 0 integer.
**********************************************************************/

int get_int(int *ptr)
{
    int status = -1;
    char buffer[4096];
    
    if (fgets(buffer, sizeof(buffer), stdin) == NULL)
    {
        VPRINT("Reached EOF while reading data");
    }
    else if (sscanf(buffer, "%d", ptr) !=1)
    {
        VPRINT("Number not detected.");
    }
    else
    {
        status = 0;
    }
    
    
    return status;
}

