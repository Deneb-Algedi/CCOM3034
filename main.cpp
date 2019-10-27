#include "parsedfile.h"
#include <iostream>
#include <tr1/unordered_map>
#include "moviesIndex.h"
#include <vector>
#include <string>
#include <list>
#include "movies.h"
#include "functions.h"
#include "engine.h"
//#include <ctime>


using namespace std;



int main() {

    cout << "Hello, friend. I'm reading your files now!" << endl;
    string dir = string("../moviesdb/");
    vector<string> files = vector<string>();
    getdir(dir,files);

    cout << "I'm working on it! And..." << endl;
    
    Engine engine;


    for (int i = 0; i < files.size(); i++) {
        if (files[i].c_str()[0]!='.') {
            vector<string> words = ParsedFile(dir + files[i]).readAndTokenize(); //Get all words
            for (int j = 0; j < words.size(); j++)
                engine.addToEngine(sanitize(words[j]), files[i]); //Removes capital letters, an non alpha chars
        }
    }


    cout << "Done!";
    files.clear(); //Clean up memory


    //Start asking for words to search for.
    string parse; //Input parser.

    do {
        cout << endl;
        cout << "Enter words to search for or type 0 to exit." << endl;
        cout << "Search for: ";
        getline(cin, parse);

        if(parse == "0")
            break; //Exit the program

        //Tokenize returns vector of words, then remove those that are not in engine
        vector<string> words = getSearchableWords(tokenize(parse, " "), engine);

        cout<<endl<<"Search Results:"<<endl;
        int counter = 0;

        if (words.size() > 0) {

            list<Movies> topHits = engine.search(words); //Get a sorted intersection of all searchable words.

            for (list<Movies>::iterator index = topHits.begin(); index != topHits.end(); index++) {

                // Print name of files/movies and its repetitions
                cout<<++counter << ". "<< index->getTitle() << " - " << index->getRepetitions()<<endl;
                if (counter == 3)
                    break; // Show only the top 3 movies
            }
            cout<<endl;
        }


        if(counter < 3)
            cout<<"Unfortunately, we couldn't find more results..."<<endl; //Error message if less than 3 results


   //Perform another search if 0 wasnt entered
    } while (true) ;

    //Exit message
    cout << endl;
    cout << "Hope you found what you were looking for!" <<endl;
    
    return 0;
}
