#include <iostream>
#include <cmath>
#include <list>
#include <vector>
#include <tuple>

#include "lib.h"

namespace integer {


	template <typename T>
	void print_ip(int a) {
		unsigned char uc = (unsigned char) a;
		std::cout << (int) uc << '\n';
	}
	void print_ip(int8_t a) {
		unsigned char uc = (unsigned char) a;
		std::cout << (int) uc << '\n';
	}
	void print_ip(int16_t a) {
		int8_t a1 = a / 256;
		int8_t a2 = a % 256;
		unsigned char uc1 = (unsigned char) a1;
		unsigned char uc2 = (unsigned char) a2;
		std::cout << (int) uc1 << "." << (int) uc2 << '\n';
	}
	void print_ip(int32_t a) {
		int8_t a1 =  a / pow(256, 3);
		int8_t a2 = (a - a1 * pow(256, 3)) / pow(256, 2);
		int8_t a3 = (a - a1 * pow(256, 3)
					   - a2 * pow(256, 2)) / pow(256, 1);
		int8_t a4 = (a - a1 * int(pow(256, 3))
					   - a2 * int(pow(256, 2))
					   - a3 * int(256))         % int(256);
		unsigned char uc1 = (unsigned char) a1;
		unsigned char uc2 = (unsigned char) a2;
		unsigned char uc3 = (unsigned char) a3;
		unsigned char uc4 = (unsigned char) a4;
		std::cout << (int) uc1 << "." << (int) uc2 << "." << (int) uc3 << "." << (int) uc4 << '\n';
	}
	void print_ip(int64_t a) {
		int8_t a1 =  a / pow(256, 7);
		int8_t a2 = (a - a1 * pow(256, 7)) / pow(256, 6);
		int8_t a3 = (a - a1 * pow(256, 7)
					   - a2 * pow(256, 6)) / pow(256, 5);
		int8_t a4 = (a - a1 * pow(256, 7)
					   - a2 * pow(256, 6)
					   - a3 * pow(256, 5)) / pow(256, 4);
		int8_t a5 = (a - a1 * pow(256, 7)
					   - a2 * pow(256, 6)
					   - a3 * pow(256, 5)
					   - a4 * pow(256, 4)) / pow(256, 3);
		int8_t a6 = (a - a1 * pow(256, 7)
					   - a2 * pow(256, 6)
					   - a3 * pow(256, 5)
					   - a4 * pow(256, 4)
					   - a5 * pow(256, 3)) / pow(256, 2);
		int8_t a7 = (a - a1 * pow(256, 7)
					   - a2 * pow(256, 6)
					   - a3 * pow(256, 5)
					   - a4 * pow(256, 4)
					   - a5 * pow(256, 3)
					   - a6 * pow(256, 2)) / pow(256, 1);
		int8_t a8 = (a - a1 * int(pow(256, 7))
					   - a2 * int(pow(256, 6))
					   - a3 * int(pow(256, 5))
					   - a4 * int(pow(256, 4))
					   - a5 * int(pow(256, 3))
					   - a6 * int(pow(256, 2))
					   - a7 * int(pow(256, 1))) % int(256);
		unsigned char uc1 = (unsigned char) a1;
		unsigned char uc2 = (unsigned char) a2;
		unsigned char uc3 = (unsigned char) a3;
		unsigned char uc4 = (unsigned char) a4;
		unsigned char uc5 = (unsigned char) a5;
		unsigned char uc6 = (unsigned char) a6;
		unsigned char uc7 = (unsigned char) a7;
		unsigned char uc8 = (unsigned char) a8;
		std::cout << (int) uc1 << "." << (int) uc2 << "." << (int) uc3 << "." << (int) uc4 << "." <<
					 (int) uc5 << "." << (int) uc6 << "." << (int) uc7 << "." << (int) uc8 << '\n';
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