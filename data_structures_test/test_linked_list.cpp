

#include "pch.h"
#include "CppUnitTest.h"
#include "../codemon/data_structures.h"
#include <string>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace testlinkedlist
{
	TEST_CLASS(testlinkedlist)
	{
	public:
		TEST_METHOD(LIST_CONSTRUCTOR)
		{
			std::string first_node = "1";
			std::string sec_node = "2";
			int third_node = 3;

			Linked_list new_list;
			Linked_list* ll_ptr = &new_list;

			//Add the three different data into the list
			ll_ptr->add_node(&first_node);
			ll_ptr->add_node(&sec_node);
			ll_ptr->add_node(&third_node);

			Node* curr_node = ll_ptr->get_head();

			Assert::AreEqual(*(int*)curr_node->get_data(), third_node);
			curr_node = curr_node->get_next();
			Assert::AreSame(*(std::string*)curr_node->get_data(), sec_node);
			curr_node = curr_node->get_next();
			Assert::AreSame(*(std::string*)curr_node->get_data(), first_node);
		};
		
		TEST_METHOD(LIST_REMOVE_NODE)
		{
			std::string first_node = "1";
			std::string sec_node = "2";
			int third_node = 3;
			int fourth_node = 4;
			double fifth_node = 5.05;
			std::string sixth_node = "6";

			Linked_list new_list;
			Linked_list* ptr = &new_list;

			//Add the three different data into the list
			new_list.add_node(&first_node);
			new_list.add_node(&sec_node);
			new_list.add_node(&third_node);
			new_list.add_node(&fourth_node);
			new_list.add_node(&fifth_node);
			new_list.add_node(&sixth_node);

			//remove the firstnode
			new_list.remove_at(5);
			//Check that the tail is now the second node 
			Assert::AreEqual(sec_node, *(std::string*)new_list.get_tail()->get_data());

			//Remove the head and check that was moved correctly
			Assert::IsTrue(new_list.remove_at(0));
			//Check that the tail is now the second node 
			Assert::AreEqual(*(double*)new_list.get_tail()->get_data(), fifth_node);


		};
	};
}