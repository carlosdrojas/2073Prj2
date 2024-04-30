//Source file to define functions
#include <stdio.h>
#include <stdlib.h>
#include "hotel.h"

void guestLogin(int guestNum) {
    int choice;

    while (1) {
        printf("\n1. Log in as new guest\n");
        printf("2. Log in as returning guest\n");
        printf("3. Exit\n");
        printf("Enter your selection: ");
        scanf("%d", &choice);
        if (choice == 1) {
            
        }
        else if (choice == 2) 
        {
            
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

void staffLogin() {
    int amongus = 0;
    int pass;
    while(amongus == 0) {
        printf("Enter password: ");
        scanf("%d", &pass);
        if (pass == 1234) {
            break;
        }
        printf("Incorrect, try again.\n");
    }   
}

void printMenu() {

    printf( "\n\n######### Hotel Database MENU #########\n");
    printf( "1. Login as Guest\n" );
    printf( "2. Login as Staff\n" );
    printf( "3. Exit\n" );
    printf( "Enter your selection: " );
}

void guestOptions() {
    printf( "\n1. Book Rooms\n" );
    printf( "2. Edit Reservations\n" );
    printf( "3. View Room Bookings\n" );
    printf( "4. Exit\n" );
    printf( "Enter your selection: " );
}

void staffOptions() {
    printf( "\n1. Add/Remove Rooms\n" );
    printf( "2. Manage Bookings\n" );
    printf( "3. View Room Availability\n" );
    printf( "4. Exit\n" );
    printf( "Enter your selection: " );
}