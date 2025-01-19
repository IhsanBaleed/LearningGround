#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>

template <typename T>
class Stack {

    /* You can use a vector to allow dynamic allocation of data
    *  Be careful when pushing or popping, always check for current size
    */

    int index = -1; // always points to the top of the list
    int size; // max size
    T* data;

public:

    Stack(int size = 100) : size(size) {
        data = new T[size];
    }

    ~Stack() {
        delete[] data;
    }

    void push(T item) {
        if (index >= size-1) {
            std::cout << "Stack overflown" << std::endl;
            return;
        }
        data[++index] = item;
    }

    T pop() {
        if (index < 0) {
            std::cout << "Stack underflow" << std::endl;
            return T();
        }
        return data[index--];
    }

    T peek() {
        if(index < 0) {
            std::cout << "Stack is empty" << std::endl;
            return T();
        }
        return data[index];
    }

    bool is_empty() {
        return (index < 0);
    }

};

template <typename T>
class SingleLinkedList {
    /* Update the head when inserting or deleting at the start
     * When inserting or deleting at an index, stop before the targeted item
     * Assign Null to head if list has no items
     * To make thinking easier, establish a base case, then use it for more advanced ones, much easier to reason about
    */

private:

    class Node {
        T val;
        Node* next = NULL;

        Node(T val) : val(val){}

        friend class SingleLinkedList;
    };

    Node* head;

public:

    SingleLinkedList(): head(NULL){}

    ~SingleLinkedList() {
        delete_list();
    }

    void print_items() {
        if (!head) {
            std::cout << "No Items in the SLL" << std::endl;
            return;
        }
        Node* current = head;
        while (current) {
            std::cout << current->val << " -> ";
            current = current->next;
        }
        std::cout << "NULL" << std::endl;
    }

    void insert_at_beginning(T item) {
        if (!head) {
            std::cout << "Head is empty, inserting at the start" << std::endl;
            head = new Node(item);
            return;
        }
        
        Node* new_item = new Node(item);
        new_item->next = head;
        head = new_item;
    }

    void insert_at_end(T item) {
        if (!head) {
            insert_at_beginning(item);
            return;
        }
        Node* new_item = new Node(item);

        Node* current_item = head;
        while (current_item->next) {
            current_item = current_item->next;
        }
        current_item->next = new_item;
    }

    void insert_at_index(int index, T item) {
        if (index == 1 || !head) {
            insert_at_beginning(item);
            return;
        }
        
        // we start at 1 as head is located there
        // we also want to stop just before we insert
        // we iterate until we get the index or we reach end of list.
        Node* current_item = head;
        for (int i=1; i < index -1 && current_item; i++) { 
            current_item = current_item->next;
        }
        if (current_item) {
            Node* new_item = new Node(item);
            new_item->next = current_item->next;
            current_item->next = new_item;
            return;
        }
        std::cout << "Index out of bounds, Inserting at the end" << std::endl;
        insert_at_end(item);
    }

    void delete_list() {

        if(!head) {
            return;
        }

        std::cout << "Deleting List" << std::endl;
        /*
        * to free up memory, try to delete from R to L
        * you already have a hold of head, so start from there
        * get a hold of next then delete current, until the end.
        */        
        Node* current_item = head;
        Node* next_item;
        
        while (current_item) {
            next_item = current_item->next;
            delete current_item;
            current_item = next_item;
        }
        head = NULL; // Very important, delete will give it a wild value, not same as null!!
    }

    void delete_at_start() {
        if (!head) {
            std::cout << "No items to delete" << std::endl;
            return;
        }
        Node* to_delete = head;
        head = head->next;
        delete to_delete;
    }

    void delete_at_end() {
        if (!head) {
            std::cout << "No items to delete" << std::endl;
            return;
        }

        // if we have 1 item, you can be lazy and call delete_at_start
        if (head->next == nullptr) {
            delete head;
            head = NULL;
            return;
        }

        Node* current_item = head;
        while (current_item->next->next) { // before the last item
            current_item = current_item->next;
        }
        delete current_item->next;
        current_item->next = NULL;
    }

