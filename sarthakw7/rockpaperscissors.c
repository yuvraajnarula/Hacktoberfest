#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef int PLAYER;
PLAYER You, Computer;

int menu()
{
    int ch;
    printf("1. Select Rock\n");
    printf("2. Select Paper\n");
    printf("3. Select Scissor\n");
    printf("4. Exit\n");
    printf("Enter Your Choice:\n");
    scanf("%d",&ch);
    return (ch);
}

void setup()
{
    label:
    Computer = rand()%4;
    if(Computer == 0)
        goto label;

    You = menu();
}

void MakeLogic()
{
    switch (You)
    {
        case 1:
            if (Computer == 1)
            {
                printf("\n!!__Game Draw__!!");
                printf("\nYou = Rock\nComputer = Rock");
            }
            else if (Computer == 2)
            {
                printf("\n!!__Computer Won__!!");
                printf("\nYou = Rock\nComputer = Paper");
            }
            else
            {
                printf("\n!!__You Won__!!");
                printf("\nYou = Rock\nComputer = Scissor");
            }
            break;

        case 2:
            if (Computer == 1)
            {
                printf("\n!!__You Won__!!");
                printf("\nYou = Paper\nComputer = Rock");
            }
            else if (Computer == 2)
            {
                printf("\n!!__Game Draw__!!");
                printf("\nYou = Paper\nComputer = Paper");
            }
            else
            {
                printf("\n!!__Computer Won__!!");
                printf("\nYou = Paper\nComputer = Scissor");
            }
            break;

        case 3:
            if (Computer == 1)
            {
                printf("\n!!__Computer Won__!!");
                printf("\nYou = Scissor\nComputer = Rock");
            }
            else if (Computer == 2)
            {
                printf("\n!!__You Won__!!\"");
                printf("\nYou = Scissor\nComputer = Paper");
            }
            else
            {
                printf("\n!!__Game Draw__!!");
                printf("\nYou = Scissor\nComputer = Scissor");
            }
            break;

        case 4:
            exit(0);

        default:
            printf("\nInvalid User Choice!!!");
    }
}

int main()
{
    while (1)
    {
        system("cls");
        setup();
        MakeLogic();
        getch();
    }
    return 0;
}