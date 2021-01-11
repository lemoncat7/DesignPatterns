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
		std::cout << "开启原神游戏..." << std::endl;
	}
	void getName() {
		std::cout << "原神" << std::endl;
	}
};

class HuoYin : public Game {
public :
	HuoYin(){}
	void play() {
		std::cout << "开启火影忍者游戏..." << std::endl;
	}
	void getName() {
		std::cout << "火隐忍者" << std::endl;
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
		std::cout << "诺基亚手机" << std::endl;
	}
	void setGame(Game* game) {
		std::cout << "安装游戏: ";
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
		std::cout << "小米手机" << std::endl;
	}
	void setGame(Game* game) {
		std::cout << "安装游戏: ";
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