#include<stdio.h>
#include<stdlib.h>
#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

//TESTING Adventurer Card


void testAdventurer(){

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
    printf("CARD TEST 2 - Adventurer Card Effect\n");
    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
    int treasureCount = 0;
    initializeGame(2, k, 10, &G);
    gainCard(6, &G,1,0);
    gainCard(6, &G,1,0);
    gainCard(6, &G,1,0);
    gainCard(7,&G,2,0);
    int currentNumCards = numHandCards(&G);

    printf("\n");
    printf("Player Hand\n");
    int i;
    for (i = 0; i <  currentNumCards; i++){
        int card = handCard(i, &G);
        printf("%d. %s\n", (i+1), cardNames[card]);
    }

    printf("\n");
    //get the number of treasure cards in hand
    for (i = 0; i < currentNumCards; i++){
        if (handCard(i, &G) == copper ){
            treasureCount++;
        }
        if (handCard(i, &G) == silver ){
            treasureCount++;
        }
        if (handCard(i, &G) == gold ){
            treasureCount++;
        } 
    }
     //then draw until there are 2 more treasure in hand
    playCard((currentNumCards - 1), -1, -1, -1, &G);
    //get the number of treasure cards in hand again
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
        printf("PASS player has the correct number of cards in hand! Current: %d Correct: %d \n", newCurrentNumCards, correctAmount);
    }
    else{
       printf("FAIL player does NOT have the correct number of cards in hand! Current: %d Correct: %d \n", newCurrentNumCards, correctAmount);
    
    }

    if (newTreasureCount == correctTreasure){
        printf("PASS player has the correct number of treasure cards in hand! Current: %d Correct: %d \n", newTreasureCount, correctTreasure);
    }
    else{
       printf("FAIL player does NOT have the correct number of treasure cards in hand! Current: %d Correct: %d \n", newTreasureCount, correctTreasure);
    
    }
   
    printf("Verify the Adventurer card is discarded from the hand\n");
    int discarded = 1;
    printf("\n");
    printf("Player Hand\n");
    for (i = 0; i <  newCurrentNumCards; i++){
        int card = handCard(i, &G);
        printf("%d. %s\n", (i+1), cardNames[card]);
        if(strcmp(cardNames[card],"Adventurer") == 0){
            discarded = 0;
        }
    }
    printf("\n");

    if (discarded == 1){
        printf("PASS the Adventurer card was discarded from the hand!\n");
    }
    else{
       printf("FAIL the Adventurer card was not discarded from the hand!\n");
    }

    printf("\n");
}


int main(int argc, char *argv[]){
    
        
    testAdventurer();
    return 0;
}



