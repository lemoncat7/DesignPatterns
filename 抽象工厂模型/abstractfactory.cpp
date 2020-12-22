#include <iostream>
#include <cstdlib>

class AbstractLori {
public:
	AbstractLori(){}
	void print() {};
};

class Amelia : public AbstractLori {
public:
	Amelia() {
		print();
	}
	void print() {
		std::cout << "a lovely Lori named Amelia is produced" << std::endl;
	}
};

class Rosemary : public AbstractLori {
public :
	Rosemary() {
		print();
	}
	void print() {
		std::cout << "here is a Lori, Rosemary produced" << std::endl;
	}
};

class NightDemon : public AbstractLori {
public:
	NightDemon() {
		print();
	}
	void print() {
		std::cout << "sir, NightDemon the Lori is produced now" << std::endl;
	}
};

class ElijahSfir : public AbstractLori {
public :
	ElijahSfir() {
		print();
	}
	void print() {
		std::cout << "a cute Lori named ElijahSfir is produced" << std::endl;
	}
};

class ShuoMoonTour : public AbstractLori {
public:
	ShuoMoonTour() {
		print();
	}
	void print() {
		std::cout << "a lovely Lori named ShuoMoonTour is produced" << std::endl;
	}
};

class AbstractGirl {
public:
	AbstractGirl(){}
	void print() {};
};

class Mathsy : public AbstractGirl {
public:
	Mathsy() {
		print();
	}
	void print() {
		std::cout << "a lovely Girl named Mathsy is produced" << std::endl;
	}
};

class Anastasia : public AbstractGirl {
public:
	Anastasia() {
		print();
	}
	void print() {
		std::cout << "sir, Anastasia the Girl is produced now" << std::endl;
	}
};

class M4a1 : public AbstractGirl {
public:
	M4a1() {
		print();
	}
	void print() {
		std::cout << "a cute Girl named M4a1 is produced" << std::endl;
	}
};

class Ar15 : public AbstractGirl {
public:
	Ar15() {
		print();
	}
	void print() {
		std::cout << "here is a Girl, Ar15 produced" << std::endl;
	}
};

class Fal : public AbstractGirl {
public:
	Fal() {
		print();
	}
	void print() {
		std::cout << "a lovely Girl named Fal is produced" << std::endl;
	}
};

class AbstractRoyalSister {
public :
	AbstractRoyalSister(){}
	void print() {};
};

class Chen : public AbstractRoyalSister {
public :
	Chen() {
		print();
	}
	void print() {
		std::cout << "A mature royal sister, Chen, has been produced" << std::endl;
	}
};

class Skaha : public AbstractRoyalSister {
public :
	Skaha() {
		print();
	}
	void print() {
		std::cout << "produce an odor-cooked woman Skaha" << std::endl;
	}
};

class AbstractFactory {
public:
	AbstractFactory(){}
	virtual AbstractRoyalSister* getRoyalSister() = 0;
	virtual AbstractLori* getLori() = 0;
	virtual AbstractGirl* getGirl() = 0;
};

class TomorrowArk : public AbstractFactory {
public:
	TomorrowArk() {
		std::cout << "============ Tomorrow's Ark===========" << std::endl;
		unsigned seed = time(0);
		srand(seed);
	}
	AbstractLori* getLori() {
		switch (rand() % 3 + 1) {
		case 1: return new Amelia();
		case 2: return new Rosemary();
		case 3: return new NightDemon();
		}
		return new AbstractLori();
	}
	AbstractRoyalSister* getRoyalSister() {
		return new Chen();
	}
	AbstractGirl* getGirl() {
		std::cout << "no girl produced" << std::endl;
		return new AbstractGirl();
	}
};

class FGO : public AbstractFactory {
public:
	FGO() {
		std::cout << "============      FGO      ===========" << std::endl;
		unsigned seed = time(0);
		srand(seed);
	}
	AbstractLori* getLori() {
		switch (rand() % 2 + 1) {
		case 1: return new ElijahSfir();
		case 2: return new ShuoMoonTour();
		}
		return new AbstractLori();
	}
	AbstractRoyalSister* getRoyalSister() {
		return new Skaha();
	}
	AbstractGirl* getGirl() {
		switch (rand() % 2 + 1) {
		case 1: return new Mathsy();
		case 2: return new Anastasia();
		}
		return new AbstractGirl();
	}
};

class GirlFront : public AbstractFactory {
public:
	GirlFront() {
		std::cout << "============ Girl   Front   ===========" << std::endl;
		unsigned seed = time(0);
		srand(seed);
	}
	AbstractLori* getLori() {
		std::cout << "no lori produced" << std::endl;
		return new AbstractLori();
	}
	AbstractRoyalSister* getRoyalSister() {
		std::cout << "no roya sister produced" << std::endl;
		return new AbstractRoyalSister();
	}
	AbstractGirl* getGirl() {
		switch (rand() % 3 + 1) {
		case 1: return new M4a1();
		case 2: return new Ar15();
		case 3: return new Fal();
		}
		return new AbstractGirl();
	}
};

int main() {
	AbstractFactory* factory = NULL;
	AbstractGirl* girl = NULL;
	AbstractLori* lori = NULL;
	AbstractRoyalSister* royal = NULL;
	factory = new TomorrowArk();
	lori = factory->getLori();
	lori = factory->getLori();
	lori = factory->getLori();
	girl = factory->getGirl();
	royal = factory->getRoyalSister();
	factory = new FGO();
	lori = factory->getLori();
	lori = factory->getLori();
	girl = factory->getGirl();
	girl = factory->getGirl();
	royal = factory->getRoyalSister();
	factory = new GirlFront();
	lori = factory->getLori();
	girl = factory->getGirl();
	girl = factory->getGirl();
	girl = factory->getGirl();
	royal = factory->getRoyalSister();
	return 0;
}