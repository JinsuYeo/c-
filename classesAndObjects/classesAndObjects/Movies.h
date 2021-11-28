//
//  Movies.h
//  classesAndObjects
//
//  Created by 여진수 on 2021/11/26.
//

#ifndef _MOVIES_H_
#define _MOVIES_H_

#include <string>
#include <stdbool.h>
#include <vector>
#include "Movie.h"


class Movies {
private:
    std::vector<Movie> movies;
public:
    Movies();
    ~Movies();
    
    bool add_movie(std::string name, std::string rating, int watched);
    bool increment_watched(std::string name);
    
    void display() const;
};

#endif /* Movies_h */
