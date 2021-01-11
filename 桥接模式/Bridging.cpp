#include <iostream>
#include <vector>

class Game {
public:
	Game(){}
	virtual void play() = 0;
	virtual void getName() = 0;
};

class YuanShen : public Game {
public:
	YuanShen(){}
	void play() {
		std::cout << "����ԭ����Ϸ..." << std::endl;
	}
	void getName() {
		std::cout << "ԭ��" << std::endl;
	}
};

class HuoYin : public Game {
public :
	HuoYin(){}
	void play() {
		std::cout << "������Ӱ������Ϸ..." << std::endl;
	}
	void getName() {
		std::cout << "��������" << std::endl;
	}
};

class Phone {
public:
	std::vector<Game*> games;
public:
	Phone() {}
	virtual void setGame(Game* game) = 0;
	virtual void play() = 0;
};

class Nokiya : public Phone {
public:
	Nokiya() {
		std::cout << "ŵ�����ֻ�" << std::endl;
	}
	void setGame(Game* game) {
		std::cout << "��װ��Ϸ: ";
		game->getName();
		games.push_back(game);
	}
	void play() {
		for (auto it : games) {
			it->play();
		}
	}
};

class Xiaomi : public Phone {
public:
	Xiaomi() {
		std::cout << "С���ֻ�" << std::endl;
	}
	void setGame(Game* game) {
		std::cout << "��װ��Ϸ: ";
		game->getName();
		games.push_back(game);
	}
	void play() {
		for (auto it : games) {
			it->play();
		}
	}
};

int main() {
	Phone* phone1 = new Nokiya();
	Game* game1 = new YuanShen();
	Game* game2 = new HuoYin();
	phone1->setGame(game1);
	phone1->setGame(game2);
	phone1->play();
	Phone* phone2 = new Xiaomi();
	phone2->setGame(game1);
	phone2->setGame(game2);
	phone2->play();
	return 0;
}