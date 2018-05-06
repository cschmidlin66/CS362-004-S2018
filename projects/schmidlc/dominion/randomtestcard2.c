#include<stdio.h>
#include<stdlib.h>
#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//TESTING Council Room Card Effect


void testCouncilRoom(){

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
    printf("RANDOM CARD TEST - Council Room\n");
    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
        sea_hag, council_room, smithy};
    initializeGame(randPlayerCount, k, randSeedNum, &G);

    /*gainCard(6, &G,1,0);
    gainCard(6, &G,1,0);
    gainCard(6, &G,1,0);
    gainCard(8, &G,2,0);*/

    int currentNumCards = numHandCards(&G);
    int j;

    for (j = 1; j < randPlayerCount; j++){
        int k;
        for (k = 0; k < 5; k ++){
            //G.whoseTurn = j;
            drawCard(j, &G);
        }
    }

    //printf("Verify current player draws 4 more cards to their hand\n");


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
    
    printf("Giving random player the Council Room card\n");

    printf("\n");

    gainCard(8,&G,2, randPlayer);
    printf("Player %d received the Council Room card\n", randPlayer);
    int currentPlayerCards = G.handCount[randPlayer];

    G.whoseTurn = randPlayer;

    printf("Player %d will now play the Council Room card\n", randPlayer);
    printf("\n");

    printf("\n");
    int originalBuyNum = G.numBuys;
    //int secondPlayerHand = G.handCount[1];
    playCard((currentPlayerCards-1), -1, -1, -1, &G);

    int newCurrentNumCards = numHandCards(&G);
    //int secondPlayerHandNew = G.handCount[1];

    if (newCurrentNumCards == (currentPlayerCards-1)+4){
        printf("PASS Player %d added four more cards to their hand! Current: %d Correct: %d \n", randPlayer, newCurrentNumCards,(currentNumCards+4));
    }
    else{
        printf("FAIL Player %d did not add four more cards to their hand! Current: %d Correct: %d \n", randPlayer, newCurrentNumCards,((currentNumCards -1)+4));
    }

    int newBuyNum = G.numBuys;

    printf("Verify Player %d gains an extra buy action \n", randPlayer);
    if (newBuyNum == (originalBuyNum + 1)){
        printf("PASS Player %d received one more buy action! \n", randPlayer);
    }
    else{
       printf("FAIL Player %d did not receive one more buy action! \n", randPlayer); 
    }


    printf("Verify all other players draw one card.\n");
    for (j = 0; j < randPlayerCount; j++){
        if (j != randPlayer){
            if (G.handCount[j] == 6){
                printf("PASS Player %d added one card to their hand! \n", j);
            }
            else{
                printf("FAIL Player %d did not add one card to their hand! \n", j);
            }
        }
    }
    /*if (secondPlayerHandNew == (secondPlayerHand + 1)){
        printf("PASS the other player added one card to their hand! \n");
    }
    else{
       printf("FAIL the other player did not add one card to their hand! \n");
    }*/


    printf("Verify the Council Room card is discarded from Player %d's hand\n", randPlayer);
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
                if(strcmp(cardNames[card],"Council Room") == 0){
                    discarded = 0;
                }
            }
        }

        printf("\n");

    }
    printf("\n");

    if (discarded == 1){
        printf("PASS the Council Room card was discarded from player %d's hand!\n", randPlayer);
    }
    else{
       printf("FAIL the Council Room card was not discarded from player %d's hand!\n", randPlayer);
    }

    printf("\n");
}


int main(int argc, char *argv[]){
    srand(time(NULL));
    int i;
    for (i = 0; i < 5; i++){
        testCouncilRoom();   
    }
    
    return 0;
}



