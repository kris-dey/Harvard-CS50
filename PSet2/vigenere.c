#include<cs50.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main(int argc, string argv[])
{
    if(argc==2){
        string k = argv[1];

        for( int p =0, t= strlen(k); p<t; p++ ){
            if( !isalpha( k[p] ) )
            {
                 eprintf("Usage: ./vigenere k\n");
                 return 1;
            }
            k[p]=tolower(k[p]);
        }

        printf("plaintext: ");
        string s = get_string();
        int l = strlen(k);
        for( int n=0, i=0; s[n]!='\0'; n++ )
        {
            if( isalpha(s[n]) ){

                if( isupper(s[n]) )
                    s[n] = (s[n] -65 + k[i] - 97) % 26 + 65;
                else if(islower(s[n]))
                    s[n] = (s[n] -97 + k[i] - 97) % 26 + 97;

                i++;
            }

            if(i==l) i = 0;
        }

        printf("ciphertext: %s\n", s);
    }
    else{
        eprintf("Usage: ./vigenere k\n");
        return 1;
    }

}
