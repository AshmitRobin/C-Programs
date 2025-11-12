#include <iostream>
#include <string>
using namespace std;

class MusicRecord
{
public:
    string artistName;
    string artistGenre;
    string labelName;
    int labelYear;
    string eraTag;

    void classifyEra()
    {
        if (labelYear == 0)
            eraTag = "Unknown Era";
        else if (labelYear < 2000)
            eraTag = "Old Era";
        else if (labelYear <= 2015)
            eraTag = "Golden Era";
        else
            eraTag = "New Wave";
    }

    // Default Constructor
    MusicRecord()
    {
        artistName = "Unknown Artist";
        artistGenre = "Unknown Genre";
        labelName = "Unknown Label";
        labelYear = 0;
        classifyEra();
    }

    // Parameterized Constructor
    MusicRecord(string name, string genre, string label, int year)
    {
        artistName = name;
        artistGenre = genre;
        labelName = label;
        labelYear = (year > 0) ? year : 0;
        classifyEra();
    }

    // Copy Constructor
    MusicRecord(MusicRecord &obj)
    {
        artistName = obj.artistName;
        artistGenre = obj.artistGenre;
        labelName = obj.labelName;
        labelYear = obj.labelYear;
        classifyEra();
    }

    void display()
    {
        cout << "\nArtist Name  : " << artistName;
        cout << "\nArtist Genre : " << artistGenre;
        cout << "\nLabel Name   : " << labelName;
        cout << "\nLabel Year   : " << labelYear;
        cout << "\nEra Tag      : " << eraTag << "\n";
    }
};

int main()
{
    MusicRecord records[5];
    int count = 0;
    int choice;

    do
    {
        cout << "\n==== MUSIC RECORD MENU ====\n";
        cout << "1. Add Artist & Label (Default Constructor)\n";
        cout << "2. Add Artist & Label (Parameterized Constructor)\n";
        cout << "3. Copy an Existing Record (Copy Constructor)\n";
        cout << "4. Show All Records\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            if (count < 5)
            {
                records[count] = MusicRecord(); // Default constructor
                cout << "Default record added at index " << count << "\n";
                count++;
            }
            else
                cout << "List is full\n";
            break;

        case 2:
            if (count < 5)
            {
                string name, genre, label;
                int year;
                cout << "Enter artist name: ";
                getline(cin, name);
                cout << "Enter artist genre: ";
                getline(cin, genre);
                cout << "Enter label name: ";
                getline(cin, label);
                cout << "Enter label year: ";
                cin >> year;
                cin.ignore();

                records[count] = MusicRecord(name, genre, label, year);
                cout << "Parameterized record added at index " << count << "\n";
                count++;
            }
            else
                cout << "List is full\n";
            break;

        case 3:
            if (count < 5)
            {
                int index;
                cout << "Enter index to copy (0 to " << count - 1 << "): ";
                cin >> index;
                cin.ignore();
                if (index >= 0 && index < count)
                {
                    records[count] = MusicRecord(records[index]); // Copy constructor
                    cout << "Copied record from index " << index << " to index " << count << "\n";
                    count++;
                }
                else
                    cout << "Invalid index\n";
            }
            else
                cout << "List is full\n";
            break;

        case 4:
            if (count == 0)
                cout << "No records to display\n";
            else
            {
                for (int i = 0; i < count; i++)
                {
                    cout << "\n--- Record " << i << " ---";
                    records[i].display();
                }
            }
            break;

        case 5:
            cout << "Exiting\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
