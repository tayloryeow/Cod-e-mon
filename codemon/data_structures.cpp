//Generic Linked List class - singly linked for now.
class linked_list
{
private:
    Node* head;
    Node* tail;
public:
    linked_list() {
        this->head = nullptr;
        this->tail = nullptr;

    }
    //Add a node to the linked list
    // -Take a dataPtr
    // - Add new_now to the head of the list.
    bool add_node(void* dataptr) {
        //Create a node to put the data_ptr in
        Node new_node(dataptr);

        //Case 1: Empty List - if it breaks add a check for tail nullness
        //  head->new_node<-tail
        //           \->nullptr
        if (this->head == nullptr) {
            this->head = &new_node;
            this->tail = this->head;
        }
        //Case 2: 1 Node List
        // head isn't nullptr and they are the same pointer. 
        else if (this->head == this->tail)
        {
            //new node points at the head 
            new_node.set_next(this->head);
            //The new node becomes the head.
            this->head = &new_node;

        }
        //Case 3: >2 Node List
        else {
            new_node.set_next(this->head);
            this->head = &new_node;
        }
    }

    //Remove a node from the linked list -
    // - Remove the node with the dataptr that matches
    bool remove_node(void* remove_me) {

    }
};

class Node
{
private:
    void* data = nullptr;     //Poiter to the data that's held.
    Node* next = nullptr;     //Pointer to the next data node
public:
    //Constructor: Intended that the new node becomes the head of the list.
    Node(void* data_ptr) {
        data = data_ptr;
        this->next = nullptr;
    }
    //Get the next node in the list. 
    Node* get_next() {
        return this->next;
    }
    Node* set_next(Node* next_node) {
        this->next = next_node;
    }
    //Just keep the pointer to the data, don't store all of it.
    Node* set_data(void* new_data) {
        //TODO when setting data, reconfirm that the data's deleted too.
        this->data = new_data;
    }
};