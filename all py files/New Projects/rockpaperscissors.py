import random

print("Hello")
x = input("what is your name: ")
print(f"hi {x} ".title())
print("Welcome to Rock Paper Scissors game.".title())
permit = input("Would you like to start the game?  choose [1/0]: ")
if permit == "1":
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


    def again():
        p = input("Would you like to try again?  choose [1/0]: ")
        if p == '1':
            x, y = player_computer_choices()
            z = whowon(x, y)
            print(z)
            again()

        else:
            print("are you sure?[yes/no]")
            x = input(':')
            if x == 'yes':
                print("hope you enjoyed the game "
                      "have a nice day".title())


            else:
                x, y = player_computer_choices()
                z = whowon(x, y)
                print(z)
                again()


    x, y = player_computer_choices()
    z = whowon(x, y)
    print(z)
    again()
else:
    print("Ok "
          "thanks For trying".title())
