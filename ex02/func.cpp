#include "func.hpp"
#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <cstdlib>	 // rand(), srand() のために必要
#include <exception> // std::bad_cast (またはその基底の std::exception) のために必要
#include <iostream>

Base *generate(void)
{
	int choice = std::rand() % 3; // 0, 1, 2 のいずれかの乱数を生成

	std::cout << "Generating instance of ";
	switch (choice)
	{
	case 0:
		std::cout << "A" << std::endl;
		return new A();
	case 1:
		std::cout << "B" << std::endl;
		return new B();
	case 2:
		std::cout << "C" << std::endl;
		return new C();
	default:
		std::cerr << "Unknown type generated!" << std::endl;
		return NULL;
	}
}

// ポインタ版のidentify：dynamic_castの結果がNULLかどうかで判定
void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
	{
		std::cout << "A" << std::endl;
	}
	else if (dynamic_cast<B *>(p))
	{
		std::cout << "B" << std::endl;
	}
	else if (dynamic_cast<C *>(p))
	{
		std::cout << "C" << std::endl;
	}
	else
	{
		std::cerr << "Unknown type or NULL pointer" << std::endl;
	}
}

// 参照版のidentify：dynamic_castが例外を投げるかどうかで判定
void identify(Base &p)
{
	// Aへのキャストを試みる
	try
	{
		(void)dynamic_cast<A &>(p); // キャスト結果は使わないので(void)で警告抑制
		std::cout << "A" << std::endl;
		return; // 型が確定したら関数を抜ける
	}
	catch (const std::exception &e)
	{
		// キャスト失敗。何もしないで次に進む
	}

	// Bへのキャストを試みる
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (const std::exception &e)
	{
		// キャスト失敗。
	}

	// Cへのキャストを試みる
	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Unknown type" << std::endl;
	}
}
