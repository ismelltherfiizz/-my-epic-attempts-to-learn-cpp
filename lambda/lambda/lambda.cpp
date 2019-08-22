// lambda.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <functional>

int main()
{
	auto fact = [](int a)
	{
		auto factInternal = [](int a, auto f)
		{
		if (a < 0) return 0;
		if (a == 0) return 1;
		else return a * f(a - 1, f);
		};
		return factInternal(a, factInternal);
	};

	auto identityf = [](auto &x) 
	{
		return [&x]()
		{
			x = 18;
			if (x > 20) return x;
			else return x + 1;
			
		};
	};
	int b = 5;
	std:: cout << identityf(b)() << std::endl;
	std::cout << b << std::endl;


	std::cout << fact(5) << std::endl;
}
