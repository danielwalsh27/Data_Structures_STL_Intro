//Linked Listed Implementation
//Queue uses .front()

#include <iostream>
#include <queue>
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
	//create queue
	queue <string> myqueue, copyQ;

//INSERT
	myqueue.push("My Entry");
	myqueue.push("USMC>USN");
	myqueue.push("Whos the best Basketball player ever?");
	myqueue.push("My more");
	myqueue.push("My another");
	myqueue.push("My trythis");

//SEARCH
	copyQ = myqueue;
	for(int i = myqueue.size(); i > 0; i--){			//size changed after each pop, so cant inc up as it incs down...
		if(myqueue.front() == "My Entry")
			cout << "Found item" << "\n";
		myqueue.pop();
	}
	//copy items to copy queue before search, then copy back to restore
	myqueue = copyQ;

//REMOVE
	for(int i = myqueue.size(); i > 0; i--){
		cout << myqueue.front() << endl;
		myqueue.pop();
	}

	//*************************************************************//
	//******************** Creating New Queue  ********************//
	//*************************************************************//

	Student a("Daniel", "Walsh", "(09/29/93)", "Comm", 8876536, 3);
	Student b("Charlie", "Huang", "(03/22/89)", "CompSci", 8873653, 5);
	Student c("Tyler", "Yoo", "(09/01/95)", "Business", 8876998, 2);
	Student d("John", "Smith", "(02/12/97)", "Biology", 8776354, 2);
	Student e("Kim", "Jones", "(01/30/94)", "Math", 855463, 2);

	//create queue
	queue <Student> stuQueue, copyCat;

//INSERT
	stuQueue.push(a);
	stuQueue.push(b);
	stuQueue.push(c);
	stuQueue.push(d);
	stuQueue.push(e);

//SEARCH
	copyCat = stuQueue;
	for(int i = stuQueue.size(); i > 0; i--){			//size changed after each pop, so cant inc up as it incs down...
		if(stuQueue.front().getCWID() == 8776354)
			cout << "Found Student " << stuQueue.front().getName();
		stuQueue.pop();
	}
	//copy items to copy queue, then copy back to standard queue
	stuQueue = copyCat;

//REMOVE
	for(int i = stuQueue.size(); i > 0; i--){
		cout << stuQueue.front() << endl;
		stuQueue.pop();
	}

	cout<<"Queue (STL: queue):\n"<<"\tAVG Case:"<<"\n\tAccress"<<"\tSearch"<<"\tInsert"<<"\tDelete"<<"\n\tO(n)"<<"\tO(n)"<<"\tO(1)"<<"\tO(1)";
	cout<<"\n\tWORST Case:"<<"\n\tAccress"<<"\tSearch"<<"\tInsert"<<"\tDelete"<<"\n\tO(n)"<<"\tO(n)"<<"\tO(1)"<<"\tO(1)";
}

