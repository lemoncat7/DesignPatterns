#include <iostream>

class AbstractProduct {		//抽象产品
public:
	AbstractProduct() {}
	void print() {};
	void play() {};
};

class PowerArmor : public AbstractProduct {
public:
	PowerArmor() {
		print();
		play();
	}
	void print() {
		std::cout << "得到一个动力装甲" << std::endl;
	}
	void play() {
		std::cout << "动力装甲因太过脆弱而被损坏" << std::endl;
	}
};

class FlyingPowder : public AbstractProduct {
public:
	FlyingPowder() {
		print();
		play();
	}
	void print() {
		std::cout << "得到一个飞路粉" << std::endl;
	}
	void play() {
		std::cout << "动力装甲因太过脆弱而被损坏" << std::endl;
	}
};

class Goblins : public AbstractProduct {
public:
	Goblins() {
		print();
		play();
	}
	void print() {
		std::cout << "得到一个哥布林" << std::endl;
	}
	void play() {
		std::cout << "暴躁的哥布林发起了进攻" << std::endl;
	}
};

class AbstractFacotry {
public :
	AbstractFacotry() {}
	virtual AbstractProduct* getProduct() = 0;
};

class MachineryFactory : public AbstractFacotry{
public : 
	MachineryFactory() {}
	AbstractProduct* getProduct() {
		return new PowerArmor();
	}
};

class MagicFactory : public AbstractFacotry {
public:
	MagicFactory() {}
	AbstractProduct* getProduct() {
		return new FlyingPowder();
	}
};

class Greenfactory : public AbstractFacotry {
public:
	Greenfactory() {}
	AbstractProduct* getProduct() {
		return new Goblins();
	}
};

int main() {
	AbstractFacotry* factory = NULL;
	AbstractProduct* product = NULL;
	factory = new MachineryFactory();
	product = factory->getProduct();
	factory = new MagicFactory();
	product = factory->getProduct();
	factory = new Greenfactory();
	product = factory->getProduct();
	return 0;
}