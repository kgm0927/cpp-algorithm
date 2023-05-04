#include <iostream>
#include <vector>
using namespace std;

// 가변 데이터를 처리하기 위해 std::vector를 처리할 수 있는 컨테이너가 필요하기도 하다.
// 이러한 문제를 std::vector가 어떻게 해결하는지 보겠다.
// 
//

int main() {
	// 크기가 0인 벡터 선언
	vector <int> vec;// 이 코드는 벡터는 원소 크기를 지정하지 않고 선언할 수 있다.



	// 지정한 초깃값으로 이루어진 크기가 5인 벡터 선언
	vector<int> vec = { 1,2,3,4,5 }; // 초깃값을 지정하여 크기를 유추할 수 있게 할 수 있다.



	// 크기가 10인 벡터 선언
	vector<int> vec(10);



	// 크기가 10이고, 모든 원소가 5로 초기화된 벡터 선언
	vector<int> vec(10,5);



	int val=1;
	vec.push_back(val);// 벡터의 제일 마지막에 새로운 원소를 추가한다.



	vec.insert(1,1); // 함수를 삽입할 위치를 나태내는 반복자(iterator)를 첫번째 인자로 받음으로써 원하는 위치에 원소를 추가할 수 있다.




	vector<int> vec = { 1,2,3,4,5 };// 이러한 벡터 값이 초기화되어 있을 때,
	// 벡터의 맨 앞에 새로운 원소를 추가하려면 insert() 함수를 다음과 같이 사용한다.



	vec.insert(vec.begin(),0);// 책에서는 int.begin() 이라고 나오는데 정확한 원인을 알 수 없음. (오타로 추정)


	// push_back()과 insert() 함수를 사용하는 예제 코드를 좀 더 살펴본다.

	vector<int> vec;

	vec.push_back(1);

	vec.push_back(2);

	vec.insert(vec.begin(),0);

	vec.insert(find(vec.begin(), vec.end(), 1), 4);



}

// 만약 벡터의 크기를 명시적으로 지정하지 않거나 또는 초깃밧을 지정하여 크기를 유추할 수 있게 코드를 작성하지 않을 시, 컴파일러 구현 방법에 따른 용량을
// 갖는 벡터가 생성이 된다. 벡터의 크기는 벡터에 실제로 저장된 원소 개수를 나타내는 용어이며, 용량과는 다른 의미이다.
// 그래서 첫 번째 초기화의 경우, 크기는 0이지만 용량은 0 또는 작은 양수일 수 있다.