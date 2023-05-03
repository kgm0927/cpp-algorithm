#include <iostream>
#include <array>
#include <type_traits>
using namespace std;




// �����̳ʸ� �����ϴ� build_array() �Լ��� �����Ѵ�. �� �Լ��� ���� ���� ��ȸ�� �����ϴ� std::array�� ��ȯ�Ѵ�. �׸��� ���� ������ �Ű������� ����ϱ� ���� ���� ���ø��� ����.
// 
//  std::array�� ����Ϸ��� ������ Ÿ�԰� ���� ������ �����ؾ� �Ѵ�. std::array�� ������ ������ Ÿ���� �����ϱ� ���� std::common_type ���ø��� ����� �� �ִ�.
// �� �۾��� �Լ� ���ڿ� �������̱⿡ �Լ� ��ȯ���� ���� ����Ÿ��(trailing return type)���� �����ؾ� �Ѵ�.
// 
// �ռ� �ۼ��� �ڵ忡 �߰��� ���� ������ �˾Ƴ��� �ڵ�� commonType�� �̿��Ͽ� �迭�� �����ϴ� �ڵ带 �Է��Ѵ�.
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
// ���:
// 1 0 97 3.2 0
/*
int main() {
	auto data2 = build_array(1, "Packt", 2.0);// �̷��� ����� �ڵ�� �Ұ����ϴ�. �̴� ���ڿ��� ���ڸ� ��� ǥ���� �� �ִ� ������ �ڷ����� �������� �ʱ� �����̴�.
}*/