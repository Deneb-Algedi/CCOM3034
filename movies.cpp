#include "movies.h"
#include <string>

using namespace std;

//Default constructor
Movies::Movies(const string t) {

    Title = t;
    repetitions = 1;

}

//Constructor with setter
Movies::Movies(const string t, const int rep) {

    Title = t;
    repetitions = rep;

}

//Increase total repetitions
void Movies::increase() {

    repetitions++;

}

//Get total repetitions
int Movies::getRepetitions() const {

    return repetitions;

}

//Get the movie title
string Movies::getTitle() const {

    return Title;

}

//Compares relevance of movies
bool moviesSort(const Movies& movies1, const Movies& movies2) {

    return movies1.getRepetitions() > movies2.getRepetitions();

}
