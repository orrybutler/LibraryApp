#ifndef bookHandling_H_
#define bookHandling_H_

#include <iostream>
#include <string>

using namespace std;

class Books {
    public:
        int ISBN;
        string language;
        string condition;
        Books();
        //void newISBN(int newISBN);
        //void newLanguage(string newLanguage);
        //void newCondition(string newCondition);
        void newBook(int newISBN, string newLanguage, string newCondition);
        int getISBN();
        string getLanguage();
        string getCondition();
        friend bool operator< (Books &book1, Books &book2);
        friend ostream & operator<<(ostream &out, Books &book);
        //bool operator== (Books &book1);
};
Books::Books() {
    ISBN = 0;
    language = "";
    condition = "";
}
void Books::newBook(int newISBN, string newLanguage, string newCondition){
    ISBN = newISBN;
    language = newLanguage;
    condition = newCondition;
}
int Books::getISBN(){
    return ISBN;
}
string Books::getLanguage(){
    return language;
}
string Books::getCondition(){
    return condition;
}
bool operator< (Books &book1, Books &book2){
    if (book1.ISBN < book2.ISBN){
        return true;
    }
    if (book1.ISBN == book2.ISBN){
        if (book1.condition == "new" && (book2.condition == "used" || book2.condition == "digital")){
            return true;
        }
        if (book1.condition == "used" && book2.condition == "digital"){
            return true;
        }
        if (book1.condition == "digital" && (book2.condition == "used" || book2.condition == "digital")) {
            return false;
        }
        if (book1.condition == "used" && book2.condition == "new"){
            return false;
        }
        if (book1.condition == book2.condition){
            if (book1.language <= book2.language){
                return true;
            }
            else{
                return false;
            }
        }
    }
    if (book1.ISBN > book2.ISBN){
        return false;
    }
    if(book1.ISBN == book2.ISBN && book1.language == book2.language && book1.condition == book2.condition){
        return false;
    }

}
ostream & operator<<(ostream &out, Books &book){
    out << book.ISBN << ", " << book.condition << ", " << book.language << endl;
    return out;
}


#endif // bookHandling_H_
