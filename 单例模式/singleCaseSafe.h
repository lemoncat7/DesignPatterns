#pragma once 

#include <iostream>
#include <mutex>

class SingleCaseFafe {
private:
	SingleCaseFafe() {
		std::cout << "��ȫ����ʵ������" << std::endl;
	}
	static SingleCaseFafe* single;
	static std::mutex m_mutex;
public:
	static SingleCaseFafe* Single() {
		m_mutex.lock();
		if (single == NULL) {
			single = new SingleCaseFafe();
		}
		m_mutex.unlock();
		return single;
	}
};

SingleCaseFafe* SingleCaseFafe::single = NULL;
std::mutex SingleCaseFafe::m_mutex;

unsigned int __stdcall CallSingleCaseSafe(void* pPM) {
	SingleCaseFafe* single = SingleCaseFafe::Single();
	Sleep(100);
	std::cout << "�̱߳�� : " << *(int*)pPM << std::endl;
	return 0;
}