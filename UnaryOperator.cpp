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
            cout << i + 1 << ". "
                 << artistNames[i] << " (" << artistGenres[i] << ") - "
                 << labelNames[i] << " [Founded: " << labelYears[i] << "]\n";
        }
    }

    // Unary ++ to add a Unknown artist
    MusicRecord operator++() 
    {
        if (Count < 10)
        {
            artistNames[Count] = "Unknown Artist";
            artistGenres[Count] = "Unknown";
            labelNames[Count] = "Unknown";
            labelYears[Count] = 0;
            Count++;
            cout << "Unknown Artist added\n";
        }
        else
        {
            cout << "List is full \n";
        }
        return *this;
    }

    // Unary -- to remove the last artist
    MusicRecord operator--() 
    {
        if (Count > 0)
        {
            Count--;
            cout << "Removed last artist \n";
        }
        else
        {
            cout << "No artist to remove \n";
        }
        return *this;
    }
};

int main()
{
    MusicRecord record;
    int choice;

    do
    {
        cout << "\n--- MUSIC RECORD MENU ---\n";
        cout << "1. Add Artist (Full Details)\n";
        cout << "2. Show All Records\n";
        cout << "3. Use ++ Operator (Add Unknown Artist)\n";
        cout << "4. Use -- Operator (Remove Last Artist)\n";
        cout << "5. Exit\n";
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
                record.showRecords();
                break;
            case 3:
                ++record;
                break;
            case 4:
                --record; 
                break;
            case 5:
                cout << "Exiting program \n";
                break;
            default:
                cout << "Invalid choice \n";
        }
    } while (choice != 5);

    return 0;
}
