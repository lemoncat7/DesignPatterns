#include <iostream>

class AbstractProduct {	//�����Ʒ
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
		std::cout << "�õ�һ������С��" << std::endl;
	}
	void taste() {
		std::cout << "���С���������е���" << std::endl;
	}
};

class ParamountPortableFood : public AbstractProduct {
public :
	ParamountPortableFood() {
		print();
		taste();
	}
	void print() {
		std::cout << "�õ�һ�������Ʊ�ЯʳƷ" << std::endl;
	}
	void taste() {
		std::cout << "���ʳƷ������ ûʳ��" << std::endl;
	}
};

class ATravelerWhoCannotSpeak : public AbstractProduct {
public:
	ATravelerWhoCannotSpeak() {
		print();
		taste();
	}
	void print() {
		std::cout << "�õ�һ������˵����������" << std::endl;
	}
	void taste() {
		std::cout << "��������߳������ͺ�����" << std::endl;
	}
};

class Factory {
public :
	Factory(){}
	AbstractProduct* getProduct(std::string name) {
		if (name == "����С��") {
			return new TheOneEyedAndy();
		} else if(name == "�����Ʊ�ЯʳƷ") {
			return new ParamountPortableFood();
		} else if (name == "����˵����������") {
			return new ATravelerWhoCannotSpeak();
		} else {
			return new AbstractProduct();
		}
	}
};

int main() {
	Factory* factory = new Factory();
	AbstractProduct* product = NULL;
	product = factory->getProduct("����С��");
	product = factory->getProduct("�����Ʊ�ЯʳƷ");
	product = factory->getProduct("����˵����������");
	return 0;
}