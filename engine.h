#ifndef ____Engine__
#define ____Engine__

#include <iostream>
#include <unordered_set>
#include "moviesIndex.h"
#include <string>
#include <vector>
#include "movies.h"


//Its key is a word that could be searched and value is a MoviesIndex of that word per file


class Engine: public tr1::unordered_map<string, MoviesIndex> {

private:
    std::unordered_set<string> stopWords; // Engine must keep track of trivial words


public:
    //Constructor
    Engine();

    //Methods

    // Word and its containing file to be added to the engine
    void addToEngine(const string word, const string file);

    // Perform a search and obtain a list of top results
    list<Movies> search(const vector<string>& words);

    // Read the stop words list
    std::unordered_set<string> buildStopWords();

};


#endif /* defined(____Engine__) */
