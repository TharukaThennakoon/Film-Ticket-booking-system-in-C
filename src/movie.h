#ifndef MOVIE_H
#define MOVIE_H

typedef struct 
{
    int id;
    char name[50];
    char genre[20];
    char format[10];
    char show_date[20];
    char show_time[20];
    int price;
    int available_seats;
} Movie;

void addMovie();
void showMovies();
void editMovie();
void deleteMovie();
int findMovie(int id, Movie *m);

#endif // MOVIE_H
