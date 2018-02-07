from cs50 import get_string
import sys

def main():
    if len(sys.argv) == 2:
        f = sys.argv[1]
        k = int(f)
        print("plaintext: ", end="")
        s = get_string()
        print("ciphertext: ", end="")
        for c in s:
            #checking if alphabet
            if c.isalpha():
                #checking if uppercase
                if c.isupper():
                    d = (ord(c) - 65 + k) % 26 + 65
                    c = chr(d)
                    print(c, end="")
                #checking if lowercase
                elif c.islower():
                    d = (ord(c) - 97 + k) % 26 + 97
                    c = chr(d)
                    print(c, end="")
            else:
                print(c, end="")
        print("")

    else:
        print("Usage: ./caesar k")
        sys.exit(1)

if __name__ == "__main__":
    main()