/*******************************************************************************
 * Preprocessor directives
 * Sample Output
input
  
D1: 6 - D2: 2 - Sum: 8                                                                                                                                                             
Playing for point:8. Please hit enter.                                                                                                                                             

D1: 1 - D2: 6 - Sum: 7                                                                                                                                                             
You lost the game.

input
ROLL THE DICE WITH [ENTER] 
D1: 5 - D2: 2 - Sum: 7                                                                                                                                                             
You won the game.  
 ******************************************************************************/
#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#define WON 0
#define LOSE 1


/*******************************************************************************
 * Function prototypes
 ******************************************************************************/
int rollDice(void);
int playGame(void);


/*******************************************************************************
 * Function definitions
 ******************************************************************************/
/*----------------------------------------------------------------------------*/
int rollDice(void) {
    return ((rand() % 6) + 1);
}

/*----------------------------------------------------------------------------*/
int playGame(void){
    int dice_1 = 0;
    int dice_2 = 0;
    int sum = 0;
    int result;
    int point = 0;
    time_t t;
    bool playForPoint = false;

    srand(time(&t)); // Initialize random seed
    printf("ROLL THE DICE WITH [ENTER]\n");
    fgetc(stdin);
    dice_1 = rollDice();
    dice_2 = rollDice();
    sum = dice_1 + dice_2;
    printf("D1:%2d - D2:%2d - Sum:%2d\n", dice_1, dice_2, sum);

    switch ( sum )
    {
        case 7:
        case 11:
            result = WON;
            break;
        case 2:
        case 3:
        case 12:
            result = LOSE;
            break;
        default:
            playForPoint = true;
            point = sum;
            printf("Playing for point:%d. Please hit enter.\n", point);
            fgetc(stdin);
            break;
    }

    while ( playForPoint )
    {
        dice_1 = rollDice();
        dice_2 = rollDice();
        sum = dice_1 + dice_2;
        printf("D1:%2d - D2:%2d - Sum:%2d\n", dice_1, dice_2, sum);
        if ( sum == 7 ) {
            playForPoint = false;
            result = LOSE;
        } else if ( sum == point ) {
            playForPoint = false;
            result = WON;
        } else {
            printf("Please roll the dice again with [ENTER].\n");
            fgetc(stdin);
        }
    }

    return result;
}

/*----------------------------------------------------------------------------*/
int main (void){
    int result = playGame();
    switch ( result )
    {
        case WON:
            printf("You won the game.\n");
            break;
        case LOSE:
            printf("You lost the game.\n");
            break;
        default:
            printf("Something went wrong in the program.\n");
            break;
    }

    return 0;
}
