#include<stdio.h>
#include<stdlib.h>
#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

//TESTING Smithy Card


void testSmithy(){

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
    printf("CARD TEST 1 - Smithy Card Effect \n");
    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};

    initializeGame(2, k, 10, &G);
    gainCard(13,&G,2,0);
    int currentNumCards = numHandCards(&G);
    int i;
    printf("\n");
    printf("Player Hand\n");
    for (i = 0; i <  currentNumCards; i++){
        int card = handCard(i, &G);
        printf("%d. %s\n", (i+1), cardNames[card]);
    }

    printf("\n");
    //int smithyPos = -1;
    playCard((currentNumCards-1), -1, -1, -1, &G);

    int newHandNum = numHandCards(&G);
    //In this case do not discard a card because this is just testing the effect but not played from the hand
    int correctNum = ((currentNumCards)+2);

    if (newHandNum == correctNum){
        printf("PASS the current player gained 3 more cards! Current: %d Correct: %d \n", newHandNum, correctNum);
    }
    else{
       printf("FAIL the current player did not gain 3 more cards! Current: %d Correct: %d \n", newHandNum, correctNum); 
    }

    printf("Verify the Smithy card is discarded from the hand\n");

    int discarded = 1;
    printf("\n");
    printf("Player Hand\n");
    for (i = 0; i <  newHandNum; i++){
        int card = handCard(i, &G);
        printf("%d. %s\n", (i+1), cardNames[card]);
        if(strcmp(cardNames[card],"Smithy") == 0){
            discarded = 0;
        }
    }
    printf("\n");

    if (discarded == 1){
        printf("PASS the Smithy card was discarded from the hand!\n");
    }
    else{
       printf("FAIL the Smithy card was not discarded from the hand!\n");
    }

   

    printf("\n");
}


int main(int argc, char *argv[]){
    testSmithy();
        
    
    return 0;
}



