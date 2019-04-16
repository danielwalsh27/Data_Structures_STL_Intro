//using vector STL, showing use of .push_back, .front, .at, .pop_back, .size, .capacity, and iterators
//also showing use of user defined types, Objects.

#include <vector>
#include <iostream>
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
	//creating string vector
	vector<string> myVect;

	//displaying size and capacity
	cout << "Vector size = \t\t" << myVect.size() << endl;
	cout << "Vector capacity = \t" << myVect.capacity() << endl << endl;

//INSERT
	//myVect[0] = 101;				//cannot write into 0th bc it doesn't exist yet
	myVect.push_back("Entry number won");
	myVect.push_back("Larry > Lebron");
	myVect.push_back("Now size will be four");
	//myVect[3] = 100;   < -- wont work		//will only write into items that have already occupied

	cout << "Added 3 items. " << endl;
	cout << "Vector size = \t\t" << myVect.size() << endl;
	cout << "Vector capacity = \t" << myVect.capacity() << endl;

//ACCESS
	cout << myVect[1] << endl;
	cout << myVect.front() << endl; // prints the 0th index

	//how to print array using standard for loop
	for(int i = 0; i < myVect.size(); i++)
		cout << "\t" << myVect.at(i) << endl;

//SEARCH
	//searching for an item in our Vector
	cout << "\nSeaching for 'Zeroth Index'. Is this in the Vector?" << endl;
	bool found = false;
	for (auto i : myVect){
		if(i == "Zeroth Index") { cout<< "FOUND " << i<< endl;  found = true;}
	}
	if(!found){ cout<< "Couldn't find item" << endl; }

	//deleting values 3, size will change, capacity wont..
	cout << "\nDeleted 3 items. What is new size and capacity?" << endl;
	myVect.pop_back();
	myVect.pop_back();
	myVect.pop_back();
	cout << "Vector size = \t\t" << myVect.size() << endl;
	cout << "Vector capacity = \t" << myVect.capacity() << endl;

	cout << "\n.resize(5); What is new size and capacity?" << endl;
	myVect.resize(5);	//this adjusts size not capacity, why would we use this?
	cout << "Vector size = \t\t" << myVect.size() << endl;
	cout << "Vector capacity = \t" << myVect.capacity() << endl;

	cout << "\n.shrink_to_fit(); What is new size and capacity?" << endl;
	myVect.shrink_to_fit();  //this adjusts capacity not size, why would we use this?
	cout << "Vector size = \t\t" << myVect.size() << endl;
	cout << "Vector capacity = \t" << myVect.capacity() << endl;

//DELETE
	myVect.clear();
	// or create loop and delete one by one

//*************************************************************//
//******************** Creating New Vector ********************//
//*************************************************************//

	cout << "\nCreating new Vector, of type Student. Empty." << endl;
	//creating new student vector
	vector <Student> objVec;

	//creating 5 student objects
	Student a("Daniel", "Walsh", "(09/29/93)", "CompSci", 8876536, 3);
	Student b("Junyu", "Huang", "(03/22/89)", "Grad", 8873653, 5);
	Student c("Justin", "Yoo", "(09/01/95)", "Business", 8876998, 2);
	Student d("John", "Yoo", "(02/12/97)", "CompSci", 8776354, 2);
	Student e("Kim", "Jones", "(01/30/94)", "Business", 855463, 2);

//INSERT
	//adding items to DS
	objVec.push_back(a);
	objVec.push_back(b);
	objVec.push_back(c);
	objVec.push_back(d);
	objVec.push_back(e);
	cout << "\nAdded 5 Student Objects. What is new size and capacity?" << endl;
	cout << "Vector size = \t\t" << objVec.size() <<endl;
	cout << "Vector capacity = \t" << objVec.capacity() << endl;

//ACCESS
	cout << "Accessing object directly: cout <<  objVec[1]; ";
	cout << objVec[1] << endl;

//SEARCH
	//searching for a student in vector
	cout << "\nSeaching for CWID of 8776345. Does this Student exist?" << endl;
	found = false;		//reset to false
	for (auto i : objVec){
			if(i.getCWID() == 8776354) { cout<< "FOUND " << i.getName()<< ", by the CWID."<< endl; found = true;}
	}
	if(!found) { cout << "Couldn't find CWID" << endl;}

	/*
	//printing student objects
	for(int i = 0; i < objVec.size(); i++)
		cout << objVec[i] << "\t";
	for(auto i = objVec.begin(); i != objVec.end(); i++){ //vector<string>::iterator i....
		cout << *i << "\n";
	}
	*/

//DELETE
	objVec.clear();
	// or create loop and delete one by one

	cout<<"\nVector (STL: vector):\n"<<"\tAVG Case:"<<"\n\tAccress"<<"\tSearch"<<"\tInsert"<<"\tDelete"<<"\n\tO(1)"<<"\tO(n)"<<"\tO(1)AM"<<"\tO(n)";
	cout<<"\n\tWORST Case:"<<"\n\tAccress"<<"\tSearch"<<"\tInsert"<<"\tDelete"<<"\n\tO(1)"<<"\tO(n)"<<"\tO(n)"<<"\tO(n)";
	return 0;
}

// capacity and size = 0
// capacity restructures = { 0, 1, 2, 4, 8, 16, 32, 64, 128, ... } never gets smaller
// why would we use the resize() function? doesn't adjust capacity
// push_back worked in for loop
// myVect[index]= value;  didn't work in the for loop
// myVect[index]= value;  works outside of loop


// Access = 	O(1)		cout << myVect[10];
// Insert = 	O(1)		myVect[index] = value;
// Delete = 	O(N)		Find item O(N), delete it, then copy
					//run self test to see if its N^2 or N
// Search = 	O(N)		for (auto i : myVect){ if(i.value = input) { return true; } }
