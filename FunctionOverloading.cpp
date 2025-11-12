#include <iostream>
#include <string>
using namespace std;

class MusicRecord 
{
public:
    string artistNames[10];
    string artistGenres[10];
    string labelNames[10];
    int labelYears[10];
    int Count;

    MusicRecord() 
    {
        Count = 0;
    }

    //1. Full Details
    void addArtist_Label(string name, string genre, string title, int year)
    {
        if (Count < 10)
        {
            artistNames[Count] = name;
            artistGenres[Count] = genre;
            labelNames[Count] = title;
            labelYears[Count] = year;
            Count++;
        } 
        else 
        {
            cout << "List is full \n";
        }
    }

    //2. Only Artist and Genre
    void addArtist_Label(string name, string genre)
    {
        if (Count < 10)
        {
            artistNames[Count] = name;
            artistGenres[Count] = genre;
            labelNames[Count] = "Unknown";
            labelYears[Count] = 0;
            Count++;
        } 
        else 
        {
            cout << "List is full \n";
        }
    }

    //3. Only Artist Name
    void addArtist_Label(string name)
    {
        if (Count < 10)
        {
            artistNames[Count] = name;
            artistGenres[Count] = "Unknown";
            labelNames[Count] = "Unknown";
            labelYears[Count] = 0;
            Count++;
        } 
        else 
        {
            cout << "List is full \n";
        }
    }

    void showRecords()
    {
        cout << "\n--- Artist and Label Details ---\n";

        if (Count == 0)
        {
            cout << "No records to display \n";
            return;
        }

        for (int i = 0; i < Count; i++) 
        {
            cout << i+1 << ". " 
                 << artistNames[i] << " (" << artistGenres[i] << ") - "
                 << labelNames[i] << " [Founded: " << labelYears[i] << "]\n";
        }
    }

    //Searching Artist
    void searchArtist(string name)
    {
        bool found = false;
        for (int i = 0; i < Count; i++) 
        {
            if (artistNames[i] == name) 
            {
                cout << "\nFound: " << artistNames[i] << " (" << artistGenres[i] 
                     << ") - " << labelNames[i] << " [Founded: " << labelYears[i] << "]\n";
                found = true;
                break;
            }
        }
        if (!found) cout << "\nArtist not found \n";
    }
};

int main() 
{
    MusicRecord record;
    int choice;

    do 
    {
        cout << "\n MUSIC RECORD MENU \n";
        cout << "1. Add Artist (Full Details)\n";
        cout << "2. Add Artist (Name and Genre)\n";
        cout << "3. Add Artist (Name Only)\n";
        cout << "4. Show All Records\n";
        cout << "5. Search Artist\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) 
        {
            case 1: 
            {
                string name, genre, title;
                int year;
                cout << "Enter artist name: ";
                getline(cin, name);
                cout << "Enter artist genre: ";
                getline(cin, genre);
                cout << "Enter label title: ";
                getline(cin, title);
                cout << "Enter label year: ";
                cin >> year;
                cin.ignore();
                record.addArtist_Label(name, genre, title, year);
                break;
            }
            case 2:
            {
                string name, genre;
                cout << "Enter artist name: ";
                getline(cin, name);
                cout << "Enter artist genre: ";
                getline(cin, genre);
                record.addArtist_Label(name, genre);
                break;
            }
            case 3:
            {
                string name;
                cout << "Enter artist name: ";
                getline(cin, name);
                record.addArtist_Label(name);
                break;
            }
            case 4:
                record.showRecords();
                break;
            case 5:
            {
                string name;
                cout << "Enter artist name to search: ";
                getline(cin, name);
                record.searchArtist(name);
                break;
            }
            case 6:
                cout << "\nExiting \n";
                break;
            default:
                cout << "Invalid choice \n";
        }
    } while (choice != 6);

    return 0;
}
