#include <iostream>
#include <array>
#include <type_traits>
using namespace std;




// 컨테이너를 생성하는 build_array() 함수를 선언한다. 이 함수는 빠른 원소 순회를 보장하는 std::array를 반환한다. 그리고 임의 개수의 매개변수를 허용하기 위해 가변 템플릿을 쓴다.
// 
//  std::array를 사용하려면 원소의 타입과 원소 개수를 지정해야 한다. std::array에 저장할 원소의 타입을 결정하기 위해 std::common_type 템플릿을 사용할 수 있다.
// 이 작업은 함수 인자에 의존적이기에 함수 반환형을 후행 리턴타입(trailing return type)으로 지정해야 한다.
// 
// 앞서 작성한 코드에 추가로 원소 개수를 알아내는 코드와 commonType을 이용하여 배열을 생성하는 코드를 입력한다.
// 


template<typename ... Args>
auto build_array(Args&& ...args) -> std::array<typename common_type<Args...>::type,sizeof ... (args)>{
	using commonType = typename common_type<Args ...>::type;
	return { std::forward<commonType>((Args&&)args)... };
}




int main() {

	auto data = build_array(1,0u,'a',3.2f,false);
	for (auto i:data)
	{
		cout << i << " ";
	}
	cout << endl;
}

//
// 결과:
// 1 0 97 3.2 0
/*
int main() {
	auto data2 = build_array(1, "Packt", 2.0);// 이러한 방법의 코드는 불가능하다. 이는 문자열과 숫자를 모두 표현할 수 있는 공통의 자료형이 존재하지 않기 때문이다.
}*/