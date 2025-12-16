#ifndef BOOKING_H
#define BOOKING_H

typedef struct
{
    int booking_id;
    char customer_name[50];
    char phone[20];
    int movie_id;
    char movie_name[50];
    char format[10];
    int seats;
    int total_price;
    char show_date[20];
    char show_time[20];
} Booking;

void bookTicket();
void showMyTicket();
void checkSeat();

#endif // BOOKING_H
