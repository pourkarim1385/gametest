#include <stdio.h>
#define True 1
#define False 0

#define MAX_LEN 100


/*Function Definitions*/
int getLength(char arr[]);
int getEnergyCost(char move);
int getNewPosition(int pos, char move);
int getNewLivesValue(int lives, char cell);
int printCondition(int lives, int energy, char cell, int position, int routeLength , char move);

/*main function*/
int main(void) {
    /*Variable Definitions*/
    char route[MAX_LEN];
    int lives = 0, energy = 0;
    int position = 0, routeLength = 0, gameRun = True;

    /*Inputting*/
    for (int i = 0; i < MAX_LEN; i++) {
        scanf("%c", &route[i]);
    }
    routeLength = getLength(route);

    scanf("%c", &lives);
    scanf("%c", &energy);

    /*Game start*/
    while (gameRun){
        char move[2];
        fgets(move, 2, stdin);

        position = getNewPosition(position, *move);
        energy = energy - getEnergyCost(*move);
        lives = getNewLivesValue(lives, route[position]);

        gameRun = printCondition(lives, energy, route[position], position, routeLength, *move);
    }

    return 0;
}

/*Function Declaration*/

/*getlenght: Calculate the length of route and returns the value*/
int getlength(char arr[]) {
    int length = 0;
    while (arr[length] != '\0') {
        length++;
    }
    return length;
}

/*getnEnergy: Calculate the energy based on the cell and returns the cost of energy*/
int getEnergyCost(char move) {
    int coeffiecntsEnery[4] = {1,1,2,2};

    if (move == 'R') {
       return coeffiecntsEnery[0];
    }
    if (move == 'L') {
        return coeffiecntsEnery[1];
    }
    if (move == 'T') {
        return coeffiecntsEnery[2];
    }
    if (move == 'K') {
        return coeffiecntsEnery[3];
    }
    return 0; /*Quit*/
}

/*getNewPosition: Based on the command entered calculate the new position and returns the new value
 if players enter Q the function will return the Previous Position
 */
int getNewPosition(int pos, char move) {
    int newPosition = pos;
    int coeffiecntsMovement[4] = {1,-1,2,-2};

    if (move == 'R') {
        return coeffiecntsMovement[0] + newPosition;
    }
    if (move == 'L') {
        return coeffiecntsMovement[1] + newPosition;
    }
    if (move == 'T') {
        return coeffiecntsMovement[2] + newPosition;
    }
    if (move == 'K') {
        return coeffiecntsMovement[3] + newPosition;
    }
    return pos;
}

/*getnNewLivesValue: Calculate the lives based on the cell and returns the new value of lives*/
int getNewLivesValue(int lives, char cell) {
    if (cell == 'H' || cell == 'T') {
        return lives - 1;
    }
    return lives;
}

/*printfCondition: does the print job and return the truth value of Exiting and Continuing Program
 False: Exit code
 True: Continue Code
 */
int printCondition(int lives, int energy, char cell, int position, int routeLength, char move) {
    printf("Moved to position %d, Energy left: %d, Lives left: %d", position, energy, lives);

    if (lives == 0) {
        printf("TARZAN HAS NO LIFE LEFT!\n");
        return False;

    }

    if (energy == 0) {
        printf("TARZAN RAN OUT OF ENERGY!\n");
        return False;
    }

    if (cell == 'F') {
        printf("TARZAN REACHED HIS FRIEND!");
        return False;
    } /*found the friend*/

    if (cell == 'T') {
        printf("TARZAN STEPPED ON A TRAP, LOSE 1 LIFE!");
    } /*trap*/

    if (cell == 'H') {
        printf("TARZAN STEPPED INTO A HOLE, LOSE 1 LIFE!");
    } /*hole*/

    if (0 < position || position > routeLength) {
        printf("TARZAN GOT LOST IN THE JUNGLE!");
        return False;
    } /*lost*/

    if (move == 'Q') {
        return False;
    } /*quiting*/

    return True;
}
