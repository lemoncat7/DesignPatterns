#pragma once

#include <iostream>
#include <Windows.h>
#include <process.h>

class SingleCaseNoSafe {
private:
	SingleCaseNoSafe() {
		std::cout << "����ȫ����ʵ������" << std::endl;
	}
	static SingleCaseNoSafe* single;
public:
	static SingleCaseNoSafe* Single() {
		if (single == nullptr) {
			single = new SingleCaseNoSafe();
		}
		return single;
	}
	static void DeleteSingle() {
		if (single != nullptr) {
			delete single;
			single = NULL;
		}
	}
};
SingleCaseNoSafe* SingleCaseNoSafe::single = NULL;

unsigned int __stdcall CallSingleCaseNoSafe(void* pPM) {
	SingleCaseNoSafe* single = SingleCaseNoSafe::Single();
	Sleep(100);
	std::cout << "�̱߳�� : " << *(int*)pPM << std::endl;
	return 0;
}

