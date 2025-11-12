 #include <iostream>
#include <string>
using namespace std;

class MusicRecords {
public:
    string artistName;
    string genre;
    string songTitle;
    int year;
    float duration;

    void input() {
        cout << "\nEnter artist name  : ";
        getline(cin, artistName);

        cout << "Enter genre        : ";
        getline(cin, genre);

        cout << "Enter song title   : ";
        getline(cin, songTitle);

        cout << "Enter year of song : ";
        cin >> year;

        cout << "Enter duration (m) : ";
        cin >> duration;
    }

    void display() {
        cout << "\n---- Music Record ----\n";
        cout << "Artist   : " << artistName << '\n';
        cout << "Genre    : " << genre << '\n';
        cout << "Song     : " << songTitle << '\n';
        cout << "Year     : " << year << '\n';
        cout << "Duration : " << duration << " minutes\n";
    }
};

int main() {
    MusicRecords record;
    bool hasRecord = false;
    int choice;

    do {
        cout << "\n---MUSIC MENU ---\n";
        cout << "1. Add Record\n";
        cout << "2. Show Record\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                record.input();
                hasRecord = true;
                cout << "Record saved!\n";
                break;

            case 2:
                if (hasRecord) {
                    record.display();
                } else {
                    cout << "No record found.\n";
                }
                break;

            case 3:
                cout << "Exit \n";
                break;

            default:
                cout << "Invalid choice \n";
        }
    } while (choice != 3);

    return 0;
}
