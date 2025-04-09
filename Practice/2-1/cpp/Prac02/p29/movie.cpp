#include "movie.h"

Genre toGenre(const std::string& str){
    if(str == "Action") return Genre::Action;
    if(str == "Comedy") return Genre::Comedy;
    if(str == "Drama") return Genre::Drama;
    if(str == "Romance") return Genre::Romance;
    if(str == "SciFi") return Genre::SciFi;
    return Genre::Action;
}

Rating toRating(const std::string& str){
    if(str == "★☆☆☆☆") return Rating::One;
    if(str == "★★☆☆☆") return Rating::Two;
    if(str == "★★★☆☆") return Rating::Three;
    if(str == "★★★★☆") return Rating::Four;
    if(str == "★★★★★") return Rating::Five;
    return Rating::Unrated;
}

int toInt(Rating r){
    switch(r){
        case Rating::One: return 1;
        case Rating::Two: return 2;
        case Rating::Three: return 3;
        case Rating::Four: return 4;
        case Rating::Five: return 5;
        default: return 0;
    }
}


int avg(const std::vector<int>& list){
    int sum = 0;
    int size = list.size();
    for(int i = 0; i < size; ++i){
        sum += list[i];
    }
    return static_cast<int>((sum / static_cast<double>(size)) + 0.5);
}

std::string genreToString(Genre g) {
    switch(g) {
        case Genre::Action: return "Action";
        case Genre::Comedy: return "Comedy";
        case Genre::Drama: return "Drama";
        case Genre::Romance: return "Romance";
        case Genre::SciFi: return "SciFi";
        default: return "Unknown";
    }
}


void printSummary(const std::map<std::string, std::vector<int>>& ratings,
                  const std::map<std::string, Genre>& genres) {
    std::cout << "\nMovie Ratings Summary:\n";
    for (const auto& pair : ratings) {
        const std::string& title = pair.first;
        const std::vector<int>& list = pair.second;
        int count = list.size();
        int average = avg(list);
        std::string genreStr = genreToString(genres.at(title));

        std::cout << title << ": " << count
                  << " ratings, average rating " << average
                  << " stars, genre: " << genreStr << std::endl;
    }
}
