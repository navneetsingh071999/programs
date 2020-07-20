# Tic-Tac-To
'''
Here Num Pad is your respective box.
    7 | 8 | 9
    ----------
    4 | 5 | 6
    ----------
    1 | 2 | 3
    
'''
import random

#Function to Draw Board
def board(game_input):
    print(game_input[7]+' | '+game_input[8]+' |'+game_input[9])
    print("---------")
    print(game_input[4]+' | '+game_input[5]+' |'+game_input[6])
    print("---------")
    print(game_input[1]+' | '+game_input[2]+' |'+game_input[3])

#Function to initilize Player Sign    
def player_input():
    marker = ''
    marker = input("Choose your Symbol: ")
    while marker != 'x' and marker != 'o':
        marker = input("Choose your Symbol: ")
    if marker == 'x':
        return ('x','o')
    else:
        return ('o','x')
#Function to assign box with respective symbol 
def put_marker(game_input, marker, position):
    game_input[position] = marker

#Function for wining condition it returns true if any of the condition becomes true
def win(marker, game_input):
    return ((game_input[1] == game_input[2] == game_input[3] == marker) or (game_input[4] == game_input[5] == game_input[6] == marker) or
    (game_input[7] == game_input[8] == game_input[9] == marker) or (game_input[1] == game_input[4] == game_input[7] == marker) or
    (game_input[2] == game_input[5] == game_input[8] == marker) or (game_input[9] == game_input[6] == game_input[3] == marker) or
    (game_input[1] == game_input[5] == game_input[9] == marker) or (game_input[7] == game_input[5] == game_input[3] == marker))

#Function for selecting 1st chance      
def choose_player():
    player = random.randint(1,2)
    if player == 1:
        return 'Player_1'
    else:
        return 'Player_2'

#Function to check if given space is empty or not
def space(position, game_input):
    return game_input[position] == ' '

#Funtion to take input of position from player
def player_choice(game_input):
    position  = 0
    while position not in [1,2,3,4,5,6,7,8,9] or not space(position, game_input):
        position = int(input("Please choose Position from (1-9): "))
    return position
#Play again to cnfrm if player wants to play again
def play_again():
    choice = input("Do you like to play again[y/n] : ")
    return choice == "y"

#Main Program flow starts from here.

while True:
    game_input = [' ']*10               #initilisinz a list with size 10 because 0 space not utilize
    
    player_1, player_2 = player_input() #defining symbols to player
    
    print(player_1 + " -> is player 1 Sign")
    print(player_2 + " -> is player 2 Sign")

    turn = choose_player()              #1st chance selector, returns Player_1 or Player_2
    print(turn + " Will play first")

    play_game = input("Are you ready [y/n] :")

    if play_game == 'y':
        game_on = True
    else:
        game_on = False
    
    while game_on:
        if turn == 'Player_1':
            board(game_input)
            position = player_choice(game_input)
            put_marker(game_input, player_1, position)

            if win(player_1, game_input):
                board(game_input)
                print("\nPlayer 1 Wins")
                game_on = False
            else:
                if space(position, game_input):
                   board(game_input)
                   print("\nGame Tie.....!")
                   game_on = False
                   
                else:
                    turn = 'Player_2'

        elif turn == 'Player_2':
            board(game_input)
            position = player_choice(game_input)
            put_marker(game_input, player_2, position)

            if win(player_2, game_input):
                board(game_input)
                print("\nPlayer 2 Wins")
                game_on = False

            else:
                if space(position, game_input):
                   board(game_input)
                   print("\nGame Tie.....!")
                   game_on = False
                else:
                    turn = 'Player_1'


    if not play_again():
        break
