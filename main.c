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
    int guestID;
    int checkIn;
    int checkOut;
    int roomNum;
    int reserveID = 420;
    int temp1;
    int temp2;

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
        record[i].reservationID = 0;
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

    fillRecords(fileIn, record, guests);

    fclose( fileIn );

    //TODO: function to fill room records
    //createRecords( fileIn, &record );


    

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

        //printMenu();
        printf( "\n\n######### Hotel Database MENU #########\n");
        printf( "1. Login as Guest\n" );
        printf( "2. Login as Staff\n" );
        printf( "3. Exit\n" );
        printf( "Enter your selection: " );
        scanf("%d", &choice);

        if (choice == 1) {
            while (1) {
                //guestLogin();
                //guestOptions();
                printf( "\n\n######### Guest MENU #########\n");
                printf( "1. Book Rooms\n" );
                printf( "2. Edit Reservations\n" );
                printf( "3. View Room Bookings\n" );
                printf( "4. Exit\n" );
                printf( "Enter your selection: " );
                scanf("%d", &choice);

                if (choice == 1) {
                    printf("Enter Guest ID: ");
                    scanf("%d", &guestID);
                    printf("Enter room number: ");
                    scanf("%d", &roomNum);
                    printf("Enter check-in date: ");
                    scanf("%d", &checkIn);
                    printf("Enter check out date: ");
                    scanf("%d", &checkOut);

                    for (i = 0; i < 20; i++) {
                        if (roomNum == record[i].roomNumber) {
                            record[i].reservationID = reserveID;
                            printf("Your reservation ID is %d\n", record[i].reservationID);
                            for (j = 0; j < 90; j++) {
                                if (j >= checkIn && j <= checkOut) {
                                    record[i].availability[j - 1] = guestID;
                                }
                            }
                        }
                    }

                    reserveID++;
                    printf("Thank you for booking!\n");


                }
                else if (choice == 2) 
                {
                    temp2 = 0;
                    printf("Please enter reservation ID: ");
                    scanf("%d", &temp1);
                    for (i = 0; i < 20; i++) {
                        if (temp1 == record[i].reservationID) {
                            temp2 = 1;
                        }
                    }
                    if (temp2 == 0) {
                        printf("Invalid Reservation ID, please try again\n");
                    } else {
                        for (i = 0; i < 20; i++) {
                            if (record[i].reservationID == temp1) {
                                for (j = 0; j < 90; j++) {
                                    record[i].availability[j] = 0;
                                }
                            }
                        }
                        printf("Enter new check-in date: ");
                        scanf("%d", &checkIn);
                        printf("Enter new check-out date: ");
                        scanf("%d", &checkOut);
                        for (i = 0; i < 20; i++) {
                            if (temp1 == record[i].reservationID) {
                                for (j = 0; j < 90; j++) {
                                    if (j >= checkIn && j <= checkOut) {
                                        record[i].availability[j - 1] = guestID;
                                    }
                                }
                            }
                        }
                    }
                    
                }
                else if (choice == 3) 
                {
                    //FIXME: add functionality
                    printf("Enter guest ID: ");
                    scanf("%d", &temp1);
                    temp2 = 0;
                    for (i = 0; i < 20; i++) {
                        if (temp1 == guests[i].guestID) {
                            temp2 = 1;
                        }
                    }
                    if (temp2 == 1) {
                        for (i = 0; i < 20; i++) {
                            if (record[i].guestID == temp1) {
                                printf("Room number: %d\n", record[i].roomNumber);
                                printf("Days booked: ");
                                for (j = 0; j < 90; j++) {
                                    if (record[i].availability[j] != 0) {
                                        printf("%d ", j + 1);
                                    }
                                }
                            }
                        }
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
            while (1) {
                staffLogin();

                //staffOptions();
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
                        for (i = 0; i < 20; i++) {
                            if (record[i].roomNumber == roomNum) {
                                for (j = 0; j < 90; j++) {
                                    if (j >= checkIn && j <= checkOut) {
                                        record[i].availability[j] = guestID;
                                    }
                                }
                            }
                        }

                    }
                    else if (choice == 2)
                    {
                        printf("Enter Reservation ID: ");
                        scanf("%d", &temp1);
                        for (i = 0; i < 20; i++) {
                            if (record[i].reservationID) {
                                for (j = 0; j < 90; j++) {
                                    record[i].availability[j] = 0;
                                }
                            }
                        }
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
                    //FIXME: add view room availability functionality
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
        else if (choice == 3) 
        {
            break;
        } 
        //temp debug chioce, remove once done
        //--------
        else if (choice == 4) 
        {
            for (i = 0; i < 20; i++) {
                printf("Room %d: \n", i + 1);
                //if (record[i].reservationID != NULL) {
                    printf("Reservation ID: %d\n", record[i].reservationID);
                //}
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
                    printf("Day %d: %d\n", j + 1, record[i].availability[j]);
                }
                printf("\n");
            }     
        } 
        //--------
        else
        {
            printf("invalid choice.");
        }
    }

    //FIXME: add functinality of writing rooms to file
    
    return 0;
}