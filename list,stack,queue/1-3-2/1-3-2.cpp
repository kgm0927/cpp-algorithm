#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

//���� ũ�� �迭 �����ϱ�


// dynami_array��� �̸��� Ŭ���� ���ø��� �ۼ��ϰ�, �ֿ� ��� ������ �����Ѵ�.
template <typename T>
class dynamic_array {
	T* data;
	size_t n;



public:

	// ��� �����Ϳ� ���� �����ϱ� ���� [] �����ڿ� at() �Լ��� �ۼ��Ѵ�. [] �����ڸ� ���������ν� std::array�� ����� ������� �迭 ���ҿ� ������ �� �ִ�.


	T& operator[](int index) {
		return data[index];
}

	const T& operator[](int index) const {// ����� ��ȯ�Ѵ�?
		return data[index];
	}

	T& at(int index) {
		if (index < n)
			return data[index];
		throw "Index out of range";
	}


	// �迭 ũ�⸦ ���ڷ� �޴� �����ڿ� ���� �����ڸ� �߰��Ѵ�
	dynamic_array(int n) {
		this->n = n;
		data = new T[n];
	}
	dynamic_array(const dynamic_array<T>& other) {
		n = other.n;
		data = new T[n];

		for (int i = 0; i < n; i++)
		{
			data[i] = other[i];
		}
	}

	//�迭�� ũ�⸦ ��ȯ�ϴ� size() ��� �Լ��� �Ҹ���(destructor)�� �����Ѵ�. �Ҹ��ڿ����� �޸� ���� �����ϱ� ���� �Ҵ�� �޸𸮸� �����Ѵ�.

	size_t size()const {
		return n;
	}

	~dynamic_array() {
		delete[] data;
	}
	// dynamic_array�� �迭 ���Ҹ� ��ȸ�� �� ����� �ݺ��� ���� �Լ��� �����Ѵ�.
	T* begin() { return data; }
	const T* begin()const { return data; }
	T* end() { return data + n; }
	const T* end()const { return data + n; }
	

	// �� �迭�� �ϳ��� ��ġ�� ������ �����ϴ� +������ �Լ��� �����Ѵ�. �� �Լ��� friend�� �����Ѵ�.
	friend dynamic_array<T> operator+ (const dynamic_array<T>& arr1, dynamic_array<T>& arr2) {
		dynamic_array<T> result(arr1.size() + arr2.size());
		copy(arr1.begin(),arr1.end(),result.begin());
		copy(arr2.begin(), arr2.end(), result.begin() + arr1.size());

		return result;
	}


	// �迭�� ����� ��� �����͸� ���ڿ��� ��ȯ�ϴ� to_string() ��� �Լ��� �ۼ��Ѵ�. �� �Լ��� ������ ������ ���� ���ڿ� sep�� ���ڷ� ������, 
	// �⺻ ���� ��ǥ(", ")�� �����Ѵ�.
	string to_string(const std::string& sep = ", ") {
		if (n == 0)
			return "";

		ostringstream os;
		os << data[0];

		for (int i = 1; i < n; i++)
		{
			os << sep << data[i];
		}

		return os.str();

	}
	



};



// �л� ������ ������ ����ü student�� �����Ѵ�. �� ����ü�� �л��� �̸� name�� �л��� �б�
//������ ��� standard ����� ������ �ִ�. �׸��� << �����ڸ� �̿��� ǥ�� ����� �����Ѵ�.

struct student
{
	string name;
	int standard;
};

ostream& operator<<(ostream& os, const student& s) {
	return (os << "[" << s.name << ", " << s.standard << "]");
}

int main() {
	int nStudents;
	cout << "1�� �л� ���� �Է��ϼ���.";
	cin >> nStudents;

	dynamic_array<student> class1(nStudents);

	for (int i = 0; i < nStudents; i++)
	{
		string name;
		int standard;
		cout << i + 1 << "��° �л� �̸��� ���̸� �Է��ϼ���:";
		cin >> name >> standard;
		class1[i] = student{ name,standard };

	}

	// �迭 ũ�⺸�� ū �ε����� �л��� ����

	try {
		class1.at(nStudents) = student{ "john",8 };
	}
	catch(...){
		cout << "���� �߻�!" << endl;
	}

	// ���� ����
	auto class2 = class1;
	std::cout << "1���� �����Ͽ� 2�� ����: " << class2.to_string() << endl;

	// �� �б��� ���ļ� ���ο� ū �б��� ����

	auto class3 = class1 + class2;

	cout << "1�� 2���� ���� 3�� ����" << class3.to_string() << endl;

	return 0;


}