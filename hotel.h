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
    struct Guest* next;
} Guest;

typedef struct {
    int staffID;
} Staff;


void guestLogin();

void staffLogin();

void printMenu();

void guestOptions();

void staffOptions();



#endif