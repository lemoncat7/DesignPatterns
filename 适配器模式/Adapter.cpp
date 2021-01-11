#include <iostream>

class Controller {
public:
	Controller() {}
	virtual void pathPlaning() = 0;
};

class DxfParser {
public:
	DxfParser(){}
	void parseFile() {
		std::cout << "�����ļ���ȡ����..." << std::endl;
	}
};

class PathPlanner {
public:
	PathPlanner() {}
	void calculate() {
		std::cout << "����ӹ�·��" << std::endl;
	}
};

class Adapter : public Controller {	//������
public :
	Adapter() {
		dxfparser = new DxfParser();
		pathplanner = new PathPlanner();
	}
	void pathPlaning() {
		std::cout << "·���滮..." << std::endl;
		pathplanner->calculate();
		dxfparser->parseFile();
	}

private:
	DxfParser* dxfparser = nullptr;
	PathPlanner* pathplanner = nullptr;
};

int main() {
	Adapter* adapter = new Adapter();
	adapter->pathPlaning();
	return 0;
}