# # This is rockpaperscissors game version 2.0
# import random
# print("Hello")
# x = input("what is your name: ")
# print(f"hi {x} ".title())
# print("Welcome to Rock Paper Scissors game.".title())
# def player_computer_choices():
#     choicelist = ["rock", "paper", "scissors"]
#     playerchoice = input("Enter Your Choice(rock,paper,scissors): ")
#     computerchoice = random.choice(choicelist)
#
#     return playerchoice, computerchoice
# def whowon(player, computer):
#         print(f"the player choose [{player}] & the computer choose [{computer}]")
#         if player == computer:
#
#             return "Tie"
#         elif player != computer:
#             if player == "rock":
#                 if computer == "paper":
#
#                     return ("Paper takes Rock  "
#                             " computer Won")
#                 else:
#
#                     return ("Rock breaks Scissors"
#                             " You Won!!")
#
#             elif player == "paper":
#                 if computer == "scissors":
#
#                     return ("Scissors cut Paper"
#                             " computer Won")
#                 else:
#
#                     return ("Paper takes Rock"
#                             " You Won!!")
#             elif player == "scissors":
#                 if computer == "rock":
#
#                     return ("Rock breaks Scissors"
#                             " computer won")
#                 else:
#
#                     return ("Scissors cut Paper"
#                               " You Won!!")
# permit = input("Would you like to start the game?  choose [1/0]: ")
# while True:
#     if permit == '1':
#         x, y = player_computer_choices()
#         z = whowon(x, y)
#         print(z)
#         again = input("Would you like to try again?  choose [1/0]: ")
#         if again=='1':
#             continue
#         else:
#             print("are you sure?[yes/no]")
#             x = input(':')
#             if x == 'yes':
#                 print("hope you enjoyed the game "
#                       "have a nice day".title())
#                 break
#             else:
#                 continue
#     elif permit == '0':
#         print("thanks for trying")
#         break
#     else:
#         print("Run the game again")
#         break

#
#
#
#
# # This is rockpaperscissors game version 3.0


import random


def true():
    def player_computer_choices():
        choicelist = ["rock", "paper", "scissors"]
        playerchoice = input("Enter Your Choice(rock,paper,scissors): ")
        computerchoice = random.choice(choicelist)

        return playerchoice, computerchoice

    def whowon(player, computer):
        print(f"the player choose [{player}] & the computer choose [{computer}]")
        if player == computer:

            return "Tie"
        elif player != computer:
            if player == "rock":
                if computer == "paper":

                    return ("Paper takes Rock  "
                            " computer Won")
                else:

                    return ("Rock breaks Scissors"
                            " You Won!!")

            elif player == "paper":
                if computer == "scissors":

                    return ("Scissors cut Paper"
                            " computer Won")
                else:

                    return ("Paper takes Rock"
                            " You Won!!")
            elif player == "scissors":
                if computer == "rock":

                    return ("Rock breaks Scissors"
                            " computer won")
                else:

                    return ("Scissors cut Paper"
                            " You Won!!")

    while True:
        x, y = player_computer_choices()
        z = whowon(x, y)
        print(z)
        again = input("Would you like to try again?  choose [1/0]: ")
        if again == '1':
            continue
        else:

            x = input("are you sure?[yes/no]: ")
            if x == 'yes':
                print("hope you enjoyed the game "
                      "have a nice day".title())
                break
            else:
                continue


print("Hello")
x = input("what is your name: ")
print(f"hi {x} ".title())
print("Welcome to Rock Paper Scissors game.".title())
permit = input("Would you like to start the game?  choose [1/0]: ")

if permit == '0':
    print("thanks for trying")
else:
    true()
