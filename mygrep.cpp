#include <iostream>
#include <string>
#include <fstream>


using namespace std;

int main(int argc, char *argv[]){

    if (argc < 3) {
        cerr << "Usage: " << argv[0] << " <pattern> <file | ->\n"
            << "  <pattern> : text to search for\n"
            << "  <file>    : path to input file";
        return (1);
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

