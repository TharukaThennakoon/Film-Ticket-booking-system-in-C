#include <stdio.h>
#include <string.h>
#include "movie.h"

void addMovie(){
    FILE * fp = fopen("movies.dat", "ab");
    Movie m;

    printf("Enter movie name: ");
    scanf("%s", m.name);
    printf("Enter genre: ");
    scanf("%s", m.genre);
    printf("Enter format (2D/3D): ");
    scanf("%s", m.format);
    printf("Enter show date (YYYY-MM-DD): ");
    scanf("%s", m.show_date);
    printf("Enter show time (HH:MM): ");
    scanf("%s", m.show_time);
    printf("Enter price: ");
    scanf("%d", &m.price);
    printf("Enter available seats: ");
    scanf("%d", &m.available_seats);

    //auto ID 
    FILE * fp2 = fopen("movies.dat", "rb");
    int id = 1;
    Movie temp;
    while(fp2 && fread(&temp, sizeof(Movie), 1, fp2))
    id = temp.id + 1;
    if(fp2) fclose(fp2);

    m.id = id;

    fwrite(&m, sizeof(Movie), 1, fp);
    fclose(fp);

    printf("Movie added successfully with ID: %d\n", m.id);

}

