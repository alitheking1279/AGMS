#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<string>
#include<fstream>
#include<vector>
#include<iomanip>
#include<limits>
using namespace std;
int Record;
//Structures of Art_Gallery_Management_System
struct Art{
	unsigned int Painting_id;
	string Painting_name;
	string Painter_Fname;//first name
	string Painter_Lname;//last name
	unsigned int price;
	
};
int record();
void Display_Menu();
void addData();
void deleteData();
void editData();
void viewData();
void displayData();


//main function
int main()
{   cout<<"****************************************WELCOME TO ART GALLERY MANAGEMENT SYSTEM****************************************\n"<<endl;
    char n;
    cout<<"\nPress any key on the key board to display menu."<<endl;
    n=getch();
    Display_Menu();
	fstream fout;
	fout.open("database.txt");
	fout<< setw(5)<< left<<"ID"<< setw(15)<< left<<"First Name"<< setw(15)<< left<<"Last name"<< setw(15)<< left<<"Painting's Name"<< setw(15)<< right<<"Cost"<<endl;
	fout.close();
	Display_Menu();
	return 0;
}
int record()
{
	vector<string> tracer;
	string lines;
	int record;
	ifstream fin;
	fin.open("database.txt");
	while(getline(fin,lines))
	tracer.push_back(lines);
	fin.close();
	record=tracer.size();
	return record;
}



//function to delete record from database
void deleteData()
{

  int id;
  char t;


  cout << "Enter the Id of the record you wish to delete: ";
  cin >> id;
  if(id>(Record-1))
  {
  	cout<<"\nRecord Does Not Exist"<<endl<<"Press Any Key To Continue";
  	t=getch();
  	system("cls");
  	deleteData();
  }

  fstream fin;

  fin.open("database.txt");

 
  vector<string> lines;
  string line;

  while (getline(fin, line))
    lines.push_back(line);
	fin.close();

  ofstream fout;
  fout.open("database.txt");

  for (int i = 0; i < lines.size(); i++)
    if (i != id)
      fout<< lines[i] << endl;

  fout.close();

}
//funtion to display menu
void Display_Menu(){
	char n;char c;
	do{
	Record=record();
	system("cls");
	cout<<"\nEnter the action you wish to perform";
	cout<<"\n[1] Add a record to the database";
	cout<<"\n[2] Delete a record from the database";
	cout<<"\n[3] Edit an existing record within the database";
	cout<<"\n[4] Search and Display a record from the database";
	cout<<"\n[5] Display every record of the database"<<endl<<endl;
  	n=getch();
	switch (n)
	{
		case '1':
		{	system("cls");
			addData();
			break;
		}
		case '2':
			{
				system("cls");
				deleteData();
				break;
			}
			case '3':
				{
					system("cls");
					editData();
					break;
				}
				case '4':
					{
						system("cls");
						viewData();
						break;
					}
				case '5':
					{
						system("cls");
						displayData();
						break;
					}
				default:
					{cout<<"\nInvalid Command!";
					break;
					}
	}
	cout<<"\n\nDo you wish to proceed: Y/N";
	c=getch();
	}
while(c=='Y'||c=='y');
cout<<"\nGOODBYE!";
	
}
//funtion to view a specific record
void viewData()
{

  int id;
  char t;


  cout << "Enter the Id of the record you wish to view: ";
  cin >> id;
    if(id>(Record-1))
  {
  	cout<<"\nRecord Does Not Exist"<<endl<<"Press Any Key To Continue";
  	t=getch();
  	system("cls");
  	viewData();
  }

  fstream fin;

  fin.open("database.txt");

 
  vector<string> lines;
  string line;

  while (getline(fin, line))
    lines.push_back(line);
	fin.close();
	for (int i = 0; i < lines.size(); i++)
    if (i == id)
      cout<< lines[i] << endl;

}

//function to display all the records on console
void displayData()
{
	vector<string> Display;
	fstream fin;
  fin.open("database.txt");
  string line;

  while (getline(fin,line))
    Display.push_back(line);
	fin.close();
	for (int i = 0; i < Display.size(); i++)
      cout<< Display[i] << endl;

	
}
//function to edit record within database
void editData()
{

    int id;
	Art* P = new Art;
	char t;
	bool Valid=false;
	char check;
	vector<string> temp;
  cout << "Enter the Id of the record you wish to edit: ";
  cin >> id;
    if(id>(Record-1))
  {
  	cout<<"\nRecord Does Not Exist"<<endl<<"Press Any Key To Continue";
  	t=getch();
  	system("cls");
  	editData();
	return;
  }
  string Newline;
  cout<<"\nEnter the painter's first name: ";
  cin>>P->Painter_Fname;
  cout<<"\nEnter the painter's last name: ";
  cin>>P->Painter_Lname;
  cout<<"\nEnter the painting's name: ";
  getline(cin>>ws,P->Painting_name);
  while (!Valid) {
    
      	cout<<"\nEnter the price of the painting: ";
    	cin>>P->price;

        if (cin.fail()) {
            cout << "INVALID DATA TYPE. PLEASE INPUT AN INTEGER"<< endl<<"PRESS ANY KEY TO CONTINUE";
            t=getch();
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            	system("cls");
			}
            else {
            Valid = true;
        }
        
        }

  ofstream fout;
  fout.open("tem.txt",ios::trunc);
  fout<< setw(5)<< left<<id<< setw(15)<< left<<P->Painter_Fname<< setw(15)<< left<<P->Painter_Lname<< setw(15)<< left<<P->Painting_name<< setw(15)<< right<<P->price;
  fout.close();
  fstream fin;
  fin.open("tem.txt");
  getline(fin,Newline);
  temp.push_back(Newline);
  fin.close();
  fin.open("database.txt");
  vector<string> lines;
  string line;

  while (getline(fin, line))
    lines.push_back(line);
	fin.close();
    ofstream Fout;
    Fout.open("database.txt");

  for (int i = 0; i < lines.size(); i++)
    {
	if (i != id)
      
	  Fout<< lines[i] << endl;
      else
      Fout<< temp[0]<<endl;	
}
  fout.close();

}
//funtion to add new record to database
void addData()
{	
	Art* P = new Art;
	bool valid = false;
	bool Valid=false;
	char t;

    while (!valid) {
    
      	cout<<"\nEnter the painting's ID: ";
    	cin>>P->Painting_id;

        if (cin.fail()) {
            cout << "INVALID DATA TYPE. PLEASE INPUT AN INTEGER"<< endl<<"PRESS ANY KEY TO CONTINUE";
            t=getch();
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            	system("cls");
			}
            else {
            valid = true;
        }
        
        }


	cout<<"\nEnter the Painter's first' name: ";
	cin>>P->Painter_Fname;
	cout<<"\nEnter the Painter's last name: ";
	cin>>P->Painter_Lname;
	cout<<"\nEnter the Painting's name: ";
	getline(cin>>ws,P->Painting_name);
while (!Valid) {
    
      	cout<<"\nEnter the price of the painting: ";
    	cin>>P->price;

        if (cin.fail()) {
            cout << "INVALID DATA TYPE. PLEASE INPUT AN INTEGER"<< endl<<"PRESS ANY KEY TO CONTINUE";
            t=getch();
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            	system("cls");
			}
            else {
            Valid = true;
        }
        
        }

	ofstream fout;
	fout.open("database.txt",ios::app);
	fout<< setw(5)<<left<<P->Painting_id<< setw(15)<< left<<P->Painter_Fname<< setw(15)<< left<<P->Painter_Lname<< setw(15)<< left<<P->Painting_name<< setw(15)<< right<<P->price<<endl;
	fout.close();
}