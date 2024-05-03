//header file containing fucntion delcarations
#ifndef HOTEL_H
#define HOTEL_H

typedef enum {
    SUITE,
    DOUBLE,
    SINGLE
} RoomType;

typedef struct {
    int roomNumber;
    int availability[90];
    RoomType roomType;
} RoomRecord;

typedef struct Guest {
    int guestID;
    char name[50];
    char emailAddress[50];
    char phoneNumber[20];
    char address[50];
} Guest;

typedef struct {
    int staffID;
} Staff;

int getRandomNumber(int, int);

int fillRecords(FILE*, RoomRecord*, Guest*);

void createRecords(FILE*, RoomRecord*, Guest*, int);

int guestLogin(int*, Guest*);

void staffLogin();

#endif