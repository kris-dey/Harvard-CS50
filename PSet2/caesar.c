#include<cs50.h>
#include<stdio.h>
#include<ctype.h>

int main(int argc, string argv[])
{
    if(argc==2){
        string f = argv[1];
        int k = atoi(f);
        printf("plaintext: ");
        string s = get_string();

        for(int n=0; s[n]!='\0'; n++)
        {
            if(isalpha(s[n])){
                if(isupper(s[n]))
                    s[n] = (s[n] -65 + k) % 26 + 65;
                else if(islower(s[n]))
                    s[n] = (s[n] -97 + k) % 26 + 97;
            }
        }

        printf("ciphertext: %s\n", s);
    }
    else{
        eprintf("Usage: ./caesar k\n");
        return 1;
    }

}
