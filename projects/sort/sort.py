import csv
from sys import argv, exit

if len(argv) != 2:
    print("Usage: python sort.py unsorted_file.txt")
    exit(1)

with open(argv[1], "r") as unsorted:
    print(list(unsorted))

sorted = unsorted

with open("sorted.txt", "a") as sorted:
    for number in sorted:
        sorted.write(number)


