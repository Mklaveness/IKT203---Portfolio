//
// Created by mikae on 15.09.2026.
//
#include "TMovie.h"
using namespace std;

//constructor initialises all movie data fields
TMovie::TMovie(const string& title, const string& director, int year, EMovieGenreType genre, float score)
    : Title(title), Director(director), Year(year), Genre(genre), Score(score) {
};

//getter methods to access private data fields
string TMovie::GetTitle() const {
    return Title;
}
string TMovie::GetDirector() const {
    return Director;
}
int TMovie::GetYear() const {
    return Year;
}
EMovieGenreType TMovie::GetGenre() const {
    return Genre;
}
float TMovie::GetScore() const {
    return Score;
}

