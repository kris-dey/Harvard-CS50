#include<stdio.h>
#include<cs50.h>

int main(void)
{
    printf("Minutes: ");
    int minutes = get_int();            //gets the input
    int bottles = minutes * 12;         //evaluates water used in terms of bottles
    printf("Bottles: %i \n", bottles);  //prints the result
}
