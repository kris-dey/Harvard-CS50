#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string s = get_string();
    int n=0;
    if(s[n]!=' ') printf("%c", toupper(s[n]));
    while (s[n] != '\0')
    {

        while(s[n]==' '&&s[n+1] != '\0') {
            n++;
            if(s[n]!=' '){
                printf("%c", toupper(s[n]));
            }
        }
        n++;
    }
    printf("\n");
}
