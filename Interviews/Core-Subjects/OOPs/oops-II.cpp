#include <bits/stdc++.h>
using namespace std;

// Encapsulation: It is the wrapping up of data members
// and member functions under a single unit,
// also referred to as class.

// Full Encapsulation: When all the data members and
// member functions are declared as private in a class,
// the class is said to have achieved full encapsulation.

// Advantages of Encapsulation:
// a) Data / Information Hiding.
// b) Code Reusability.
// c) If we want, we can make class "Read Only".
//  [by not declaring getters and setters].
// d) Helps in Unit Testing.

// Inheritance: Ability of a class to inherit data members / member functions
// from another class. The class which inherits is known as child class
// and the class from which it inherits is known as parent class.

// Mode of Inheritance: Specifies what will be the state of each method/data member inside the child class
// after being inherited from the parent class.

//     Parent 			Child 			Final Mode

//     Public			Public			Public
//	   Public			Private			Private
//     Public			Protected		Protected

//     Private			Public			Not Accessible
//	   Private			Private			Not Accessible
//     Private			Protected		Not Accessible

//     Protected			Public			Protected
//	   Protected			Private			Private
//     Protected			Protected		Protected


/*

class Human {
public:
	string name;
	int age, height;

	void setHumanMembers (string name, int age, int height) {
		this->name = name;
		this->age = age;
		this->height = height;
	}
};

class Male : public Human {
public:
	int weight;
	bool bald;

	void setMembers(int weight, bool bald) {
		this->weight = weight;
		this->bald = bald;
	}
};

*/


// Types of Inheritance:

// Single Inheritance: The class inherits from only 1 other class.
// The Male class is inheriting only the Human class.

/*

class Human {
public:
	string name;
	int age, height;

	void setHumanMembers (string name, int age, int height) {
		this->name = name;
		this->age = age;
		this->height = height;
	}

	void speak() {
		cout << "Speaking" << '\n';
	}
};

class Male : public Human {
public:
	int weight;
	bool bald;

	void setMembers(int weight, bool bald) {
		this->weight = weight;
		this->bald = bald;
	}
};


*/


// Multi-level Inheritance: A child class inherits from a parent class, which in-turn has inherited
// from another class and the chain may go on.
// Asian class inherits from Male class, which inherits from Human class.

/*

class Human {
public:
	string name;
	int age, height;

	void setHumanMembers (string name, int age, int height) {
		this->name = name;
		this->age = age;
		this->height = height;
	}

	void speak() {
		cout << "Speaking" << '\n';
	}
};

class Male : public Human {
public:
	int weight;
	bool bald;

	void setMembers(int weight, bool bald) {
		this->weight = weight;
		this->bald = bald;
	}
};

class Asian : public Male {

};

*/


// Multiple Inheritance: A class inheriting from multiple parent classes.
// Indian class inherits both from SouthEastAsian as well as Human class.


class Human {
public:
	string name;
	int age, height;

	void setHumanMembers (string name, int age, int height) {
		this->name = name;
		this->age = age;
		this->height = height;
	}

	void speak() {
		cout << "Speaking" << '\n';
	}
};

class Male : public Human {
public:
	int weight;
	bool bald;

	void setMembers(int weight, bool bald) {
		this->weight = weight;
		this->bald = bald;
	}
};

class Asian : public Male {
	void speakAsian() {
		cout << "Asian Speaking" << '\n';
	}
};

class SouthEastAsian {
public:
	void speakAsian() {
		cout << "South East Asian Speaking" << '\n';
	}
};

class Indian : public SouthEastAsian, public Human {

};


// Hierarchical Inheritance: 1 class serves as base class for more than 1 derived class.
// B inherits A and C inherits A as well. D and E inherit from B.


/*


class A {
public:
	string printA() {
		return "Function A called";
	}
};

class B : public A {
public:
	string printB() {
		return "Function B called";
	}
};

class C : public A {
public:
	string printC() {
		return "Function C called";
	}
};

class D : public B {
public:
	string printD() {
		return "Function D called";
	}
};

class E : public B {
public:
	string printE() {
		return "Function E called";
	}
};


*/


// Hybrid Inheritance: Combination of more than 1 type of inheritance is known as hybrid inheritance.
// The below inheritance combines hirearchical and multiple inheritance.


class A {
public:
	string printA() {
		return "Function A called";
	}
};

class B : public A {
public:
	string printB() {
		return "Function B called";
	}
};

class C : public A {
public:
	string printC() {
		return "Function C called";
	}
};

class D : public B {
public:
	string printD() {
		return "Function D called";
	}
};

class E : public B {
public:
	string printE() {
		return "Function E called";
	}
};

class F {
public:
	string printF() {
		return "Function F called";
	}
};

class G : public C, public F {
public:
	string printG() {
		return "Function G called";
	}
};

