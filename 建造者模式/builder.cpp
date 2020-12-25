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
		std::cout << "���� : " << body << std::endl;
		std::cout << "��̨ : " << platform << std::endl;
		std::cout << "֧�� : " << bracket << std::endl;
		std::cout << "���� : " << prop << std::endl;
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
		doll_model->SetBody("���οƼ���ʮ�������");
	}
	void BuildPlatform() {
		doll_model->SetPlatform("����ľ�ƻ��ƴ����");
	}
	void BuildBracket() {
		doll_model->SetBracket("���ν�������֧��");
	}
	void BuildProp() {
		doll_model->SetProp("����δ���Ƽ�����ǹ");
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
		doll_model->SetBody("����ר��������������");
	}
	void BuildPlatform() {
		doll_model->SetPlatform("����ר��Ӳֽ����");
	}
	void BuildBracket() {
		doll_model->SetBracket("����ר����Яʽ֧��");
	}
	void BuildProp() {
		doll_model->SetProp("����ר�����������ѽ��ֳֵ���");
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