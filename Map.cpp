//uses objects as keys, objects as values, overloaded < operator to allow objs and define how to store them
//uses .at and .find functions within STL, & heavy use of iterators

#include <iostream>
#include <map>
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

	//*** Overloaded the < operator to allow objects to be used as the key
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
void map1();
void map2(Student a,Student b,Student c);
void map3(Student a,Student b,Student c,Student d,Student e,Student f);

int main(){
	//creating 6 student objects for map2 & map3
	Student a("Daniel", "Walsh", "(09/29/93)", "CompSci", 8876536, 3);
	Student b("Junyu", "Huang", "(03/22/89)", "Grad", 8873653, 5);
	Student c("Justin", "Yoo", "(07/12/95)", "Business", 8776355, 2);
	Student d("Anthony", "Goosens", "(03/12/95)", "Kines", 8879063, 2);
	Student e("Adan", "Nevarez", "(03/03/94)", "Comm", 9883763, 3);
	Student f("William", "Price", "(06/09/92)", "CompSci", 7736353, 2);

	//map use with primitive types
	map1();
	//map using user defined objects as value
	map2(a,b,c);
	//map using user defined objects as key
	map3(a,b,c,d,e,f);

	cout<<"\n\nAVL Tree (STL- map):\n"<<"\tAVG Case:"<<"\n\tAccress"<<"\tSearch"<<"\tInsert"<<"\tDelete"<<"\n\tO(lg(n))"<<"\tO(lg(n))"<<"\tO(lg(n))"<<"\tO(lg(n))";
	cout<<"\n\tWORST Case:"<<"\n\tAccress"<<"\tSearch"<<"\tInsert"<<"\tDelete"<<"\n\tO(lg(n))"<<"\tO(lg(n))"<<"\tO(lg(n))"<<"\tO(lg(n))";
}//end of main


void map1(){
	//creating Map
	cout << "\t\t****\t Using Primitive Types for Map \t****" << endl;
	cout << "\t\t****\t map <int, string> avltree \t****" << endl;
	map <int, string> avltree;

//INSERT
	//loading avltree
	avltree[0] = "The Office";
	avltree[1] = "Entourage";
	avltree[2] = "Parks and Rec";

//ACCESS
	//using at() function to access key directly
	cout << "**Using the .at(2) function** = " << avltree.at(2) << endl;

	//three examples of for loops and how to use them
	for(int i = 0; i < avltree.size(); i++)			//for(auto i : avltree)
		cout << avltree[i] << "\n";					//	cout << i.first << " " << i.second << "\n";

	//for(map<int,string>::iterator it = avltree.begin(); it != avltree.end(); it++)
	//	cout << it->first << " " << it->second << endl;

//SEARCH
	//using .find method for AVL tree
	cout << "\n\tSearching through the DS using avltree.find(<int(index)>)" << endl;
	map<int,string>::iterator itty;
	itty = avltree.find(2);
	if(itty != avltree.end())	//if found then it will stop and not reach end
		cout << "FOUND KEY(2) = " << itty->second << endl;
	else							//reached end, item not found
		cout << "Couldn't find " << itty->first << endl;

//DELETE
	avltree.clear();
	// or create loop and delete one by one
}


void map2(Student a,Student b,Student c){
	//creating Map
	cout << "\n\t\t****\t User Defined Types for Value \t****" << endl;
	cout << "\t\t****\t map<string,Student> NameMap \t****" << endl;
	map<string,Student> NameMap;

//INSERT
	//loading Map using array type syntax
	NameMap["Daniel"] = a;	NameMap["Junyu"] = b;	NameMap["Justin"] = c;

	//iterating through Map
	for(map<string,Student>::iterator it = NameMap.begin(); it != NameMap.end(); it++){
			cout << "First: " << it->first << endl;
			cout << "Second: " << it->second.getCWID() << endl;
	}

//ACCESS
	//using at() function to access key directly
	cout << "\n**Using the .at('Junyu') function** \t" << NameMap.at("Junyu") << endl;

//SEARCH
	//using .find method to on NameMap
	cout << "\n\tSearching through the DS using NameMap.find(<string(name)>)" << endl;
	map<string,Student>::iterator itty;
	itty = NameMap.find("Daniel");
	if(itty != NameMap.end())	//if found then it will stop and not reach end
		cout << "FOUND KEY = Daniel" << itty->second << endl;
	else							//reached end, item not found
		cout << "Couldn't find " << itty->first << endl;

//DELETE
	NameMap.clear();
	// or create loop and delete one by one
}


void map3(Student a,Student b,Student c,Student d,Student e,Student f){
	//creating Map
	cout << "\n\t\t****\t User Defined Types for Key \t****" << endl;
	cout << "\t\t****\t map<Student,string> stmap \t****" << endl;
	map<Student,string> stmap;

//INSERT
	//loading Map by creating a pair, then loading the pairs first and second, then inserting
	//loading Map by crating pair in insert function, adding student and string in parameters
	pair<Student,string> p;
	stmap[a] = "Daniel";
	stmap[b] = "Junyu";
	p.first = c;		p.second = "Justin";		stmap.insert(p);
	p.first = d;		p.second = "Anthony";	stmap.insert(p);
	stmap.insert(pair<Student,string>(e, "Adan"));
	stmap.insert(pair<Student,string>(f, "William"));

//ACCESS
	//using at() function to access key directly
	//cout << "**Using the .at(c) function** \t" << NameMap.at(b) << endl;

	//iterating through Map
	for(map<Student,string>::iterator it = stmap.begin(); it != stmap.end(); it++){
			cout << "First: " << it->first.getCWID() << endl;
			cout << "Second: " << it->second << endl;
	}

//SEARCH
	//using .find method to on NameMap
	cout << "\n\tSearching through the DS using stmap.find(<StudentObject>)" << endl;
	map<Student,string>::iterator itty;
	itty = stmap.find(c);
	if(itty != stmap.end())	//if found then it will stop and not reach end
		cout << "FOUND CWID = 8879063, it belongs to " << itty->second << endl;
	else						//reached end, item not found
		cout << "Couldn't find :" << a;

//DELETE
	stmap.clear();
	// or create loop and delete one by one
}
