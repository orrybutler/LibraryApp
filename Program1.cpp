#include "bookHandling.h"
#include "searchStrategies.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <string>


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
    
    if (argc != 4){
        cerr << "./Program1 <newBooks.dat> <request.dat> <results.dat>";
        return 0;
    }

    vector<Books> newBooks;
    vector<Books> requests;
    string newBooksFile = argv[1];
    string requestFile = argv[2];
    string resultsFile = argv[3];

    ifstream inFile1;
    ifstream inFile2;
    ofstream outFile;

    inFile1.open(newBooksFile);
    inFile2.open(requestFile);
    outFile.open(resultsFile);

    if (!inFile1) {
        cerr << "Books file unable to open";
        exit(1);
    }

    if (!inFile2) {
        cerr << "Request file unable to open";
        exit(1);
    }

    newBooks = readFromFile(newBooks, inFile1);
    for(int i = 0; i < newBooks.size(); i++){
        cout << newBooks.at(i) << endl;
    }
    requests = readFromFile(requests, inFile2);
    for(int j = 0; j < requests.size(); j++){
        cout <<requests.at(j) << endl;
    }

    char choice;

    cerr << "Choice of search method ([l]inear,[b]inary,[r]ecursiveBinary)" << endl;

    cin >> choice;

    while (choice != 'l' && choice != 'b' && choice != 'r'){
        cerr << "Incorrect choice" << endl;
        cin >> choice;
    }

    if (choice == 'l'){
        linearSearch(newBooks, requests, outFile);
    }if(choice == 'b'){
        sort(newBooks.begin(), newBooks.end());
        for(int i = 0; i < newBooks.size(); i++){
            cout << newBooks.at(i) << endl;
        }
    }if(choice == 'r'){

    }
    return 0;
}  