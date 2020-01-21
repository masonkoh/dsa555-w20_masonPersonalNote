//
//  dlist.h
//  linkedlist_xcode
//
//  Created by Mason Youngmin Ko on 2020-01-21.
//  Copyright © 2020 Mason Youngmin Ko. All rights reserved.
//

#ifndef dlist_h
#define dlist_h

// you have to declare template in header file.
template <typename T>
class DList{
    
    struct Node{ // next, prev pointer
        T data_;
        Node* next_;
        Node* prev_;
        Node(const T& data=T{}, Node* next=nullptr, Node* prev=nullptr){// constructor. defining an empty object.
            data_=data;
            next_=next;
            prev_=prev;
        };
    };
    
    
    // data members of DList
    Node* front_; // point to the first node // this is not a node itself, it's a pointer pointing to a node
    Node* back_;  // point to the last node // this is not a node itself, it's a pointer pointing to a node

public:
    // constructor. creates an instance of the LList. // 'DList' stands for 'Doubly Linked List'.
    DList();
    void push_front(const T& data); // const for safety(because the content doesn't need to be modified. & for reference.
    void push_back(const T& data);
    void pop_front();
    void pop_back();
    void print() const;
};

template <typename T> // why repeating this?
DList<T>::DList(){
    front_=nullptr;
    back_=nullptr;
};

template <typename T>
void DList<T>::push_front(const T& data){
        
    // what does my node constuctor wants?
    Node* nn=new Node(data); // you need a node pointer that points to the new node. // nn points to the node that you just made
    if(front_!=nullptr){
        front_->prev_=nn;
    }else{
        back_=nn;
    }
    front_=nn; // if you put *, it means whole thing of the target of nn. too much // if you put &, it's pointing to the pointer that points to the object, like a birdge. // so we don't put anything like * or &.
};

#endif /* dlist_h */
