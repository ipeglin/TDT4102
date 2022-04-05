#include "LinkedList.h"

namespace LinkedList {
    std::ostream& operator<<(std::ostream &os, const Node &node) {
        os << "Node content:" << std::endl
           << "\tValue: " << node.getValue() << std::endl
           << "\tNext node: " << node.getNext() << std::endl
           << "\tPrevious node: " << node.getPrev();

        return os;
    }

    Node* LinkedList::insert(Node* pos, const std::string &value) {
        if (head.get() == pos) {
            head = std::make_unique<Node>(value, std::move(head), nullptr);
            pos->prev = head.get();
        } else {
            std::unique_ptr<Node> new_ptr = std::make_unique<Node>(value, std::move(pos->prev->next), pos->prev);
            pos->prev = new_ptr.get();
            pos->prev->next = move(new_ptr);
        }

        return pos->prev;
    }

    Node* LinkedList::remove(Node* pos) {
        if (pos->prev == nullptr) {
            pos->next->prev = nullptr;
            pos->next = std::move(head);

            return head.get();
        } else if (pos->next.get() == tail) {
            pos->prev->next = std::move(pos->next); // Moving unique_ptr

            return pos->next.get();
        } else {
            pos->next->prev = pos->prev;
            pos->prev->next = std::move(pos->next); // Moving unique_ptr
            return pos->next.get();
        }
    }

    Node* LinkedList::find(const std::string &value) {
        if (head->getValue() == value) {
            return head.get();
        }

        Node *ptr{head->next.get()};
        while (ptr != tail) {
            if (ptr->getValue() == value) {
                return ptr;
            } else {
                ptr = ptr->next.get();
            }
        }

        return tail;
    }

    void LinkedList::remove(const std::string &value) {
        remove(find(value));
    }

    std::ostream& operator<<(std::ostream &os, const LinkedList &list) {
        os << "List content: " << std::endl << std::endl;

        for (Node &node : list) {
            os << node << std::endl;
        }

        return os;
    }
}