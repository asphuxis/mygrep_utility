#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void noarg(){ // Funktio, jolla tehdään merkkijonon haku käyttäjän syötteestä

    string line;
    while (line.empty()) { // Looppi, jota toistetaan kunnes jokin tekstilähde syötetään
        cout << "Give string from which to search for: ";
        getline(cin, line);
        if (line.empty()==true)
        {
            cout << "You entered nothing. Please enter your query string or exit by pressing CTRL+C" << endl;
        } 
    }
    
    string pattern;
    while (pattern.empty()) { // Looppi, jota toistetaan kunnes haettava merkkijono syötetään
        cout << "Give search string: ";
        getline(cin, pattern);
        if (pattern.empty()==true)
        {
            cout << "You entered nothing. Please enter your search string or exit by pressing CTRL+C" << endl;
        }
    }

    if (line.find(pattern) != string::npos) { // if-lause, jolla määritetään löytyykö merkkijono tekstilähteestä.
        cout <<"\"" << pattern << "\" found in \"" << line <<"\"" << " at position " << line.find(pattern);
    } else {
        cout << "\"" <<  pattern << "\" NOT found in \"" << line << "\"";
    }
    
}

void arg(string v_pattern, string v_filename){ // Funktio, jolla tehdään merkkijonon haku mikäli lähteenä on tiedosto

    string line;

    ifstream file; // avattaan tiedosto
    file.open(v_filename); // Tarkistetaan onko tiedosto auki
    if (!file) {
        cerr << "Error - Could not open file: " << v_filename;
    } else if (v_pattern.empty()) { // Tarkistetaan onko haettava merkkijono tyhjä
        cerr << "Error - Empty pattern";
    } else {
        istream* in = &file;

        int matchCount = 0; 
        while (getline(*in, line)) {
            if (line.find(v_pattern) != string::npos) {
                std::cout << line << '\n';
                matchCount++;
            }
        }

        if (matchCount == 0) {
            cout << "\"" << v_pattern << "\" was NOT found in \"" << v_filename << "\"";
        }
    }
}

int main(int argc, char *argv[]){ // Pääfunktio 

    switch (argc) { // Switch-lause, jolla määritetään mikä aliohjelista haetaan ja millä ohjelma terminoidaan huonon promptin sattuessa
    case 1:
    {
        noarg();
        return(0);
    }   
    case 3:
    {
        arg(argv[1], argv[2]);
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
