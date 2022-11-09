//Generic Linked List class - singly linked for now.
class Node
{
private:
    void* data = nullptr;     //Poiter to the data that's held.
    Node* next = nullptr;     //Pointer to the next data node
public:
    //Constructor: Intended that the new node becomes the head of the list.
    Node(void* data_ptr);
    //Get the next node in the list. 
    Node* get_next();
    Node* set_next(Node* next_node);
    //Just keep the pointer to the data, don't store all of it.
    Node* set_data(void* new_data);
};

class linked_list
{
private:
    Node* head;
    Node* tail;
public:
    linked_list();
    //Add a node to the linked list
    // -Take a dataPtr
    // - Add new_now to the head of the list.
    bool add_node(void* dataptr);
    //Remove a node from the linked list -
    // - Remove the node with the dataptr that matches
    bool remove_node(void* remove_me);
};

