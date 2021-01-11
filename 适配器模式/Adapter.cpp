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
		std::cout << "解析文件提取数据..." << std::endl;
	}
};

class PathPlanner {
public:
	PathPlanner() {}
	void calculate() {
		std::cout << "计算加工路径" << std::endl;
	}
};

class Adapter : public Controller {	//适配器
public :
	Adapter() {
		dxfparser = new DxfParser();
		pathplanner = new PathPlanner();
	}
	void pathPlaning() {
		std::cout << "路径规划..." << std::endl;
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