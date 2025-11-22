import random


def roll():
    li = [1, 2, 3, 4, 5, 6]
    r = random.choice(li)
    return r


while True:
    players = input("Choose players number between (2-6): ")

    if players.isdigit():
        players = int(players)

        if 2 <= players <= 6:
            break
        else:
            print("Please enter between 2-6.")
    else:
        print("Invalid input. Try again.")


player_scores = [0 for _ in range(players)]

while max(player_scores) < 50:
    for i in range(players):
        print(f"Player {i+1}'s turn. Time to roll some dice!!\n")
        while True:
            y = input("Would you like to roll the dice? (y/n): ").lower()
            if y != "y":

                break

            rol = roll()
            if 2 <= rol <= 6:
                player_scores[i] += rol
                print(
                    f"You rolled {rol}. Your current total score = {player_scores[i]}\n"
                )
            elif rol == 1:
                player_scores[i] = 0  # Reset the score to 0 if 1 is rolled
                print(
                    "You rolled 1. Turn's up. Lost your score. Current total score = 0"
                )
                break

            if player_scores[i] >= 50:
                print(f"Player {i+1} wins!!")
                exit()
