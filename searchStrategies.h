#ifndef searchStrategies_H_
#define searchStrategies_H_

#include "bookHandling.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void linearSearch(vector<Books> books, vector<Books> requests, ofstream &outFile) {
    int count = 0;
    for (int j =0; j < requests.size(); j++){
        for (int i = 0; i < books.size(); i++){
            if(books.at(i).getISBN() == requests.at(j).getISBN() && 
            books.at(i).getCondition() == requests.at(j).getCondition() && 
            books.at(i).getLanguage() == requests.at(j).getLanguage()){
                count = count + 1;
                outFile << books.at(i);
            }
        }
    }
}
void binarySearch(vector<Books> books, vector<Books> requests, 
ofstream &outFile, int low, int high){
    sort(books.begin(), books.end());
    for(int i = 0; i < books.size(); i++){
        cout << books.at(i) << endl;
    }
    int count = 0;
    for (int j = 0; j < requests.size(); j++){
        int left = low;
        int right = high;
        while (left < right){
            int m = (left + right)/2;
            if(books.at(m) < requests.at(j))
            {
                left = m + 1;
            }if(requests.at(j) < books.at(m)) {
                right = m;
            }if(books.at(left).getISBN() == requests.at(j).getISBN() && 
            books.at(left).getCondition() == requests.at(j).getCondition() && 
            books.at(left).getLanguage() == requests.at(j).getLanguage()){
                count = count + 1;
                outFile << books.at(left);
            }

        }
    }
}


#endif // searchStrategies_H_