#include <iostream>
#include<array>
using namespace std;

// std::array�� �޸𸮸� �ڵ����� �Ҵ��ϰ� �����Ѵ�. std::array�� ������ Ÿ�԰� �迭�� ũ�⸦ �Ű������� ����ϴ�
// Ŭ���� ���ø��̴�.

int main() {
	array<int, 10> arr1; // ũ�Ⱑ 10�� int Ÿ�� �迭 ����
	arr1[0] = 1;
	cout << "arr1 �迭�� ù ��° ����:" << arr1[0] << endl;

	array<int, 4> arr2 = { 1,2,3,4 };
	cout << "arr2�� ��� ����";

	for (int i = 0; i < arr2.size(); i++)
	{
		cout << arr2[i] << " ";
	}
	cout << endl;
	
}