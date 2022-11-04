#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include <string>
#include <iomanip>
#include "functions.h"
//#include myheader.h

/*****************************************************************
* Searching Linked List
* Program that allows a yser to track/search their DVD collection. 
* Uses an input file that contains the list of DVD with the following attributs:
* Title, Leading actor/actress, supporting actor, alternate genre, year rating and synopsis
* _______________________________________________________________
* INPUT:
* fileIn; // IN - Name of the input file being used
* sTitle; // IN - used to search based on title
* sGenre; // IN - used to search based on genre
* sLead; // IN - used to search based on lead
* sYear; // IN - used to search based on year
* rating; // IN - used to search based on rating
* OUTPUT:
* fileOut; // OUT - Name of the output file
*
******************************************************************/




int main()
{
    MovieNode *head;
    int command; // IN - used to navigate menu and enter the while loop
    ifstream inFile; // IN - input file 
    ofstream outFile; // OUT - output file
    string fileIn; // IN - Name of the input file being used
    string fileOut; // OUT - Name of the output file
    bool titleCheck; // OUT - used to check if movie title is in the list
    string stitle; // IN - the movie title the user inputed
    string sGenre; // IN - used to search based on genre
    string sLead; // IN - used to search based on lead
    int sYear; // IN - used to search based on year
    int rating; // IN - used to search based on rating

    command = -1;
    
    // Open file
    cout << "Which input file would you like (type d for default file)? ";
    getline(cin, fileIn);
    if (fileIn.compare("d") == 0)
    {
        fileIn = "InFile.txt";
        cout << "opening default file: " << fileIn << endl;
        head = Create(head); // calling create function to importing data from file
    }

    // saving outfile name
    cout << "Which output file would you like to use (type d for default file)? ";
    getline(cin, fileOut);
    if (fileOut.compare("d") == 0)
    {
        fileOut = "OFile.txt";
        cout << "Saving to default file: " << fileOut << endl;
    }

    // opening fileIn and fileOut
    inFile.open(fileIn);
    outFile.open(fileOut);

    // error checking
    if (!inFile)
    {
        cout << "Error opening file: " << fileIn << endl;
        exit(1); //terminate with error
    }

    while (command!= 0)
        {
            cout << "\n\n\n1 - Output Entire List\n";
            cout << "2 - Title Search\n";
            cout << "3 - Genre Search\n";
            cout << "4 - Actor Search\n";
            cout << "5 - Year Search\n";
            cout << "6 - Rating Search (0-9)\n";
            cout << "0 - EXIT\n";
            cout << "Enter command: ";

            cin >> command;

            switch (command)
                {
                    /*
                     * Will exit the program 
                    */
                    case EXIT:
                    cout << "Exiting..." << endl;
                    break;

                    case OUTPUT:
                    /*
                     * Calls on the function Display(MovieNode *head) 
                     * function will display the loaded inFile.txt for the user
                    */
                    Display(head, outFile);
                    break;

                    case TITLE:
                    /*
                     * If title of the movie is found - output move to Ofile.txt
                     * cout << "Found the movie " << title << " !"
                     * If title of the movie is NOT found
                     * cout << "Sorry, the movie " << title << " was not found." 
                     */ 
                    SearchTitle(head, outFile);
                    break;

                    case GENRE:
                    /*
                     * bool function (T/F)
                     * return true - if GENRE of movie is found - output movie to Ofile.txt
                     *             - cout how many movies that match the genre searched for
                     * return false - if GENRE of movie is NOT found 
                     *              - cout << "Sorry, no movies for the genre " << genre << were found
                     *  
                    */
                    SearchGenre(head, outFile);
                    break;

                    case YEAR:
                    /*
                     * YEAR of movie is found - output movie to Ofile.txt
                     *             - cout how many movie that match the year searched for
                     *             - cout << "Found " << year << " for the year " << 
                     *  YEAR of movie NOT found
                     */
                    break;

                    
                }
        }
    
    inFile.close();
    outFile.close();    
    return 0;
}