    void delete_at_index(int index) {
        if (!head || index < 1) {
            std::cout << "SLL is empty, cant delete" << std::endl;
        }
        if (index == 1) {
            delete_at_start();
            return;
        }

        Node* current_item = head;
        for (int i=1; i < index -1 && current_item; i++) { // stops 1 place before target
            current_item = current_item->next;
        }
        if (!current_item || !current_item->next) { // when we go out of bounds
            std::cout << "Index out of range" << std::endl;
            return;
        }
        Node* target_item = current_item->next; // get target item
        current_item->next = target_item->next; // link the chain
        delete target_item; // remove the item.
    }

    T get_first_item() {
        if(head){
            return head->val;
        }
        std::cout << "SLL is empty" << std::endl;
        return T();
    }

    T get_last_item() {
        if (!head) {
            std::cout << "SLL is empty" << std::endl;
            return T();
        }
        if (!head->next) {
            return head->val;
        }
        Node* current_item = head;
        while (current_item->next) {
            current_item = current_item->next;
        }
        return current_item->val;
    }

    T get_item(int index) {
        if (!head) {
            std::cout << "SLL is empty" << std::endl;
            return T();
        }
        if (index == 1) {
            return get_first_item();
        }
        if (!head->next) {
            std::cout << "Only one item in SLL, here it is: " << head->val << std::endl;
            return get_first_item();
        }

        Node* current_item = head;
        for (int i=1; i < index && current_item; i++) {
            current_item = current_item->next;
        }

        if (current_item) {
            return current_item->val;
        }
        std::cout << "Item out of bounds" << std::endl;
        return T();

    }
};

template <typename T>
class DoubleLinkedList {

    struct Node {
        T data;
        Node* next = nullptr;
        Node* before = nullptr;

        Node() = default;
        Node(T data): data(data){}
    };

    Node* head;
    Node* end;

public:

    DoubleLinkedList(): head(NULL), end(NULL)
    {}

    ~DoubleLinkedList() {
        delete_all();
    }

    void insert_at_beginning(T item) {
        if (!head) {
            head = new Node(item);
            end = head;
            return;
        }
        Node* new_item = new Node(item);
        
        new_item->next = head;
        head->before = new_item;
        head = new_item;
    }

    void insert_at_end(T item) {
        if (!head) {
            insert_at_beginning(item);
            return;
        }
        Node* new_item = new Node(item);
        
        new_item->before = end;
        end->next = new_item;
        end = new_item;
    }

    void insert_at_index(int index, T item) {
        if (!head) {
            std::cout << "Error, no items. Inserting at the start" << std::endl;
            insert_at_beginning(item);
            return;
        }
        if (index == 1 || index <= 0) {
            insert_at_beginning(item);
            return;
        }
        if (head == end) {
            std::cout << "List has one item, inserting at end" << std::endl;
            insert_at_end(item);
            return;
        }


        Node* current_item = head;
        int i=1;
        while (i < index-1 && current_item->next) {
            current_item = current_item->next;
            i++;
        }

        if (!current_item->next) {
            if (i < index-1) {
                std::cout << "Trying to insert out of bounds, Will insert at the end" << std::endl;
            }
            insert_at_end(item);
            return;
        }

        Node* new_item = new Node(item);
        new_item->next = current_item->next;
        new_item->before = current_item;
        
        current_item->next = new_item;
        new_item->next->before = new_item;
    }

    void display_items() {
        if(!head) {
            std::cout << "List has no items" << std::endl;
            return;
        }
        
        Node* current_item = head;
        std::cout << "NULL -> ";
        while (current_item) {
            std::cout << current_item->data << " -> ";
            current_item = current_item->next;
        }
        std::cout << "NULL" << std::endl;
    }

    void delete_at_beginning() {
        if (!head) {
            std::cout << "No Items to delete" << std::endl;
            return;
        }
        if (head == end) {
            delete head;
            head = nullptr;
            end = nullptr;
            return;
        }
        Node* new_head = head->next;

        delete head;
        head = new_head;
        new_head->before = nullptr;
    }

