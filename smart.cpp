#include <iostream>
#include "smart.h"
using namespace std;

int main(void)
{
    int *i = new int(2);
    smart_ptr_t<int> ptr1(i);
    {
        smart_ptr_t<int> ptr2(ptr1);
        {
            smart_ptr_t<int> ptr3 = ptr2;
            cout << *ptr1 << endl;
            *ptr1 = 20;
            cout << *ptr2 << endl;
        }
    }
    return 0;
}
