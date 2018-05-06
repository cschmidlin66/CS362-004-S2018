#include<stdio.h>
#include<stdlib.h>
#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//TESTING Smithy Card


void testSmithy(){

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
    printf("RANDOM CARD TEST - Smithy Card Effect \n");
    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};

    initializeGame(randPlayerCount, k, randSeedNum, &G);

    
    int currentNumCards = numHandCards(&G);
    int j;   

    for (j = 1; j < randPlayerCount; j++){
        int k;
        for (k = 0; k < 5; k ++){
            //G.whoseTurn = j;
            drawCard(j, &G);
        }
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
    
    printf("Giving random player the Smithy card\n");

    printf("\n");

    gainCard(13,&G,2, randPlayer);
    printf("Player %d received the Smithy card\n", randPlayer);
    int currentPlayerCards = G.handCount[randPlayer];

    G.whoseTurn = randPlayer;

    printf("Player %d will now play the Smithy card\n", randPlayer);
    printf("\n");

    //int smithyPos = -1;
    playCard((currentPlayerCards-1), -1, -1, -1, &G);

    int newHandNum = numHandCards(&G);
    //In this case do not discard a card because this is just testing the effect but not played from the hand
    int correctNum = ((currentNumCards)+3);

    if (newHandNum == correctNum){
        printf("PASS player %d gained 3 more cards! Current: %d Correct: %d \n", randPlayer, newHandNum, correctNum);
    }
    else{
       printf("FAIL player %d did not gain 3 more cards! Current: %d Correct: %d \n", randPlayer, newHandNum, correctNum); 
    }

    printf("Verify the Smithy card is discarded from player %d's hand \n", randPlayer);

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
                if(strcmp(cardNames[card],"Smithy") == 0){
                    discarded = 0;
                }
            }
        }

        printf("\n");

    }
    printf("\n");

    if (discarded == 1){
        printf("PASS the Smithy card was discarded from player %d's hand!\n", randPlayer);
    }
    else{
       printf("FAIL the Smithy card was not discarded from player %d's hand!\n", randPlayer);
    }

   

    printf("\n");
}


int main(int argc, char *argv[]){
    srand(time(NULL));
    int i;
    for (i = 0; i < 5; i++){
        testSmithy();      
    }
    return 0;
}



