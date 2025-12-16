#include <stdio.h>
#include <string.h>
#include "booking.h"
#include "movie.h"

void bookTicket(){
    showMovies();

    int id, seats;
    printf("Enter movie ID to book: ");
    scanf("%d", &id);

    Movie m;
    if(!findMovie(id, &m)){
        printf("Movie with ID %d not found.\n", id);
        return;
    }

    Booking b;
    printf("Enter your name: ");
    scanf("%s", b.customer_name);

    printf("Enter your phone number: ");
    scanf("%s", b.phone);

    printf("Enter number of seats to book: ");
    scanf("%d", &seats);

    if(seats > m.available_seats){
        printf("Only %d seats available for this movie.\n", m.available_seats);
        return;
    }

    b.movie_id = id;
    strcpy(b.movie_name, m.name);
    strcpy(b.format, m.format);
    strcpy(b.show_date, m.show_date);
    strcpy(b.show_time, m.show_time);

    b.seats = seats;
    b.total_price = seats * m.price;

    m.available_seats -= seats;

        FILE *fp = fopen("movies.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    Movie tempMovie;

    while(fread(&tempMovie, sizeof(Movie), 1, fp)){
        if(tempMovie.id == id){
            tempMovie.available_seats = m.available_seats;
        }
        fwrite(&tempMovie, sizeof(Movie), 1, temp);
    }

    fclose(fp);
    fclose(temp);
    remove("movies.dat");
    rename("temp.dat", "movies.dat");

        FILE *fp2 = fopen("customer.dat", "ab");
    fwrite(&b, sizeof(Booking), 1, fp);
    fclose(fp);

    printf("Booking successful! Total price: %d\n", b.total_price);


    
}

