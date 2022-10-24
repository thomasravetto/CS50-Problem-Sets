# TODO
def main():
    text = str(input("Text: "))

    # Assigning to letters the value of the number of letters
    letters = count_letters(text)

    # Assigning to words the value of the number of words
    words = count_words(text)

    # Assigning to sentences the value of the number of sentences
    sentences = count_sentences(text)

    L = letters / words * 100
    S = sentences / words * 100

    # Calculating the grade
    grade = round(0.0588 * L - 0.296 * S - 15.8)

    # Printing the grade
    if grade < 1:
        print("Before Grade 1")
    elif grade > 16:
        print("Grade 16+")
    else:
        print(f"Grade {grade}")

# Defining a function that returns the number of letters that the text contains


def count_letters(text):
    lett_num = 0
    for letter in text:
        if letter.isalpha():
            lett_num += 1
    return lett_num

# Defining a function that returns the number of words that the text contains


def count_words(text):
    words = len(text.split())
    return words

# Defining a function that returns the number of words that the text contains


def count_sentences(text):
    punctuation = ['.', '?', '!']
    sentence_num = 0
    for sentence in text:
        if sentence in punctuation:
            sentence_num += 1
    return sentence_num


main()
