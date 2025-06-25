#include "func.hpp"
#include <cstdlib> // srand(), rand()
#include <ctime>   // time()
#include <iostream>

int main()
{
	// 乱数生成器のシードを初期化
	srand(time(NULL));

	Base *p = NULL;

	std::cout << "--- Testing 10 random instances ---" << std::endl;
	for (int i = 0; i < 10; ++i)
	{
		std::cout << "\n--- Test " << i + 1 << " ---" << std::endl;

		// 1. ランダムなインスタンスを生成
		p = generate();

		// 2. ポインタで型を特定
		std::cout << "Identify by pointer:   ";
		identify(p);

		// 3. 参照で型を特定
		std::cout << "Identify by reference: ";
		identify(*p);

		delete p;
	}

	// NULLポインタのテスト
	std::cout << "\n--- Testing NULL pointer ---" << std::endl;
	p = NULL;
	std::cout << "Identify by pointer:   ";
	identify(p);
	// identify(*p) はセグフォになるのでテストしない

	return 0;
}
