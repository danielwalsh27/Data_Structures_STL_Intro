//Linked Listed Implementation
//Stack uses .top()
//

#include <iostream>
#include <stack>
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
	//create Stack
	stack <string> myStack, copyS;

//INSERT
	myStack.push("My Entry");
	myStack.push("USMC>USN");
	myStack.push("Whos the best Basketball player ever?");
	myStack.push("My more");
	myStack.push("My another");
	myStack.push("My trythis");

//SEARCH
	copyS = myStack;
	for(int i = myStack.size(); i > 0; i--){			//size changed after each pop, so cant inc up as it incs down...
		if(myStack.top() == "My Entry")
			cout << "Found item" << "\n";
		myStack.pop();
	}
	//copy items to copy stack before search, then copy back to restore
	myStack = copyS;

//REMOVE
	for(int i = myStack.size(); i > 0; i--){
		cout << myStack.top() << endl;
		myStack.pop();
	}

	//*************************************************************//
	//******************** Creating New Stack  ********************//
	//*************************************************************//

	Student a("Daniel", "Walsh", "(09/29/93)", "CompSci", 8876536, 3);
	Student b("Junyu", "Huang", "(03/22/89)", "Grad", 8873653, 5);
	Student c("Justin", "Yoo", "(09/01/95)", "Business", 8876998, 2);
	Student d("John", "Yoo", "(02/12/97)", "CompSci", 8776354, 2);
	Student e("Kim", "Jones", "(01/30/94)", "Business", 855463, 2);

	//create stack
	stack <Student> stuStack, copyCat;

//INSERT
	stuStack.push(a);
	stuStack.push(b);
	stuStack.push(c);
	stuStack.push(d);
	stuStack.push(e);

//SEARCH
	copyCat = stuStack;
	for(int i = stuStack.size(); i > 0; i--){			//size changed after each pop, so cant inc up as it incs down...
		if(stuStack.top().getCWID() == 8776354)
			cout << "Found Student " << stuStack.top().getName();
		stuStack.pop();
	}
	//copy items to copy stack, then copy back to standard queue
	stuStack = copyCat;

//REMOVE
	for(int i = stuStack.size(); i > 0; i--){
		cout << stuStack.top() << endl;
		stuStack.pop();
	}

	cout<<"Stack (STL: stack):\n"<<"\tAVG Case:"<<"\n\tAccress"<<"\tSearch"<<"\tInsert"<<"\tDelete"<<"\n\tO(n)"<<"\tO(n)"<<"\tO(1)"<<"\tO(1)";
	cout<<"\n\tWORST Case:"<<"\n\tAccress"<<"\tSearch"<<"\tInsert"<<"\tDelete"<<"\n\tO(n)"<<"\tO(n)"<<"\tO(1)"<<"\tO(1)";
}
