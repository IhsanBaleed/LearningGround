#include <iostream>

namespace Union {

	class UnionTest {

	public:

		union { // these are called a variant members.
			int x = 0;
			// you can only initialize one member var inside a union
			//int y = 0;
			int y;
		};
	};

	// you can make a "struct" using a union
	union UnionTest2 {
		int z;
		char ch;
	};
}

void test_union();


namespace AnonymousObj {

	class Anon {

		int a;
		int b;

	public:

		Anon() {
			std::cout << "Anon Created" << std::endl;
		}

		Anon(std::string val) {
			std::cout << "Anon says " << val << std::endl;
		}

		void spin() {
			std::cout << "I am spinning" << std::endl;
		}

	};
}

void test_Anon();
