#include "movie.h"
#include <iostream>

int main() {
    std::map<std::string, std::vector<int>> ratings;
    std::map<std::string, Genre> genres;

    std::string title, genreStr, ratingStr;

    //std::cout << "Enter movie data (Title, Genre, Rating). Type 'q' to quit:\n";

    while (std::getline(std::cin, title) && title != "q") {
        std::getline(std::cin, genreStr);
        std::getline(std::cin, ratingStr);
        
        // Implement your code
        
    }
    
    printSummary(ratings, genres);

    return 0;
}