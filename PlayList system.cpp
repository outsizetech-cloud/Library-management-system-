#include <iostream>
#include <cstring>
using namespace std;

struct Track {
    int id;
    char title[50];
    char artist[50];
    int duration;
    Track* prev;
    Track* next;
};

Track* start = NULL;
Track* current = NULL;

void addTrack() {
    Track* newNode = new Track;

    newNode->id = 56;
    strcpy(newNode->title, "70");
    strcpy(newNode->artist, "68");
    newNode->duration = 200;

    newNode->next = NULL;
    newNode->prev = NULL;

    if (start == NULL) {
        start = newNode;
        current = newNode;
        cout << "Song inserted.\n";
        return;
    }

    Track* temp = start;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    cout << "Song inserted.\n";
}

Track* findTrack() {
    if (start == NULL) {
        cout << "Playlist is empty.\n";
        return NULL;
    }

    char key[50];
    cout << "Enter Title or Artist to search: ";
    cin.ignore();
    cin.getline(key, 50);

    Track* temp = start;

    while (temp != NULL) {
        if (strcmp(temp->title, key) == 0 || strcmp(temp->artist, key) == 0)
            return temp;
        temp = temp->next;
    }

    return NULL;
}

void updateTrack() {
    Track* s = findTrack();
    if (s == NULL) {
        cout << "Song not found.\n";
        return;
    }

    cout << "Enter new Artist: ";
    cin.ignore();
    cin.getline(s->artist, 50);

    cout << "Enter new Duration: ";
    cin >> s->duration;

    cout << "Song updated successfully.\n";
}

void showPlaylist() {
    if (start == NULL) {
        cout << "Playlist is empty.\n";
        return;
    }

    Track* temp = start;
    int count = 0;

    cout << "\n--- Playlist ---\n";

    while (temp != NULL) {
        cout << "ID: " << temp->id
             << " | Title: " << temp->title
             << " | Artist: " << temp->artist
             << " | Duration: " << temp->duration << " sec\n";

        count++;
        temp = temp->next;
    }

    cout << "Total songs: " << count << "\n";
}

void playNext() {
    if (current == NULL) {
        cout << "No song.\n";
        return;
    }

    if (current->next == NULL) {
        cout << "No next song.\n";
        return;
    }

    current = current->next;
    cout << "Now playing: " << current->title << " by " << current->artist << "\n";
}

void playPrevious() {
    if (current == NULL) {
        cout << "No song.\n";
        return;
    }

    if (current->prev == NULL) {
        cout << "No previous song.\n";
        return;
    }

    current = current->prev;
    cout << "Now playing: " << current->title << " by " << current->artist << "\n";
}

int main() {
    int choice;

    do {
        cout << "\n1. Insert Song\n2. Search Song\n3. Modify Song\n4. Display Playlist\n5. Play Next\n6. Play Previous\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addTrack(); break;
            case 2: {
                Track* s = findTrack();
                if (s != NULL)
                    cout << "Found: " << s->title << " by " << s->artist << "\n";
                else
                    cout << "Song not found.\n";
                break;
            }
            case 3: updateTrack(); break;
            case 4: showPlaylist(); break;
            case 5: playNext(); break;
            case 6: playPrevious(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n"; break;
        }

    } while (choice != 0);

    return 0;
}