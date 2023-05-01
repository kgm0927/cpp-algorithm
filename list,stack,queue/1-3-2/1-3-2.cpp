#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

//동적 크기 배열 구현하기


// dynami_array라는 이름의 클래스 템플릿을 작성하고, 주요 멤버 변수를 선언한다.
template <typename T>
class dynamic_array {
	T* data;
	size_t n;



public:

	// 멤버 데이터에 적접 접근하기 위한 [] 연산자와 at() 함수를 작성한다. [] 연산자를 제공함으로써 std::array와 비슷한 방식으로 배열 원소에 접근할 수 있다.


	T& operator[](int index) {
		return data[index];
}

	const T& operator[](int index) const {// 상수를 반환한다?
		return data[index];
	}

	T& at(int index) {
		if (index < n)
			return data[index];
		throw "Index out of range";
	}


	// 배열 크기를 인자로 받는 생성자와 복사 생성자를 추가한다
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

	//배열의 크기를 반환하는 size() 멤버 함수와 소멸자(destructor)를 구현한다. 소멸자에서는 메모리 릭을 방지하기 위해 할당된 메모리를 해제한다.

	size_t size()const {
		return n;
	}

	~dynamic_array() {
		delete[] data;
	}
	// dynamic_array의 배열 원소를 순회할 때 사용할 반복자 관련 함수를 정의한다.
	T* begin() { return data; }
	const T* begin()const { return data; }
	T* end() { return data + n; }
	const T* end()const { return data + n; }
	

	// 두 배열을 하나로 합치는 연산을 수행하는 +연산자 함수를 정의한다. 이 함수는 friend로 정의한다.
	friend dynamic_array<T> operator+ (const dynamic_array<T>& arr1, dynamic_array<T>& arr2) {
		dynamic_array<T> result(arr1.size() + arr2.size());
		copy(arr1.begin(),arr1.end(),result.begin());
		copy(arr2.begin(), arr2.end(), result.begin() + arr1.size());

		return result;
	}


	// 배열에 저장된 모든 데이터를 문자열을 반환하는 to_string() 멤버 함수를 작성한다. 이 함수는 데이터 구분을 위한 문자열 sep를 인자로 받으며, 
	// 기본 값은 쉼표(", ")로 지정한다.
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



// 학생 정보를 저장할 구조체 student를 정의한다. 이 구조체는 학생의 이름 name과 학생의 학급
//정보를 담는 standard 멤버를 가지고 있다. 그리고 << 연산자를 이용한 표준 출력을 지원한다.

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
	cout << "1반 학생 수를 입력하세요.";
	cin >> nStudents;

	dynamic_array<student> class1(nStudents);

	for (int i = 0; i < nStudents; i++)
	{
		string name;
		int standard;
		cout << i + 1 << "번째 학생 이름과 나이를 입력하세요:";
		cin >> name >> standard;
		class1[i] = student{ name,standard };

	}

	// 배열 크기보다 큰 인덱스의 학생에 접근

	try {
		class1.at(nStudents) = student{ "john",8 };
	}
	catch(...){
		cout << "예외 발생!" << endl;
	}

	// 깊은 복사
	auto class2 = class1;
	std::cout << "1반을 복사하여 2반 생성: " << class2.to_string() << endl;

	// 두 학급을 합쳐서 새로운 큰 학급을 생성

	auto class3 = class1 + class2;

	cout << "1반 2반을 합쳐 3반 생성" << class3.to_string() << endl;

	return 0;


}