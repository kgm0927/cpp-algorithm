#include <iostream>
#include <array>
using namespace std;

int main() {
	array<int, 4> arr2 = { 1,2,3,4 };
	cout << "arr2�� ��� ����";

	for (auto it = arr2.begin()	; it !=arr2.end(); it++)
	{
		auto element = (*it);
		cout << element << ' ';
	}// array::begin()�Լ��� ù ��° ���Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ, 
	//array::end()�� ������ ���� ������ ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
	cout << endl;

	array<int, 5> arr = { 1,2,3,4,5 };
	cout << arr.front() << endl;
	cout << arr.back() << endl;
	cout << *(arr.data() +1) << endl;

	// front(): �迭�� ù ��° ���ҿ� ���� ������ ��ȯ�Ѵ�.
	// back(): �迭�� ������ ���ҿ� ���� ������ ��ȯ�Ѵ�.
	// data(): �迭 ��ü ���ο��� ���� ������ ���۸� ����Ű�� �����͸� ��ȯ�Ѵ�.
	// ��ȯ�� �����͸� �̿��Ͽ� �پ��� ������ ������ ������ �� �ִ�. �� ����� �����͸� �Լ��� ���ڷ�
	// �޴� ���� ��Ÿ���� �Լ��� ����� �� �����ϴ�.

	
}