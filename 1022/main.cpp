#include <iostream>
#include <vector>
#include <map>
#include <stdio.h>
#include <string>
#include <set>
#include <string.h>
#include <fstream>

using namespace std;

struct Book {
    string id;
    string title;
    string author;
    vector<string> keywords;
    string publisher;
    string pubyear;
};

int main() {
    ifstream in("in.txt");
    cin.rdbuf(in.rdbuf());
    int n;
    cin >> n;
    cin.ignore();
    //vector<Book> library;
    map< string, set<string> > bookMap[5];
    for (int i = 0; i < n; ++i) {
        Book book;
        getline(cin, book.id);
        getline(cin, book.title);
        getline(cin, book.author);
        string keyword;
        while(cin>>keyword) {
            book.keywords.push_back(keyword);
            if (cin.get() == '\n') { break; }
        }
        getline(cin, book.publisher);
        getline(cin, book.pubyear);
         bookMap[0][book.title].insert(book.id);
        bookMap[1][book.author].insert(book.id);
        for (vector<string>::iterator kit = book.keywords.begin();
             kit != book.keywords.end(); ++kit) {
            bookMap[2][*kit].insert(book.id);
        }
        bookMap[3][book.publisher].insert(book.id);
        bookMap[4][book.pubyear].insert(book.id);
        //library.push_back(book);
    }

//    for (int i = 0; i < n; ++i) {
//        cout << library[i].id << endl;
//        cout << library[i].title << endl;
//        cout << library[i].author << endl;
//        for (vector<string>::iterator it = library[i].keywords.begin();
//            it != library[i].keywords.end(); ++it) {
//            cout << *it << " ";
//        }
//        cout << endl;
//        cout << library[i].publisher << endl;
//        cout << library[i].pubyear << endl;
//    }
//    map< string, set<string> > bookMap[5];
//    for (vector<Book>::iterator it = library.begin(); it != library.end(); ++it) {
//        bookMap[0][(*it).title].insert((*it).id);
//        bookMap[1][(*it).author].insert((*it).id);
//        for (vector<string>::iterator kit = (*it).keywords.begin();
//             kit != (*it).keywords.end(); ++kit) {
//            bookMap[2][*kit].insert((*it).id);
//        }
//        bookMap[3][(*it).publisher].insert((*it).id);
//        bookMap[4][(*it).pubyear].insert((*it).id);
//    }

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int no;
        string query;
        cin >> no;
        cin.get();
        cin.get();
        getline(cin, query);
        cout << no << ": " << query << endl;
        no = no - 1;
        if (bookMap[no].count(query)) {
            for (set<string>::iterator it = bookMap[no][query].begin();
                 it != bookMap[no][query].end(); ++it) {
                 cout << *it << endl;
            }
        } else {
            cout << "Not Found" << endl;
        }
    }
    return 0;
}
