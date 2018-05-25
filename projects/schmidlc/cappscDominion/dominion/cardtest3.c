#include<stdio.h>
#include<stdlib.h>
#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

//TESTING Council Room Card Effect


void testCouncilRoom(){
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
           sea_hag, council_room, smithy};
    initializeGame(2, k, 10, &G);

       

    printf("\n");
    printf("-------------------------------------------------------------------------------------------------------------\n");
    printf("CARD TEST 3 - Council Room\n");

    gainCard(6, &G,1,0);
    gainCard(6, &G,1,0);
    gainCard(6, &G,1,0);
    gainCard(8,&G,2,0);

    int currentHandCount = numHandCards(&G);

    printf("Verify current player draws 4 more cards to their hand\n");


    printf("\n");
    printf("Player Hand\n");
    int i;
    for (i = 0; i <  currentHandCount; i++){
        int card = handCard(i, &G);
        printf("%d. %s\n", (i+1), cardNames[card]);
    }

    printf("\n");
    int originalBuyNum = G.numBuys;
    int secondPlayerHand = G.handCount[1];
    playCard((currentHandCount - 1), -1, -1, -1, &G);

    int newCurrentNumCards = numHandCards(&G);
    int secondPlayerHandNew = G.handCount[1];

    if (newCurrentNumCards == (currentHandCount -1)+4){
        printf("PASS the current play added four more cards to their hand! Current: %d Correct: %d \n", newCurrentNumCards,((currentHandCount -1)+4));
    }
    else{
        printf("FAIL the current play did not add four more cards to their hand! Current: %d Correct: %d \n", newCurrentNumCards,((currentHandCount -1)+4));
    }

    int newBuyNum = G.numBuys;

    printf("Verify current player gains an extra buy action \n");
    if (newBuyNum == (originalBuyNum + 1)){
        printf("PASS current player received one more buy action! \n");
    }
    else{
       printf("FAIL current player did not receive one more buy action! \n"); 
    }


    printf("Verify other player draw one card.\n");
    if (secondPlayerHandNew == (secondPlayerHand + 1)){
        printf("PASS the other player added one card to their hand! \n");
    }
    else{
       printf("FAIL the other player did not add one card to their hand! \n");
    }


    printf("Verify the Council Room card is discarded from the hand\n");
    int discarded = 1;
    printf("\n");
    printf("Player Hand\n");
    for (i = 0; i <  newCurrentNumCards; i++){
        int card = handCard(i, &G);
        printf("%d. %s\n", (i+1), cardNames[card]);
        if(strcmp(cardNames[card],"Council Room") == 0){
            discarded = 0;
        }
    }
    printf("\n");

    if (discarded == 1){
        printf("PASS the Council Room card was discarded from the hand!\n");
    }
    else{
       printf("FAIL the Council Room card was not discarded from the hand!\n");
    }

    printf("\n");
}


int main(int argc, char *argv[]){
    
    testCouncilRoom();   
    
    return 0;
}



