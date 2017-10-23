#include <iostream>
#include "smart.h"
#include "handle.h"
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

    {
        handle_t<int> hp(new int(42));
        {
            handle_t<int> hp2 = hp;
            cout<<*hp<<"  "<<*hp2<<endl;
            *hp2 = 10;
        }
        cout<<*hp<<endl;
    }
    return 0;
}
