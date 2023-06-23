// #include<bits/stdc++.h>
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <strstream>
#include <tuple>
#include <typeinfo>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;
class Node
{
public:
    int val;
    Node *next;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};
void print_original(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}
void removeElements(Node *&head, int val)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (head->val == val)
        {
            head = head->next;
            temp = head; // Move temp to the new head
            continue;
        }
        else if (temp->next != NULL && temp->next->val == val)
        {
            Node *deleteNode = temp->next;
            temp->next = temp->next->next;
            delete deleteNode;
            continue;
        }
        temp = temp->next;
    }
}
/*
 Node *temp = head;
    while (temp != NULL)
    {
        if (head->val == val)
        {
            head = head->next;
            continue;
        }
        else if (temp->next->val == val)
        {
            //
            Node *deleteNode = temp->next;
            temp->next = temp->next->next;
            delete deleteNode;
        }
        cout << temp->val << endl;
        temp = temp->next;
    }
*/
void insert_head(Node *&head, Node *&tail, int value)
{
    Node *newNode = new Node(value);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;

    head = newNode;
}
void insert_any_position(Node *head, int position, int value)
{
    Node *newNode = new Node(value);
    Node *temp = head;
    for (int i = 1; i <= position - 1; i++)
    {
        temp = temp->next;
    }
    // 10 20 100 30 40
    newNode->next = temp->next; // 100->30
    temp->next = newNode;       // 20->100
}
void insert_tail(Node *&head, Node *&tail, int value)
{
    Node *newNode = new Node(value);
    if (tail == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = tail->next;
}
int size(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
int main()
{

    Node *head = NULL;
    Node *tail = NULL;

    int val;
    cin >> val;
    int value;
    while (true)
    {
        cin >> value;
        if (value == -1)
        {
            break;
        }
        insert_tail(head, tail, value);
    }
    // insert_head(head, tail, value);
    // insert_any_position(head, pos, value);
    // cout << val << endl;
    removeElements(head, val);
    print_original(head);

    return 0;
}