#include <iostream>

class List {
public:
    List() = default;
    List(int initial_value);
    bool IsEmpty() const;
    void Show() const;
    void PushFront(int el);
    void PushBack(int el);
    void PopFront();
    void PopBack();
    int GetMedianValue() const;
    ~List();

private:
    struct Node {
        int value = 0;
        Node *next = nullptr;
    };

    Node *head = nullptr;
    Node *tail = nullptr;

};

List::List(int initial_value) {
    head = tail = new Node{initial_value};
}

bool List::IsEmpty() const { return head == nullptr; }

void List::Show() const {
    if (IsEmpty()) {
        std::cout << "List is empty";
        return;
    }

    Node *current = head;
    std::cout << "List elements: \n";
    while (current != nullptr) {
        std::cout << current->value << "\n";
        current = current->next;
    }
}

void List::PushFront(int el) {
    Node *new_node = new Node{el, head};
    head = new_node;
    if (tail == nullptr) {
        tail = head;
    }
}

void List::PushBack(int el) {
    Node *new_node = new Node{el};
    if (IsEmpty()) {
        head = tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
}

void List::PopFront() {
    if (IsEmpty()) {
        std::cout << "List is empty";
        return;
    }

    Node *temp = head;
    head = head->next;
    delete temp;

    if (head == nullptr) { 
        tail = nullptr;
    }
}

void List::PopBack() {
    if (IsEmpty()) {
        std::cout << "List is empty";
        return;
    }

    if (head == tail) {
        delete head;
        head = tail = nullptr;
        return;
    }

    Node *current = head;
    while (current->next != tail) {
        current = current->next;
    }
    
    delete tail;
    tail = current;
    tail->next = nullptr;
}

int List::GetMedianValue() const {
    if (IsEmpty()) {
        std::cout << "List is empty";
        return -1;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->value;
}

List::~List() {
    while (head != nullptr) {
        PopFront();
    }
}

int main() {
    {
        List list(1);
        
        list.PushBack(2);
        list.PushBack(3);

        list.Show();
        std::cout << "\n";
        std::cout << "Is empty: " << list.IsEmpty() << "\n";
        std::cout << "\n";

        list.PushBack(4);
        list.Show();

        std::cout << "\n";

        // push_front testing
        list.PushFront(0);
        list.Show();

        std::cout << "\n";

        // pop_front testing
        list.PopFront();
        list.Show();

        std::cout << "\n";
        // pop_back testing
        list.PopBack();
        list.Show();

        std::cout << "\n";

        // GetMedianValue testing
        std::cout << "Median: " << list.GetMedianValue() << "\n";
    }

    return 0;
}
