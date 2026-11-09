#include <iostream>
using namespace std;

#include"TMovieNode/TMovieNode.h"
#include"TMovie/TMovie.h"
#include"TMovieList/TMovieList.h"


//names
//Classes = 'TMovie'
//DataFields = 'camelCase'
//Functions = 'pascalCase'
//Enum = 'EMovieGenreType'
//typedef functions = 'FCheckMovie'


//search types in the form from the callback function
bool SearchByTitle(TMovie* movie, void* criteria) {
    string* title = static_cast<string*>(criteria);

    return movie->GetTitle() == *title;
}

bool SearchByDirector(TMovie* movie, void* criteria) {
    string* director = static_cast<string*>(criteria);

    return movie->GetDirector() == *director;
}

bool SearchByGenre(TMovie* movie, void* criteria) {
    EMovieGenreType* genre = static_cast<EMovieGenreType*>(criteria);

    return movie->GetGenre() == *genre;
}

int main() {

    //fill the linked list with test data
    TMovieList movies;

    movies.Append(new TMovie("The Oddessy", "Christopher Nolan", 2026, Action, 8.8));
    movies.Append(new TMovie("The Batman", "Mat Reeves", 2022, Action, 9.7));
    movies.Append(new TMovie("Happy Gilmore", "Dennis Dugan", 1996, Comedy, 6.6));
    movies.Append(new TMovie("The Conjuring", "James Wan", 2013, Horror, 5.5));
    movies.Append(new TMovie("The Godfather", "Francis Ford Coppola", 1972, Drama, 9.2));
    movies.Append(new TMovie("Fight Club", "David Fincher", 1999, Drama, 9.1));
    movies.Append(new TMovie("Avengers: Infinity War", "Anthony Russo", 2018, Action, 7.3));
    movies.Append(new TMovie("Inglourious Basterds", "Quentin Tarantino", 2009, static_cast<EMovieGenreType>(Comedy | Action), 8.8));

    movies.Prepend(new TMovie("Inception", "Christopher Nolan", 2010, static_cast<EMovieGenreType>(Action | SCIFI), 7.9 ));
    movies.Prepend(new TMovie("Forrest Gump", "Robert Zemeckis", 1994, Comedy, 8.8));
    movies.Prepend(new TMovie("The Shawshank Redemption", "Frank Darabont", 1994, Drama, 9.9));
    movies.Prepend(new TMovie("Pulp Fiction", "Quentin Tarantino", 1994, static_cast<EMovieGenreType>(Comedy | Drama), 8.8));
    movies.Prepend(new TMovie("Mad Max: Fury Road", "George Miller", 2015, Action, 6.6));
    movies.Prepend(new TMovie("Green Book", "Peter Farrelly", 2018, Drama, 9.1));
    movies.Prepend(new TMovie("Rocky", "John G. Avildsen", 1976, Drama, 7.9));

    //boolean function to determain if the loop should run
    bool isLive = true;
    //int for choosing menu options
    int choice = 0;
    //int for choosing index in the list for the apropriate functions
    int index = 0;

    //the menu loop and posible options
    while (isLive) {
        cout << "1. Show the linked list" << endl;
        cout << "2. Reverse the linked list" << endl;
        cout << "3. Get movie based on index in list" << endl;
        cout << "4. Search for movie by Title: " << endl;
        cout << "5. Search for movie by Director: " << endl;
        cout << "6. Search for movie by Genre: " << endl;
        cout << "7. Remove movie from list" << endl;
        cout << "8. End Program" << endl;

        cin >> choice;
        switch (choice) {
            case 1:
                //show list
                movies.ShowList();
                break;

            case 2:
                //reverse the list
                movies.Reverse();
                break;

            case 3: {
                //search for movie in list based on index
                cout << "Choose the index of which movie you would like" << endl;
                cin >> index;
                TMovie* movie = movies.GetAtIndex(index);

                if (movie != nullptr) {
                    cout << "Title: " << movie->GetTitle() << endl;
                    cout << "Director: " << movie->GetDirector() << endl;
                    cout << "Year: " << movie->GetYear() << endl;
                    cout << "Genre: " << movie->GetGenre() << endl;
                    cout << "Rating: " << movie->GetScore() << endl;
                }
                else {
                    cout << "no movie found";
                }
                break;
            }

            case 4: {
                //search for movie based on name
                cout << "Please type in movie name: ";
                string movieName;
                cin.ignore();
                getline(cin, movieName);

                TMovie* result = movies.SearchFor(SearchByTitle, &movieName);
                if (result != nullptr) {
                    cout << result->GetTitle() << endl;
                }
                else {
                    cout << "No movie found in the list" << endl;
                }
                break;
            }

            case 5: {
                //search for movie based on director
                cout << "Please type in director: " << endl;
                string movieDirector;
                cin.ignore();
                getline(cin, movieDirector);

                TMovie* result = movies.SearchFor(SearchByDirector, &movieDirector);
                if (result != nullptr) {
                    cout << result->GetTitle() << endl;
                }
                else {
                    cout << "no movie found by that director" << endl;
                }
                break;
            }

            case 6: {
                //search for movie based on director
                EMovieGenreType genre;
                cout << "Please type in genre: ";
                string movieGenre;
                cin >> movieGenre;

                if (movieGenre == "action") {
                    genre = Action;
                }
                else if (movieGenre == "comedy") {
                    genre = Comedy;
                }
                else if (movieGenre == "scifi") {
                    genre = SCIFI;
                }
                else if (movieGenre == "horror") {
                    genre = Horror;
                }
                else if (movieGenre == "drama"){
                    genre = Drama;
                }
                else {
                    cout << "invalid movie genre" << endl;
                    break;
                }

                TMovie* result = movies.SearchFor(SearchByGenre, &genre);
                if (result != nullptr) {
                    cout << result->GetTitle() << endl;
                }
                else {
                    cout << "No movie found in that genre" << endl;
                }

                break;
            }


            case 7:
                //remove item from list
                cin >> index;
                movies.Remove(index);
                break;

            case 8:
                //endloop
                isLive = false;
                break;
        }
    }

    return 0;
}