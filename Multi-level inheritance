#include <iostream>
#include <string>
using namespace std;
class Artist 
{
public:
 string artistName;
 string artistGenre;
  Artist() 
    {
        artistName = "";
        artistGenre = "";
    }

      void setArtist(string name, string genre) 
     {
        artistName = name;
        artistGenre = genre;
     }

    void showArtist() 
    {
        cout << "Artist: " << artistName << " (" << artistGenre << ")";
     }
};
class Label : public Artist
{
    public:
      string labelName;
      int foundedYear;

    Label()
    {
        labelName = "";
        foundedYear = 0;
    }

    void setLabel(string name, int year) 
    {
        labelName = name;
        foundedYear = year;
     }
    void showLabel() 
    {
        cout << "- Label: " << labelName << " [Founded: " << foundedYear << "]";
    }
};
class MusicRecord : public Label
{
public:
 void setRecord(string artist, string genre, string label, int year) 
    {
        setArtist(artist, genre);
        setLabel(label, year);
    }

    void showRecord() 
     {
        showArtist();
        showLabel();
        cout << endl;
    }
};

int main()
{
    MusicRecord records[10];
    int count = 0, choice;

    do {
        cout << "\n Menu\n";
        cout << "1. Add Record\n";
        cout << "2. Show Records\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch(choice) 
        {
         case 1: 
            {
                if (count < 10)
                 {
                    string name, genre, label;
                    int year;
                    cout << "Enter artist name: ";
                    getline(cin, name);
                    cout << "Enter artist genre: ";
                    getline(cin, genre);
                    cout << "Enter label name: ";
                    getline(cin, label);
                    cout << "Enter label founded year: ";
                    cin >> year;
                    cin.ignore();

                    records[count].setRecord(name, genre, label, year);
                    count++;
                    cout << "Record added\n";
                } 
                else  {
                    cout << "Record list is full\n";
                }
                break;
            }
            case 2: 
            {
                if (count == 0) 
                {
                 cout << "No records available\n";
                } 
                else 
                {
                 cout << "\n--- All Records ---\n";
                    for (int i = 0; i < count; i++) 
                    {
                        cout << i + 1 << ". ";
                        records[i].showRecord();
                     }
                }
                break;
            }
            case 3:
                cout << "Exiting\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } 
    while (choice != 3);

    return 0;
} 
