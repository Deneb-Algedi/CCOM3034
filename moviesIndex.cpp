#include "moviesIndex.h"
#include <string>
#include <tr1/unordered_map>
#include "movies.h"

using namespace std;

//Constructor
MoviesIndex::MoviesIndex() {

    totalRepetitions = 0;

}

//Default constructor
MoviesIndex::MoviesIndex(const string movies) {

    totalRepetitions = 1;
    reverseIndex[movies] = 1;

}

//Get the movies map
tr1::unordered_map<string, int> MoviesIndex::getReverseIndex() const {

    return reverseIndex;

}

//Get total repetitions of a word
int MoviesIndex::getTotalRepetitions() const {

    return totalRepetitions;

}

//Add a new movie to the movies collection
void MoviesIndex::add(const string moviesTitle) {

    totalRepetitions++;
    reverseIndex[moviesTitle] += 1;

}

//Add a new movie with an actual value of repetitions
void MoviesIndex::add(const string moviesTitle, const int total) {

    totalRepetitions += total;
    reverseIndex[moviesTitle] = total;

}

//Calculate the intersections between two words
MoviesIndex getIntersection(tr1::unordered_map<string, int> moviesindex1, tr1::unordered_map<string, int> moviesindex2) {

    MoviesIndex intersection;

    tr1::unordered_map<string, int>::iterator mapIndex;

    for (mapIndex = moviesindex1.begin(); mapIndex != moviesindex1.end(); mapIndex++)
        if(moviesindex2.find(mapIndex->first) != moviesindex2.end())
            //If a movie is a match, then add their values
            intersection.add(mapIndex->first, mapIndex->second + moviesindex2[mapIndex->first]);

    return intersection;
}

//Build a list of the results
list<Movies> MoviesIndex::toList() {

    list<Movies> movies;

    for (tr1::unordered_map<string, int>::iterator mapIndex = reverseIndex.begin(); mapIndex != reverseIndex.end(); mapIndex++)
        movies.push_back(Movies(mapIndex->first, mapIndex->second));

    movies.sort(moviesSort); //Reverse sort it

    return movies;
}



