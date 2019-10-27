#include "moviesIndex.h"
#include "engine.h"
#include <tr1/unordered_map>
#include <fstream>
#include <vector>
#include "movies.h"
#include <unordered_set>

//Default constructor.
Engine::Engine() {

    //Get the stopwords from the file
    stopWords = buildStopWords();
}


//Receives a word and the containing file
void Engine::addToEngine(const string word, const string file) {

    //If the word is not a stop word or a "" string then add it to the engine
    if (stopWords.find(word) == stopWords.end() && !word.empty()) {
        if (find(word) != end()) //If the word is in the engine, then set the new file
            find(word)->second.add(file);

        else  //If not found, add the word to the engine with the current file
            insert(pair<string, MoviesIndex>(word, MoviesIndex(file)));
    }
}

//Receives a list of words to be searched
//list of Movies that are an intersection with the words

list<Movies> Engine::search(const vector<string>& words) {

    //Add the first for 1 word searches
    MoviesIndex intersection = find(words[0])->second;
    //If more than one word is being searched, calculate their intersections
    for (int i = 1; i < words.size(); i++)
        intersection = getIntersection(intersection.getReverseIndex(), find(words[i])->second.getReverseIndex());

    return intersection.toList();
}


//Builds stopWords list
std::unordered_set<string> Engine::buildStopWords() {

    ifstream stopFile("../stopwords.txt");
    std::unordered_set<string> stopWords;

    do {
        string parse;
        stopFile >> parse;
        stopWords.insert(parse);
    } while (!stopFile.eof());

    stopFile.close();

    //for (auto p: stopWords)
    //cout<< p <<endl;

    return stopWords;

}

