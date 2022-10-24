# TODO
while True:
    try:
        change = float(input("Change owed: "))
    except ValueError:
        continue
    if change >= 0:
        break

coins = 0
total = change * 100
# subtracting 25 from total
while total >= 25:
    total -= 25
    coins += 1

# subtracting 10 from total
while total >= 10:
    total -= 10
    coins += 1

    # subtracting 5 from total
while total >= 5:
    total -= 5
    coins += 1

    # subtracting 1 from total
while total >= 1:
    total -= 1
    coins += 1

print(f"{coins}")

