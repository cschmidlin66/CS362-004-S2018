#include<stdio.h>
#include<stdlib.h>
#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//TESTING Adventurer Card


void testAdventurer(){

    int randPlayerCount = rand() % (4 + 1 - 2) + 2;
    int randSeedNum = rand() % (50 + 1 - 1) + 1;

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
   

    printf("\n");
    printf("-------------------------------------------------------------------------------------------------------------\n");
    printf("RANDOM CARD TEST  - Adventurer Card Effect\n");
    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
    int treasureCount = 0;
    initializeGame(randPlayerCount, k, randSeedNum, &G);

    int j;
    printf("\n");
        

    int currentNumCards = numHandCards(&G);


    for (j = 1; j < randPlayerCount; j++){
        int k;
        for (k = 0; k < 5; k ++){
            //G.whoseTurn = j;
            drawCard(j, &G);
        }
    }

    printf("Adding 3 gold cards to each player's discard pile and set their deck counts to 2\n");
    for (j = 0; j < randPlayerCount; j++){
        gainCard(6, &G,0,j);
        gainCard(6, &G,0,j);
        gainCard(6, &G,0,j);
        G.deckCount[j] = 2;
    }
    printf("\n");
   
    for (j = 0; j < randPlayerCount; j++){
        printf("\n");
        printf("Player %d Starting Hand \n", j);
        int i;
        for (i = 0; i <  G.handCount[j]; i++){
            //int card = handCard(i, &G);
            int card = G.hand[j][i];
            printf("%d. %s\n", (i+1), cardNames[card]);
        }

        printf("\n");

    }

    int randPlayer = rand() % randPlayerCount;

    printf("Giving random player the adventurer card\n");

    printf("\n");

    //printf("First Player will now gain the Adventurer card\n \n");
    gainCard(7,&G,2,randPlayer);
    printf("Player %d received the Adventurer card\n", randPlayer);
    int currentPlayerCards = G.handCount[randPlayer];
    //get the number of treasure cards in hand
    int i;
    for (i = 0; i < currentNumCards; i++){
        if (G.hand[randPlayer][i] == copper ){
            treasureCount++;
        }
        if (G.hand[randPlayer][i] == silver ){
            treasureCount++;
        }
        if (G.hand[randPlayer][i] == gold ){
            treasureCount++;
        } 
    }

    printf("\n");
    printf("Before playing the Adventurer Card Player %d has %d treasure cards in hand\n", randPlayer, treasureCount);
    printf("\n");

    G.whoseTurn = randPlayer;

    printf("Player %d will now play the Adventurer card\n", randPlayer);
    printf("\n");
    playCard((currentPlayerCards - 1), -1, -1, -1, &G);
    int newCurrentNumCards = numHandCards(&G);
    int correctAmount = currentNumCards + 2;
    int correctTreasure = treasureCount + 2;    
    int newTreasureCount = 0;
    for (i = 0; i < newCurrentNumCards; i++){
        if (handCard(i, &G) == copper ){
            newTreasureCount++;
        }
        if (handCard(i, &G) == silver ){
            newTreasureCount++;
        }
        if (handCard(i, &G) == gold ){
            newTreasureCount++;
        } 
    }

    if (newCurrentNumCards == correctAmount){
        printf("PASS player %d has the correct number of cards in hand! Current: %d Correct: %d \n", randPlayer, newCurrentNumCards, correctAmount);
    }
    else{
       printf("FAIL player %d does NOT have the correct number of cards in hand! Current: %d Correct: %d \n", randPlayer, newCurrentNumCards, correctAmount);
    
    }

    if (newTreasureCount == correctTreasure){
        printf("PASS player %d has the correct number of treasure cards in hand! Current: %d Correct: %d \n", randPlayer, newTreasureCount, correctTreasure);
    }
    else{
       printf("FAIL player %d does NOT have the correct number of treasure cards in hand! Current: %d Correct: %d \n", randPlayer, newTreasureCount, correctTreasure);
    
    }
   
    printf("Verify the Adventurer card is discarded from player %d's hand\n", randPlayer);
    int discarded = 1;
    printf("\n");
   
    for (j = 0; j < randPlayerCount; j++){
        printf("\n");
        printf("Player %d Current Hand \n", j);
        int i;
        for (i = 0; i <  G.handCount[j]; i++){
            //int card = handCard(i, &G);
            int card = G.hand[j][i];
            printf("%d. %s\n", (i+1), cardNames[card]);
            if (j == randPlayer){
                if(strcmp(cardNames[card],"Adventurer") == 0){
                    discarded = 0;
                }
            }
        }

        printf("\n");

    }

    printf("\n");

    if (discarded == 1){
        printf("PASS the Adventurer card was discarded from player %d's hand!\n", randPlayer);
    }
    else{
       printf("FAIL the Adventurer card was not discarded from player %d's hand!\n", randPlayer);
    }

    printf("\n");
}


int main(int argc, char *argv[]){
    srand(time(NULL));
    int i;
    for (i = 0; i < 5; i++){
        printf("Test %d \n",i);
        testAdventurer();
        printf("-------------------------------------------------------------------------------------------------------------------\n");
        
    }      
    return 0;
}



