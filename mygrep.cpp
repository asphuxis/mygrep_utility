#include <iostream>
#include <string>
#include <fstream>


using namespace std;

void noarg(){

    string line;
    cout << "Enter string from which to search for: ";
    cin >> line;
    
    string pattern;
    cout << "Enter search string: ";
    cin >> pattern;

    if (line.find(pattern) != std::string::npos) {
        cout << pattern << " found in " << line;
    } else {
        cout << pattern << " NOT found in " << line;
    }
    
}

int main(int argc, char *argv[]){

    if (argc < 3) {
        noarg();
        return(0);
    }
    
    string pattern = argv[1]; // Haluttu teksti tai merkki jota haetaan
    string fileLocation = argv[2]; // Tiedosto tai sijainti jota luetaan
    string line;

    ifstream file;
    file.open(fileLocation);
    istream* in = &file;

    int matchCount;

    while (getline(*in, line))
    {
        
        if (line.find(pattern) != string::npos) {
            std::cout << line << '\n';
            matchCount++;
        }
        
    }

    if (matchCount == 0)
    {
        cout << pattern << " was NOT found in " << fileLocation;
    }
    
    return(0);
    
}
