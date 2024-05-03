#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hotel.h"

int main(int argc, char* argv[]) {

	srand((int)time(0));

    FILE *fileIn;
    RoomRecord record[20];
    Guest guests[20];
    int i;
    int j;
    int choice;
    int guestNum = 0;
    int guestID;
    int checkIn;
    int checkOut;
    int roomNum;
    int roomCheck;

    if ( argc < 2 ) {
    printf( "ERROR: Missing file name" );
    return 1;
    }

    /*Attempt to open the file. Print out Opening <filename>... before you
    call fopen(). */
    printf( "Opening %s...\n", argv[1] );
    fileIn = fopen(argv[1], "r");

    /* Check to see if the file opens. If it does not open, print out ERROR:
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

    guestNum = fillRecords(fileIn, record, guests);
    
    printf("Number of guests in database: %d", guestNum);

    fclose( fileIn );
    

    
    while (1) {

        printf( "\n\n######### Hotel Database MENU #########\n");
        printf( "1. Login as Guest\n" );
        printf( "2. Login as Staff\n" );
        printf( "3. View Complete Database\n" );
        printf( "4. Exit\n" );
        printf( "Enter your selection: " );
        scanf("%d", &choice);

        if (choice == 1) {
            guestID = guestLogin(&guestNum, guests);

            while (1) {
                
                printf( "\n\n######### Guest MENU #########\n");
                printf( "1. Book Rooms\n" );
                printf( "2. Edit Reservations\n" );
                printf( "3. View Room Bookings\n" );
                printf( "4. Exit\n" );
                printf( "Enter your selection: " );
                scanf("%d", &choice);

                if (choice == 1) {
                    while (1) {
                        printf("Enter room number: ");
                        scanf("%d", &roomNum);
                        printf("Enter check-in date: ");
                        scanf("%d", &checkIn);
                        printf("Enter check out date: ");
                        scanf("%d", &checkOut);


                    
                        roomCheck = 0;
                        for (i = 0; i < 20; i++) {
                            if (roomNum == record[i].roomNumber) {
                                for (j = 0; j < 90; j++) {
                                    if (j >= checkIn - 1 && j <= checkOut - 1) {
                                        if (record[i].availability[j] != 0) {
                                            printf("Reservation conflicts with pre-existing reservation, please try again.\n");
                                            roomCheck = 1;
                                            break;
                                        }
                                    }
                                }
                            }
                            if (roomCheck == 1) {
                                break;
                            }
                        }
                        if (roomCheck == 0) {
                            break;
                        }
                    }
                    
                    for (i = 0; i < 20; i++) {
                        if (roomNum == record[i].roomNumber) {
                            for (j = 0; j < 90; j++) {
                                if (j >= checkIn - 1 && j <= checkOut - 1) {
                                    record[i].availability[j] = guestID;
                                }
                            }
                        }
                    }

                    printf("Thank you for booking!\n");


                }
                else if (choice == 2) 
                {
                    for (i = 0; i < 20; i++) {
                        for (j = 0; j < 90; j++) {
                            if (record[i].availability[j] == guestID) {
                                record[i].availability[j] = 0;
                            }
                        }
                    }
                    printf("Enter new room number: ");
                    scanf("%d", &roomNum);
                    printf("Enter new check-in date: ");
                    scanf("%d", &checkIn);
                    printf("Enter new check-out date: ");
                    scanf("%d", &checkOut);
        
                    for (j = 0; j < 90; j++) {
                        if (j >= checkIn - 1 && j <= checkOut - 1) {
                            record[roomNum - 1].availability[j] = guestID;
                        }
                    }
                    
                }
                else if (choice == 3) 
                {
                    roomCheck = 0;
                    for (i = 0; i < 20; i++) {
                        for (j = 0; j < 90; j++) {
                            if (record[i].availability[j] == guestID) {
                                roomCheck = 1;
                            }
                        }
                    }

                    if (roomCheck == 0) {
                        printf("You have no active reservations\n");
                    } else {
                        printf("You have days ");
                        for (i = 0; i < 20; i++) {
                            
                            for (j = 0; j < 90; j++) {
                                if (record[i].availability[j] == guestID) {
                                    printf("%d ", j + 1);
                                    roomNum = record[i].roomNumber;
                                }
                            }
                        }
                        printf("booked in room %d", roomNum);
                    }

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
            staffLogin();
            while (1) {
                

                printf( "\n\n######### Staff MENU #########\n");
                printf( "1. Manage Bookings\n" );
                printf( "2. View Room Availability\n" );
                printf( "3. Exit\n" );
                printf( "Enter your selection: " );
                scanf("%d", &choice);

                if (choice == 1) 
                {
                    printf( "\n1. Add Booking \n" );
                    printf( "2. Remove Booking\n" );
                    printf( "3. Exit\n" );
                    printf( "Enter your selection: " );
                    scanf("%d", &choice);

                    if (choice == 1) 
                    {
                        printf("Enter Room Number: ");
                        scanf("%d", &roomNum);
                        printf("Enter Guest ID: ");
                        scanf("%d", &guestID);
                        printf("Enter check-in date: ");
                        scanf("%d", &checkIn);
                        printf("Enter check-out date: ");
                        scanf("%d", &checkOut);
                       
                        for (j = 0; j < 90; j++) {
                            if (j >= checkIn - 1 && j <= checkOut - 1) {
                                record[roomNum - 1].availability[j] = guestID;
                            }
                        }
                          
                    }
                    else if (choice == 2)
                    {
                        printf("Enter Guest ID: ");
                        scanf("%d", &guestID);
                        for (i = 0; i < 20; i++) {
                            for (j = 0; j < 90; j++) {
                                if (record[i].availability[j] == guestID) {
                                    record[i].availability[j] = 0;
                                }
                            }
                        }
                        printf("Bookings removed");
                    }
                    else if (choice == 3)
                    {
                        break;
                    }
                    else 
                    {
                        printf("Invalid selection\n");
                    }

                }
                else if (choice == 2) 
                {
                    printf("Enter room number: ");
                    scanf("%d", &roomNum);

                    printf("Days available for room %d: ", roomNum);

                    for (j = 0; j < 90; j++) {
                        if (record[roomNum - 1].availability[j] == 0) {
                            printf("%d ", j + 1);
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
        } 
        else if (choice == 4) 
        {
            break;
        } 
        else if (choice == 3) 
        {
            for (i = 0; i < 20; i++) {
                printf("\nRoom %d: \n", i + 1);
                if (record[i].roomType == SINGLE) {
                    printf("Room Type: Single\n");
                }
                else if (record[i].roomType == DOUBLE) {
                    printf("Room Type: Double\n");
                }
                else if (record[i].roomType == SUITE) {
                    printf("Room Type: Suite\n");
                }
                for (j = 0; j < 90; j++) {
                    printf("Day %d: %d ", j + 1, record[i].availability[j]);
                }
                printf("\n");
            }     
        } 
        else
        {
            printf("invalid choice.");
        }
    }

    fileIn = fopen(argv[1], "w");
    createRecords( fileIn, record, guests, guestNum);

    fclose(fileIn);


    
    return 0;
}