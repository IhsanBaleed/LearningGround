#include <iostream>
#include <stdio.h>

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

namespace EventHandling {

	// this will be the event caller
	class EventSource {
	public:
		// this function will rais the event
		__event void event_caller(int val);
	};

	class EventReciever {
	public:

		// the handlers must match the event they are handling
		void handler_1(int val) {
			std::cout << "Handler 1 called " << val << std::endl;
		}
		void handler_2(int val) {
			std::cout << "Handler 2 called " << val << std::endl;
		}

		// this will let the handlers listen and wait for the event
		// pass the address of the methods, and a pointer to the calling object
		void hookEvent(EventSource* s_ptr) {
			__hook(&EventSource::event_caller, s_ptr, &EventReciever::handler_1);
			__hook(&EventSource::event_caller, s_ptr, &EventReciever::handler_2);
		}

		// this will unhook the event
		void unhookEvent(EventSource* s_ptr) {
			__unhook(&EventSource::event_caller, s_ptr, &EventReciever::handler_1);
			__unhook(&EventSource::event_caller, s_ptr, &EventReciever::handler_1);
		}
	};
}
void test_handlres() {

	EventHandling::EventSource s;
	EventHandling::EventReciever r;

	r.hookEvent(&s);

	// parameters passed into the event are then passed in turn into the handler
	s.event_caller(707);

	r.unhookEvent(&s);
}

namespace DT_Sizes {

	void show_sizes() {

		std::cout << "Size of char: " << sizeof(char) << " byte(s)" << std::endl;
		std::cout << "Size of int: " << sizeof(int) << " byte(s)" << std::endl;
		std::cout << "Size of float: " << sizeof(float) << " byte(s)" << std::endl;
		std::cout << "Size of double: " << sizeof(double) << " byte(s)" << std::endl;
		std::cout << "Size of bool: " << sizeof(bool) << " byte(s)" << std::endl;
		std::cout << "Size of wchar_t: " << sizeof(wchar_t) << " byte(s)" << std::endl;
		std::cout << "Size of int8_t: " << sizeof(int8_t) << " byte(s)" << std::endl;
		std::cout << "Size of int16_t: " << sizeof(int16_t) << " byte(s)" << std::endl;
		std::cout << "Size of int32_t: " << sizeof(int32_t) << " byte(s)" << std::endl;
		std::cout << "Size of int64_t: " << sizeof(int64_t) << " byte(s)" << std::endl;
		std::cout << "Size of char16_t: " << sizeof(char16_t) << " byte(s)" << std::endl;
		std::cout << "Size of char32_t: " << sizeof(char32_t) << " byte(s)" << std::endl;
		std::cout << "Size of size_t: " << sizeof(size_t) << " byte(s)" << std::endl; // size_t holds unsigned value - 8 bytes
	}


}

