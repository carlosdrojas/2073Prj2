#include <stdio.h>
#include <stdlib.h>
#include "hotel.h"

int main(int argc, char* argv[]) {


    FILE *fileIn;
    //RoomRecord *record;
    RoomRecord record[20];
    Guest guests[20];
    int i;
    int j;
    int choice;
    int guestNum;

    if ( argc < 2 ) {
    printf( "ERROR: Missing file name" );
    return 1;
    }

    /* 3. Attempt to open the file. Print out Opening <filename>... before you
    call fopen(). */
    printf( "Opening %s...\n", argv[1] );;
    fileIn = fopen(argv[1], "r");
    /* 4. Check to see if the file opens. If it does not open, print out ERROR:
    Could not open file and end the program. */
    if ( fileIn == NULL ) {
        printf( "ERROR: Coult not open file" );
        return -1;
    }

    for (i = 0; i < 20; i++) {
        record[i].roomNumber = i + 1;
        for (j = 0; j < 90; j++) {
            record[i].availability[j] = 0;
        }
        if (i < 10) {
            record[i].roomType = SINGLE;
        } else if (i < 15) {
            record[i].roomType = DOUBLE;
        } else {
            record[i].roomType = SUITE;
        }
    }

    // for (i = 0; i < 20; i++) {
    //     printf("Room %d: \n", i + 1);
    //     if (record[i].roomType == SINGLE) {
    //         printf("Room Type: Single\n");
    //     }
    //     else if (record[i].roomType == DOUBLE) {
    //         printf("Room Type: Double\n");
    //     }
    //     else if (record[i].roomType == SUITE) {
    //         printf("Room Type: Suite\n");
    //     }
    //     for (j = 0; j < 90; j++) {
    //         printf("Day %d: %d\n", j + 1, record[i].availability[j]);
    //     }
    //     printf("\n");
    // }     

    
    while (1) {
        printMenu();

        scanf("%d", &choice);

        if (choice == 1) {
            while (1) {
                //guestLogin();
                guestOptions();
                scanf("%d", &choice);

                if (choice == 1) {

                }
                else if (choice == 2) 
                {

                }
                else if (choice == 3) 
                {
                    
                }
                else if (choice == 4)
                {
                    break;
                } 
                else
                {
                    printf("invalid choice.");
                }
            }
        } 
        else if (choice == 2) 
        {
            while (1) {
                staffLogin();

                staffOptions();
                scanf("%d", &choice);

                if (choice == 1) {

                }
                else if (choice == 2) 
                {

                }
                else if (choice == 3) 
                {
                    
                }
                else if (choice == 4)
                {
                    break;
                } 
                else
                {
                    printf("invalid choice.");
                }
            }
        } 
        else if (choice == 3) 
        {
            break;
        } 
        else
        {
            printf("invalid choice.");
        }
    }
    
    return 0;
}