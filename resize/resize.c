/**
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./resize n infile outfile\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];
    int f = atoi(argv[1]);
    
    if(f < 0 || f > 100)
    {
        printf("Error");
        return 1;
    }
    // open input file 
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

   bi.biHeight = bi.biHeight * f;
    bi.biWidth = bi.biWidth * f;
    
      // determine padding for scanlines
      int in_padding = (4 - ((bi.biWidth/f) * sizeof(RGBTRIPLE)) % 4) % 4;
      int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
      
       bi.biSizeImage = ((sizeof(RGBTRIPLE) * bi.biWidth) + padding) * abs(bi.biHeight) ;
      
      
     bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);
    
    
    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

     
    


    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < (biHeight)/f; i++)
    {
        int count = f;
        while(count)
        {
                
        
        // iterate over pixels in scanline
        for (int j = 0; j < (bi.biWidth)/f; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

          
            
        }
        
  
        count--;
        }
        
        
        fseek(inptr, ((bi.biWidth/f) * 3) ,SEEK_CUR);
        
        // skip over padding, if any
        fseek(inptr, in_padding, SEEK_CUR);

        
    
    
        
    }        


    // success
    return 0;
}
