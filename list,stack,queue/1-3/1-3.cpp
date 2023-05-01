#include <iostream>
#include<array>
using namespace std;

// std::array는 메모리를 자동으로 할당하고 해제한다. std::array는 원소의 타입과 배열의 크기를 매개변수로 사용하는
// 클래스 템플릿이다.

int main() {
	array<int, 10> arr1; // 크기가 10인 int 타입 배열 선언
	arr1[0] = 1;
	cout << "arr1 배열의 첫 번째 원소:" << arr1[0] << endl;

	array<int, 4> arr2 = { 1,2,3,4 };
	cout << "arr2의 모든 원소";

	for (int i = 0; i < arr2.size(); i++)
	{
		cout << arr2[i] << " ";
	}
	cout << endl;
	
}