#include <iostream>
#include <string>
using namespace std;

class MusicRecord 
{
public:

    static string artistNames[5];
    static string artistGenres[5];
    static string labelNames[5];
    static int labelYears[5];
    static int Count;

    static void addArtist_Label(string name, string genre, string title, int year)
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
            cout << "List is full\n";
        }
    }

    
    static void showArtist_Label()
    {
        cout << "\n--- Artist and Label Details ---\n";

        if (Count == 0)
        {
            cout << "No records to display\n";
            return;
        }

        int oldEra = 0, goldenEra = 0, newWave = 0;

        for (int i = 0; i < Count; i++) 
        {
            cout << artistNames[i] << " (" << artistGenres[i] << ") - "
                 << labelNames[i] << " [Founded: " << labelYears[i] << "]";

            if (labelYears[i] < 2000) 
            {
                cout << " Old Era \n";
                oldEra++;
            } 
            else if (labelYears[i] <= 2015) 
            {
                cout << "Golden Era \n";
                goldenEra++;
            } 
            else 
            {
                cout << "New Wave \n";
                newWave++;
            }
        }

        cout << "\n--- Summary ---\n";
        cout << "Old Era Labels (before 2000): " << oldEra << "\n";
        cout << "Golden Era Labels (2000-2015): " << goldenEra << "\n";
        cout << "New Wave Labels (after 2015): " << newWave << "\n";
    }
};

// Static data member definitions
string MusicRecord::artistNames[5];
string MusicRecord::artistGenres[5];
string MusicRecord::labelNames[5];
int MusicRecord::labelYears[5];
int MusicRecord::Count = 0;

int main() 
{
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
                MusicRecord::addArtist_Label(name, genre, title, year);
                break;
            }
            case 2:
                MusicRecord::showArtist_Label();
                break;
            case 3:
                cout << "\nExiting\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 3);

    return 0;
}
