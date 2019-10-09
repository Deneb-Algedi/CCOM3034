#ifndef ____MoviesIndex__
#define ____MoviesIndex__

#include <iostream>
#include <string>
#include <tr1/unordered_map>
#include <list>
#include "movies.h"

using namespace std;

//keeps a history of the files in which a word appears.
//And there is a total of occurences per file which is also stored


class MoviesIndex {

private:
    int totalRepetitions;
    tr1::unordered_map<string, int> reverseIndex;

public:
    //Constructor
    MoviesIndex();

    //Default constructor
    MoviesIndex(const string);


    //Methods
    void add(const string);
    void add(const string, const int);

    //Getters
    int getTotalRepetitions() const;

    tr1::unordered_map<string, int> getReverseIndex() const;

    list<Movies> toList();

};

//Helper functions
MoviesIndex getIntersection(tr1::unordered_map<string, int> , tr1::unordered_map<string, int>);

MoviesIndex getUnion(tr1::unordered_map<string, int> , tr1::unordered_map<string, int>);


#endif /* defined(____MoviesIndex__) */
