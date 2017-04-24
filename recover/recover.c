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
    
    // create buffer
    unsigned char buffer[512];
    
    // filename counter
    int filecount = 0;
    
    FILE* picture = NULL; 
    
    // check if we've found a jpeg yet or not
    int jpg_found = 0; //false
    
    // go through cardfile until there aren't any blocks left
    while (fread(buffer, 512, 1, input) == 1)
    {
        // read first 4 bytes of buffer and see if jpg signature using bitwise on last byte
       
        
        
        
    }

    

    return 0;
}