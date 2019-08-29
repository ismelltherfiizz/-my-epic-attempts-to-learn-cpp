#include <iostream>
#include <vector>
#include <memory>



void typeFunc(int a)
{
	std::cout << a << " is int" << std::endl;
}

void typeFunc(double a)
{
	std::cout << a << " is double" << std::endl;
}

template <typename T>
void typeFunc(T a)
{
	std::cout << a << " is undefined" << std::endl;
}

template <typename T>
void g(T First)
{
	typeFunc(First);

}


template <typename T, typename... Args>
void g(T First, Args&&... args)
{
		typeFunc(First);

		g(std::forward<Args>(args)...);
		
	//std::vector<Args> v = { args... };

	//for (auto i : ( args... ) ) {
	//	std::cout << i << std::endl;
	//}
}

template <typename T, typename... StructVars>
struct Tuple : public Tuple<StructVars...>{
	Tuple(T first, StructVars... structVars) : Tuple<StructVars...>(structVars...), first(first)
	{
		//g(first, std::forward<StructVars>(structVars)...);
		std::cout << first << "  1st" << std::endl;
	}

	T first;

};

template<typename T>
struct Tuple<T> {
	Tuple(T first) : first(first) {
		std::cout << first << "  2nd" << std::endl;
	}

	T first;
};

template<int index, typename T, typename... StructVars>
struct GetImpl {
	static auto value(const Tuple<T, StructVars...>* t) -> decltype(GetImpl<index - 1, StructVars...>::value(t)) {
		return GetImpl<index - 1, StructVars...>::value(t);

	}
};

template<typename T, typename... StructVars>
struct GetImpl<0, T, StructVars...> {
	static T value(const Tuple<T, StructVars...>* t) {
		return t->first;
	}
};


template<int index, typename T, typename... StructVars>
auto get(const Tuple<T, StructVars...>& t) -> decltype(GetImpl<index, T, StructVars...>::value(&t)) { 
	return GetImpl<index, T, StructVars...>::value(&t);
}

template<typename T, std::size_t N>
constexpr std::size_t arraysize(T(&)[N]) noexcept
{

}

int main()
{	

	//double a = 5.5;
	//float b = 66.6;
	////const char* c= "";
	//float c = 11.1;
	//Tuple<double, int, double, float, float> t(a, 2, 5.1, b, c);
	//std::cout << get<0>(t);

	
	
}