    void delete_at_end() {
        if (!end) {
            std::cout << "No Items to delete" << std::endl;
            return;
        }
        if (head == end) {
            delete end;
            end = nullptr;
            head = nullptr;
            return;
        }
        
        Node* new_end = end->before;
        delete end;
        end = new_end;
        end->next = nullptr;
    }

    void delete_at_index(int index) {
        if (!head) {
            std::cout << "No Items to remove" << std::endl;
            return;
        }
        if (index == 1) {
            delete_at_beginning();
            return;
        }
        if (head == end) {
            std::cout << "List has one item, choose correct index" << std::endl;
            return;
        }

        int i=1;
        Node* current_item = head;
        while (i < index-1 && current_item->next) {
            current_item = current_item->next;
            i++;
        }
       
        if (!current_item->next) {
            std::cout << "Index out of bounds" << std::endl;
            return;
        }

        if(!current_item->next->next) {
            delete_at_end();
            return;
        }

        Node* deleted_item = current_item->next;

        current_item->next = deleted_item->next;
        deleted_item->next->before = current_item;
        delete deleted_item;
    }

    void delete_all() {
        if (!head) {
            std::cout << "All items deleted" << std::endl;
            return;
        }
        if (head == end) {
            delete_at_beginning();
            return;
        }

        Node* current_item = head;
        Node* next_item;
        while(next_item) {
            next_item = current_item->next;
            delete current_item;
            current_item = next_item;
        }
        head = nullptr;
        end = nullptr;
    }

    T get_start() {
        if (head) {
            return head->data;
        }
        std::cout << "List has no items" << std::endl;
        return T();
    }

    T get_end() {
        if (end) {
            return end->data;
        }
        std::cout << "List has no items" << std::endl;
        return T();
    }

    T get_at_index(int index) {
        if (index == 1) {
            return get_start();
        }

        if (!head) {
            std::cout << "List has no items" << std::endl;
            return T();
        }

        Node* current_item = head;
        int i = 1;
        while (i <index && current_item->next) {
            current_item = current_item->next;
            i++;
        }

        if (i < index) {
            std::cout << "Index out of bounds" << std::endl;
            return T();
        }

        return current_item->data;
    }

};

template <typename T>
class Queue {

    std::vector<T> data;

public:

    void queue(T item) {
        data.push_back(item);
    }

    T dequeue() {
        if (!data.empty()) {
            T item = data[0];
            data.erase(data.begin());
            return item;
        }
        return T();
    }

    void print_queue() {
        for (auto& item : data) {
            std::cout << item << " " ;
        }
        std::cout << std::endl;
    }

    T front() {
        if(!data.empty()) 
            return data[0];
        
        return T();
    }

    T rear() {
        if(!data.empty())
            return data[data.size()-1];
        
        return T();
    }

    bool is_empty() {
        return data.empty();
    }

    int size() {
        return data.size();
    }


};

class HashTable {

private:
    // a collection of lists, each list holding pairs of data.
    std::vector<std::list<std::pair<std::string, int>>> table;

    int numBuckets;

    int hashFunction(const std::string& key) {
        int hash = 0;
        for (char ch : key) {
            hash = (hash * 31 + ch) % numBuckets;
        }
        return hash;
    }

public:

    // num of buckets determines the likelihood of collisions.
    HashTable(int size) : numBuckets(size) {
        table.resize(numBuckets);
    }

    void insert(const std::string& key, int value) {
        int index = hashFunction(key); // this will decide to which bucket the data goes to.
        for (auto& pair : table[index]) {
            if (pair.first == key) {
                pair.second = value; // Update value if key already exists
                return;
            }
        }
        table[index].emplace_back(key, value); // Insert new key-value pair
    }

    void remove(const std::string& key) {
        int index = hashFunction(key); // find the bucket
        auto& pairs = table[index];
        for (auto it = pairs.begin(); it != pairs.end(); ++it) { // look through it
            if (it->first == key) {
                pairs.erase(it); // remove when found
                return;
            }
        }
    }

