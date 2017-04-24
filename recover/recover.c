#include <cs50.h>       
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    //ensuring usage
    if(argc!=2)
    {
        fprintf(stderr,"Wrong usage");
        return 1;
    }

    
    char *infile = argv[1];
    
    // open memory card file
    FILE* input = fopen(infile, "r");
    if (input == NULL)
    {
        printf("Could not open card.raw.\n");
        return 2;
    }

    

    return 0;
}