class H : public C {
public:
	string printH() {
		return "Function H called";
	}
};



// Inheritance Ambiguity: If 2 classes have methods with same name, then, if a class inherits
// both the classes, an ambiguity arises when calling the method with same name, as to which class's function
// to call? This is resolved using a scope resolution operator.


class Male {
public:
	void speak() {
		cout << "Patriarchy for the win" << '\n';
	}
};

class Female {
public:
	void speak() {
		cout << "Matriarchy for the win" << '\n';
	}
};

class Transgender : public Male, public Female {
public:
	void speak() {
		cout << "Equality shall prevail" << '\n';
	}
};

// Polymorphism: The ability of something to exist in multiple forms is said to be Polymorphism.

// 2 types of Polymorphism:

// Compile Time / Static Polymorphism: 2 types:

// 1) Function Overloading: Existence of multiple functions with same name
// but different combination of argument list.


class functionOverloading {
public:
	void speak(string name) {
		cout << name << " is speaking about Anonymous subject." << '\n';
	}

	void speak() {
		cout << "Anonymous is speaking about Anonymous subject." << '\n';
	}

	void speak(string name, string subject) {
		cout << name << " is speaking about " << subject << '.' << '\n';
	}
};


// 2) Operator Overloading: Using a operator to do a different task than what it is supposed to do.
// For eg, we want to use divide operator to multiply instead.


class operatorOverloading {
public:
	int a;
	void operator/ (operatorOverloading &B) {
		int value1 = this->a;
		int value2 = B.a;
		cout << value1 << " / " << value2 << " = " << (value1 * value2) << '\n';
	}
};

// Runtime / Dynamic Polymorphism: Can be achieved by Method overriding.
// Method Overriding Rules:
// 1) Only works in inherited classes.
// 2) Should have same method name as base class.
// 3) Should have same paramter list as base class.

// When the same method is defined in the derived class
// the method in the derived class is called
// instead of the method of base class,
// if the call is through object of derived class.


class functionOverriding_Animal {
public:
	void speak() {
		cout << "Speaking" << '\n';
	}
};

class functionOverriding_Dog : public functionOverriding_Animal {
public:
	void speak() {
		cout << "Barking" << '\n';
	}
};


// Abstraction: Also known as Implementation Hiding.
// Only showing the necessary information and hiding the underlying details.
// Helps in code reusability, security.
// The hidden code can only be changed by the one who created it.
// Avoids duplication of code.


int main() {

	Male archi;

	// setting data members of parent class members
	// calling methods of parent class
	archi.setHumanMembers("Archi", 22, 160);
	cout << "Name = " << archi.name << '\n';
	cout << "Age = " << archi.age << '\n';
	cout << "Height = " << archi.height << '\n';
	cout << '\n';


	// accessing data members and methods
	// of child class itself.
	archi.setMembers(70, false);
	cout << "Weight = " << archi.weight << '\n';
	cout << archi.name << " is " << (archi.bald ? "" : "not ") << "bald" << '\n';
	cout << '\n';

	// Accessing method of class Human
	Male m;
	m.speak();
	cout << '\n';


	// Accessing method of class Human, 2 classes above
	Asian a;
	a.speak();
	cout << '\n';


	// Accessing method of class Indian,
	// inheriting from 2 different classes.
	Indian i;
	i.speak();
	i.speakAsian();
	cout << '\n';



	// _a can access only A's functions
	A _a;
	cout << _a.printA() << '\n';


	// _b can access A's as well as B's own functions
	B _b;
	cout << _b.printA() << '\n';
	cout << _b.printB() << '\n';


	// _c can access A's as well as C's own functions
	C _c;
	cout << _c.printA() << '\n';
	cout << _c.printC() << '\n';


	// _d can access B's as well as D's own functions
	D _d;
	cout << _d.printB() << '\n';
	cout << _d.printD() << '\n';


	// _e can access B's as well as E's own functions
	E _e;
	cout << _e.printB() << '\n';
	cout << _e.printE() << '\n';
	cout << '\n';


	// _g inherits from both F and C classes
	G _g;
	cout << _g.printC() << '\n';
	cout << _g.printF() << '\n';
	cout << _g.printG() << '\n';
	cout << '\n';


	// work with the redefinition of class Male
	// inheritance ambiguity
	Transgender tg;
	tg.Male::speak();
	tg.Female::speak();
	tg.Transgender::speak();
	cout << '\n';


	// overloading functions
	functionOverloading fo;
	fo.speak();
	fo.speak("Archi");
	fo.speak("Archi", "Competetive Programming");
	cout << '\n';


	// overloading operators
	operatorOverloading A, B;
	A.a = 30;
	B.a = 6;
	A / B;
	cout << '\n';


	// function overriding
	functionOverriding_Animal an;
	an.speak();
	functionOverriding_Dog dog;
	dog.speak();

	return 0;
}