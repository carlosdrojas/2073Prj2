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
    int reservationID;
    int guestID;
    int availability[90];
    RoomType roomType;
} RoomRecord;

typedef struct Guest {
    int guestID;
    char name[50];
    //FIXME: add more info for guests
} Guest;

typedef struct {
    int staffID;
} Staff;

void fillRecords(FILE*, RoomRecord*, Guest*);

void guestLogin(int);

void staffLogin();

void printMenu();

void guestOptions();

void staffOptions();



#endif