#ifndef FUCTIONS_H_
#define FUCTIONS_H_
#include <iostream>

using namespace std;

//original is in replit CS1B_AS03
using namespace std;

//Struct
struct MovieNode
{
    string title;
    string lead;
    string support;
    string genre;
    string altGenre;
    int year;
    int rating;
    string synopsis;
    MovieNode *next;

    MovieNode()
    {
        title = "empty";
        lead = "empty";
        support = "empty";
        genre = "empty";
        altGenre = "empty";
        year = 0;
        rating = 0;
        synopsis = "empty";
    }
            
};

enum command {EXIT = 0, OUTPUT = 1, TITLE = 2, GENRE = 3, LEAD = 4, YEAR = 5, RATING = 6};

/*
 * This function will load the default file (inFile.txt) that contains the movie details
 * it will place the data in the apporiate fields:
 * Title, lead, support, genre, altGenre, year, rating and the synopsis 
 */
MovieNode *Create(MovieNode *head)
{
    //bool found;    // OUT - check to see if the element is in the list
    MovieNode* perPtr; // OUT - pointer to the element
    ifstream inFile;
    inFile.open("InFile.txt");
    perPtr = new MovieNode; // Makes new node

    while (inFile && perPtr != NULL)
    {
        getline(inFile, perPtr->title);
        getline(inFile, perPtr->lead);
        getline(inFile, perPtr->support);
        getline(inFile, perPtr->genre);
        getline(inFile, perPtr->altGenre);
        inFile>>perPtr->year;
        inFile.ignore(1000, '\n'); // clears buffer
        inFile>>perPtr->rating;
        inFile.ignore(1000, '\n'); // clears buffer
        getline(inFile, perPtr->synopsis);
        inFile.ignore(1000, '\n'); // clears buffer
        perPtr->next = head; // advances the pointer and assigns it to head
        head = perPtr; // pointer is now at the front of the node
        perPtr = new MovieNode; // makes new node
    }

    delete perPtr; // deletes the pointer
    return head;
}

void Display(MovieNode *head, ostream &outFile)
{
    //cout << "\n\nMovie List:" << endl << endl;
    int count = 0;
    MovieNode* perPtr = head;
    //output to console
    cout << "\n\nCOMPLETE MOVIE LISTING"<< endl;
    cout << "MOVIE#" << setw(6) << "TITLE" << setw(65) << "YEAR " << setw(7) << "RATING" << setw(7) << "GENRE" << setw(22) << "ALT GENRE" << setw(20)<< "LEAD ACTOR" << setw(35) << "SUPPORTING ACTOR" << endl;
    cout << "------" << setw(8) << " ---------------------------------------------------------------" << setw(6) << "----"<< setw(8) << "------" << setw(16) << "--------------" << setw(21) << "-----------------" << setw(29) << "----------------------------" << setw(33) << "--------------------------------" << endl;
    
    //output to file
    outFile << "\n\nCOMPLETE MOVIE LISTING"<< endl;
    outFile << "MOVIE#" << setw(6) << "TITLE" << setw(65) << "YEAR " << setw(7) << "RATING" << setw(7) << "GENRE" << setw(20) << "ALT GENRE" << setw(20)<< "LEAD ACTOR" << setw(35) << "SUPPORTING ACTOR" << endl;
    outFile << "------" << setw(8) << " ---------------------------------------------------------------" << setw(6) << "----"<< setw(8) << "------" << setw(16) << "--------------" << setw(20) << "------------------" << setw(29) << "----------------------------" << setw(33) << "--------------------------------" << endl;
    while (perPtr!= NULL)
    {
        string str;
        string temp;
        str = perPtr->title;
        temp = str.substr(0, 45);
        
        count++;
        // output to console
        cout << right;
        cout << setw(3) << count;
        cout << left;
        cout << setw(4) << "";
        cout << setw(65) << temp;
        cout << setw(8) << perPtr->year;
        cout << setw(6) << perPtr->rating;
        cout << setw(18) << perPtr->genre;
        cout << setw(18) << perPtr->altGenre;
        cout << setw(29) << perPtr->lead;
        cout << setw(20) << perPtr->support << endl;
        
        // output to file
        outFile << right;
        outFile << setw(3) << count;
        outFile << left;
        outFile << setw(4) << "";
        outFile << setw(65) << temp;
        outFile << setw(8) << perPtr->year;
        outFile << setw(6) << perPtr->rating;
        outFile << setw(16) << perPtr->genre;
        outFile << setw(20) << perPtr->altGenre;
        outFile << setw(29) << perPtr->lead;
        outFile << setw(20) << perPtr->support << endl;
        
        perPtr = perPtr->next;
    }
    delete perPtr; // deletes pointerd
}

