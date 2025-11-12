#include <iostream>
#include <string>
using namespace std;

class MusicRecord 
{
public:
    string artistNames[5], artistGenres[5];
    string labelNames[5];
    int labelYears[5];

    int artistCount = 0;
    int labelCount = 0;

    void addArtist(string name = "Unknown Artist", string genre = "Pop")
     {
        if (artistCount < 5) 
        {
            artistNames[artistCount] = name;
            artistGenres[artistCount] = genre;
            cout << "Artist Name: " << name << "\nGenre: " << genre << endl;
            artistCount++;
        } 
        else 
        {
            cout << "Artist limit reached!\n";
        }
    }

    void addLabel(string name = "Independent", int yearFounded = 2000) 
    {
        if (labelCount < 5) 
        {
            labelNames[labelCount] = name;
            labelYears[labelCount] = yearFounded;
            cout << "Label Name: " << name << "\nYear Founded: " << yearFounded << endl;
            labelCount++;
        } 
        else
         {
            cout << "Label limit reached!\n";
        }
    }

    void showAllRecords()
     {
        cout << "\n--- Stored Artists ---\n";
        for (int i = 0; i < artistCount; i++) 
        {
            cout << i + 1 << "." << artistNames[i] << " (" << artistGenres[i] << ")\n";
        }

        cout << "\n--- Stored Labels ---\n";
        for (int i = 0; i < labelCount; i++)
         {
            cout << i + 1 << "." << labelNames[i] << " (Founded: " << labelYears[i] << ")\n";
        }
    }
};

void menu() 
{
    cout << "\n---- MUSIC RECORD MENU ----\n";
    cout << "1. Add Artist\n";
    cout << "2. Add Label\n";
    cout << "3. Show All Records\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

int main()
 {
    MusicRecord mr;
    int choice;
    char subChoice;

    do 
    {
        menu();
        cin >> choice;
        cin.ignore();

        switch (choice) 
        {
            case 1: 
                cout << "Use default artist? (y/n): ";
                cin >> subChoice;
                cin.ignore();
                if (subChoice == 'y' || subChoice == 'Y')
                 {
                    mr.addArtist();
                } 
                else 
                {
                    string name, genre;
                    cout << "Enter Artist Name: ";
                    getline(cin, name);
                    cout << "Enter Genre: ";
                    getline(cin, genre);
                    mr.addArtist(name, genre);
                }
                break;

            case 2: 
                cout << "Use default label? (y/n): ";
                cin >> subChoice;
                cin.ignore();
                if (subChoice == 'y' || subChoice == 'Y')
                 {
                    mr.addLabel();
                } 
                else
                 {
                    string name;
                    int year;
                    cout << "Enter Label Name: ";
                    getline(cin, name);
                    cout << "Enter Year Founded: ";
                    cin >> year;
                    cin.ignore();
                    mr.addLabel(name, year);
                }
                break;

            case 3:
                mr.showAllRecords();
                break;

            case 4:
                cout << "Exiting \n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } 
    while (choice != 4);

    return 0;
}
