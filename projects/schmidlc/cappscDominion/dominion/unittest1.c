#include<stdio.h>
#include<stdlib.h>
#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//TESTING initializeGame FUNCTION


void testInitialize(int numPlayers, int kingdomCards[10], int randomSeed, struct gameState *state){
    initializeGame(numPlayers, kingdomCards, randomSeed, state);

    printf("\n");
    printf("-------------------------------------------------------------------------------------------------------------\n");
    printf("UNIT TEST 1 - initializeGame\n");

    //Verfiy number of players
    if (state->numPlayers == numPlayers){
        printf("initializeGame: PASS number of players is correct!\n");
    }
    else{
        printf("initializeGame: FAIL number of plyers is inconsistent with the input amount! gameState: %d, input: %d\n", state->numPlayers, numPlayers);
    }

    //Verify correct 'curse' card amount
    if (numPlayers == 2)
    {
        if (state->supplyCount[curse] == 10){
            printf("initializeGame: PASS supply count for 'curse' is correct!\n");
        }
        else{
            printf("initializeGame: FAIL supply count for 'curse' is correct! Current: %d Correct: 10\n", state->supplyCount[curse]);
        }
        
    }
    else if (numPlayers == 3)
    {
      if (state->supplyCount[curse] == 20){
            printf("initializeGame: PASS supply count for 'curse' is correct!\n");
        }
        else{
            printf("initializeGame: FAIL supply count for 'curse' is correct! Current: %d Correct: 20\n", state->supplyCount[curse]);
        }
    }
    else
    {
      if (state->supplyCount[curse] == 30){
            printf("initializeGame: PASS supply count for 'curse' is correct!\n");
        }
        else{
            printf("initializeGame: FAIL supply count for 'curse' is correct! Current: %d Correct: 30\n", state->supplyCount[curse]);
        }
    }

    //Verify correct 'Victory' card amount
    if (numPlayers == 2)
    {
        if (state->supplyCount[estate] == 8){
            printf("initializeGame: PASS estate amount is correct!\n");
        }
        else{
            printf("initializeGame: FAIL estate amount is incorrect! Current: %d Correct: 8\n", state->supplyCount[estate]);
        }

        if (state->supplyCount[duchy] == 8){
            printf("initializeGame: PASS duchy amount is correct!\n");
        }
        else{
            printf("initializeGame: FAIL duchy amount is incorrect! Current: %d Correct: 8\n", state->supplyCount[duchy]);
        }

        if (state->supplyCount[province] == 8){
            printf("initializeGame: PASS amount is correct!\n");
        }
        else{
            printf("initializeGame: FAIL province amount is incorrect! Current: %d Correct: 8\n", state->supplyCount[province]);
        }
    }
    else
    {
      if (state->supplyCount[estate] == 12){
            printf("initializeGame: PASS estate amount is correct!\n");
        }
        else{
            printf("initializeGame: FAIL estate amount is incorrect! Current: %d Correct: 12\n", state->supplyCount[estate]);
        }

        if (state->supplyCount[duchy] == 12){
            printf("initializeGame: PASS duchy amount is correct!\n");
        }
        else{
            printf("initializeGame: FAIL duchy amount is incorrect! Current: %d Correct: 12\n", state->supplyCount[duchy]);
        }

        if (state->supplyCount[province] == 12){
            printf("initializeGame: PASS amount is correct!\n");
        }
        else{
            printf("initializeGame: FAIL province amount is incorrect! Current: %d Correct: 12\n", state->supplyCount[province]);
        }
    }

    //Verify treasure cards
    if (state->supplyCount[copper] == 60 - (7 * numPlayers)){
        printf("initializeGame: PASS copper amount is correct!\n");
    }
    else{
        printf("initializeGame: FAIL copper amount is incorrect!\n");
    }

    if (state->supplyCount[silver] == 40){
        printf("initializeGame: PASS silver amount is correct!\n");
    }
    else{
       printf("initializeGame: FAIL silver amount is incorrect!\n"); 
    }

    if (state->supplyCount[gold] == 30){
        printf("initializeGame: PASS gold amount is correct!\n");
    }
    else{
       printf("initializeGame: FAIL gold amount is incorrect!\n"); 
    }

    //Verify first player's turn is correct
    if (state->outpostPlayed == 0){
        printf("initializeGame: PASS outpostPlayed amount is correct!\n");
    }
    else{
       printf("initializeGame: FAIL outpostPlayed amount is incorrect!\n"); 
    }

    if (state->phase == 0){
        printf("initializeGame: PASS game is in the correct phase!\n");
    }
    else{
       printf("initializeGame: FAIL game is in the wrong phase!\n"); 
    }

    if (state->numActions == 1){
        printf("initializeGame: PASS only 1 action is available on first turn!\n");
    }
    else{
       printf("initializeGame: FAIL the number of actions available on the first turn is not 1!\n"); 
    }

    if (state->numBuys == 1){
        printf("initializeGame: PASS the number of buys is 1!\n");
    }
    else{
       printf("initializeGame: FAIL the number of buys is not 1!\n"); 
    }

    if (state->playedCardCount == 0){
        printf("initializeGame: PASS the number of cards played is 0!\n");
    }
    else{
       printf("initializeGame: FAIL the number of cards played is not 0!\n"); 
    }

    if (state->whoseTurn == 0){
        printf("initializeGame: PASS the turn counter is set to 0!\n");
    }
    else{
       printf("initializeGame: FAIL the turn counter is not set to 0!\n"); 
    }

    if (numHandCards(state) == 5){
        printf("initializeGame: PASS the hand count at the start of the turn is 5!\n");
    }
    else{
       printf("initializeGame: FAIL the hand count at the start of the turn is not 5! Current: %d \n", numHandCards(state)); 
    }

    printf("\n");
}


int main(int argc, char *argv[]){
    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};

    //testIntitialize(2, k, atoi(argv[1]), &G);
    testInitialize(2, k, 10, &G);       
    
    return 0;
}



