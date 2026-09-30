#include<iostream>
using namespace std;

class Course {
	public:
	int code;
	string name;
	double feesper;
	int credithours;
	
	Course(int x = 0,string f = "no",double fee = 0.0, int hours = 0);
	double totalfee();
};



class Student {
	private:
	int id;
	string name;
	
	public:
		Course c[5];
		int total_courses;
		void takedata();
		Student(int x = 0,string n = "not",int total = 0);
		void display(int n,Student s[]);
};


class FeeRecord {
	double feetotal;
	
	public:
		Student s[22];
		FeeRecord(Student);
		
	
		double gettotalfee() {
			return feetotal;
		}
};



FeeRecord::FeeRecord(Student s) {
	feetotal = 0 ;
	
	for (int j=0 ; j<s.total_courses ; j++) {
		feetotal += s.c[j].totalfee();
	}
}



Course::Course(int x,string f,double fee,int hours) {
	 code = x;
	 name = f;
	 feesper = fee;
	 credithours = hours;
}


Student::Student(int x,string n,int total) {
	id = x;
	name = n;
	total_courses = total;
	c[total];
}



double Course::totalfee() {
	return credithours * feesper;
}


void Student::takedata() {

}


int main() {

	Student s[50],s1;
	Course c[8];
	int n , id , no , code , hours ;
	double feeper;
	string name , course;


	cout << "How Many Students ";
	cin >> n;
	s[n];
	for (int i=0 ; i<n ; i++) {
		cout << "--- STUDENT DETAILS ---" << endl;
		
		cout << "Student Name:";
		cin >> name;
		
		cout << "Student ID:";
		cin >> id;
		
		cout << "Number of Courses:";
		cin >> no;
		
		s[i] = Student(id,name,no);
		
		for (int j=0 ; j<no ; j++) {
		
		cout << "--- COURSE DETAILS " << j+1 << "---" << endl;
		cout << "Course Code:";
		cin >> code;
		
		cout << "Course Name (no space):";
		cin >> course;
		
		cout << "Course Credit Hours:";
		cin >> hours;
		
		cout << "Course Fee Per Credit Hour:";
		cin >> feeper;
		
		s[i].c[j] = Course(code,course,feeper,hours);
	}
	cout << endl;
	}
	
	s1.display(n,s);
	return 0;
}
	


void Student::display(int n,Student s[]) {
	FeeRecord f(0.0);
	double a;
	    cout << endl;
		cout << "-------- ALL STUDENT DETAILS --------" << endl;
	    for (int i=0 ; i<n ; i++) {
		cout << "Student Number:" << i+1 << endl;
		cout << "Student Name:" << s[i].name << endl;
		cout << "Student ID:" << s[i].id << endl;
		cout << "Number of Courses:" << s[i].total_courses << endl;
		cout << "--- COURSE DETAILS " << "---" << endl;
		
		for (int j=0 ; j<s[i].total_courses ; j++) {
		cout << "Course:" << j+1 << endl;
		cout << "Course Code:" << s[i].c[j].code << endl;
		cout << "Course Name:" << s[i].c[j].name << endl;
		cout << "Course Credit Hours:" << s[i].c[j].credithours << endl;
		cout << "Course Fee Per Credit Hour:" << s[i].c[j].feesper << endl;
		cout << "Fee For This Course:" << s[i].c[j].totalfee();
		cout << endl;
		}
		
		f = FeeRecord(s[i]);
		cout << "Total fee:" << f.gettotalfee() << endl;
		cout << "====================\n" << endl;
		
}
}
