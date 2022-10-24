# TODO
while True:
    # if user input a value that is more than 8 or less than 1, or not an int the program will prompt again
    try:
        height = int(input("Height: "))
    except ValueError:
        continue
    if 0 < height < 9:
        break
    # printing each row
for i in range(height):
    print(" " * (height - i - 1), end="")
    print("#" * (i + 1))
