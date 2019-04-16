//unsorted_set
//not sorted, only stores unique values, uses Hash table

//unsorted_multiset
//not sorted, allows multiples of nums, can only erase one at a time, uses Hash table


#include <iostream>
#include <unordered_set>
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

void intSet1();
void stringMultiSet2();
void studentSet3();

int main(){
	//hash set of integers
	intSet1();
	//hash multiset of strings
	stringMultiSet2();
	//hash set of students
	studentSet3();


	cout<<"\nHash Set (STL: unordered_set):\n"<<"\tAVG Case:"<<"\n\tAccess"<<"\tSearch"<<"\tInsert"<<"\tDelete"<<"\n\tN/A"<<"\tO(1)"<<"\tO(1)"<<"\tO(1)";
	cout<<"\n\tWORST Case:"<<"\n\tAccess"<<"\tSearch"<<"\tInsert"<<"\tDelete"<<"\n\tN/A"<<"\tO(n)"<<"\tO(n)"<<"\tO(n)";
}

void intSet1(){
	//creating Hash Set
	cout << "\t\t****\t Using Integer for Hash Set \t****" << endl;
	cout << "\t\t****\t unordered_set <int> mySet \t****" << endl;
	unordered_set <int> mySet;

//INSERT
	mySet.insert(16);
	mySet.insert(4);
	mySet.insert(164);
	mySet.insert(6332);
	mySet.insert(16);		//didn't insert, doesn't allow duplicates

	cout << "\nload_factor = (size / bucket_count)" << endl;
	cout << "size         = "<< mySet.size() << endl;
	cout << "bucket_count = "<< mySet.bucket_count() << endl;
	cout << "load_factor  = "<< mySet.load_factor() << endl;

	for (int i=0; i<mySet.bucket_count(); i++) {
		cout << "Bucket " << i << " contains: ";
		for(auto it = mySet.begin(i); it !=mySet.end(i); it++)
			cout << "[" << *it << "] ";
		cout << "\n";
	 }

//SEARCH
	//using .find method for hast Set
	cout << "\n\tSearching through the DS using myMultiSet.find(<int(value)>)" << endl;
	unordered_set<int>::iterator iter;
	iter = mySet.find(12110);
	if(iter != mySet.end())	//if found then it will stop and not reach end
		cout << "FOUND VAL = " << *iter << endl;
	else	 						//reached end, item not found
		cout << "Couldn't find item" << endl;

	iter = mySet.find(1210);
	if(iter != mySet.end())	//if found then it will stop and not reach end
		cout << "FOUND VAL = " << *iter << endl;
	else	 						//reached end, item not found
		cout << "Couldn't find item" << endl;

//DELETE
	mySet.clear();
}

void stringMultiSet2(){
	//creating Hash Multiset
	cout << "\t\t****\t Using Integer for Hash_Multi-Set \t****" << endl;
	cout << "\t\t****\t unordered_multiset <int> myMS \t\t****" << endl;
	unordered_multiset <string> myMultiSet;

	//10 inputs, make of size 20, load factor = 50% full
	myMultiSet.rehash(20);

//INSERT
	myMultiSet.insert("America");
	myMultiSet.insert("USA");
	myMultiSet.insert("Year 1918");
	myMultiSet.insert("USMC > USN");
	myMultiSet.insert("America");
	myMultiSet.insert("USA");
	myMultiSet.insert("California");
	myMultiSet.insert("USMC");
	myMultiSet.insert("USA");
	myMultiSet.insert("Alaska");

	//showing load factor math
	cout << "\nload_factor = (size / bucket_count)" << endl;
	cout << "size         = "<< myMultiSet.size() << endl;
	cout << "bucket_count = "<< myMultiSet.bucket_count() << endl;
	cout << "load_factor  = "<< myMultiSet.load_factor() << endl;

	//for(unordered_multiset<int>::iterator i = myMultiSet.begin(); i != myMultiSet.end(); i++)
	//	cout << *i << "\n";

	//display buckets and lists within buckets
	for (int i=0; i<myMultiSet.bucket_count(); i++) {
		cout << "Bucket " << i << " contains: ";
		for(auto it = myMultiSet.begin(i); it !=myMultiSet.end(i); it++)
			cout << "[" << *it << "] ";
		cout << "\n";
	 }

//SEARCH
	//using .find method for AVL tree
	cout << "\n\tSearching through the DS using myMultiSet.find(<int(value)>)" << endl;
	unordered_multiset<string>::iterator iter;
	iter = myMultiSet.find("Merica");
	if(iter != myMultiSet.end())	//if found then it will stop and not reach end
		cout << "FOUND VAL = " << *iter << endl;
	else	 						//reached end, item not found
		cout << "Couldn't find item" << endl;

	iter = myMultiSet.find("America");
	if(iter != myMultiSet.end())	//if found then it will stop and not reach end
		cout << "FOUND VAL = " << *iter << endl;
	else	 						//reached end, item not found
		cout << "Couldn't find item" << endl;

//DELETE
	myMultiSet.clear();

}

