#include<stdio.h>
#include<cs50.h>

int main(void)
{
    int height;
    do
    {
        printf("Enter height: ");
        height = get_int();
    }
    while ( height < 0 || height > 23);
    int row = 1;
    for (int x = height; x > 0; x--)
    {
        for ( int i = x - 1; i > 0; i-- )               //prints starting spaces
        {
            printf(" ");
        }
        for ( int k = 1; k <= row; k++)                 //prints first triangle
        {
            printf("#");
        }
        printf("  ");                                   //prints spaces between pyramids
        for ( int k = 1; k <= row; k++)                 //prints second pyramid
        {
            printf("#");
        }
        printf("\n");                                   //goes to next line
        row++;                                          //updates row by 1

    }
}
