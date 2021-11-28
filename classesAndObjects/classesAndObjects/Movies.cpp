//
//  Movies.cpp
//  classesAndObjects
//
//  Created by 여진수 on 2021/11/26.
//

#include <iostream>
#include "Movies.h"
#include "Movie.h"

Movies::Movies(){
}

Movies::~Movies(){
}

bool Movies::add_movie(std::string name, std::string rating, int watched){
    for(const auto &movie: movies) {
        if(movie.get_name() == name) {
            return false;
        }
    }
    Movies::movies.push_back(Movie {name, rating, watched});
    return true;
}

bool Movies::increment_watched(std::string name){
    for(auto &movie: movies) {
        if(movie.get_name() == name) {
            movie.increment_watched();
            return true;
        }
    }
    return false;
}

void Movies::display() const{
    if(movies.size() == 0) {
        std::cout << "Sorry, no movies to display\n";
    } else {
        for(const auto &movie: Movies::movies) {
            movie.display();
        }
    }
}
