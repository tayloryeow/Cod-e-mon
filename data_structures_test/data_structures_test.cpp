#include "pch.h"
#include "CppUnitTest.h"
#include "../codemon/data_structures.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace datastructurestest
{
	TEST_CLASS(datastructurestest)
	{
	public:
		//Test if it'll take a null pointer as data -> should crash
		TEST_METHOD(NodeMustBeValid)
		{
			void* data = nullptr;
			 Node node(NULL);
			
		}
		//Test that it can store data into a Node -> Should return the Nodes data un permuted.
		//Test that when created the next node link is null -> ->next should be null
	};
}
