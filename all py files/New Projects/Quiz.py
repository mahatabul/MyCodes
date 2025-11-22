import random

# Dictionary containing the quiz questions and answers
quiz_dict = {
    "What does CPU stand for?": "Central Processing Unit",
    "What does RAM stand for?": "Random Access Memory",
    "Which type of memory is non-volatile?": "ROM",
    "What is the common term for a computer program that replicates itself and spreads to other devices?": "Virus",
    "What does HTTP stand for?": "Hypertext Transfer Protocol",
    "What does SSD stand for?": "Solid State Drive",
    "What does URL stand for?": "Uniform Resource Locator"
}


def ask_question(question, correct_answer):
    answer = input(question + " ").capitalize()
    if answer == correct_answer.capitalize():
        print("Correct!!")
    else:
        print(f"Wrong answer. The correct answer is {correct_answer}.")


def quiz_game():
    print("Hello \nWant to play a quiz?")
    x = input("yes/no: ").lower()
    if x == "no":
        quit()

    # Shuffle the questions
    questions = list(quiz_dict.keys())
    random.shuffle(questions)

    # Ask each question
    for question in questions:
        correct_answer = quiz_dict[question]
        ask_question(question, correct_answer)

    print("Quiz finished! Thanks for playing.")


# Run the quiz game
quiz_game()
