#include "BookHandling.h"
#include "SearchStrategies.h"
#include "TimeHandling.h"

using namespace std;

vector<Books> readFromFile(vector<Books> books, ifstream &inFile) {

    string info1;
    string info2;
    string info3;

    while (!inFile.eof()){
        if(inFile.eof()){
            exit(1);
        }
        Books book;
        getline(inFile, info1, ',');
        if (info1 == ""){
            return books;
        }
        getline(inFile, info2 , ',');
        getline(inFile, info3);
        book.newBook(stoi(info1), info2, info3);
        books.push_back(book);
    }
    return books;
}

int main (int argc, char *argv[]) {
    
    if (argc != 3 && argc != 4){
        cerr << "Usage: ./SearchNewBooks <newBooks.dat> <request.dat> <results.dat>";
        return 0;
    }

    vector<Books> newBooks;
    vector<Books> requests;
    string newBooksFile = argv[1];
    string requestFile = argv[2];
    string resultsFile;

    ifstream inFile1;
    ifstream inFile2;
    ofstream outFile;

    Timer ct;

    if (argc == 3) {
        resultsFile = "found.dat";
        cout << resultsFile << endl;
    }else {
        resultsFile == argv[3];
    }

    inFile1.open(newBooksFile);
    inFile2.open(requestFile);
    outFile.open(resultsFile);

    if (!inFile1) {
        cerr << "Error: Cannot open file " << newBooksFile << endl;
        exit(1);
    }

    if (!inFile2) {
        cerr << "Error: Cannot open file " << requestFile << endl;
        exit(1);
    }
    
    if (!outFile) {
        cerr << "Error: Cannot open file " << resultsFile << endl;
        exit(1);
    }
    

    newBooks = readFromFile(newBooks, inFile1);
    requests = readFromFile(requests, inFile2);

    char choice;

    cerr << "Choice of search method ([l]inear,[b]inary,[r]ecursiveBinary)?" << endl;

    cin >> choice;

    while (choice != 'l' && choice != 'b' && choice != 'r'){
        cerr << "Incorrect choice" << endl;
        cin >> choice;
    }

    ct.Reset();

    if (choice == 'l'){
        linearSearch(newBooks, requests, outFile);
    }if(choice == 'b'){
        binarySearch(newBooks, requests, outFile, 0, newBooks.size());
    }if(choice == 'r'){
        sort(newBooks.begin(), newBooks.end());
        int count = 0;
        for (int i = 0; i < newBooks.size(); i++) {
            if ( recursiveBinarySearch(newBooks, requests.at(i), outFile, 0, newBooks.size() - 1) == 1) {
                count = count + 1;
            }
        }
        outFile << count << endl;
        cerr << count << endl;
    }

    ct.CurrentTime();
    cerr << ct << endl;
    return 0;
}  