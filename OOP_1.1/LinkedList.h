#pragma once

#include <iostream>

using namespace std;

template<class L>
struct node {
    node<L>* next;
    L data;
};

template<class L>
class LinkedList
{
public:
    node<L>* head;
    node<L>* last;
    LinkedList<L>() {
        head = NULL;
        last = NULL;
    }
    void add(L data) {
        if (!head) {
            head = new node<L>;
            head->data = data;
            head->next = NULL;
            last = head;
        }
        else {
            if (last == head) {
                last = new node<L>;
                last->data = data;
                last->next = NULL;
                head->next = last;
            }
            else {
                node<L>* insdata = new node<L>;
                insdata->data = data;
                insdata->next = NULL;
                last->next = insdata;
                last = insdata;
            }
        }
    }

    L get(int index) {
        if (index == 0) {
            return this->head->data;
        }
        else {
            node<L>* curr = this->head;
            for (int i = 0; i < index; ++i) {
                curr = curr->next;
            }
            return curr->data;
        }
    }

    L operator[](int index) {
        return get(index);
    }
};

