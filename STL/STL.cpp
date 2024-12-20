#include "STL.hh"
#include <iostream>

void vector_test() {

    std::vector<int> v1 = {24,55,61,8,26};

    // -------------- direct access
        std::cout << v1.at(3) << std::endl;
        std::cout << v1[2] << std::endl;
        std::cout << v1.front() << std::endl;
        std::cout << v1.back() << std::endl;

    // -------------- capacity dispaly
        std::cout << v1.empty() << std::endl;
        std::cout << v1.size() << std::endl;
        std::cout << v1.max_size() << std::endl;    
        std::cout << v1.capacity() << std::endl;
        
    // --------------- iterators
        std::vector<int>::iterator it;      // makes an iterator of the same vector type
        it = v1.begin();
        std::cout << *it << std::endl;      // must be de-referenced like a pointer
        it ++;                              // can be incremented like a pointer
        std::cout << *it << std::endl;
        it = v1.end();                      // end() will return the post last position
        std::cout << *it << std::endl;

        // const iterator
        std::vector<int>::const_iterator cit;
        cit = v1.cbegin();
        std::cout << *cit << std::endl;

        // reverese iterator, it also has a constant variation
        std::vector<int>::reverse_iterator rit;
        rit = v1.rbegin();
        std::cout << *rit << std::endl;

    // ---------------- Modifiers
        v1.clear();                         // clear all data
        v1.insert(v1.begin(), 4);           // takes in iterator as position
        v1.emplace(v1.begin()+1, 7);        // constructs element in place
        for (auto i : v1)
            std::cout << i << std::endl;
        v1.erase(v1.begin());               // erase at specific index/position
        v1.push_back(12);                   // adds elements to the end
        v1.emplace_back(32);
        v1.pop_back();                      // removes the last element
        v1.resize(1);
        for (auto i : v1)
            std::cout << i << std::endl;
        
        std::vector<int> v2 {1,2,3,4,5};
        v1.swap(v2); // swap the content of one vector with another
        for (auto i : v1)
            std::cout << i << std::endl;
}

void list_test() {

    std::list<int> l1;
    l1.assign(5, 123);                  // replaces all previous elements with new ones
    for (auto i : l1)
        std::cout << i << std::endl; 
    l1.assign(2, 444);
    for (auto i : l1)
        std::cout << i << std::endl;

    std::cout << l1.front() << std::endl;   // first element
    std::cout << l1.back() << std::endl;    // last element
    std::cout << l1.empty() << std::endl;
    std::cout << l1.size() << std::endl;

    l1.emplace(l1.begin() ,34);         // requires an iterator
    l1.insert(l1.begin(), 44);
    
    l1.emplace_back(56);                // add at end
    l1.push_back(44);
    l1.emplace_front(12);               // add at start
    l1.push_front(41);

    l1.pop_back();                      // remove at end
    l1.pop_front();                     // remove at start
    l1.erase(l1.begin());
    l1.clear();
    l1.remove(44);                      // removes all 44(s)
    // l1.remove_if();                  // take a function that returns true, will remove element based on function

    // l1.swap()                        // swap one set with another
    // l1.splice()                      // transfer elements from one set to another
    // l1.merge()                       // merge two lists into one sorted list

    l1.resize(3);                       // resize the set

    l1.sort();                          // sorts the elements
    l1.reverse();                       // reverse the order of elements in the list

    std::list<int>::iterator it;        // has full iterator support
    it = l1.begin();
    it = l1.end();

    std::list<int>::reverse_iterator rit;
    rit = l1.rbegin();
    rit = l1.rend();




}

void queue_test() {

    std::queue<int> q1;

    q1.push(23);        // adds items
    q1.emplace(33);

    q1.pop();           // removes items

    // q1.swap()        // swaps the content with another queue

    std::cout << q1.front() << std::endl;
    std::cout << q1.back()  << std::endl;
    std::cout << q1.empty() << std::endl;
    std::cout << q1.size() << std::endl;

    //using a dequeue will be better
    // it has lots functions that are offered by a list and a vector
}

void set_test() {

    std::set<int> s;

    s.insert(1);
    s.erase(0);
    s.clear();
    // s.swap();  swap content with another set
    s.emplace(3);
    s.emplace(5);
    s.emplace(88);


    // Has iterator support for const, and reverse iterators
    std::set<int>::iterator it;
    it = s.find(3);
    it = s.begin();
    it = s.end();
    std::cout << *it << std::endl;
    
    std::cout << s.count(3) << std::endl;
    std::cout << s.empty() << std::endl;
    std::cout << s.size() << std::endl;
    
    it = s.lower_bound(10);     // finds first element not less than given value
    std::cout << *it << std::endl;

    it = s.upper_bound(4);  // finds first element greater than given value
    std::cout << *it << std::endl;
}

void map_test() {
    
    std::map<int, int> m;

    m.clear();
    m.insert(std::pair<int,int>(1,1)); // insert requires a pair
    m.emplace(4,6);
    m.emplace(5,8);
    m.emplace(6,9);
    m.erase(1);
    m[88] = 23;
    // m.swap()     // you can swap elements with another map
    for (auto item : m) 
        std::cout << item.first << " " << item.second << std::endl;
    
    std::cout << m.count(5) << std::endl;
    std::cout << m.size() << std::endl;
    bool val = m.empty();
    int item = m.at(6);         // returns the item associated with the key 6
    int item2 = m[4];
    
    std::map<int,int>::iterator it;
    it = m.find(5); // finds element with key 5
    it = m.upper_bound(2);
    it = m.lower_bound(5);
    it = m.begin();
    it = m.end();

}

void stack_test() {
    std::stack<int> s;

    bool b1 = s.empty();
    bool b2 = s.size();

    s.push(1);
    s.push(2);
    s.emplace(3);
    s.emplace(4);

    std::cout << s.top() << std::endl;

    s.pop();
    s.pop();
    s.pop();

    // s.swap // requires another stack

    // does not support iterators, all elements must be accessed from the top.
}

