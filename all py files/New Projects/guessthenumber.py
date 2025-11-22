import random


def game(s, e, chance):
    target = random.randint(s, e)
    while chance:
        usrchoice = input("Enter your guess or Quit(q): ")
        if usrchoice == "q":
            print("You left the game midway ... try again later")
            break
        usrchoice = int(usrchoice)
        if usrchoice == target:
            print("wow!! you won")
            break
        elif usrchoice > target:
            chance -= 1
            print("Your guess is more than the target number. Guess smaller...")
            print(chance, "chances remaining")
        elif usrchoice < target:
            chance -= 1
            print("Your guess is less than the target number. Guess bigger...")
            print(chance, "chances remaining")

    if chance == 0:
        print("You lost!! the target was", target)


def infinitymode(s, e):
    target = random.randint(s, e)
    while True:
        usrchoice = input("Enter your guess or Quit(q): ")
        if usrchoice == "q":
            print("You left the game midway ... try again later")
            break
        usrchoice = int(usrchoice)
        if usrchoice == target:
            print("wow!! you won")
            break
        elif usrchoice > target:

            print("Your guess is more than the target number. Guess smaller...")

        elif usrchoice < target:

            print("Your guess is less than the target number. Guess bigger...")


print("Hello "
      "welcome to guess the number game".title())

user = input("press 's' to start or 'q' to quit: ")
if user == "q":
    print("quit")
else:
    s = int(input("Enter start point: "))
    e = int(input("Enter end point: "))
    chance = input("Enter chances ... for infinity chances write 'infinite' : ")

    if chance == "infinite":
        infinitymode(s, e)
    else:
        chance = int(chance)
        game(s, e, chance)