    int search(const std::string& key) {
        int index = hashFunction(key);
        for (const auto& pair : table[index]) {
            if (pair.first == key) {
                return pair.second;
            }
        }
        throw std::runtime_error("Key not found");
    }

    void display() {
        for (int i = 0; i < numBuckets; ++i) {
            std::cout << "Bucket " << i << ": ";
            for (const auto& pair : table[i]) {
                std::cout << "(" << pair.first << ", " << pair.second << ") ";
            }
            std::cout << std::endl;
        }
    }

};

template <typename T>
class BinaryTree {

    struct Node {
        T val;
        Node* left = nullptr;
        Node* right = nullptr;

        Node (T val) {
            this->val = val;
        }
    };

public: 

    BinaryTree(std::vector<T> data) {
        if (data.empty()) return;

        tree = new Node(data[0]);
        std::queue<Node*> q;
        q.push(tree);

        size_t i = 1;
        while (i < data.size()) {
            Node* current = q.front();
            q.pop();

            if (i < data.size()) {
                current->left = new Node(data[i++]);
                q.push(current->left);
            }
            if (i < data.size()) {
                current->right = new Node(data[i++]);
                q.push(current->right);
            }
        }
    }

    ~BinaryTree() {
        clear(tree);
    }

    void traversal_dfs() {
        dfs_traversal(tree);
        std::cout << std::endl;
    }

    void traversal_bfs() {

        if (tree == nullptr) return;

        std::queue<Node*> nodes;
        nodes.push(tree);

        while (!nodes.empty()) {
            
            Node* node = nodes.front();
            nodes.pop();

            std::cout << node->val << " ";

            if (node->left != nullptr)   nodes.push(node->left);
            if (node->right != nullptr)  nodes.push(node->right);
        }
        std::cout << std::endl;
    }

    void insert(T item) {
        if (tree == nullptr) {
            tree = new Node(item);
            return;
        }

        std::queue<Node*> nodes;
        nodes.push(tree);

        while (!nodes.empty()) {
            
            Node* node = nodes.front();
            nodes.pop();

            if (node->left == nullptr) {
                node->left = new Node(item);
                return;
            } nodes.push(node->left);

            if (node->right == nullptr) {
                node->right = new Node(item);
                return;
            } nodes.push(node->right);
        }
    }

    bool search_dfs(T item) {
        return dfs_search(item, tree);
    }

    void delete_item(T item) {

        if (tree == nullptr) return;

        std::queue<Node*> nodes;
        nodes.push(tree);
        Node* target = nullptr;

        while (!nodes.empty()) {
            Node* curr = nodes.front();
            nodes.pop();

            if (curr->val == item) { 
                target = curr;
                break;
            }

            if (curr->left) nodes.push(curr->left);
            if (curr->right) nodes.push (curr->right);
        }

        if (target == nullptr) return;

        // a pair of child - parent nodes
        std::pair<Node*, Node*> last_pair = {nullptr, nullptr};
        
        std::queue<std::pair<Node*, Node*>> pairs;
        pairs.push({tree, nullptr});

        while (!pairs.empty()) {
            auto curr = pairs.front();
            pairs.pop();

            last_pair = curr;

            if (curr.first->left) pairs.push({curr.first->left, curr.first});
            if (curr.first->right) pairs.push({curr.first->right, curr.first});
        }

        Node* last_node = last_pair.first;
        Node* last_parent = last_pair.second;

        target->val = last_node->val;

        if (last_parent == nullptr) { // if tree only has one item
            delete last_node;
            tree = nullptr;
            return;
        }
        // you have to set LHS or RHS to nullptr, deleting it frees the memory, but wont nullfy it.
        if (last_parent->left == last_node) last_parent->left = nullptr;
        else last_parent->right = nullptr;
        delete last_node;
    }

private:

