#include <iostream>
using namespace std;

class human {
protected:
	string name;
	int age;
	bool sex;    // Male => true; Female => false

	// Init
	human(string name, int age, bool sex) {
		this->name = name;
		this->age = age;
		this->sex = sex;
	}
};

class male : protected human {
public:
    male(string name, int age, bool sex = true) : human(name, age, sex) {
        this->name = name;
        this->age = age;
    }

	string getName() {
		return this->name;
	}

	int getAge() {
		return this->age;
	}

	bool getSex() {
		return this->sex;
	}
};


int main() {
	male* man = new male("Henry", 22);

	cout<<man->getSex();

	return 0;
}