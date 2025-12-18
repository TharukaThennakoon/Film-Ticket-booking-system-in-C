#include <stdio.h>
#include "movie.h"
#include "booking.h"

int main(){
    int choice;

    while(1){

        printf("\n ====Movie Ticket Booking System====\n");
        printf("1. Book Ticket\n");
        printf("2. Show My Ticket\n");
        printf("3. Check Seat Availability\n");
        printf("4. Add Movie (Admin)\n");
        printf("5. Show Movies\n");
        printf("6. Edit Movie (Admin)\n");
        printf("7. Delete Movie (Admin)\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {        
        case 1: bookTicket(); break;

        case 2: showMyTicket(); break;

        case 3: checkSeat(); break;

        case 4: addMovie(); break;

        case 5: showMovies(); break;

        case 6: editMovie(); break;

        case 7: deleteMovie(); break;

        case 0: printf("Thank you for using the system. Goodbye!\n"); return 0;
        }

    }
}