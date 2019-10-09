#ifndef _functions_h
#define _functions_h

#include <locale>
#include "engine.h"
#include <vector>
#include <tr1/unordered_map>
#include "moviesIndex.h"
//#include <ctime>

using namespace std;


//Remove possesives, uppercases, non-alpha chars
string sanitize(string& word) {
    locale filter;
    for (int k = 0; k < word.length(); k++) {
        word[k] = tolower(word[k], filter);
        if(!isalpha(word[k], filter)) {
            if(word[k] == '\'') word.erase(k);
            else word.erase(k--,1);
        }
    }
    return word;
}

//Receives a list of words to be searched
//returns the ones thta can be searched
vector<string> getSearchableWords(vector<string> words, const Engine& engine) {
    for (int i = 0; i < words.size(); i++)
        if (engine.find(words[i]) == engine.end())
            words.erase(words.begin() + i--);
    return words;
}


#endif
