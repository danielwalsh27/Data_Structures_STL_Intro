#include <iostream>
#include <unordered_map>
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
	int getYear() const{return year;}

	//cannot use only hash function, when values are unique they must compare using
	//this comparison operator used for students
	bool operator==(const Student &s) const{
		return (fName == s.fName && lName == s.lName && DOB == s.DOB
				&& major == s.major && CWID == s.CWID && year == s.year);
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

// *** requiring this student object to hash item. Hash by CWID
template<>
struct hash<Student>{
  size_t operator()(const Student & obj) const{
	  return 33 * obj.getCWID();
  }
};

/*
namespace std{
    template <>
    struct hash<Student>{
        size_t operator()( const Student& s ) const{
 // http://stackoverflow.com/a/1646913/126995
            size_t res = 17;
            res = res * 31 + hash<string>()( s.getName() );
            res = res * 31 + hash<string>()( s.getDOB() );
            res = res * 31 + hash<string>()( s.getMajor() );
            res = res * 31 + hash<int>()( s.getCWID() );
            res = res * 31 + hash<int>()( s.getYear() );
            return res;
        }
    };
}
*/


//setting prototypes
void hashTable1();
void hashTable2(Student a,Student b,Student c);
void hashTable3(Student a,Student b,Student c,Student d,Student e,Student f);

int main(){
	Student a("Daniel", "Walsh", "(09/29/93)", "CompSci", 8876536, 3);
	Student b("Junyu", "Huang", "(03/22/89)", "Grad", 8873653, 5);
	Student c("Justin", "Yoo", "(07/12/95)", "Business", 8776355, 2);
	Student d("Anthony", "Goosens", "(03/12/95)", "Kines", 8879063, 2);
	Student e("Adan", "Price", "(03/03/94)", "Comm", 9883763, 3);
	Student f("William", "Stegs", "(06/09/92)", "CompSci", 7736353, 2);

	//map use with primitive types
	hashTable1();
	//map using user defined objects as value
	hashTable2(a,b,c);
	//map using user defined objects as key
	hashTable3(a,b,c,d,e,f);

	cout<<"\nHash Table (STL: unordered_map):\n"<<"\tAVG Case:"<<"\n\tAccress"<<"\tSearch"<<"\tInsert"<<"\tDelete"<<"\n\tN/A"<<"\tO(1)"<<"\tO(1)"<<"\tO(1)";
	cout<<"\n\tWORST Case:"<<"\n\tAccress"<<"\tSearch"<<"\tInsert"<<"\tDelete"<<"\n\tN/A"<<"\tO(n)"<<"\tO(n)"<<"\tO(n)";
}

void hashTable1(){
	//creating Hash Table
	cout << "\t\t****\t User Primitive Types for Hash Table \t****" << endl;
	cout << "\t\t****\t unordered_map <int,string> myHT \t****" << endl;
	unordered_map <int, string> myHT;

//INSERT
	myHT[0] = "First Entry";
	myHT[1] = "what index?";
	myHT[2] = "seeplusplus";
	myHT[3] = "wonderful word";
	myHT[6] = "asd";
	myHT[12] = "MacBook";
	cout << "Size = " << myHT.size() << endl;

//ACCESS
	//using at() function to access key directly
	cout << "**Using the .at(2) function** = " << myHT.at(2) << endl;

//SEARCH
	//using .find method for AVL tree
	cout << "\n\tSearching through the DS using avltree.find(<int(index)>)" << endl;
	unordered_map<int,string>::iterator itty;
	itty = myHT.find(2);
	if(itty != myHT.end())	//if found then it will stop and not reach end
		cout << "FOUND KEY(2) = " << itty->second << endl;
	else							//reached end, item not found
		cout << "Couldn't find " << itty->first << endl;

	//three examples of for loops and how to use them
		//for(int i = 0; i < myHT.size(); i++)
		//	cout << myHT[i] << "\n";
		//for(auto i : myHT)
		//	cout << i.first << " " << i.second << "\n";
	for(unordered_map<int,string>::iterator it = myHT.begin(); it != myHT.end(); it++)
		cout << it->first << " " << it->second << endl;

//NOTE:LOAD FACTOR IS SO LOW BECAUSE IT GOT A KEY OF 12 AND EXPANDED THE SIZE

	//myHT.rehash(10);
	cout << "\nload_factor = (size / bucket_count)" << endl;
	cout << "size         = "<< myHT.size() << endl;
	cout << "bucket_count = "<< myHT.bucket_count() << endl;
	cout << "load_factor  = "<< myHT.load_factor() << endl;
	//myHT.rehash(15);
	cout << "\nRehashed to 15 \nload_factor = (size / bucket_count)" << endl;
	cout << "size         = "<< myHT.size() << endl;
	cout << "bucket_count = "<< myHT.bucket_count() << endl;
	cout << "load_factor  = "<< myHT.load_factor() << endl;

	for (int i=0; i<myHT.bucket_count(); i++) {
		cout << "Bucket " << i << " contains: ";
		for(auto it = myHT.begin(i); it !=myHT.end(i); it++)
			cout << "[" << it->first << ":" << it->second << "] ";
		cout << "\n";
	 }

//DELETE
	myHT.clear();
	// or create loop and delete one by one
}



void hashTable2(Student a,Student b,Student c){
	//creating Hash Table
	cout << "\n\t\t****\t User Defined Types for Value \t\t****" << endl;
	cout << "\t\t****\t unordered_map <string,Student> studentHT \t****" << endl;
	unordered_map <string,Student> studentTable;

//INSERT
	//loading Map using array type syntax
	studentTable["Daniel"] = a;	studentTable["Junyu"] = b;	studentTable["Justin"] = c;

	//iterating through Map
	for(unordered_map<string,Student>::iterator it = studentTable.begin(); it != studentTable.end(); it++){
			cout << "First: " << it->first << endl;
			cout << "Second: " << it->second.getCWID() << endl;
	}

//ACCESS
	//using at() function to access key directly
	cout << "\n**Using the .at('Junyu') function** \t" << studentTable.at("Junyu") << endl;

//SEARCH
	//using .find method to on studentTable
	cout << "\n\tSearching through the DS using studentTable.find(<string(name)>)" << endl;
	unordered_map<string,Student>::iterator itty;
	itty = studentTable.find("Daniel");
	if(itty != studentTable.end())	//if found then it will stop and not reach end
		cout << "FOUND KEY = Daniel" << itty->second << endl;
	else							//reached end, item not found
		cout << "Couldn't find " << itty->first << endl;

//DELETE
	studentTable.clear();
	// or create loop and delete one by one
}


void hashTable3(Student a,Student b,Student c,Student d,Student e,Student f){
	//creating Map
	cout << "\n\t\t****\t User Defined Types for Key \t\t****" << endl;
	cout << "\t\t****\t unordered_map<Student,string> stdntHshTble \t****" << endl;
	unordered_map <Student,string> stdntHshTble;

//INSERT
	//loading Map by creating a pair, then loading the pairs first and second, then inserting
	//loading Map by crating pair in insert function, adding student and string in parameters
	pair<Student,string> p;
	stdntHshTble[a] = "Daniel";
	stdntHshTble[b] = "Junyu";
	p.first = c;		p.second = "Justin";		stdntHshTble.insert(p);
	p.first = d;		p.second = "Anthony";	stdntHshTble.insert(p);
	stdntHshTble.insert(pair<Student,string>(e, "Adan"));
	stdntHshTble.insert(pair<Student,string>(f, "William"));

//ACCESS
	//using at() function to access key directly
	cout << "**Using the .at(c) function** \t" << stdntHshTble.at(b) << endl;

	//iterating through Map
	for(unordered_map<Student,string>::iterator it = stdntHshTble.begin(); it != stdntHshTble.end(); it++){
			cout << "First: " << it->first.getCWID() << endl;
			cout << "Second: " << it->second << endl;
	}

//SEARCH
	//using .find method to on NameMap
	cout << "\n\tSearching through the DS using stdntHshTble.find(<StudentObject>)" << endl;
	unordered_map<Student,string>::iterator itty;
	itty = stdntHshTble.find(c);
	if(itty != stdntHshTble.end())	//if found then it will stop and not reach end
		cout << "FOUND CWID = 8879063, it belongs to " << itty->second << endl;
	else						//reached end, item not found
		cout << "Couldn't find :" << itty->first;

//DELETE
	stdntHshTble.clear();
	// or create loop and delete one by one
}




