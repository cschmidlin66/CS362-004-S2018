#include<stdio.h>
#include<stdlib.h>
#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//TESTING endTurn FUNCTION


void testEndTurn(){

    printf("\n");
    printf("-------------------------------------------------------------------------------------------------------------\n");
    printf("UNIT TEST 4 - endTurn\n");

    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
    initializeGame(3, k, 10, &G);
   
    int currentPlayer = whoseTurn(&G);
    printf("FIRST TURN\n");
    if (currentPlayer == 0){
        printf("PASS first turn is with the correct player! Current: Player %d Correct: Player 0 \n", currentPlayer);
    }
    else{
       printf("FAIL first turn is with the incorrect player! Current: Player %d Correct: Player 0 \n", currentPlayer);
    }

    endTurn(&G);
    currentPlayer = whoseTurn(&G);
    printf("SECOND TURN\n");
    if (currentPlayer == 1){
        printf("PASS second turn is with the correct player! Current: Player %d Correct: Player 1 \n", currentPlayer);
    }
    else{
       printf("FAIL second turn is with the incorrect player! Current: Player %d Correct: Player 1 \n", currentPlayer);
    }

    endTurn(&G);
    currentPlayer = whoseTurn(&G);
    printf("THIRD TURN\n");
    if (currentPlayer == 2){
        printf("PASS third turn is with the correct player! Current: Player %d Correct: Player 2 \n", currentPlayer);
    }
    else{
       printf("FAIL third turn is with the incorrect player! Current: Player %d Correct: Player 2 \n", currentPlayer);
    }

    endTurn(&G);
    currentPlayer = whoseTurn(&G);
    printf("FOURTH TURN\n");
    if (currentPlayer == 0){
        printf("PASS fourth turn is with the correct player! Current: Player %d Correct: Player 0 \n", currentPlayer);
    }
    else{
       printf("FAIL fourth turn is with the incorrect player! Current: Player %d Correct: Player 0 \n", currentPlayer);
    }

    printf("\n");
}


int main(int argc, char *argv[]){
        
    testEndTurn();
    return 0;
}



