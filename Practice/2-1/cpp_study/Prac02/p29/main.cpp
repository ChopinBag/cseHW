#include "movie.h"
#include <iostream>

using namespace std;

int main() {
    map<string, vector<int>> ratings;
    map<string, Genre> genres;

    string title, genreStr, ratingStr;

    //std::cout << "Enter movie data (Title, Genre, Rating). Type 'q' to quit:\n";

    while (getline(cin, title) && title != "q") {
        getline(std::cin, genreStr);
        getline(std::cin, ratingStr);
        
        Genre g = toGenre(genreStr);
        Rating r = toRating(ratingStr);
        int score = toInt(r);

        genres[title] = g;
        ratings[title].push_back(score);

    }
    
    printSummary(ratings, genres);

    return 0;
}