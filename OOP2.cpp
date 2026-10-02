#include<iostream>
using namespace std;
class Products {
	float price;
	string name;
	int quantity;
	public:
	Products(float p=0.0, string n="n0", int q=0);
	float total();
	void output();
};

Products::Products(float p, string n, int q) {
	price = p;
	name = n;
	quantity = q;
}

float Products::total() {
return price * quantity;	
}

class ShoppingCart {
	string customer_name;
	float total_amount;
	Products p[10];
	
	public:
		ShoppingCart(string c="no", float t=0.0, Products pi[]=0, int i=0);
		void setname(string n);
		float showtotal(int i);
		void addproduct(string c, float t, int j, int i);
		void output(int j);
};
void ShoppingCart::setname(string n) {
	customer_name = n;	
}

ShoppingCart::ShoppingCart(string c, float t, Products pi[], int i) {
			customer_name = c;
			total_amount = t;
			
			for (int j=0 ; j<i ; j++) {
				p[j] = pi[j];
			}
}
ShoppingCart s;

void ShoppingCart::addproduct(string c, float t, int j, int i)
 {
 	p[i] = Products(t,c,j);
}

void ShoppingCart::output(int j) {
	float total = 0;
	cout << "Customer Name: " << customer_name << endl;
	cout << endl;
	
	for (int i=0 ; i<j ; i++) {
	cout << "---- Product No: " << i+1 <<"-----" << endl;
	p[i].output();
	
	total += p[i].total();
	cout << endl;
   }
   cout << "Your Total Bill is " << total << endl;
}

void Products::output() {
		cout << "Product Name: " << name << endl;
		cout << "Product Quantity: " << quantity <<endl;
		cout << "Each Product Price: " << price << endl;
		cout << "Total Price: " << total() << endl;
}

float ShoppingCart::showtotal(int i) {
	
	float total_amount = 0;
	
	for (int j=0 ; j<i ; j++) {
		total_amount += p[j].total();
	}
	return total_amount;
}
	
void customerdetails(int total) {
	string name, pname;
	int q;
	float price;
	
	
	cout << "Customer Name: ";
	cin >> name;
	
		s.setname(name);
		
	for (int j=0 ; j<total ; j++) {
	cout << "PRODUCT NO: " << j+1 << endl;
	
	cout << "Product Name: ";
	cin >> pname;
	
	cout << "Product Price: ";
	cin >> price;
	
	cout << "Product Quantity: ";
	cin >> q;
	
	s.addproduct(pname, price, q, j);
	}
}


int main() {
	int count;
	
	cout << "How many products: ";
	cin >> count;
	
	cout << "ADD TO CART" << endl;
	
	customerdetails(count);
	

	cout << "\n======================" << endl << endl;
	cout << "       DETAILS" << endl;
	
	s.output(count);
   }