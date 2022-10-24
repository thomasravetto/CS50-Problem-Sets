# TODO

while True:
    # prompting the user for int between 1 and 8
    try:
        height = int(input("Height: "))
    except ValueError:
        continue
    if 0 < height < 9:
        break

# printing each row
for i in range(height):
    print(" " * (height - i - 1), end="")
    print("#" * (i + 1), end="")
    print("  ", end="")
    print("#" * (i + 1))