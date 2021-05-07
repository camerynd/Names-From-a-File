#include<iostream>
#include<fstream>//library for fstream objects
#include<string>//library for string objects
using namespace std;
//function prototypes
void error_message(ifstream&);
void first_and_last_in_line(ifstream&, string&, string&);
void display_results(string&, string&);
//main function
int main()
{
    //declare ifstream object to read from a file
    ifstream inFile; 
    //declare string variables
    string firstInLine,
           lastInLine;
    cout << "The list of student names is being accessed from a file." << endl;
    //open txt file to read from
    inFile.open("LineUp.txt");
    //call functions
    error_message(inFile);
    first_and_last_in_line(inFile, firstInLine, lastInLine);
    //close txt file
    inFile.close();
    //call function to display results
    display_results(firstInLine, lastInLine);
    return 0;
}
//function to display error message if error opening file
void error_message(ifstream& file)
{
    if(file.fail())//detects file open failiure
    {
        cout << "Error opening file.";
        exit(1);//exit program if file won't open
    }
}
//function to read from file and make necessary determinations about the 
//data being read
void first_and_last_in_line(ifstream& file, string& first, string& last)
{  
    //declaring variables within the function because they are only needed 
    //within the function
    string name; 
    int count = 0,
        ASCII = 0;
    //reading the first name from txt file
    file >> name;
    //setting ASCII value of the first letter of the first name in file to a
    //variable as a starting place for comparing the other names in the file
    ASCII = name[0];
    while(!file.eof())//runs until everything in the file has been read
    {
        //reads from file and stores in variable name
        file >> name;
        //if ASCII value of the first letter of name being read is lower than 
        //the last, it is closer to the beginning of the alphabet
        if(name[0] < ASCII)
        {
            first = name;
        }
        //if ASCII value of the name being read is lower than the last, it is 
        //closer to the end of the alphabet
        if(name[0] > ASCII)
        {
            last = name;
        }
        //counts how many names are in the file
        count++;
        //input validation, making sure there are less than 25 students in the file
        if(count > 25)
        {
            cout << "You must use a file with 25 or less student names." << endl;
            exit(1);//exit program if the user chose a file with too many names
        }
    }
}
//function to display results to user
void display_results(string& first, string& last)
{
    cout << "First in line: " << first << endl;
    cout << "Last in line: " << last << endl;
}