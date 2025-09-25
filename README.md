# C++ Programs
// It contains a set of 10 Programs in C++ Language

 PROGRAM 1: To Implement Classes and Objects
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

PROGRAM 2: To Implement Default Arguments
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

PROGRAM 3: To Implement Friend Functions
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

PROGRAM 4: To Implement Default, Parameterized and Copy Constructors
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

PROGRAM 5: To Implement Static Functions
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

PROGRAM 6: To Implement Function Overloading
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

PROGRAM 7: To Implement Unary Operator Overloading
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

PROGRAM 8: To Implement Binary Operator Overloading
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

PROGRAM 9: To Implement Multiple Inheritance
#include<iostream>
#include<string>
using namespace std;
class Artist
 { 
 public:
    string ArtistName;
    string ArtistGenre;
    Artist()
    {
        ArtistName="";
        ArtistGenre="";
    }
 void SetArtist(string name, string genre)
    {
        ArtistName=name;
        ArtistGenre=genre;
    }
    void ShowArtist()
    {
        cout << "Artist: " << ArtistName << " (" << ArtistGenre << ") ";
    }
};
class Label
{
public:
    string LabelName;
    int FoundYear;
    Label()
    {
        LabelName="";
        FoundYear=0;
    }
    void SetLabel(string name, int year)
    {
        LabelName=name;
        FoundYear=year;
    }
    void ShowLabel()
    {
     cout << "-Label: " << LabelName << " (Founded: " << FoundYear << ")" << endl;
    }
};
class MusicRecord : public Artist, public Label{
  public:
  void SetRecord(string artist, string genre, string label, int year)
  {
    SetArtist(artist, genre);
    SetLabel(label, year);
  }
  void ShowRecord()
  {
    ShowArtist();
    ShowLabel();
  }

};
int main()
{
    MusicRecord record[10];
    int count=0,choice;
    do{
        cout << "\n Menu \n";
        cout << "1. Add Record \n";
        cout << "2. Show Records \n";
        cout << "3. Exit \n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        switch(choice)
        {
          case 1:
          {
           if(count<10)
            {
             string name, genre, label; int year;
             cout << "Enter Artist Name: ";
             getline(cin, name);
             cout << "Enter Artist Genre: ";
             getline(cin, genre);
             cout << "Enter Label Name: ";
             getline(cin, label);
             cout << "Enter Found Year: ";
             cin >> year;
             cin.ignore();
             record[count].SetRecord(name, genre, label, year);
             count ++;
             cout << "Record Added";
            }else{
                cout << "Record list is full";
            }
            break;
          }
          case 2:
          {
            if(count==0)
            {
                cout << "No records available";
            } 
            else{
                for(int i=0; i<count; i++)
                {
                    cout << i+1 << ".";
                    record[i].ShowRecord();
                }
            }
            break;
          }
          case 3:
          {
            cout << "exit";
            break;
          }
          default:
          cout << "Wrong Choice";
        }
    }
    while (choice != 3);
    return 0;
}

PROGRAM 10: To Implement Multi-Level Inheritance
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
