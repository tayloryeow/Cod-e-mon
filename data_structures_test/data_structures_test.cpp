#include "pch.h"
#include "CppUnitTest.h"
#include "../codemon/data_structures.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace datastructurestest
{



	TEST_CLASS(datastructurestest)
	{
	public:
		//Test if it'll take a null pointer as data -> should crash
		TEST_METHOD(NODE_THROWS_EXCEPTION_ON_NULL)
		{
			void* data = nullptr;

			//Can't make a Nodefrom null
			Assert::ExpectException<std::invalid_argument>([data]() {
				Node node(data);
			});
			//Can't set a node to null
			Assert::ExpectException<std::invalid_argument>([]() {
				std::string dummy_data = "dummy";
				Node node((void *) &dummy_data);
				node.set_data(nullptr);
			});
		}
		//Test that it can store data into a Node -> Should return the Nodes data un permuted.
		TEST_METHOD(NODE_GET_DATA)
		{
			std::string data = "testtest";
			Node test_node(&data);
			std::string* node_data = (std::string*)test_node.get_data();
			Assert::AreSame(data, *node_data);
		}
		TEST_METHOD(NODE_SET_DATA)
		{
			std::string data = "testtest";
			Node test_node(&data);
			std::string change_data = "Wuz up";
			test_node.set_data(&change_data);


			std::string* node_data = (std::string*)test_node.get_data();
			Assert::AreSame(change_data, *node_data);
		}

		//Test that when created the next node link is null -> ->next should be null
		TEST_METHOD(NODE_NEXT_SET_TO_NULL)
		{
			std::string data = "testtest";
			Node test_node(&data);

			Assert::IsNull(test_node.get_next());
		}
	};
}
