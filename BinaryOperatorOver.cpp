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

    // Binary + operator to merge two records
    MusicRecord operator+(MusicRecord &other) 
    {
        MusicRecord temp;

        // Copy from first record
        for (int i = 0; i < Count; i++)
        {
            temp.addArtist_Label(artistNames[i], artistGenres[i], labelNames[i], labelYears[i]);
        }

        // Copy from second record
        for (int j = 0; j < other.Count; j++)
        {
            if (temp.Count < 10) 
                temp.addArtist_Label(other.artistNames[j], other.artistGenres[j], other.labelNames[j], other.labelYears[j]);
            else
                cout << "Not enough space \n";
        }

        return temp;
    }
};

int main()
{
    MusicRecord record1, record2, merged;
    int choice;

    do
    {
        cout << "\n--- MUSIC RECORD MENU ---\n";
        cout << "1. Add Artist to Record 1\n";
        cout << "2. Add Artist to Record 2\n";
        cout << "3. Show Record 1\n";
        cout << "4. Show Record 2\n";
        cout << "5. Merge Record1 + Record2\n";
        cout << "6. Show Merged Record\n";
        cout << "7. Exit\n";
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
                record1.addArtist_Label(name, genre, title, year);
                break;
            }
            case 2:
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
                record2.addArtist_Label(name, genre, title, year);
                break;
            }
            case 3:
                cout << "\nRecord 1:";
                record1.showRecords();
                break;
            case 4:
                cout << "\nRecord 2:";
                record2.showRecords();
                break;
            case 5:
                merged = record1 + record2; 
                cout << "Records merged\n";
                break;
            case 6:
                cout << "\nMerged Record:";
                merged.showRecords();
                break;
            case 7:
                cout << "Exiting \n";
                break;
            default:
                cout << "Invalid choice \n";
        }
    } while (choice != 7);

    return 0;
}
