#include <iostream>
#include <list>
using namespace std;

class Student{
private:
	string fName, lName, DOB, major;
	int CWID, year;

public:
	Student()
		:fName(""), lName(""), DOB(""), major(""), CWID(99999), year(0){}
	Student(string f, string l, string d, string m, int c, int y)
		:fName(f), lName(l), DOB(d), major(m), CWID(c), year(y){}
	string getName() const {return fName +" "+ lName;}
	string getDOB() const {return DOB;}
	string getMajor() const { return major; }
	int getCWID() const{return CWID;}
	//*** Overloading the << operator to allow the printing of objects
	friend ostream& operator <<(ostream& os, const Student& obj);
};
//*** Overloading the << operator to allow the printing of objects
ostream& operator <<(ostream& out, const Student& obj){
	out << "\nNAME:\t\t " << obj.fName << " " << obj.lName;
	out << "\nMAJOR:\t\t " << obj.major;
	out << "\nCWID:\t\t " << obj.CWID;
	out << "\nYEAR:\t\t " << obj.year;
	out << "\nDOB:\t\t " << obj.DOB;
	return out;
}

int main(){
	//creating a linked list
	list <string> stringlist;
	cout << "List size = " << stringlist.size() << endl;

//INSERT
	//loading items into linked list
	stringlist.push_front("First Entry");
	stringlist.push_back("Another one");
	stringlist.push_front("Team Kobe");

	cout << "\nAdded 3 items into list." << endl;
	cout << ".size() = " << stringlist.size() << endl << endl;

	//printing all items in order
	for(list<string>::iterator i = stringlist.begin(); i != stringlist.end(); i++){
		cout << *i << "\n";
	}
	cout << "\n.sort() "<< endl;
	stringlist.sort();

	//printing all itmes in sorted order
	for(list<string>::iterator i = stringlist.begin(); i != stringlist.end(); i++){
		cout << *i << "\n";
	}

//SEARCH
	//searching for a item in list
	cout << "\nSeaching for Team Kobe. Does this item exist?" << endl;
	bool found = false;				//create a trigger
	for (auto i : stringlist){
			if(i == "Team Kobe") { cout<< "FOUND " << i << " in the List."<< endl; found = true;}
	}
	if(!found) { cout << "Couldn't find item" << endl;}

//DELETE
	stringlist.clear();
	// or create loop and delete one by one

//*************************************************************//
//******************* Creating Student List *******************//
//*************************************************************//

	cout << "\nCreating new List, of type Student." << endl;
	list<Student> listSt;

	//creating 5 student objects
	Student a("Daniel", "Walsh", "(09/29/93)", "CompSci", 8876536, 3);
	Student b("Junyu", "Huang", "(03/22/89)", "Grad", 8873653, 5);
	Student c("Justin", "Yoo", "(09/01/95)", "Business", 8876998, 2);
	Student d("John", "Yoo", "(02/12/97)", "CompSci", 8776354, 2);
	Student e("Kim", "Jones", "(01/30/94)", "Business", 8554631, 2);

//INSERT
	//adding Students to list		push_front & _back
	listSt.push_back(a);
	listSt.push_front(b);
	listSt.push_back(c);
	listSt.push_front(d);
	listSt.push_back(e);

	//printing all items in list
	//for(auto i: listSt)			//(list<string>::iterator i = stringlist.begin(); i != stringlist.end(); i++)
		//cout << i << endl;			//cout << *i << endl;

	//using .front function to show first item in list
	cout << "\n.front() = " << listSt.front() << endl;

//SEARCH
	//searching for a student in list
	cout << "\nSeaching for CWID of 8554631. Does this Student exist?" << endl;
	found = false;				//reset to false
	for (auto i : listSt){
			if(i.getCWID() == 8554631) { cout<< "FOUND " << i.getName()<< ", by the CWID."<< endl; found = true;}
	}
	if(!found) { cout << "Couldn't find CWID" << endl;}

//DELETE
	listSt.clear();
	// or create loop and delete one by one


	cout<<"\nSingly/Dbly Linked List (STL: list):\n"<<"\tAVG Case:"<<"\n\tAccress"<<"\tSearch"<<"\tInsert"<<"\tDelete"<<"\n\tO(n)"<<"\tO(n)"<<"\tO(1)"<<"\tO(1)";
	cout<<"\n\tWORST Case:"<<"\n\tAccress"<<"\tSearch"<<"\tInsert"<<"\tDelete"<<"\n\tO(n)"<<"\tO(n)"<<"\tO(1)"<<"\tO(1)";
}
