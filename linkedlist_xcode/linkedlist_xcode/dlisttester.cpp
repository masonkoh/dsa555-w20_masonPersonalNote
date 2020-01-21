//
//  main.cpp
//  linkedlist_xcode
//
//  Created by Mason Youngmin Ko on 2020-01-21.
//  Copyright © 2020 Mason Youngmin Ko. All rights reserved.
//
#include <iostream>
#include "dlist.h"

int main(void) {
    DList<int> theList; // TEMPLATE SYNTAX TIP: replacing T, with int! look at the header!
    theList.push_front(1);
    theList.push_front(2);
    theList.push_front(3);
    
    theList.print(); // on console, it looks like: 3 2 1
    
    return 0;
}
