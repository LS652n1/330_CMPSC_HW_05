#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdexcept>
using namespace std;

template<typename T>
class Node
{
public:
  T element;  // Element contained in the node
  Node<T>* next; // Pointer to the next node

  Node() // No-arg constructor
  {
    next = nullptr;
  }

  Node(const T& e) // Constructor
  {
    this->element = e;
    next = nullptr;
  }
};

template<typename T>
class Iterator : public std::iterator<std::forward_iterator_tag, T>
{
public:
  Iterator(Node<T>* p)
  {
    current = p;
  }

  Iterator operator++() // Prefix ++
  {
    current = current->next;
    return *this;
  }

  Iterator operator++(int dummy) // Postfix ++
  {
    Iterator temp(current);
    current = current->next;
    return temp;
  }

  T& operator*()
  {
    return current->element;
  }

  bool operator==(const Iterator<T>& iterator)
  {
    return current == iterator.current;
  }

  bool operator!=(const Iterator<T>& iterator)
  {
    return current != iterator.current;
  }

private:
  Node<T>* current;
};

template<typename T>
class LinkedList
{
public:
  LinkedList(); // No-arg constructor
  LinkedList(const LinkedList<T>& list); // Copy constructor
  virtual ~LinkedList(); // Destructor
  LinkedList<T>& operator=(const LinkedList<T>& list);
  void addFirst(const T& e);
  void addLast(const T& e);
  T& getFirst() const;
  T& getLast() const;
  T removeFirst();
  T removeLast();
  void add(const T& e);
  void add(int index, const T& e);
  void clear();
  bool contains(const T& e) const;
  T& get(int index) const;
  int indexOf(const T& e) const;
  bool isEmpty() const;
  int lastIndexOf(const T& e) const;
  void remove(const T& e);
  int getSize() const;
  T removeAt(int index);
  T& set(int index, const T& e);

  Iterator<T> begin() const
  {
    return Iterator<T>(head);
  }

  Iterator<T> end() const
  {
    return Iterator<T>(tail->next);
  }

private:
  Node<T>* head;
  Node<T>* tail;
  int size;
};

template<typename T>
LinkedList<T>::LinkedList()
{
  head = tail = nullptr; // Initialize head and tail 
  size = 0;
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& list)
{
  head = tail = nullptr;
  size = 0;

  Node<T>* current = list.head;
  while (current != nullptr)
  {
    this->add(current->element);
    current = current->next;
  }
}

template<typename T>
LinkedList<T>::~LinkedList()
{
  clear();
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& list)
{
  if (this != &list) // Do nothing with self-assignment
  {
    clear(); // Destroy this
    head = tail = nullptr;
    size = 0;

    Node<T>* current = list.head;
    while (current != nullptr)
    {
      this->add(current->element);
      current = current->next;
    }
  }

  return *this;
}

template<typename T>
void LinkedList<T>::addFirst(const T& e)
{
  Node<T>* newNode = new Node<T>(e);
  newNode->next = head;
  head = newNode;
  size++;

  if (tail == nullptr)
    tail = head;
}

template<typename T>
void LinkedList<T>::addLast(const T& e)
{
  if (tail == nullptr)
  {
    head = tail = new Node<T>(e);
  }
  else
  {
    tail->next = new Node<T>(e);
    tail = tail->next;
  }

  size++;
}

template<typename T>
T& LinkedList<T>::getFirst() const
{
  if (size == 0)
    throw runtime_error("Index out of range");
  else
    return head->element;
}

template<typename T>
T& LinkedList<T>::getLast() const
{
  if (size == 0)
    throw runtime_error("Index out of range");
  else
    return tail->element;
}

template<typename T>
T LinkedList<T>::removeFirst()
{
  if (size == 0)
    throw runtime_error("No elements in the list");
  else
  {
    Node<T>* temp = head;
    head = head->next;
    if (head == nullptr) tail = nullptr;
    size--;
    T element = temp->element;
    delete temp;
    return element;
  }
}

template<typename T>
T LinkedList<T>::removeLast()
{
  if (size == 0 || size == 1)
    return removeFirst();
  else
  {
    Node<T>* current = head;
    for (int i = 0; i < size - 2; i++)
      current = current->next;

    Node<T>* temp = tail;
    tail = current;
    tail->next = nullptr;
    size--;
    T element = temp->element;
    delete temp;
    return element;
  }
}

template<typename T>
void LinkedList<T>::add(const T& e)
{
  addLast(e);
}

template<typename T>
void LinkedList<T>::add(int index, const T& e)
{
  if (index == 0)
    addFirst(e);
  else if (index >= size)
    addLast(e);
  else
  {
    Node<T>* current = head;
    for (int i = 1; i < index; i++)
      current = current->next;
    Node<T>* temp = current->next;
    current->next = new Node<T>(e);
    (current->next)->next = temp;
    size++;
  }
}

template<typename T>
void LinkedList<T>::clear()
{
  while (head != nullptr)
  {
    Node<T>* temp = head;
    head = head->next;
    delete temp;
  }

  tail = nullptr;
  size = 0;
}

template<typename T>
T& LinkedList<T>::get(int index) const
{
  if (index < 0 || index > size - 1)
    throw runtime_error("Index out of range");

  Node<T>* current = head;
  for (int i = 0; i < index; i++)
    current = current->next;

  return current->element;
}

template<typename T>
int LinkedList<T>::indexOf(const T& e) const
{
  // Implement it in this exercise
  Node<T>* current = head;
  for (int i = 0; i < size; i++)
  {
    if (current->element == e)
      return i;
    current = current->next;
  }

  return -1;
}

template<typename T>
bool LinkedList<T>::isEmpty() const
{
  return head == nullptr;
}

template<typename T>
int LinkedList<T>::getSize() const
{
  return size;
}

template<typename T>
T LinkedList<T>::removeAt(int index)
{
  if (index < 0 || index >= size)
    throw runtime_error("Index out of range");
  else if (index == 0)
    return removeFirst();
  else if (index == size - 1)
    return removeLast();
  else
  {
    Node<T>* previous = head;
    for (int i = 1; i < index; i++)
    {
      previous = previous->next;
    }

    Node<T>* current = previous->next;
    previous->next = current->next;
    size--;
    T element = current->element;
    delete current;
    return element;
  }
}

// The functions remove(const T& e), lastIndexOf(const T& e),
// contains(const T& e), and set(int index, const T& e) are
// left as an exercise

#endif
