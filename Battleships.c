#include <stdio.h>
#include <string.h>

int ships[6][6];
void printboard ();
void boardcheck ();
void shooting(int a, int b);
void placeships ();
void placeshipsalternate ();
int gamestatus = 0;

typedef struct {
    char name[51];
    int score;
} record;

int main () {
    int h, v, turns, x, y, countturns=0;
    char s;
    record player;
    FILE *fptr;
    fptr = fopen("D:\\HighScores.txt", "a");
    placeships ();
    system("cls");
    turns = 2;
    while (turns > 1) {
        printboard();
        printf ("\n\nSelect a spot to fire on: ");
        scanf ("%d %d", &h, &v);
        shooting (h, v);
        boardcheck ();
        if (gamestatus == 1) {
            turns = 0;
        }
        countturns++;
    }
    printf ("\n\nTurns taken: %d\n", countturns);
    getc(stdin);
    printf ("\nDo you wish to save your high score? (enter Y or N): ");
    scanf ("%c", &s);
    if (s == 'Y') {
        printf ("Please enter your name (within 50 characters):\n");
        getc(stdin);
        gets (player.name);
        player.score = (100-countturns);
        fprintf (fptr, "%s\n%d\n\n", player.name, player.score);
        fclose(fptr);
    }
}

void printboard () {
    printf ("\n");
    int i, j;
    for (i=0; i<6; i++) {
        for (j=0; j<6; j++) {
            if (ships[i][j] == 1) {
                printf ("0 ");
            } else {
                printf ("%d ", ships[i][j]);
                }
        }
        printf ("\n");
    }
    printf ("0 = Unknown/Water, 7 = damaged ship, 8 = missed shot.");
}

void shooting (int a, int b) {
    if(ships[a-1][b-1] == 0) {
        ships[a-1][b-1] = 8;
    }
    else if (ships[a-1][b-1] == 1) {
        ships[a-1][b-1] = 7;
    }
}

void placeships () {
    int i, j;
    printf ("Start of Game.\n\n");
    printf ("The board is an 6x6 grid. Please input the board and thus the positions of the ships, row by row.\n");
    printf ("Use 0 to denote Water and 1 to denote a ship.\n\n");
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 6; j++) {
            scanf ("%d", &ships[i][j]);
        }
    }
}

void boardcheck () {
    int i, j, allclear = 1;
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 6; j++) {
            if (ships[i][j] == 1) {
                allclear = 0;
            }
        }
    }
    if (allclear) {
        printf ("\nYou have eliminated all enemy ships. The game is over.\n");
        gamestatus = 1;
        printboard ();
    } else if (allclear == 0) {
        printf ("\nThere are still enemy ships left. Keep shooting!\n");
        gamestatus = 0;
    }
}

/*void placeships1 () {
    int i, j, l, o, hc, vc;
    int sizes[5] = {2, 3, 4, 5, 6};
    //char numbers[8] = {'first', 'second', 'third', 'fourth', 'fifth', '\0'};
    for (l = 0; l < 5; l++) {
        printf ("The ship is %d units long. Will you place it horizontally or vertically? (Enter H or V, in capitals)", sizes[l]);
        scanf ("%c", &o);
        getc(stdin);
        printf ("Please enter the coordinates on the board to place it on. ");
        scanf ("%d %d", &hc, &vc);
        for (i = 0; i < l; i++) {
            if (o == 'H') {
                ships[hc - 1 + i][vc-1] = 1;
            } else if (o == 'V') {
                ships[hc - 1][vc - 1 + i] = 1;
            }
        }
    }
}*/
