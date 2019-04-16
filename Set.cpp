//the Set Data Structure
//uses .find functions within STL, & heavy use of iterators
//overloaded the < operator, due to its BST implementation its needs how to sort

#include <iostream>
#include <set>
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
	int getCWID() const{return CWID;}

	//*** Overloaded the < operator to allow objects to be used in the Set
	//*** this function will sort the Students by their CWID
	bool operator <(const Student& obj) const{
		if(obj.CWID < this->CWID)
			return true;
		return false;
	}

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


//setting prototypes
void set1();
void multiset2();
void set3();

int main(){
	//set using integeres
	set1();
	//multiset using strings
	multiset2();
	//set using User defined types
	set3();

	cout<<"\n\nSet (STL- set):\n"<<"\tAVG Case:"<<"\n\tAccess"<<"\tSearch"<<"\tInsert"<<"\tDelete"<<"\n\t-"<<"\tO(lg(n))"<<"\tO(lg(n))"<<"\tO(lg(n))";
	cout<<"\n\tWORST Case:"<<"\n\tAccess"<<"\tSearch"<<"\tInsert"<<"\tDelete"<<"\n\t-"<<"\tO(lg(n))"<<"\tO(lg(n))"<<"\tO(lg(n))";
}//end of main


void set1(){
	//creating set
	cout << "\t\t****\t Using Primitive Types for Set \t****" << endl;
	cout << "\t\t****\t set <int> intSet \t\t****" << endl;
	set <int> intSet;

//INSERT
	//loading intSet
	intSet.insert(3);
	intSet.insert(5678);
	intSet.insert(5272);
	intSet.insert(66);
	intSet.insert(323);
	intSet.insert(39);
	intSet.insert(39);		//didn't work, doesn't allow repeat values
	intSet.insert(1888);

	//two examples of for loops and how to use them
	for(set<int>::iterator it = intSet.begin(); it != intSet.end(); it++)		//for(int i : intSet)
		cout << *it << endl;													//		cout << "Value: " << i << "\n";

//SEARCH
	//using .find method for set
	cout << "\n\tSearching through the DS using intSet.find(<int(index)>)" << endl;
	int search = 2;
	set<int>::iterator itty;
	itty = intSet.find(search);
	if(itty != intSet.end())	//if found then it will stop and not reach end
		cout << "FOUND KEY(2) = " << *itty << endl;
	else							//reached end, item not found
		cout << "Couldn't find " << *itty << endl;

//DELETE
	intSet.clear();
	// or create loop and delete one by one
}


void multiset2(){
	//creating multiset
	cout << "\n\t\t****\t Using Primitive Types for multiSet ****" << endl;
	cout << "\t\t****\t multiset<string> NameMap \t****" << endl;
	multiset<string> stringSet;

//INSERT
	//loading set with strings
	stringSet.insert("Daniel");
	stringSet.insert("Junyu");
	stringSet.insert("Allen");
	stringSet.insert("Ryan");
	stringSet.insert("Oscar");
	stringSet.insert("Mark");
	stringSet.insert("Allen");

	//iterating through set
	for(set<string>::iterator it = stringSet.begin(); it != stringSet.end(); it++)  		//for(string  i : intSet)
			cout << "Value: " << *it << endl;											//		cout << i << "\n";

//SEARCH
	//using .find method to on stringSet
	cout << "\n\tSearching through the DS using stringSet.find(<string(name)>)" << endl;
	string search = "Daniel";
	set<string>::iterator itty;
	itty = stringSet.find(search);
	if(itty != stringSet.end())	//if found then it will stop and not reach end
		cout << "FOUND KEY " << *itty << endl;
	else							//reached end, item not found
		cout << "Couldn't find " << *itty << endl;

//DELETE
	stringSet.clear();
	// or create loop and delete one by one
}


void set3(){
	//creating Set
	cout << "\n\t\t****\t User Defined Types for Set \t****" << endl;
	cout << "\t\t****\t set<Student> objSet \t\t****" << endl;
	set<Student> objSet;

	//creating 6 student objects for student set
	Student a("Daniel", "Walsh", "(09/29/93)", "CompSci", 8876536, 3);
	Student b("Junyu", "Huang", "(03/22/89)", "Grad", 8873653, 5);
	Student c("Justin", "Yoo", "(07/12/95)", "Business", 8776355, 2);
	Student d("Anthony", "Goosens", "(03/12/95)", "Kines", 8879063, 2);
	Student e("Adan", "Nevarez", "(03/03/94)", "Comm", 9883763, 3);
	Student f("William", "Price", "(06/09/92)", "CompSci", 7736353, 2);

//INSERT
	//loading set
	objSet.insert(a);
	objSet.insert(b);
	objSet.insert(c);
	objSet.insert(d);
	objSet.insert(e);
	objSet.insert(f);

	//iterating through set
	//for(set<Student>::iterator it = objSet.begin(); it != objSet.end(); it++)
	//		cout << "Value: " << *it << endl;


//	Q: IF ITS SORTED BY THE CWID, AND WE PASS IN AN OBJ FOR SEARCHING. DOES IT CONDUCT A LINEAR SEARCH OR DOES IT GRAB THE OBJS
// 		CWID AND USE THAT FOR ITS SEARCHING?
//		BIG DIFFERENCE IN O(N) vs O(log(N))


//SEARCH
	//using .find method to on Student Set
	cout << "\n\tSearching through the DS using objSet.find(<StudentObject>)" << endl;
	set<Student>::iterator itty;
	itty = objSet.find(c);
	if(itty != objSet.end())	//if found then it will stop and not reach end
		cout << "FOUND: " << *itty << endl;
	else
		cout << "Couldn't find: " << *itty << endl; //reached end, item not found

//DELETE
	objSet.clear();
	// or create loop and delete one by one
}

//Set
//sorted, only unique numbers, inserted or deleted not modified, traverse with iterators
//use BST

//Multiset
//sorted, allows multiples of nums, traverse wth iterators, use BST
