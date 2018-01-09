#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

int main(int argc, char *argv[])
{
    FILE *outfile = NULL;

    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image.\n");
        return 1;
    }

    FILE *cardRaw = fopen(argv[1], "r");
    if (cardRaw == NULL)
    {
        fprintf(stderr, "Could not open forensic image %s.\n", argv[1]);
        return 2;
    }

    unsigned char buffer[512];
    int image=0;
    bool jpeg=false;

    //to read data from card.raw
    while(fread(buffer, 512, 1, cardRaw))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xe0) == 0xe0)
        {
            if (jpeg == true)
                fclose(outfile);
            else
                jpeg = true;
            char newJpeg[20];
            sprintf(newJpeg, "%03d.jpg", image);
            outfile = fopen(newJpeg, "a");
            image++;
        }
        if (jpeg == true)
            fwrite(&buffer, 512, 1, outfile);
    }
    fclose(cardRaw);
    fclose(outfile);
    return 0;
}
