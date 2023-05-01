#include <iostream>
#include <array>
using namespace std;

int main() {
	array<int, 4> arr2 = { 1,2,3,4 };
	cout << "arr2의 모든 원소";

	for (auto it = arr2.begin()	; it !=arr2.end(); it++)
	{
		auto element = (*it);
		cout << element << ' ';
	}// array::begin()함수는 첫 번째 원소를 가리키는 반복자를 반환, 
	//array::end()는 마지막 원소 다음을 가리키는 반복자를 반환한다.
	cout << endl;

	array<int, 5> arr = { 1,2,3,4,5 };
	cout << arr.front() << endl;
	cout << arr.back() << endl;
	cout << *(arr.data() +1) << endl;

	// front(): 배열의 첫 번째 원소에 대한 참조를 반환한다.
	// back(): 배열의 마지막 원소에 대한 참조를 반환한다.
	// data(): 배열 객체 내부에서 실제 데이터 버퍼를 가리키는 포인터를 반환한다.
	// 반환된 포인터를 이용하여 다양한 포인터 연산을 수행할 수 있다. 이 기능은 포인터를 함수의 인자로
	// 받는 예전 스타일의 함수를 사용할 때 유용하다.

	
}