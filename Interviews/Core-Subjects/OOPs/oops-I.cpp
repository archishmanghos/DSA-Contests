#include <bits/stdc++.h>
#include "heroImport.cpp"
using namespace std;

// What is OOPs?
// Type of programming paradigm where everything revolves around objects.

// Why OOPs? -> To improve maintainability, readability and extensibility.

// Class -> User defined datatype.

// Objects -> is an entity, which has state / properties and behaviours / methods. It is also instance of a class.

// The size of a class will be the combined sum of sizes of all the properties / variables.

/*

class Hero {
	string name;
	int health;
	char level;

	void attack();
	void defense();
	void dance();
};

*/

// In case of empty class, the system allots 1 byte to the class so that it is recognisable in the memory space.

class HeroEmpty {

};

// We can also import class from another file by using #include. Notice heroImport.cpp.

// Access modifiers:
// Private: Only accessible to the native class, where it is defined. All methods and data members of a class are defined private by default.
// Public: Accessible anywhere in the program.


// Getters and Setters -> Can be used to get the value or set the value of private data members of a class.
// These are general public methods defined in the native class to change the value of private data members.

// If we print the size of h1 object of Hero class, the value will be not only be the sum of the sizes of the datatypes but will also add in padding size.


/*

class Hero {
public:
	string name;
	int health;
	char level;

	void attack();
	void defense();
	void dance();

	int getHealth() {
		return health;
	}

	void setHealth(int value) {
		health = value;
	}
};

*/

/*

class Hero {
public:
	string name;
	int health;
	char level;

	void attack();
	void defense();
	void dance();

	int getHealth() {
		return health;
	}

	void setHealth(int value) {
		health = value;
	}
};

*/

// Constructor -> Invoked when an object is called. This has no return type and its name is same as the class name under which it is called.
// 2 types of constructors: Default constructor, which doesn't have any input parameters and Parameterised constructor, which has parameters.
// If no constructor is specified, a default constructor is called by the system itself.
// When a non-parameterised constructor is declared, the system destroys the default constructor from the memory.

// this keyword -> this stores the address of the current object. It is a pointer pointing towards the location of current object.

// If any constructor is made (parameterised / non-parameterised), the default constructor made by the sustem is destroyed. This is IMPORTANT.

// Copy Constructor: Copies the values of a pre-defined object to a new object whose constructor has been called.

// Deep Copy and Shallow Copy: If a copy constructor gets called on a pointer variable, it changes the value at that address.
// Deep copy is created when a new copy of the data structure is made and the value is copied to the new address.

// Copy Assignment Operator: Copies values of an object to another object.

// Destructor : Deallocates memory of an object. For static allocation, destructor is called immediately,
// but for dynamically allocated objects, destructor has to be called manually.

class HeroConstructor {
public:
	int health;

	// Non-Parameterised Constructor
	HeroConstructor () {
		cout << "Non-Parameterised Constructor Called" << '\n';
	}

	// Parameterised Constructor
	HeroConstructor (int health) {
		cout << "Parameterised Constructor Called" << '\n';
		cout << "Address of this = " << this << '\n';
		this -> health = health;
	}

	// Copy constructor
	// remember to pass by reference, else,
	// infinite loop.
	HeroConstructor (HeroConstructor &temp) {
		cout << "Copy Constructor Called" << '\n';
		this->health = temp.health;
	}

	~ HeroConstructor() {
		cout << "Destructor called" << '\n';
	}
};

// Static Members: Static members belong to the class and doesn't bind to the object.
// Static members can be accessed without creating an object using a scope resolution operator.

// Static Functions: Static functions also belong to the class and not the object. So they can be called without creating the object.
// These can only access static members of the class and no other members.
// Since static functions are not bound to an object, "this" keyword is not defined here, as this points to the object itself.

class Hero {
public:
	static int timeToCompleteLevel;
	string name;
	int health;
	char level;

	void attack();
	void defense();
	void dance();

	int getHealth() {
		return health;
	}

	void setHealth(int value) {
		health = value;
	}

	static int printTime () {
		return timeToCompleteLevel;
	}
};

int Hero::timeToCompleteLevel = 300;

int main() {
	Hero h1;
	cout << "Size of h1 = " << sizeof(h1) << '\n';

	HeroEmpty he1;
	cout << "Size of he1 = " << sizeof(he1) << '\n';

	HeroImport hi1;
	cout << "Size of hi1 = " << sizeof(hi1) << '\n';
	cout << '\n';

	// These will be garbage values as of now, since we did not provide values anywhere.
	cout << "Before setting:\n";
	cout << "Name of h1 = " << h1.name << '\n';
	cout << "Health of h1 = " << h1.health << '\n';
	cout << "Level of h1 = " << h1.level << '\n';
	cout << '\n';

	h1.name = "Archi";
	h1.health = 70;
	h1.level = 'A';

	// Now, the set values will be printed.
	cout << "After setting:\n";
	cout << "Name of h1 = " << h1.name << '\n';
	cout << "Health of h1 = " << h1.health << '\n';
	cout << "Level of h1 = " << h1.level << '\n';
	cout << '\n';

	cout << "Using Getter: \n";
	cout << "Health of h1 = " << h1.getHealth() << '\n';
	cout << '\n';
	cout << "Using Setter to set new health: \n";
	h1.setHealth(100);
	cout << "Health of h1 = " << h1.getHealth() << '\n';
	cout << '\n';

	// static allocation
	Hero h2;
	h2.health = 30;
	h2.level = 'B';
	h2.name = "xyz";
	cout << "Name of h2 = " << h2.name << '\n';
	cout << "Health of h2 = " << h2.health << '\n';
	cout << "Level of h2 = " << h2.level << '\n';
	cout << '\n';

	// dynamic allocation
	Hero *h3 = new Hero();
	(*h3).health = 40; // deferencing - 1 way
	h3->level = 'C'; // Using arrow - 2nd way
	h3->name = "abc";
	cout << "Name of h3 = " << h3->name << '\n';
	cout << "Health of h3 = " << h3->health << '\n';
	cout << "Level of h3 = " << (*h3).level << '\n';
	cout << '\n';

	// static allocation
	HeroConstructor hc1;

	// dynamic allocation
	HeroConstructor *hc2 = new HeroConstructor();

	HeroConstructor hc3(20);
	cout << "Address of hc3 = " << (&hc3) << '\n';
	cout << "After parameterised constructor:\n";
	cout << "Health of hc3 = " << hc3.health << '\n';
	cout << '\n';

	// Copy Constructor
	HeroConstructor hc4(hc3);
	cout << "Health of hc4 = " << hc4.health << '\n';
	cout << '\n';

	// Copy assignment operator
	HeroConstructor hc5(50);
	cout << "Health of hc5 = " << hc5.health << '\n';
	hc5 = hc4;
	cout << "Health of hc5 = " << hc5.health << '\n';

	// Destructor gets called for all objects hc1 to hc5
	// except hc2 as it's dynamically allocated.
	delete hc2;
	cout << '\n';

	// Static member, so no object creation
	cout << "Time reqd to complete Level = " << Hero::timeToCompleteLevel << '\n';
	cout << '\n';

	// Static function
	cout << "Time reqd to complete Level = " << Hero::printTime() << '\n';
	cout << '\n';

	return 0;
}