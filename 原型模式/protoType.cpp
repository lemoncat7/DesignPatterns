#include <iostream>

class AbstractPrototype {
public:
	AbstractPrototype() {}
	virtual AbstractPrototype* clone() = 0;
	virtual void print() = 0;
};

class ShallowCopy : public AbstractPrototype {
private:
	std::string name;
	char* sname = nullptr;
public:
	ShallowCopy() {}
	ShallowCopy(std::string name, char* sname) {
		this->name = name;
		this->sname = sname;
	}
	AbstractPrototype* clone() {
		return new ShallowCopy(name, sname);
	}
	void setName(std::string name) {
		this->name = name;
	}
	void setSName(char* sname) {
		for (int i = 0; i < 4; i++) {
			this->sname[i] = sname[i];
		}
	}
	void print() {
		std::cout << name << " : " << sname << std::endl;
	}
};

class DeepCopy : public AbstractPrototype {
private:
	std::string name;
	char *sname = nullptr;
public:
	DeepCopy() {}
	DeepCopy(std::string name, char* sname) {
		this->name = name;
		setSName(sname);
	}
	~DeepCopy() {
		if (sname != nullptr) {
			free(sname);
			sname = nullptr;
		}
	}
	AbstractPrototype* clone() {
		return new DeepCopy(name, sname);
	}
	void setName(std::string name) {
		this->name = name;
	}
	void setSName(char* sname) {
		this->sname = (char*)malloc(5);
		for (int i = 0; i < 4; i++) {
			this->sname[i] = sname[i];
		}
		this->sname[5] = 0;
	}
	void print() {
		std::cout << name << " : " << sname << std::endl;
	}
};

int main() {
	char sname[5] = { "zzyb" };
	AbstractPrototype* shallow = new ShallowCopy({ "小明" }, sname);
	std::cout << "原类    : ";
	shallow->print();
	AbstractPrototype* shallow_copy = shallow->clone();
	std::cout << "浅拷贝类: ";
	shallow_copy->print();
	std::cout << "修改浅拷贝类..." << std::endl;
	dynamic_cast<ShallowCopy*>(shallow_copy)->setName("小黄");
	dynamic_cast<ShallowCopy*>(shallow_copy)->setSName("yyzb");
	std::cout << "---------------" << std::endl;
	std::cout << "原类    : ";
	shallow->print();
	std::cout << "浅拷贝类: ";
	shallow_copy->print();
	char name[5] = { "zzyb" };
	std::cout << "原类    : ";
	AbstractPrototype* deep = new DeepCopy({ "小明" }, name);
	deep->print();
	AbstractPrototype* deep_copy = deep->clone();
	std::cout << "深拷贝类: ";
	deep_copy->print();
	std::cout << "修改深拷贝类..." << std::endl;
	dynamic_cast<DeepCopy*>(deep_copy)->setName("小黄");
	dynamic_cast<DeepCopy*>(deep_copy)->setSName("yyzb");
	std::cout << "原类    : ";
	deep->print();
	std::cout << "深拷贝类: ";
	deep_copy->print();
	return 0;
}