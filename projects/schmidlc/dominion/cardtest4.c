#include<stdio.h>
#include<stdlib.h>
#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

//TESTING Great Hall Card Effect


void testGreatHall(){
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
           sea_hag, great_hall, smithy};
    initializeGame(2, k, 10, &G);
 

    printf("\n");
    printf("-------------------------------------------------------------------------------------------------------------\n");
    printf("CARD TEST 4 - Great Hall\n");
    
    gainCard(6, &G,1,0);
    gainCard(6, &G,1,0);
    gainCard(6, &G,1,0);
    gainCard(16,&G,2,0);
    int currentHandCount = numHandCards(&G);

    printf("\n");
    printf("Player Hand\n");
    int i;
    for (i = 0; i <  currentHandCount; i++){
        int card = handCard(i, &G);
        printf("%d. %s\n", (i+1), cardNames[card]);
    }

    printf("\n");

    int originalActionAmount = G.numActions;

    playCard((currentHandCount - 1), -1, -1, -1, &G);

    int newActionAmount = G.numActions;

    int newCurrentNumCards = numHandCards(&G);

    printf("Verify that one card is added to the players hand\n");

    if (newCurrentNumCards == currentHandCount){
        printf("PASS one card was added to the players hand!\n");
    }
    else{
       printf("FAIL one card was not added to the players hand!\n"); 
    }
   
    printf("Verify that the player receives one extra action\n");

    if (newActionAmount == originalActionAmount){
        printf("PASS player received an extra action!\n");
    }
    else{
       printf("FAIL player did not receive an extra action!\n"); 
    }

  
    printf("Verify the Great Hall card is discarded from the hand\n");
    int discarded = 1;
    printf("\n");
    printf("Player Hand\n");
    for (i = 0; i <  newCurrentNumCards; i++){
        int card = handCard(i, &G);
        printf("%d. %s\n", (i+1), cardNames[card]);
        if(strcmp(cardNames[card],"Great Hall") == 0){
            discarded = 0;
        }
    }
    printf("\n");

    if (discarded == 1){
        printf("PASS the Great Hall card was discarded from the hand!\n");
    }
    else{
       printf("FAIL the Great Hall card was not discarded from the hand!\n");
    }

    printf("\n");
}


int main(int argc, char *argv[]){
    
    testGreatHall();    
    
    return 0;
}



