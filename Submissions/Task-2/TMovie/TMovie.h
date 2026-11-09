//
// Created by mikae on 15.09.2026.
//

#ifndef LINKEDLIST_TMOVIE_H
#define LINKEDLIST_TMOVIE_H

#include<string>
using namespace std;

//1.2 create enum for movie genres
enum EMovieGenreType {
    Action     = 1 << 0,
    Comedy     = 1 << 1,
    SCIFI      = 1 << 2,
    Horror     = 1 << 3,
    Drama      = 1 << 4
};

//1.1 TMovie class that represent a movie with common movie attributes
class TMovie {
private:
    string Title;
    string Director;
    int Year;
    EMovieGenreType Genre;
    float Score;

public:
    //constructor initialises all movie data fields
    TMovie(const string& Title, const string& Director, int year, EMovieGenreType Genre, float Score);

    //getter methods to access private data fields
    string GetTitle() const;
    string GetDirector() const;
    int GetYear() const;
    EMovieGenreType GetGenre() const;
    float GetScore() const;
};

#endif //LINKEDLIST_TMOVIE_H
