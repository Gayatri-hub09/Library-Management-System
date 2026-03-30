#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// -------------------- MODEL --------------------
class Book {
public:
    int id;
    string title;
    string author;
    bool isIssued;

    Book(int i, string t, string a, bool issued = false) {
        id = i;
        title = t;
        author = a;
        isIssued = issued;
    }

    string toFile() {
        return to_string(id) + "|" + title + "|" + author + "|" + (isIssued ? "1" : "0");
    }
};

// -------------------- FILE HANDLING --------------------
vector<Book> loadBooks() {
    vector<Book> books;
    ifstream file("books.txt");
    string line;

    while (getline(file, line)) {
        int p1 = line.find("|");
        int p2 = line.find("|", p1 + 1);
        int p3 = line.find("|", p2 + 1);

        int id = stoi(line.substr(0, p1));
        string title = line.substr(p1 + 1, p2 - p1 - 1);
        string author = line.substr(p2 + 1, p3 - p2 - 1);
        bool issued = line.substr(p3 + 1) == "1";

        books.push_back(Book(id, title, author, issued));
    }
    return books;
}

void saveBooks(vector<Book>& books) {
    ofstream file("books.txt");
    for (auto &b : books) {
        file << b.toFile() << endl;
    }
}

// -------------------- FEATURES --------------------
void addBook(vector<Book>& books) {
    int id;
    string title, author;

    cout << "Enter ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter Title: ";
    getline(cin, title);

    cout << "Enter Author: ";
    getline(cin, author);

    books.push_back(Book(id, title, author));
    saveBooks(books);

    cout << "✅ Book Added!\n";
}

void viewBooks(vector<Book>& books) {
    if (books.empty()) {
        cout << "No books available\n";
        return;
    }

    for (auto &b : books) {
        cout << b.id << " | " << b.title << " | " << b.author
             << " | " << (b.isIssued ? "Issued" : "Available") << endl;
    }
}

void searchBook(vector<Book>& books) {
    string title;
    cin.ignore();
    cout << "Enter title: ";
    getline(cin, title);

    for (auto &b : books) {
        if (b.title == title) {
            cout << "Found: " << b.id << " | " << b.author << endl;
            return;
        }
    }
    cout << "❌ Not Found\n";
}

void issueBook(vector<Book>& books) {
    int id;
    cout << "Enter ID: ";
    cin >> id;

    for (auto &b : books) {
        if (b.id == id && !b.isIssued) {
            b.isIssued = true;
            saveBooks(books);
            cout << "📕 Book Issued\n";
            return;
        }
    }
    cout << "❌ Not Available\n";
}

void returnBook(vector<Book>& books) {
    int id;
    cout << "Enter ID: ";
    cin >> id;

    for (auto &b : books) {
        if (b.id == id && b.isIssued) {
            b.isIssued = false;
            saveBooks(books);
            cout << "📗 Book Returned\n";
            return;
        }
    }
    cout << "❌ Invalid ID\n";
}

// -------------------- MAIN --------------------
int main() {
    vector<Book> books = loadBooks();
    int choice;

    do {
        cout << "\n--- Library System ---\n";
        cout << "1. Add Book\n";
        cout << "2. View Books\n";
        cout << "3. Search Book\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addBook(books); break;
            case 2: viewBooks(books); break;
            case 3: searchBook(books); break;
            case 4: issueBook(books); break;
            case 5: returnBook(books); break;
        }
    } while (choice != 0);

    return 0;
}