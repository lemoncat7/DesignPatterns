#pragma once

#include <iostream>
#include <Windows.h>
#include <process.h>

class SingleCaseNoSafe {
private:
	SingleCaseNoSafe() {
		std::cout << "不安全单例实例创建" << std::endl;
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
	std::cout << "线程编号 : " << *(int*)pPM << std::endl;
	return 0;
}

