#include<stdio.h>
#include<cs50.h>

int main(void)
{
    printf("NUMBER: ");
    long long creditCardNumber = get_long_long();
    int count=0;
    long long temp=creditCardNumber, temp2=creditCardNumber ;
    while(temp!=0) {count++; temp = temp/10;}

    int product, sum1 = 0 ;

        while(temp2>=10)
        {
            sum1 = (temp2%10) + sum1;
            temp2=temp2/10;
            product=(temp2%10)*2;
            temp2=temp2/10;
            if(product>9)
                sum1 = (product%10)+(product/10) + sum1;
            else
                sum1 = product + sum1;
        }
        sum1 = sum1 + temp2;



    if(sum1%10==0)
    {
        if(count==15) printf("AMEX\n");
        if(count==13) printf("VISA\n");
        if(count==16)
        {
            if((creditCardNumber/1000000000000000)==4)
                printf("VISA\n");
            else
                printf("MASTERCARD\n");
        }
    }
    else
        printf("INVALID\n");
}
