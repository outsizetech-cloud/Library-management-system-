#include <iostream>
#include <string>
using namespace std;

struct BookNode {
    string isbn;
    string title;
    string author;
    int year;
    BookNode* prev;
    BookNode* next;
};

BookNode* start = NULL;

void insertBook() {
    BookNode* newNode = new BookNode;

    newNode->isbn = "56";
    newNode->title = "70";
    newNode->author = "68";
    newNode->year = 2023;

    newNode->next = NULL;
    newNode->prev = NULL;

    if (start == NULL) {
        start = newNode;
        cout << "Book inserted.\n";
        return;
    }

    BookNode* temp = start;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    cout << "Book inserted.\n";
}

BookNode* searchBook() {
    if (start == NULL) {
        cout << "Library is empty.\n";
        return NULL;
    }

    string key;
    cout << "Enter ISBN or Title to search: ";
    cin.ignore();
    getline(cin, key);

    BookNode* temp = start;
    while (temp != NULL) {
        if (temp->isbn == key || temp->title == key)
            return temp;
        temp = temp->next;
    }

    return NULL;
}

void modifyBook() {
    BookNode* book = searchBook();
    if (book == NULL) {
        cout << "Book not found.\n";
        return;
    }

    cout << "Enter new Author: ";
    getline(cin, book->author);

    cout << "Enter new Year: ";
    cin >> book->year;

    cout << "Book updated successfully.\n";
}

void displayBooks() {
    if (start == NULL) {
        cout << "Library is empty.\n";
        return;
    }

    BookNode* temp = start;
    int count = 0;
    cout << "\n--- Library Books ---\n";
    while (temp != NULL) {
        cout << "ISBN: " << temp->isbn
             << " | Title: " << temp->title
             << " | Author: " << temp->author
             << " | Year: " << temp->year << "\n";
        count++;
        temp = temp->next;
    }
    cout << "Total books: " << count << "\n";
}

int main() {
    int choice;

    do {
        cout << "\n1. Insert Book\n2. Search Book\n3. Modify Book\n4. Display Books\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: insertBook(); break;
            case 2: {
                BookNode* b = searchBook();
                if (b == NULL)
                    cout << "Book not found.\n";
                else
                    cout << "Found: " << b->title << " by " << b->author << "\n";
                break;
            }
            case 3: modifyBook(); break;
            case 4: displayBooks(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n"; break;
        }

    } while (choice != 0);

    return 0;
}