//Source file to define functions
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hotel.h"

int getRandomNumber(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

int fillRecords(FILE *fileIn, RoomRecord *record, Guest *guests) {
    char buffer[1024];
    int guestID;
    char name[50];
    char email[50];
    char phoneNum[20];
    char address[50];
    int roomNum;
    int checkIn;
    int checkOut;
    int i;
    int j;
    int guestNum = 0;

    while (fgets(buffer, 1024, fileIn) != NULL) {
        sscanf( buffer, "%[^,],%[^,],%[^,],%[^,],%d,%d,%d,%d", name, email, phoneNum, address, &guestID, &roomNum, &checkIn, &checkOut );
        guests[guestNum].guestID = guestID;
        
        strcpy(guests[guestNum].name, name);
        strcpy(guests[guestNum].emailAddress, email);
        strcpy(guests[guestNum].phoneNumber, phoneNum);
        strcpy(guests[guestNum].address, address);

        for (i = 0; i < 20; i++) {
            if (record[i].roomNumber == roomNum) {
                //record[i].guestID = guestID;
                //record[i].reservationID = reserveID;
                for (j = 0; j < 90; j++) {
                    if (j >= checkIn - 1 && j <= checkOut - 1) {
                        record[i].availability[j] = guestID;
                    }
                }
            }
        }
        guestNum++;
    }
    return guestNum;

}

void createRecords(FILE *fileIn, RoomRecord *record, Guest *guests, int guestNum) {
    int i, j, k;
    for (i = 0; i < guestNum; i++) {
        fprintf(fileIn, "%s,%s,%s,%s,%d", guests[i].name, guests[i].emailAddress, guests[i].phoneNumber, guests[i].address, guests[i].guestID);
        for (j = 0; j < 20; j++) {
            for (k = 0; k < 90; k++) {
                if (record[j].availability[k] == guests[i].guestID) {
                    int checkIn = k + 1;  // Convert 0-based index to 1-based date
                    int checkOut = k + 1; // Initialize checkOut to checkIn
                    // Find the check-out date by searching for the next available date
                    while (k < 89 && record[j].availability[k + 1] == guests[i].guestID) {
                        k++;
                        checkOut++;
                    }
                    fprintf(fileIn, ",%d,%d,%d", record[j].roomNumber, checkIn , checkOut );
                }
            }
        }
        fprintf(fileIn, "\n");
    }
}

int guestLogin(int *guestNum, Guest *guests) {
    int choice;
    int guestID;
    char name[50];
    char emailAddress[50];
    char phoneNumber[15];
    char address[50];
    int temp;
    int i;
    int gNum = *guestNum;

    //FIXME: finish implementation
    while (1) {
        printf("\n1. Log in as new guest\n");
        printf("2. Log in as returning guest\n");
        //printf("3. Exit\n");
        printf("Enter your selection: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("\nPlease enter your name: ");
            scanf(" %[^\n]s", name);
            strcpy(guests[gNum].name, name);
            printf("\nPlease enter your phone number: ");
            scanf("%s", phoneNumber);
            strcpy(guests[gNum].phoneNumber, phoneNumber);
            printf("\nPlease enter your email address: ");
            scanf("%s", emailAddress);
            strcpy(guests[gNum].emailAddress, emailAddress);
            printf("\nPlease enter your physical adress: ");
            scanf("%s", address);
            strcpy(guests[gNum].address, address);
            guestID = getRandomNumber(1, 9999);
            guests[gNum].guestID = guestID;
            printf("\nYour Guest ID: %d", guestID);
            (*guestNum)++;
            return guestID;
        }
        else if (choice == 2) 
        {
            while(1) {
                temp = 0;
                printf("\nPlease enter your name: ");
                //scanf("%s", name);
                //fgets(name, 50, stdin);
                scanf(" %[^\n]s", name);

                printf("Please enter your Guest ID: ");
                scanf("%d", &guestID);
                for (i = 0; i < 20; i++) {
                    if (strcmp(guests[i].name, name) == 0 && guestID == guests[i].guestID) {
                        temp = 1;
                    }
                }
                if (temp == 1) {
                    return guestID;
                } else {
                    printf("\nInvalid guest information\n");
                }
            }
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