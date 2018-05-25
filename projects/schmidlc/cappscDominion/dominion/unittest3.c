#include<stdio.h>
#include<stdlib.h>
#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

//TESTING gainCard FUNCTION


void testGainCard(){
    const char *cardNames[27];
    cardNames[0]= "Curse";
    cardNames[1]= "Estate";
    cardNames[2]= "Duchy";
    cardNames[3]= "Province";
    cardNames[4]= "Copper";
    cardNames[5]= "Silver";
    cardNames[6]= "Gold";
    cardNames[7]= "Adventurer";
    cardNames[8]= "Council Room";
    cardNames[9]= "Feast";
    cardNames[10]= "Gardens";
    cardNames[11]= "Mine";
    cardNames[12]= "Remodel";
    cardNames[13]= "Smithy";
    cardNames[14]= "Village";
    cardNames[15]= "Baron";
    cardNames[16]= "Great Hall";
    cardNames[17]= "Minion";
    cardNames[18]= "Steward";
    cardNames[19]= "Tribute";
    cardNames[20]= "Ambassador";
    cardNames[21]= "Cutpurse";
    cardNames[22]= "Embargo";
    cardNames[23]= "Outpost";
    cardNames[24]= "Salvager";
    cardNames[25]= "Sea Hag";
    cardNames[26]= "Treasure Map";
    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
    initializeGame(2, k, 10, &G);
    //initializeGame(numPlayers, kingdomCards, randomSeed, state);

    printf("\n");
    printf("-------------------------------------------------------------------------------------------------------------\n");
    printf("UNIT TEST 3 - gainCard\n");
    printf("Verify a new card is added to the deck\n");
    int currentCopper = fullDeckCount(0,4,&G);
    printf("Current number of Copper in deck = %d\n", currentCopper);
    printf("Adding 1 copper card to the deck\n");
    gainCard(4, &G, 1, 0);
    int newCopper = fullDeckCount(0,4,&G);
    printf("Current number of Copper in deck = %d\n", newCopper);
    if (newCopper == (currentCopper + 1)){
        printf("PASS copper card was added to the deck! Current: %d Correct: %d \n", newCopper, (currentCopper + 1));
    }
    else{
       printf("FAIL copper card was not added to the deck! Current: %d Correct: %d \n", newCopper, (currentCopper + 1));
    }
    
    printf("Verify the new copper card was not added to the hand\n");
    int currentHandCount = numHandCards(&G);
    if (currentHandCount == 5){
        printf("PASS the new copper card was not added to hand! Current: %d Correct: 5 \n", currentHandCount);
    }
    else if(currentHandCount > 5){
       printf("FAIL the new copper card was added to hand! Current: %d Correct: 5 \n", currentHandCount);
    }
    else{
        printf("FAIL something odd happened and somehow there are less cards! Current: %d Correct: 5 \n", currentHandCount);
    }

    printf("\nPlayer Current Hand\n");
    int i;
    for (i = 0; i <  currentHandCount; i++){
        int card = handCard(i, &G);
        printf("%d. %s\n", (i+1), cardNames[card]);
    }
    printf("\n");
    
    gainCard(7, &G, 2, 0);
    int newHandCount = numHandCards(&G);
    printf("Verify a new card is added to the hand by adding the Adventurer card\n");
    if (newHandCount == (currentHandCount + 1)){
        printf("PASS new card added to hand and the number of cards in hand is correct! Current: %d Correct: %d \n", newHandCount, (currentHandCount + 1));
    }
    else{
       printf("FAIL new card was not added to hand and the number of cards in hand is incorrect! Current: %d Correct: %d \n", newHandCount, (currentHandCount + 1));
    }

    printf("Verfiy that it was the Adventurer card that was added to the hand\n");
    int card = handCard((newHandCount - 1),&G);
    if (strcmp(cardNames[card],"Adventurer") == 0){
        printf("PASS the Adventurer card was added to the hand!\n");
    }
    else{
       printf("FAIL the Adventurer card was not added to the hand!\n"); 
    }

    printf("\nPlayer New Hand\n");
    for (i = 0; i <  newHandCount; i++){
        int card = handCard(i, &G);
        printf("%d. %s\n", (i+1), cardNames[card]);
    }
    printf("\n");

    printf("Verify a card not set in the kingdom cards can not be added to the players cards\n");

    currentHandCount = numHandCards(&G);
    gainCard(15, &G, 2, 0);
    newHandCount = numHandCards(&G);

    if (newHandCount == (currentHandCount + 1)){
        printf("FAIL a new card was added to hand! Current: %d Correct: %d \n", newHandCount, currentHandCount);
    }
    else{
       printf("PASS new card was not added to hand! Current: %d Correct: %d \n", newHandCount, currentHandCount);
    }

    printf("\n");
}


int main(int argc, char *argv[]){
   

    //testIntitialize(2, k, atoi(argv[1]), &G);
    //initializeGame(2, k, 10, &G);
    testGainCard();
        
    
    return 0;
}



