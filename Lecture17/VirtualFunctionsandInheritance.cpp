#include <iostream>
using namespace std;

class Parent {
public:
	Parent() {
		cout << "Parent: no parameters\n";
	}
	Parent(int a) {
		cout << "Parent: int parameter\n";
	}
	virtual void whoAmIReally() {
		cout << "I am a parent." << endl;
	}
	void whoDoIApperToBe() {
		cout << "I appear to be a parent." << endl;
	}
};

class Daughter : public Parent {
public:
	Daughter(int a) {
		cout << "Daughter: int parameter\n\n";
	}
	virtual void whoAmIReally() {
		cout << "I am a daughter." << endl;
	}
	void whoDoIApperToBe() {
		cout << "I appear to be a daughter." << endl;
	}

};

class Son : public Parent {
public:
	Son(int a) : Parent(a) {
		cout << "Son: int parameter\n\n";
	}
	virtual void whoAmIReally() {
		cout << "I am a son." << endl;
	}
	void whoDoIApperToBe() {
		cout << "I appear to be a son." << endl;
	}
};

//class Grandchild : public Daughter {
//public:
//	Grandchild(int a) : Daughter(a) {
//		cout << "Grandchild: int parameter\n\n";
//	}
//	void whoAmIReally() {
//		cout << "I am a grandchild." << endl;
//	}
//	void whoDoIApperToBe() {
//		cout << "I appear to be a grandchild." << endl;
//	}
//};

int main() {
	Parent *currentPerson;

	cout << ">>>> Constructor Tests" << endl;
	Daughter kelly(0);
	Son mikey(0);
	//Grandchild baby(0);

	cout << endl << endl;
	cout << ">>>> whoAmIReally Tests (virtual)" << endl;
	cout << "Basic call for kelly: "; kelly.whoAmIReally();
	cout << "Basic call for mikey: "; mikey.whoAmIReally();
	//cout << "Basic call for baby: "; baby.whoAmIReally();

	cout << "kelly as a parent: "; currentPerson = &kelly;  currentPerson->whoAmIReally();
	cout << "mikey as a parent: "; currentPerson = &mikey;  currentPerson->whoAmIReally();
	//cout << "baby as a parent: "; currentPerson = &baby;  currentPerson->whoAmIReally();
	//cout << "baby as a daughter: "; currentPerson = &baby;  currentPerson->whoAmIReally();

	cout << endl << endl;
	cout << ">>>> whoDoIApperToBe Tests (non-virtual)" << endl;
	cout << "Basic call for kelly: "; kelly.whoDoIApperToBe();
	cout << "Basic call for mikey: "; mikey.whoDoIApperToBe();
	//cout << "Basic call for baby: "; baby.whoDoIApperToBe();

	cout << "kelly as a parent: "; currentPerson = &kelly;  currentPerson->whoDoIApperToBe();
	cout << "mikey as a parent: "; currentPerson = &kelly;  currentPerson->whoDoIApperToBe();
	//cout << "baby as a parent: "; currentPerson = &baby;  currentPerson->whoDoIApperToBe();
	//cout << "baby as a daughter: "; Daughter *currentD = &baby;  currentD->whoDoIApperToBe();
    system("pause");
    return 0;
}