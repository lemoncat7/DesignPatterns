#include <iostream>

class AbstractProduct {	//抽象产品
public : 
	AbstractProduct() {}
	void print() {};
	void taste() {};
};

class TheOneEyedAndy : public AbstractProduct {
public :
	TheOneEyedAndy() {
		print();
		taste();
	}
	void print() {
		std::cout << "得到一个独眼小宝" << std::endl;
	}
	void taste() {
		std::cout << "这个小宝尝起来有点烫" << std::endl;
	}
};

class ParamountPortableFood : public AbstractProduct {
public :
	ParamountPortableFood() {
		print();
		taste();
	}
	void print() {
		std::cout << "得到一个派蒙牌便携食品" << std::endl;
	}
	void taste() {
		std::cout << "这个食品看起来 没食欲" << std::endl;
	}
};

class ATravelerWhoCannotSpeak : public AbstractProduct {
public:
	ATravelerWhoCannotSpeak() {
		print();
		taste();
	}
	void print() {
		std::cout << "得到一个不会说话的旅行者" << std::endl;
	}
	void taste() {
		std::cout << "这个旅行者尝起来就很穷酸" << std::endl;
	}
};

class Factory {
public :
	Factory(){}
	AbstractProduct* getProduct(std::string name) {
		if (name == "独眼小宝") {
			return new TheOneEyedAndy();
		} else if(name == "派蒙牌便携食品") {
			return new ParamountPortableFood();
		} else if (name == "不会说话的旅行者") {
			return new ATravelerWhoCannotSpeak();
		} else {
			return new AbstractProduct();
		}
	}
};

int main() {
	Factory* factory = new Factory();
	AbstractProduct* product = NULL;
	product = factory->getProduct("独眼小宝");
	product = factory->getProduct("派蒙牌便携食品");
	product = factory->getProduct("不会说话的旅行者");
	return 0;
}