    void clear(Node* node) {
        if (node) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

    Node* tree = nullptr;

    void dfs_traversal(Node* tree) {
        if (tree == nullptr) return;

        dfs_traversal(tree->left);
        std::cout << tree->val << " ";
        dfs_traversal(tree->right);
    }

    bool dfs_search(T item, Node* tree) {
        if (tree == nullptr) return false;

        if (tree->val == item) return true;

        bool lhs_result = dfs_search(item, tree->left);
        bool rhs_result = dfs_search(item, tree->right);

        return lhs_result || rhs_result;
    }




};

template <typename T>
class RedBlackTree {
    /* it is a self balancing binary tree
    * has simple color code of red and black
    * auto balances itself after every insertion or deletion
    * better to use it when we have lots of insertions and deletions
    * they always maintain a balance between RHS and LHS subtrees
    * Used to make sets and maps, worst case is O(log n)
    */

   struct Node {
        T data;
        std::string color;
        Node *left, *right, *parent;

        Node(T data) : 
            data(data),
            color("RED"),
            left(nullptr),
            right(nullptr),
            parent(nullptr) {}
   };

private:

    Node* root;
    Node* NIL;

    void leftRotate(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        if (y->left != NIL) {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            root = y;
        }
        else if (x == x->parent->left) {
            x->parent->left = y;
        }
        else {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }

    void rightRotate(Node* x) {
        Node* y = x->left;
        x->left = y->right;
        if (y->right != NIL) {
            y->right->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            root = y;
        }
        else if (x == x->parent->right) {
            x->parent->right = y;
        }
        else {
            x->parent->left = y;
        }
        y->right = x;
        x->parent = y;
    }

    void fixInsert(Node* k) {
        while (k != root && k->parent->color == "RED") {
            if (k->parent == k->parent->parent->left) {
                Node* u = k->parent->parent->right; // uncle
                if (u->color == "RED") {
                    k->parent->color = "BLACK";
                    u->color = "BLACK";
                    k->parent->parent->color = "RED";
                    k = k->parent->parent;
                }
                else {
                    if (k == k->parent->right) {
                        k = k->parent;
                        leftRotate(k);
                    }
                    k->parent->color = "BLACK";
                    k->parent->parent->color = "RED";
                    rightRotate(k->parent->parent);
                }
            }
            else {
                Node* u = k->parent->parent->left; // uncle
                if (u->color == "RED") {
                    k->parent->color = "BLACK";
                    u->color = "BLACK";
                    k->parent->parent->color = "RED";
                    k = k->parent->parent;
                }
                else {
                    if (k == k->parent->left) {
                        k = k->parent;
                        rightRotate(k);
                    }
                    k->parent->color = "BLACK";
                    k->parent->parent->color = "RED";
                    leftRotate(k->parent->parent);
                }
            }
        }
        root->color = "BLACK";
    }

    void inorderHelper(Node* node) {
        if (node != NIL) {
            inorderHelper(node->left);
            std::cout << node->data << " ";
            inorderHelper(node->right);
        }
    }

    Node* searchHelper(Node* node, int data) {
        if (node == NIL || data == node->data) {
            return node;
        }
        if (data < node->data) {
            return searchHelper(node->left, data);
        }
        return searchHelper(node->right, data);
    }

public:

    RedBlackTree() {
        NIL = new Node(0);
        NIL->color = "BLACK";
        NIL->left = NIL->right = NIL;
        root = NIL;
    }

    void insert(T data) {
        Node* new_node = new Node(data);
        new_node->left = NIL;
        new_node->right = NIL;

        Node* parent = nullptr;
        Node* current = root;

        // BST insert
        while (current != NIL) {
            parent = current;
            if (new_node->data < current->data) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }

        new_node->parent = parent;

        if (parent == nullptr) {
            root = new_node;
        }
        else if (new_node->data < parent->data) {
            parent->left = new_node;
        }
        else {
            parent->right = new_node;
        }

        if (new_node->parent == nullptr) {
            new_node->color = "BLACK";
            return;
        }

        if (new_node->parent->parent == nullptr) {
            return;
        }

        fixInsert(new_node);
    }

    void inorder() { 
        inorderHelper(root);
        std::cout << std::endl;
    }

    Node* search(int data) {
        return searchHelper(root, data);
    }


};

template <typename T>
class BST {
    /* Stores data in a sorted manner
     * Left Node < Parent < Right Node
     * Allows for efficient operations
    */
private:
   struct Node {
        T data;
        Node* left;
        Node* right;
        Node(T data) : data(data) {
            left = nullptr;
            right = nullptr;
        }
   };

