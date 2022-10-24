# TODO

# Prompt the user for card number and check its length
def main():
    card = int(input("Enter card number: "))

    # Checking card length
    if len(str(card)) > 16 or len(str(card)) < 13:
        print("INVALID")
        exit(1)

    # Calling functions to determine if the card is valid
    if card_sum(card):
        type = check_card_type(card)
        print_card_type(type)
    else:
        print("INVALID")
        exit(1)


# Applying Luhn's algorithm to check if the card number is valid
def card_sum(card):
    total = 0
    # Multiplying every other number * 2 starting from second-to-last
    for i in range(1, len(str(card)), 2):
        digit = get_digit(card, i)
        digit *= 2
        if len(str(digit)) == 1:
            total += digit
        elif len(str(digit)) == 2:
            total += (get_digit(digit, 1) + get_digit(digit, 0))

    # Adding every number that was not multiplied to the total
    for i in range(0, len(str(card)), 2):
        digit = get_digit(card, i)
        total += digit

    if get_digit(total, 0) == 0:
        return True
    return False

# Checking the card type (VISA, MASTERCARD, AMEX, INVALID)


def check_card_type(card):
    card
    if len(str(card)) == 15:
        if get_digit(card, 14) == 3 and get_digit(card, 13) == 4 or 7:
            card = 'AMEX'
            print_card_type(card)
            return
    if len(str(card)) == 16:
        if get_digit(card, 15) == 5 and 1 <= get_digit(card, 14) <= 5:
            card = 'MASTERCARD'
            print_card_type(card)
            return
        elif get_digit(card, 15) == 4:
            card = 'VISA'
            print_card_type(card)
            return
    if len(str(card)) == 13:
        if get_digit(card, 12) == 4:
            card = 'VISA'
            print_card_type(card)
            return

# Printing the card type


def print_card_type(card):
    if card == 'AMEX':
        print("AMEX")
        exit(0)
    elif card == 'MASTERCARD':
        print("MASTERCARD")
        exit(0)
    else:
        print("VISA")
        exit(0)

# Function to get a certain digit in an int


def get_digit(number, n):
    return number // 10**n % 10


main()