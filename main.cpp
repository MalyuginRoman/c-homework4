#include <iostream>
#include <cmath>
#include <list>
#include <vector>
#include <tuple>

#include "lib.h"

namespace integer {
	
	template <typename T>
	auto print_ip(T &number) -> decltype(number) {
		unsigned char uc;
		int SizeInt = sizeof(T);
		switch(SizeInt)
		{
			case 1:
				uc = (unsigned char) number;
				std::cout << (int) uc;
				break;
			default:
				for (int i = SizeInt; i--;) {
					int8_t a = number / pow(256, i);
					uc = (unsigned char) a;
					std::cout << (int) uc;
					if (i > 0) std::cout << ".";
					number -= (int) uc * pow(256, i);
				}
				break;
		}
		std::cout << std::endl;
		return number;
	}
	void print_ip(std::string a) {
		std::cout << a << '\n';
	}

	void example() {
		int8_t  int8 = -1;
		print_ip(int8);
		int16_t int16 = 0;
		print_ip(int16);
		int32_t int32 = 2130706433;
		print_ip(int32);
		int64_t int64 = 8875824491850138409;
		print_ip(int64);
		std::string string = "Hello, World!";
		print_ip(string);
	}

} // integer

namespace container {

	template <typename T>			// vector
	auto print_container(T &container, long) -> decltype(container) {
		int count = container.size();
		for(int i = 0; i < count; i++) {
			if(i < (count - 1)) std::cout << container.at(i) << '.';
			else std::cout << container.at(i) << '\n';
		}
	}

	template <typename T>			// list
	auto print_container(T &container, int) -> void {
		int count = container.size();
		int iter = 0;
		for(int n : container) {
			iter ++;
			if(iter < count) std::cout << n << '.';
			else std::cout << n << '\n';
		}
	}

	template<typename T>
	void print_container(T &container) {
		container::print_container(container, 42);
	}

	void example() {
		std::vector<int> vector{100, 200, 300, 400};
		print_container(vector);
		std::list<short> list{400, 300, 200, 100};
		print_container(list);
	}
} // container

namespace tuple {

	void example() {
		std::tuple<int, int, int, int> tup;
		tup = std::make_tuple(123, 456, 789, 0);
		std::cout << std::get<0>(tup) << '.' << std::get<1>(tup) << '.' 
				  << std::get<2>(tup) << '.' << std::get<3>(tup) << std::endl;
	}
} // tuple

int main() {

    std::cout << "Version: " << version() << std::endl;
	integer::example();
	container::example();
	tuple::example();

	return 0;
}