    Node* root = nullptr;

    Node* construct_tree(std::vector<T>& data, int start, int end) {
        if (start > end)
            return nullptr;
        
        int mid = start + (end - start) / 2;
        Node* node = new Node(data[mid]);
        node->left =  construct_tree(data, start, mid-1);
        node->right = construct_tree(data, mid +1, end);
        return node;
    }

    void assign_tree(std::vector<T>& data) {
        std::sort(data.begin(), data.end());
        root = construct_tree(data, 0, data.size()-1);
    }

    bool find(T item, Node* node) {
        if (node == nullptr)
            return false;
        
        if (item == node->data)
            return true;
        
        bool l_search;
        bool r_search;

        if (item > node->data) {
            l_search = find(item, node->right);
        } else if (item < node->data) {
            r_search = find(item, node->left);
        }
        
        return (l_search || r_search);
    }

    Node* insert (T item, Node* node) {
        if (node == nullptr)
            node = new Node(item);

        if (item > node->data) {
            node->right = insert(item, node->right);
        }
        else if (item < node->data) {
            node->left = insert(item, node->left);
        }
        
        return node;
    }

    Node* search(T key, Node* node) {
        if (node == nullptr || node->data == key)
            return node;

        if (key > node->data)
            return search(key, node->right);
        else 
            return search(key, node->left);
    }

    Node* find_successor(Node* curr) { 
        // go right once
        // then keep going left until u get a null
        curr = curr->right;
        while (curr != nullptr && curr->left != nullptr)
            curr = curr->left;
        return curr;
    }

    Node* remove(T item, Node* node) {
        
        if (node == nullptr)
            return node;
        
        if (node->data > item)
            node->left = remove(item, node->left);
        else if (node->data < item)
            node->right = remove(item, node->right);
        else {

            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }

            if (node->right == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }

            // both nodes are present
            Node* succ = find_successor(node);
            node->data = succ->data;
            // when removing any part of thre tree, you must update the parent branch
            node->right = remove(succ->data, node->right);
        }
        return node;
    }

    void display_tree_dfs(Node* node) {
        if (node == nullptr)
            return;
        display_tree_dfs(node ->left);
        std::cout << node->data << " ";
        display_tree_dfs(node->right);
    }

public:

    BST(std::vector<T> data) {
        assign_tree(data);
    }

    void display_tree_dfs() {
        display_tree_dfs(root);
    }

    void display_tree_bfs() {

        if (root == nullptr)
            return;
        
        std::queue<Node*> nodes;
        nodes.push(root);

        while(!nodes.empty()) {
            Node* curr = nodes.front();
            nodes.pop();

            std::cout << curr->data << " ";

            if (curr->left != nullptr) {
                nodes.push(curr->left);
            }

            if (curr->right != nullptr) {
                nodes.push(curr->right);
            }
        }

        std::cout << std::endl;
    }

    bool find(T item) {
        return find(item, root);
    }

    void insert(T item) {
        root = insert(item, root);
    }

    Node* search(T key) {
        return search(key, root);
    }

    Node* remove(T item) {
        return remove(item, root);
    }

};

// Testing ---------------------------------------
void test_stack_1();

void test_SLL_1();
void test_SLL_2();
void test_SLL_3();

void test_DLL_1();
void test_DLL_2();
void test_DLL_3();
void test_DLL_4();
void test_DLL_5();
void test_DLL_6();

void test_qu_1();

void test_ht_1();

void test_b_tree1();

void test_rb_tree_1();

void test_bs_tree_1();
