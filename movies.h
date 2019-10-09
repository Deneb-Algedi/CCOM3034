#ifndef ____Movies__
#define ____Movies__

#include <iostream>
#include <string>


//keeps the title of a movie and the repetition of a certain word

using namespace std;


class Movies {

private:
    string Title; //movie Title
    int repetitions; //total ocurrences of a word in the movie

public:
    //Default constructor
    Movies(const string);

    //Constructor passing repetitions values
    Movies(const string, const int);

    //Method
    void increase();

    //getters
    int getRepetitions() const;

    string getTitle() const;
};

//Helper function for comparisions of movies
bool moviesSort(const Movies& movies1, const Movies& movies2);

#endif /* defined(____Movies__) */
