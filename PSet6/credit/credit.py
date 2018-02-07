from cs50 import get_int


def main():
    print("Number: ", end='')
    creditCardNumber = get_int()
    count = 0
    temp = creditCardNumber
    temp2 = creditCardNumber

    """to calculate the number of digits"""
    while temp != 0:
        count = count + 1
        temp = temp // 10

    product = 0
    sum1 = 0

    """to find the sum"""
    while temp2 >= 10:
        sum1 = (temp2 % 10) + sum1
        temp2 = (temp2 // 10)
        product = (temp2 % 10) * 2
        temp2 = temp2 // 10
        if product > 9:
            sum1 = (product % 10) + (product // 10) + sum1
        else:
            sum1 = product + sum1

    sum1 = sum1 + temp2

    """to identify the bank"""
    if (sum1 % 10) ==0 :
        if count == 15:
            print("AMEX");
        if count == 13:
            print("VISA");
        if count==16 :
            if (creditCardNumber // 1000000000000000) == 4:
                print("VISA")
            else:
                print("MASTERCARD")
    else:
        print("INVALID")

if __name__ == "__main__":
    main()