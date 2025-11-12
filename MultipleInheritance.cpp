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
