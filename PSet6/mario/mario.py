from cs50 import get_int


def main():
    height = 0
    while True:
        print("Enter Height: ", end='')
        height = get_int()
        if 0 <= height <= 23:
            break

    row = 1

    for x in range(height, 0, -1):
        for i in range(x-1, 0, -1):
            print(" ", end='')
        for k in range(1, row + 1, 1):
            print("#", end='')
        print("  ", end='')
        for k in range(1, row + 1, 1):
            print("#", end='')
        row = row + 1
        print("")


if __name__ == "__main__":
    main()