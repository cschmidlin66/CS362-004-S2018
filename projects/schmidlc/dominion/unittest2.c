#include<stdio.h>
#include<stdlib.h>
#include "dominion.h"
//#include "dominion.c"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

//TESTING getCost FUNCTION


void testCost(){
    //27 cards
    
    printf("\n");
    printf("-------------------------------------------------------------------------------------------------------------\n");
    printf("UNIT TEST 2 - getCost \n");
    
    int i;
   
    for (i = 0; i < 26; i++){
        char buffer[20];
        int correctCost;
        int returnedCost;
        switch( i ) 
        {
            case 0:
              strcpy(buffer, "curse");
              //returnedCost = getCost(curse);
              correctCost = 0;
              break;
            case 1:
              strcpy(buffer,"estate");
              //returnedCost = getCost(estate);
              correctCost = 2;
              break;
            case 2:
              strcpy(buffer,"duchy");
              //returnedCost = getCost(duchy);
              correctCost = 5;
              break;
            case 3:
              strcpy(buffer,"province");
              correctCost = 8;
              break;
              //returnedCost = getCost(province);
            case 4:
              strcpy(buffer,"copper");
              //returnedCost = getCost(copper);
              correctCost = 0;
              break;
            case 5:
              strcpy(buffer,"silver");
              //returnedCost = getCost(silver);
              correctCost = 3;
              break;
            case 6:
              strcpy(buffer,"gold");
              //returnedCost = getCost(gold);
              correctCost = 6;
              break;
            case 7:
              strcpy(buffer,"adventurer");
              //returnedCost = getCost(adventurer);
              correctCost = 6;
              break;
            case 8:
              strcpy(buffer,"council_room");
              //returnedCost = getCost(council_room);
              correctCost = 5;
              break;
            case 9:
              strcpy(buffer,"feast");
              //returnedCost = getCost(feast);
              correctCost = 4;
              break;
            case 10:
              strcpy(buffer,"gardens");
              //returnedCost = getCost(gardens);
              correctCost = 4;
              break;
            case 11:
              strcpy(buffer,"mine");
              //returnedCost = getCost(mine);
              correctCost = 5;
              break;
            case 12:
              strcpy(buffer,"remodel");
              //returnedCost = getCost(remodel);
              correctCost = 4;
              break;
            case 13:
              strcpy(buffer,"smithy");
              //returnedCost = getCost(smithy);
              correctCost = 4;
              break;
            case 14:
              strcpy(buffer,"village");
              //returnedCost = getCost(village);
              correctCost = 3;
              break;
            case 15:
              strcpy(buffer,"baron");
              //returnedCost = getCost(baron);
              correctCost = 4;
              break;
            case 16:
              strcpy(buffer,"great_hall");
              //returnedCost = getCost(great_hall);
              correctCost = 3;
              break;
            case 17:
              strcpy(buffer,"minion");
              //returnedCost = getCost(minion);
              correctCost = 5;
              break;
            case 18:
              strcpy(buffer,"steward");
              //returnedCost = getCost(steward);
              correctCost = 3;
              break;
            case 19:
              strcpy(buffer,"tribute");
              //returnedCost = getCost(tribute);
              correctCost = 5;
              break;
            case 20:
              strcpy(buffer,"ambassador");
              //returnedCost = getCost(ambassador);
              correctCost = 3;
              break;
            case 21:
              strcpy(buffer,"cutpurse");
              //returnedCost = getCost(cutpurse);
              correctCost = 4;
              break;
            case 22: 
              strcpy(buffer,"embargo");
              //returnedCost = getCost(embargo);
              correctCost = 2;
              break;
            case 23:
              strcpy(buffer,"outpost");
              //returnedCost = getCost(outpost);
              correctCost = 5;
              break;
            case 24:
              strcpy(buffer,"salvager");
              //returnedCost = getCost(salvager);
              correctCost = 4;
              break;
            case 25:
              strcpy(buffer,"sea_hag");
              //returnedCost = getCost(sea_hag);
              correctCost = 4;
              break;
            case 26:
              strcpy(buffer,"treasure_map");
              //returnedCost = getCost(treasure_map);
              correctCost = 4;
              break;
            }

            returnedCost = getCost(i);

        if (correctCost == returnedCost){
            printf("getCost: PASS - Card: %s returned the correct cost! Returned: %d Correct %d \n", buffer, returnedCost, correctCost);
        }
        else{
            printf("getCost: FAIL - Card: %s returned the wrong cost! Returned: %d Correct %d \n", buffer, returnedCost, correctCost);
        }
        strcpy(buffer," ");
    }
    
   
    
    

    printf("\n");
}


int main(int argc, char *argv[]){
    
    testCost();
    
    return 0;
}



