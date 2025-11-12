#include <iostream>
#include <string>
using namespace std;

class MusicRecord 
{
private:
    string artistNames[5];
    string artistGenres[5];
    string labelNames[5];
    int labelYears[5];
    int Count;

public:
    MusicRecord() 
    {
        Count = 0;
    }

    void addArtist_Label(string name, string genre, string title, int year)
    {
        if (Count < 5)
        {
            artistNames[Count] = name;
            artistGenres[Count] = genre;
            labelNames[Count] = title;
            labelYears[Count] = year;
            Count++;
        } 
        else 
        {
            cout << "List is full!\n";
        }
    }

    friend void showArtist_Label(MusicRecord record);
};

void showArtist_Label(MusicRecord record)
{
    cout << "\n--- Artist and Label Details ---\n";

    if (record.Count == 0)
    {
        cout << "No records to display.\n";
        return;
    }

    int oldEra = 0, goldenEra = 0, newWave = 0;

    for (int i = 0; i < record.Count; i++) 
    {
        cout << record.artistNames[i] << " (" << record.artistGenres[i] << ") - "
             << record.labelNames[i] << " [Founded: " << record.labelYears[i] << "]";

        if (record.labelYears[i] < 2000) 
        {
            cout << " -- Old Era \n";
            oldEra++;
        } 
        else if (record.labelYears[i] <= 2015) 
        {
            cout << " -- Golden Era \n";
            goldenEra++;
        } 
        else 
        {
            cout << " -- New Wave \n";
            newWave++;
        }
    }

    cout << "\n--- Summary ---\n";
    cout << "Old Era Labels (before 2000): " << oldEra << "\n";
    cout << "Golden Era Labels (2000-2015): " << goldenEra << "\n";
    cout << "New Wave Labels (after 2015): " << newWave << "\n";
}

int main() 
{
    MusicRecord record;
    int choice;

    do 
    {
        cout << "\n MUSIC RECORD MENU \n";
        cout << "1. Add Artist and Label\n";
        cout << "2. Show Artist-Label Details\n";
        cout << "3. Exit\n";
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
                record.addArtist_Label(name, genre, title, year);
                break;
            }
            case 2:
                showArtist_Label(record);
                break;
            case 3:
                cout << "\nExiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 3);

    return 0;
}
