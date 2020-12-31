#include "singleCaseNoSafe.h"
#include "singleCaseSafe.h"

int main() {
	std::cout << "single1 : ";
	SingleCaseNoSafe* single1 = SingleCaseNoSafe::Single();
	std::cout << "single2 : " << std::endl;
	SingleCaseNoSafe* single2 = SingleCaseNoSafe::Single();
	SingleCaseNoSafe::DeleteSingle();

	HANDLE handle[5];
	int thread_num = 0;
	while (thread_num < 5) {
		handle[thread_num++] = (HANDLE)_beginthreadex(NULL, 0, CallSingleCaseNoSafe, &thread_num,0,NULL);
	}
	WaitForMultipleObjects(5, handle, true, INFINITE);

	HANDLE handle[5];
	int thread_num = 0;
	while (thread_num < 5) {
		handle[thread_num++] = (HANDLE)_beginthreadex(NULL, 0, CallSingleCaseSafe, &thread_num,0,NULL);
	}
	WaitForMultipleObjects(5, handle, true, INFINITE);
	return 0;
}