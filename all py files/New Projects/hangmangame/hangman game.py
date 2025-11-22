import random
import string

from words import words


def getword(words):
    word = random.choice(words)
    while '-' in word or ' ' in word:
        word = random.choice(words)
    return word.upper()


def hangman():


    word = getword(words)
    letters = set(word)
    alphabet = set(string.ascii_uppercase)
    used_letters = set()
    lives = 7

    while len(letters) > 0 and lives > 0:
        print(f"You have {lives} lives left and used these letters so far: {' '.join(used_letters)}")

        word_list = [letter if letter in used_letters else '-' for letter in word]
        print(f"Word: {' '.join(word_list)}")

        user_input = input("Guess a character: ").upper()

        if len(user_input) != 1 or user_input not in alphabet:
            print("Invalid input. Please enter a single letter.")
            continue

        if user_input in used_letters:
            print(f"You already guessed the letter {user_input}.")
        else:
            used_letters.add(user_input)
            if user_input in letters:
                letters.remove(user_input)
            else:
                lives -= 1
                print(f"The letter {user_input} is not in the word. Lives left: {lives}")

    if lives > 0:
        print(f"Congratulations! You've guessed the word: {word}")
    else:
        print(f"Sorry, you're out of lives. The word was: {word}")


# Run the game
hangman()
