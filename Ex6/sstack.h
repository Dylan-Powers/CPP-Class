// sstack.h: simple string stack

#ifndef _sstack_h
#define _sstack_h

#include <string>

class StringStack {
public:
    StringStack();
    bool empty() const;
    void push(std::string new_item);
    std::string pop();
    void clear();
private:
    class StackNode {
        std::string _item;
        StackNode *_next;
    public:
        StackNode(std::string value, StackNode *n = nullptr)
                : _item(value), _next(n)
        { }
        std::string item() const { return _item; }
        StackNode *next() const { return _next; }
        inline void setNext(StackNode *new_item)
          { _next = new_item; };
    };

    StackNode *top;
};

#endif