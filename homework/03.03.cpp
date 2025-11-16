#include <iostream>

class List {

public:
  
  bool const is_empty();
  void const show();
  void       push_front(Node *new_node);
  void       push_back(Node *new_node);
  void       pop_front();
  void       pop_back();
  int  const get_median_value();
  ~List();

private:
  struct Node {
    int m_value = 0;
    Node *next = nullptr;
    };

  Node *head = nullptr;
  Node *tail = nullptr;

};

bool const List::is_empty() { return head == nullptr; }

void const List::show() {
  if (is_empty()) {
    std::cout << "List is empty";
    return;
  }

  Node *tail_copy = head;
  std::cout << "List elements: \n";
  while (tail_copy != nullptr) {
    std::cout << tail_copy->value << "\n";
    tail_copy = tail_copy->next;
  }
}

void List::push_front(int value) {
  Node *new_node;
  new_node->m_value = value;
  new_node->next = head;
  head = new_node;
}

void List::push_back(int value) {
  Node *new_node;
  new_node->m_value = value;
  tail->next = new_node;
  tail = new_node;
}

void List::pop_front() {
  if (is_empty()) {
    std::cout << "List is empty";
    return;
  }

  auto head_tmp = head->next;
  delete head;
  head = head_tmp;
}

void List::pop_back() {
  if (is_empty()) {
    std::cout << "List is empty";
    return;
  }

  Node *head_copy = head;
  while (head_copy->next != tail) {
    head_copy = head_copy->next;
  }
  delete tail;
  tail = head_copy;
  tail->next = nullptr;
}

//  Fast pointer faster than slow pointer in 2 times
int List::GetMedianValue() {
  if (IsEmpty()) {
    std::cout << "List is empty";
    return -1;
  }

  Node *slow = head;
  Node *fast = head;

  while (slow != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow->value;
}

List::~List() {
  Node *current =this-> head;
  while ( != nullptr) {
    Node *next = current->next;
    delete current;
    current = next;
  }

private:

  struct Node {
    int value = 0;
    Node *next = nullptr;
    };

  Node *head = nullptr;
  Node *tail = nullptr;

}

int main() {
  

/*
    // List Initialization
    Node *head = new Node{1};
    Node *node1 = new Node{2};
    Node *tail = new Node{3};

    head->next = node1;
    node1->next = tail;

    List list(head, tail);

    list.show();
    std::cout << "\n";
    std::cout << list.IsEmpty() << "\n";
    std::cout << "\n";

    // push_back testing
    Node *add_el1 = new Node{4};
    list.push_back(add_el1);
    list.show();

    std::cout << "\n";

    // push_front testing
    Node *add_el2 = new Node{0};
    list.push_front(add_el2);
    list.show();

    std::cout << "\n";

    // pop_front testing
    list.pop_front();
    list.show();

    std::cout << "\n";
    // pop_back testing
    list.pop_back();
    list.show();

    std::cout << "\n";

    // GetMedianValue testing
    std::cout << list.GetMedianValue() << "\n";
  }
  */

  List list;

  return 0;
}
