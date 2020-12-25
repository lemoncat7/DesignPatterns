#include <iostream>

class DollModel {
private:
	std::string body;
	std::string platform;
	std::string bracket;
	std::string prop;
public:
	DollModel() {}
	void SetBody(std::string body) {
		this->body = body;
	}
	void SetPlatform(std::string platform) {
		this->platform = platform;
	}
	void SetBracket(std::string bracket) {
		this->bracket = bracket;
	}
	void SetProp(std::string prop) {
		this->prop = prop;
	}
	void PrintDollModel() {
		std::cout << "主体 : " << body << std::endl;
		std::cout << "地台 : " << platform << std::endl;
		std::cout << "支架 : " << bracket << std::endl;
		std::cout << "道具 : " << prop << std::endl;
	}
};

class AbstractBuilder {
public:
	DollModel* doll_model;
public:
	AbstractBuilder() {
		doll_model = new DollModel();
	}
	virtual void BuildBody() = 0;
	virtual void BuildPlatform() = 0;
	virtual void BuildBracket() = 0;
	virtual void BuildProp() = 0;
	virtual DollModel* GetDollModel() = 0;
};

class BuilderA : public AbstractBuilder {
public:
	BuilderA() {
		std::cout << "ConcreteBuilderA" << std::endl;
	}
	void BuildBody() {
		doll_model->SetBody("技嘉科技感十足的主体");
	}
	void BuildPlatform() {
		doll_model->SetPlatform("技嘉木制花纹大地盘");
	}
	void BuildBracket() {
		doll_model->SetBracket("技嘉金属厚重支架");
	}
	void BuildProp() {
		doll_model->SetProp("技嘉未来科技金属枪");
	}
	DollModel* GetDollModel() {
		return this->doll_model;
	}
};

class BuilderB : public AbstractBuilder {
public:
	BuilderB() {
		std::cout << "ConcreteBuilderB" << std::endl;
	}
	void BuildBody() {
		doll_model->SetBody("庞杂专属线条纹身主体");
	}
	void BuildPlatform() {
		doll_model->SetPlatform("庞杂专属硬纸底座");
	}
	void BuildBracket() {
		doll_model->SetBracket("庞杂专属轻携式支架");
	}
	void BuildProp() {
		doll_model->SetProp("庞杂专属薯条带番茄酱手持道具");
	}
	DollModel* GetDollModel() {
		return this->doll_model;
	}
};

class Director {
private:
	AbstractBuilder* builder;
public:
	Director() {}
	void SetBuilder(AbstractBuilder* builder) {
		this->builder = builder;
	}
	DollModel* construct() {
		builder->BuildBody();
		builder->BuildPlatform();
		builder->BuildBracket();
		builder->BuildProp();
		return builder->GetDollModel();
	}
};

int main() {
	DollModel* doll_model = NULL;
	AbstractBuilder* builder = new BuilderA();
	Director* director = new Director();
	director->SetBuilder(builder);
	doll_model = director->construct();
	doll_model->PrintDollModel();
	builder = new BuilderB();
	director->SetBuilder(builder);
	doll_model = director->construct();
	doll_model->PrintDollModel();
	return 0;
}