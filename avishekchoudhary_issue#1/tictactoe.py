board = {
    'R11': ' ', 'R12': ' ', 'R13': ' ',
    'R21': ' ', 'R22': ' ', 'R23': ' ',
    'R31': ' ', 'R32': ' ', 'R33': ' '
}

player = 1         
moves = 0     
end_check = 0


def check():
    if board['R11'] == 'X' and board['R12'] == 'X' and board['R13'] == 'X':
        print('Player one won !')
        return 1
    if board['R21'] == 'X' and board['R22'] == 'X' and board['R23'] == 'X':
        print('Player One Won!!')
        return 1
    if board['R31'] == 'X' and board['R32'] == 'X' and board['R33'] == 'X':
        print('Player One Won!!')
        return 1
    if board['R11'] == 'X' and board['R22'] == 'X' and board['R33'] == 'X':
        print('Player One Won!!')
        return 1
    if board['R11'] == 'X' and board['R21'] == 'X' and board['R31'] == 'X':
        print('Player One Won!!')
        return 1
    if board['R12'] == 'X' and board['R22'] == 'X' and board['R32'] == 'X':
        print('Player One Won!!')
        return 1
    if board['R13'] == 'X' and board['R23'] == 'X' and board['R33'] == 'X':
        print('Player One Won!!')
        return 1

    if board['R11'] == 'O' and board['R12'] == 'O' and board['R13'] == 'O':
        print('Player Two Won!!')
        return 1  
    if board['R21'] == 'O' and board['R22'] == 'O' and board['R23'] == 'O':
        print('Player Two Won!!')
        return 1
    if board['R31'] == 'O' and board['R32'] == 'O' and board['R33'] == 'O':
        print('Player Two Won!!')
        return 1
    if board['R11'] == 'O' and board['R22'] == 'O' and board['R33'] == 'O':
        print('Player Two Won!!')
        return 1
    if board['R11'] == 'O' and board['R21'] == 'O' and board['R31'] == 'O':
        print('Player Two Won!!')
        return 1
    if board['R12'] == 'O' and board['R22'] == 'O' and board['R32'] == 'O':
        print('Player Two Won!!')
        return 1
    if board['R13'] == 'O' and board['R23'] == 'O' and board['R33'] == 'O':
        print('Player Two Won!!')
        return 1
    return 0

print('***************************')
print('R11|R12|R13')
print('- +- +-')
print('R21|R22|R23')
print('- +- +-')
print('R31|R32|R33')
print('***************************')

while 1:
    print(board['R11']+'|'+board['R12']+'|'+board['R13'])
    print('-+-+-')
    print(board['R21'] + '|' + board['R22'] + '|' + board['R23'])
    print('-+-+-')
    print(board['R31'] + '|' + board['R32'] + '|' + board['R33'])
    end_check = check()
    if moves == 9 or end_check == 1:
        break
    while 1:     
        if player == 1: 
            p1_input = input('player one')
            if p1_input.upper() in board and board[p1_input.upper()] == ' ':
                board[p1_input.upper()] = 'X'
                player = 2
                break
            # on wrong input
            else:
                print('Invalid input, please try again')
                continue
        else:
            p2_input = input('player two')
            if p2_input.upper() in board and board[p2_input.upper()] == ' ':
                board[p2_input.upper()] = 'O'
                player = 1
                break
            else:  # on wrong input
                print('Invalid input, please try again')
                continue
    moves += 1
    print('***************************')
