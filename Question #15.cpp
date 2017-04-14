//QUESTION #15
/*15) [50 pts]
Write a simple contact list (telephone directory) maintenance program.
Your program should lookup phone numbers by last names entered by the user
and change the corresponding phone number for that contact using the new phone no.
also entered by the user. The program should read its initial contact data from a file,
named "infile.txt" containing a list of names and phone numbers. The program should read
this contact data into two arrays.  The first array is an array of NameType structs,
see Question 13 above. The second array contains the corresponding phone no for each contact.

contact list

Type/paste the following into an input file named "infile.txt"

Harry N Keeling (202)806-4830
Frank L James (301)123-3459
Arthur K Paul (202)865-9090
Todd T Shurn (410)560-8909
Sally M King (212)808-3345
Jean F George (301)303-3339
Nancy K law (202)856-2342
Francis P Clark (410)560-8909
Terry U Smith (302)239-0090
Andy R Royster (240)809-4635
The program should use the structure chart above to solve this problem.

After reading the contact data into the two arrays, your program should 
prompt the user to enter a last_name and a new_phone_no. Then the last_name
should be used to look up the corresponding NameType in the name_array.  
Once the contact is found, your program must change the corresponding phone_no
in the phone_no_array.

After changing one contact's phone number your program should print the
resulting contact list.

Your program's output should look like:

contacts report

Also, your program must contain adequate comments.
*/

#include <iostream>		//for cin, cout, endl, fixed and showpoint
#include <iomanip>		//for setw and setprecision
#include <fstream>		//for file manipulation
#include <string> 		//for string operations
using namespace std;

struct NameType
{
	string first;
	char middle;
	string last;
};

ifstream myFile;
void get_contact_data(ifstream&, NameType[], string[]);
void Lookup_phone_no(string, string[], string, NameType[]);
void print_contact_list(string[], NameType[]);

int main()
{
	NameType name[10];
	string phone_no[10];
	string new_num, last_name;
	myFile.open("infile.txt");
	get_contact_data(myFile, name, phone_no);
	cout << "\n\nPlease enter the last name of the contact: ";
	cin >> last_name;
	cout << "Please enter the phone number of the contact: ";
	cin >> new_num;
	Lookup_phone_no(new_num, phone_no, last_name, name);
	myFile.close();
	print_contact_list(phone_no, name);
	return 0;
}

void get_contact_data(ifstream& myFile, NameType name[], string phone_no[])
{
	for (int x=0; x<10; x++)
	{
		myFile >> name[x].first >> name[x].middle >> name[x].last >> phone_no[x];
	}
	return;
}
void Lookup_phone_no(string new_num, string phone_no[], string last_name, NameType name[])
{
	for (int x=0; x<10; x++)
	{
		if (last_name == name[x].last)
		{
			phone_no[x] = new_num;
			break;
		}
	}
	return;
}
void print_contact_list(string phone_no[], NameType name[])
{
	int y;
	cout << "\n\n\tMY CONTACT LIST\n";
	for (y=0;y<10;y++)
	{
		cout << name[y].first << " " << name[y].middle << " " << name[y].last << "\t" << phone_no[y] << endl;
	}
}


/*

Please enter the last name of the contact: Paul
Please enter the phone number of the contact: (111)222-3333


	MY CONTACT LIST
Harry N Keeling	(202)806-4830
Frank L James	(301)123-3459
Arthur K Paul	(111)222-3333
Todd T Shurn	(410)560-8909
Sally M King	(212)808-3345
Jean F George	(301)303-3339
Nancy K law	(202)856-2342
Francis P Clark	(410)560-8909
Terry U Smith	(302)239-0090
Andy R Royster	(240)809-4635
*/