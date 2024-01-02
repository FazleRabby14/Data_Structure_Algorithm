#include <iostream>
#include <fstream>
//fstream helps me to read and write from a file.
#include <string>
#include<cctype>

using namespace std;

// Maximum number of names in input file
const int MAX_NAMES = 100;

// Name of file containing names, phone numbers, and Emails.
const string ADDRESSBOOK_FILENAME = "addressbook.txt";


struct Person
{
	string name;
	string phone;
	string email;


	Person()
	{
		name = "";
		phone = "";
		email="";
	}

	bool Matches(string name)
	{
		return (name.find(name) != string::npos);
		//Here npos means until the end of a string.
	}



};

void ReadAllPeople(Person people[], int &num_people)
{
	ifstream fin;
	fin.open(ADDRESSBOOK_FILENAME.c_str(), ios::app);
	//Here, ios::app helps you to move around a file.

	if (fin.fail())
	{
		cout << "Unable to open file " << ADDRESSBOOK_FILENAME << endl;
		return;
	}

	int i = 0;
	getline(fin, people[i].name);
	while (!fin.eof() && i < MAX_NAMES)
	{
		getline(fin, people[i].phone);

		i++;


		if (i < MAX_NAMES)
			getline(fin, people[i].name);
	}

	num_people = i;

	fin.close();
}

void SaveToFile(const Person people[], int num_people)
{
	ofstream fout;

	fout.open(ADDRESSBOOK_FILENAME.c_str());

	for(int i = 0; i < num_people; i++)
	{
		fout << people[i].name<<endl;
		fout <<people[i].phone<<endl;
		fout<<people[i].email<<endl;
		cout<<endl;

	}

}


void AppendToFile(Person person)
{
	ofstream fin;
	fin.open(ADDRESSBOOK_FILENAME.c_str(),ios::app);

	fin << person.name<<endl;
	fin <<person.phone<<endl;
	fin<<person.email<<endl;


	fin.close();

}


void AddContact(Person people[], int &num_people)
{
	Person person;


	cout <<"Enter a name to be added: ";
	cin>>person.name;

	cout <<"Enter the person's number: ";
	cin>> person.phone;

	cout <<"Enter the person's email: ";
	cin>> person.email;



	for(int i = 0; i < num_people; i++)
	{
		if( i + 1  == num_people)
			people[num_people] = person;
	}
	num_people++;

    cout<<endl;
	AppendToFile(person);
	cout <<"Name has been added."<<endl;

}


void UpdateContact(Person people[], int num_people)
{
	Person person;
	int count;

	cout <<"Enter name to change: ";
	getline(cin, person.name);


	for(count = 0; count < num_people; count++)
	{
		if(people[count].Matches(person.name))
		{	cout <<endl<< people[count].name<<endl;

		cout <<"Previous number"<<people[count].phone;
        cout<<endl;
		cout << "New number: ";
		getline(cin, people[count].phone);

		SaveToFile(people,num_people);

        cout<<endl;
		cout <<"New number Saved.";

		return;

		}

	}

	if(count = num_people)
		cout <<"\nName not found.";


}


void SearchContact(Person people[], int num_people, string n)
{

    for (int i = 0; i < num_people; i++){
        if(people[i].Matches(n)){
          cout << people[i].name << " - " << people[i].phone
          <<"-"<<people[i].email << endl;

        }
    }
}

void DeleteContact(Person people[], int num_people, string n)
{

    for (int i = 0; i < num_people; i++){
        if(people[i].Matches(n)){
           people[i].name=" ";
           people[i].phone=" ";
           people[i].email=" ";

        }
    }
}
void DisplayContact(const Person people[], int num_people)
{
	cout << "All Contact Information:"<<endl;

	for (int i = 0; i < num_people; i++)
		cout << people[i].name << " - " << people[i].phone<<"-"
		<<people[i].email << endl;
		cout<<endl;
}

int main()
{
	Person people[MAX_NAMES];
	int num_people;

	// Accessing records from file
	ReadAllPeople(people, num_people);

	int choice;
    cout<<endl;
	while(true){
		cout << "1. Add name phone number, and Email\n";
		cout << "2. Search Contact Number\n";
		cout << "3. Update Contact Number\n";
		cout << "4. Delete Contact Number\n";
		cout << "5. Display all Contact\n";
		cout << "6. Exit ";
		cout<<endl;


		cout<<"Enter your choice:";
		cin >> choice;

		 if(choice==1){
            AddContact(people, num_people);
            cout<<endl;
		 }
         else if(choice==2){
                string n;
                cout << "Enter name: ";
                cin >> n;
                SearchContact(people, num_people, n);
                cout<<endl;
         }
         else if(choice==3){
            UpdateContact(people, num_people);
            cout<<endl;
          }

         else if(choice==4){
            string n;
            cout << "Enter name: ";
            cin >> n;
            DeleteContact(people, num_people, n);
            cout<<endl;
         }

         else if(choice==5)	{
            DisplayContact(people, num_people);
            cout<<endl;
         }
         else if(choice==6){
             cout<<"Exit Program";
             break;
              cout<<endl;

         }
         else{
            cout<<"You have chosen invalid option"<<endl;
         }

		}
}





