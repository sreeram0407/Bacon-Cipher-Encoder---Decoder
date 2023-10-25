/*
Author: Sreeram Kondapalli
Date: 10/20/2022
Description: 
Usage: <usage syntax>
*/
//required includes
#include <iostream>
#include <string.h>
#include <fstream>


using namespace std;
const char* englishToBaconCode(char);
char baconCodeToEnglish (const char*);
void baconize(const char*, const char*); //creating a function to baconize the input file
void englishize(const char*, const char*); //creating a function to englishize the input file

int main(int argc, char** argv){
    //declaring and opening the input output files
    ifstream input (argv[1]);
    ofstream output (argv[3]);
    if (argc == 4) {
        //using .fail incase invalid input file is asked to be found
        if (input.fail()){
           cout << "Input file does not exist" << endl;
        }
        else if (strcmp(argv[2], "-bc") == 0) {
            cout << "Translating " << argv[1] << " to BACON code" << endl;
            //calling the function baconize the input file
            baconize(argv[1],argv[3]);
            cout << argv[3] << " file completed." << endl;
        }
        else if(strcmp(argv[2], "-e") == 0) {
            cout << "Translating " << argv[1] << " to ENGLISH " << endl;
            //calling the function englishize the input file
            englishize(argv[1],argv[3]);
            cout << argv[3] << " file completed." << endl;
        }
        else{
            cout << "Error -- usage: <exe> <input file> <-bc|-e> <output file>\n" << endl;
        }
    }
    else{
        cout << "Error -- usage: <exe> <input file> <-bc|-e> <output file>\n" << endl;
    }

    return 0;
}
//baconize function
void baconize(const char* inputFile, const char* outputFile){
    ifstream input (inputFile);
    ofstream output (outputFile);
    //setting the char limit
    char sourceString[255];
    char *token;
    while (!input.eof()) {
        input.getline(sourceString, 255);
        token = strtok(sourceString, "\n"); //first read

        while (token != NULL) {
            //creating a for loop to go past every word and split it letter by letter
            for (int i = 0; i < strlen(token); i++) {
                output << englishToBaconCode(token[i]);
                if (i < (strlen(token) - 1))
                    //adding | after every word
                    output << "|";
            }
            token = strtok(NULL, "\n"); //keep tokenizing notice NULL
        }
        output << "\n";

    }
    //closing the files
    input.close();
    output.close();

}
//englishize function
void englishize(const char* inputFile, const char* outputFile){
    ifstream input(inputFile);
    ofstream output(outputFile);
    //setting the char limit
    char sourceString[1600];
    char sourceOutput[255];
    char* token;
    while (!input.eof()) {
        //creating a for loop to go past every word and split it letter by letter
        input.getline(sourceString, 1600);
        token = strtok(sourceString, "|"); //first read
        int i = 0;

        while (token != NULL) {
            //converting each token to english and storing it in the charecter array
            sourceOutput[i] = baconCodeToEnglish(token);
            token = strtok(NULL, "|"); //keep tokenizing notice NULL
            i++;
        }
        sourceOutput[i] = '\0';
        output << sourceOutput << "\n";

    }
    //closing the files
    input.close();
    output.close();

}
const char* englishToBaconCode(char val){
    switch (val) {
        case 'A':
        case 'a': return "aaaaa"; break;
        case 'B':
        case 'b': return "aaaab"; break;
        case 'C':
        case 'c': return "aaaba"; break;
        case 'D':
        case 'd': return "aaabb"; break;
        case 'E':
        case 'e': return "aabaa"; break;
        case 'F':
        case 'f': return "aabab"; break;
        case 'G':
        case 'g': return "aabba"; break;
        case 'H':
        case 'h': return "aabbb"; break;
        case 'I':
        case 'i': return "abaaa"; break;
        case 'J':
        case 'j': return "abaab"; break;
        case 'K':
        case 'k': return "ababa"; break;
        case 'L':
        case 'l': return "ababb"; break;
        case 'M':
        case 'm': return "abbaa"; break;
        case 'N':
        case 'n': return "abbab"; break;
        case 'O':
        case 'o': return "abbba"; break;
        case 'P':
        case 'p': return "abbbb"; break;
        case 'Q':
        case 'q': return "baaaa"; break;
        case 'R':
        case 'r': return "baaab"; break;
        case 'S':
        case 's': return "baaba"; break;
        case 'T':
        case 't': return "baabb"; break;
        case 'U':
        case 'u': return "babaa"; break;
        case 'V':
        case 'v': return "babab"; break;
        case 'W':
        case 'w': return "babba"; break;
        case 'X':
        case 'x': return "babbb"; break;
        case 'Y':
        case 'y': return "bbaaa"; break;
        case 'Z':
        case 'z': return "bbaab"; break;
        case ' ': return "/"; break;
        default: return "!!!!!"; break;


    }
}

char baconCodeToEnglish (const char* val){
    if(strcmp(val, "aaaaa") == 0)
        return 'A';
    else if(strcmp(val, "aaaab") == 0)
        return 'B';
    else if(strcmp(val, "aaaba") == 0)
        return 'C';
    else if(strcmp(val, "aaabb") == 0)
        return 'D';
    else if(strcmp(val, "aabaa") == 0)
        return 'E';
    else if(strcmp(val, "aabab") == 0)
        return 'F';
    else if(strcmp(val, "aabba") == 0)
        return 'G';
    else if(strcmp(val, "aabbb") == 0)
        return 'H';
    else if(strcmp(val, "abaaa") == 0)
        return 'I';
    else if(strcmp(val, "abaab") == 0)
        return 'J';
    else if(strcmp(val, "ababa") == 0)
        return 'K';
    else if(strcmp(val, "ababb") == 0)
        return 'L';
    else if(strcmp(val, "abbaa") == 0)
        return 'M';
    else if(strcmp(val, "abbab") == 0)
        return 'N';
    else if(strcmp(val, "abbba") == 0)
        return 'O';
    else if(strcmp(val, "abbbb") == 0)
        return 'P';
    else if(strcmp(val, "baaaa") == 0)
        return 'Q';
    else if(strcmp(val, "baaab") == 0)
        return 'R';
    else if(strcmp(val, "baaba") == 0)
        return 'S';
    else if(strcmp(val, "baabb") == 0)
        return 'T';
    else if(strcmp(val, "babaa") == 0)
        return 'U';
    else if(strcmp(val, "babab") == 0)
        return 'V';
    else if(strcmp(val, "babba") == 0)
        return 'W';
    else if(strcmp(val, "babbb") == 0)
        return 'X';
    else if(strcmp(val, "bbaaa") == 0)
        return 'Y';
    else if(strcmp(val, "bbaab") == 0)
        return 'Z';
    else if(strcmp(val, "!!!!!") == 0)
        return '#';
    else if(strcmp(val, "/") == 0)
        return ' ';
    else
        return '%';
}



