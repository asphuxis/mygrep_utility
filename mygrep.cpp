#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void noarg(){

    string line;
    while (line.empty()) {
        cout << "Give string from which to search for: ";
        getline(cin, line);
        if (line.empty()==true)
        {
            cout << "You entered nothing. Please enter your query string or exit by pressing CTRL+C" << endl;
        } 
    }
    
    string pattern;
    while (pattern.empty()) {
        cout << "Give search string: ";
        getline(cin, pattern);
        if (pattern.empty()==true)
        {
            cout << "You entered nothing. Please enter your search string or exit by pressing CTRL+C" << endl;
        }
    }

    if (line.find(pattern) != string::npos) {
        cout << pattern << " found in " << line << " at position " << line.find(pattern);
    } else {
        cout << pattern << " NOT found in " << line;
    }
    
}

int main(int argc, char *argv[]){

    switch (argc) {
    case 1:
    {
        noarg();
        return(0);
    }   
    case 3:
    {
        string pattern = argv[1]; // Haluttu teksti tai merkki jota haetaan
        string fileLocation = argv[2]; // Tiedosto tai sijainti jota luetaan
        string line;

        ifstream file;
        file.open(fileLocation);
        istream* in = &file;

        int matchCount = 0;
        while (getline(*in, line)) {
            if (line.find(pattern) != string::npos) {
                std::cout << line << '\n';
                matchCount++;
            }
        }

        if (matchCount == 0) {
            cout << pattern << " was NOT found in " << fileLocation;
        }

        return(0);
    }
    default:
    {
        cerr << "Incorrect usage - either input no arguments or input two [2] arguments.";
        return(1);
    }
    
    }
    
    return(0);
    
}