void studentSet3(){
	Student a("Daniel", "Walsh", "(09/29/93)", "CompSci", 8876536, 3);
	Student b("Junyu", "Huang", "(03/22/89)", "Grad", 8873653, 5);
	Student c("Justin", "Yoo", "(07/12/95)", "Business", 8776355, 2);
	Student d("Anthony", "Goosens", "(03/12/95)", "Kines", 8879063, 2);
	Student e("Adan", "Nevarez", "(03/03/94)", "Comm", 9883763, 3);
	Student f("Steven", "Mils", "(06/09/92)", "CompSci", 7736353, 2);

//creating Hash Multiset
	cout << "\t\t****\t Using Integer for Hash_Multi-Set \t****" << endl;
	cout << "\t\t****\t unordered_multiset <int> myMS \t\t****" << endl;
	unordered_set <Student> myMultiSet;

	//6 inputs, make of size 12, load factor = 50% full
	myMultiSet.rehash(12);

//INSERT
	myMultiSet.insert(a);
	myMultiSet.insert(b);
	myMultiSet.insert(c);
	myMultiSet.insert(d);
	myMultiSet.insert(e);
	myMultiSet.insert(f);

	//showing load factor math
	cout << "\nload_factor = (size / bucket_count)" << endl;
	cout << "size         = "<< myMultiSet.size() << endl;
	cout << "bucket_count = "<< myMultiSet.bucket_count() << endl;
	cout << "load_factor  = "<< myMultiSet.load_factor() << endl;

	//for(unordered_multiset<int>::iterator i = myMultiSet.begin(); i != myMultiSet.end(); i++)
	//	cout << *i << "\n";

	//display buckets and lists within buckets
	for (int i=0; i<myMultiSet.bucket_count(); i++) {
		cout << "Bucket " << i << " contains: ";
		for(auto it = myMultiSet.begin(i); it !=myMultiSet.end(i); it++)
			cout << "[" << it->getName() << "] ";
		cout << "\n";
	 }

//SEARCH
	//using .find method for AVL tree
	cout << "\n\tSearching through the DS using myMultiSet.find(<int(value)>)" << endl;
	unordered_multiset<Student>::iterator iter;
	iter = myMultiSet.find(a);
	if(iter != myMultiSet.end())	//if found then it will stop and not reach end
		cout << "FOUND VAL = " << *iter << endl;
	else	 						//reached end, item not found
		cout << "Couldn't find item" << endl;

	iter = myMultiSet.find(c);
	if(iter != myMultiSet.end())	//if found then it will stop and not reach end
		cout << "FOUND VAL = " << *iter << endl;
	else	 						//reached end, item not found
		cout << "Couldn't find item" << endl;

//DELETE
	myMultiSet.clear();

}