void textWrap(MovieNode *head)
{
    int i= 0;
    string temp;
    string wtxt;
    MovieNode *textWrap;
    textWrap = head;

    temp = textWrap->synopsis;

    while(i < temp.size())
        {
            int j = i + 120;
            if(j > temp.size())
                j = temp.size();
            while (j > i && temp[j] !=' ')
                j--;
            if (j == i)
                j = i + 120;
            cout << temp.substr(i, j-i);
            i = j + 1;
        }
}

/**
 * This function is to search the list of movies included in the inFile.txt
 * function does not return anything to main 
 */
void SearchTitle(MovieNode *head, ostream &outFile)
{
  string searchTitle; // INPUT - the name to be searched - INPUT
  MovieNode *search; // OUTPUT - the pointer to search the list - OUTPUT
  search = head; // pointer to the first node

  if (search == NULL)
  {
      cout << "Can't search an empty list! " << endl;
  }
  else 
  {
    cout << "What movie would you like to search for? ";
    cin.ignore(1000, '\n');
    getline(cin, searchTitle);

    cout << "Searching for " << searchTitle << "..." << endl << endl;
    while (search != NULL) 
    {
      if (search->title.compare(searchTitle) == 0) 
      {
        string wtxt; // OUT - wrapped text
        wtxt = search->synopsis; // setting synopsis to variable to word wrap
        int i= 0; // counter
        cout << "Found the movie " << searchTitle << "!" << endl;
        outFile << "***************************************************************************" << endl;
        outFile << "Title: "<< search->title << endl;
        outFile << "---------------------------------------------------------------------------" << endl;
        outFile << "Year: " << search->year << setw(20) << "Rating: " << search->rating << endl;
        outFile << "---------------------------------------------------------------------------" << endl;
        outFile << "Leading Actor: " << search->lead << setw(20) << "Genre 1: " << search->genre << endl;
        outFile << "Supporting Actor: " << search->support << setw(20) << "Genre 2: " << search->altGenre << endl;
        outFile << "---------------------------------------------------------------------------" << endl;
        outFile << "PLOT: " << endl; 
        while (i < wtxt.size())
        {
            int j = i + 85;
            if (j > wtxt.size())
                j = wtxt.size();
            while (j > i && wtxt[j] != ' ')
                j--;
            if (j == i)
                j = i + 85;
            outFile << wtxt.substr(i, j - i) << endl;
            i = j + 1;
        }
          outFile << "***************************************************************************" << endl;
          outFile << endl << endl;
          break;
      } else
      {
        search = search->next;
      }
      if (search == NULL)
        cout << "Sorry, the movie " << searchTitle << " was not found." << endl;
    }
    search = NULL;
    delete search;
  }
}

void SearchGenre(MovieNode *head, ostream &outFile)
{
    string searchGenre; // IN 
    string searchAltGenre; // IN
    MovieNode *search; // OUT
    search = head; // pointer to the first node
    int count =0;

    if (search == NULL)
    {
        cout << "Can't search an empty list! " << endl;
    }
    else
    {
        cout << "What genre would you like to search for? ";
        cin.ignore(1000, '\n');
        //getline(cin, searchGenre);
        cin >> searchGenre; 
        cin >> searchAltGenre;

        cout << "Searching for " << searchGenre << endl << endl;
        while (search!= NULL)
        {
            string combined = search->genre + search->altGenre;
            if (combined == searchGenre || combined == searchAltGenre || combined == searchGenre + searchAltGenre)
            {
                count ++;
                cout << "Found " << count << " for the genre, " << searchGenre << " "<< searchAltGenre << endl;
                break;
            }
            else
            {
                search = search->next;
            }    
            
          if (search == NULL)
          {
              cout << "Sorry, no movies for the genre, " << searchGenre << " " << searchAltGenre << " were found." << endl;
          }
        }
    search = NULL;
    delete search;
    }
}


#endif
/* FUCTIONS_H_ */