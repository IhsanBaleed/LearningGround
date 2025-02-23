#include "Misc.hh"

void test_union() {

	Union::UnionTest t1;

	// all members of the union share the same memory block
	// changing one of the variables will change all of them

	t1.x = 3;
	std::cout << "the val of x is = " << t1.x << std::endl;

	t1.y = 4;
	std::cout << "the val of x is = " << t1.x << std::endl;
	std::cout << "the val of y is = " << t1.y << std::endl;

	// you can also declare it using the union keyword as well.
	union Union::UnionTest2 t2;

	t2.ch = 'X';
	std::cout << "the val of ch is = " << t2.ch << std::endl;
	std::cout << "the val of z is = " << t2.z << std::endl;

	t2.z = 7;
	std::cout << "the val of ch is = " << t2.ch << std::endl;
	std::cout << "the val of z is = " << t2.z << std::endl;
}

void test_Anon() {
	// this is an anonymous object
	// it only lives for one line
	// you must satisfy the constructor of the class when creating
	AnonymousObj::Anon();

	// you can also call functions of that clas
	AnonymousObj::Anon().spin();

	// you can call other constructors of the class if it has any
	AnonymousObj::Anon("ABC");

	// they are best used with operator overloading
	// you can also use them when you dont need a reference to an object, thus saving memory
}

