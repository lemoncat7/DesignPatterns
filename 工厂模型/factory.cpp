#include <iostream>

class AbstractProduct {		//�����Ʒ
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
		std::cout << "�õ�һ������װ��" << std::endl;
	}
	void play() {
		std::cout << "����װ����̫������������" << std::endl;
	}
};

class FlyingPowder : public AbstractProduct {
public:
	FlyingPowder() {
		print();
		play();
	}
	void print() {
		std::cout << "�õ�һ����·��" << std::endl;
	}
	void play() {
		std::cout << "����װ����̫������������" << std::endl;
	}
};

class Goblins : public AbstractProduct {
public:
	Goblins() {
		print();
		play();
	}
	void print() {
		std::cout << "�õ�һ���粼��" << std::endl;
	}
	void play() {
		std::cout << "����ĸ粼�ַ����˽���" << std::endl;
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