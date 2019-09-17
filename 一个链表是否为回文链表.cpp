//思路：使用栈存储链表前半部分，然后一个个出栈，与后半部分元素比较，如果链表长度未知，可以使用快慢指针的方法，将慢指针指向的元素入栈，然后如果快指针指向了链表尾部，此时慢指针指向了链表中间


bool is_palindromic_list2(mylist *a_list)
{
    if(a_list == nullptr)
    {
        return false;
    }
    stack<int> list_value;
    mylist * fast =a_list;
    mylist *slow =a_list;
    while(fast->next!=nullptr && fast->next->next!=nullptr)
    {
        list_value.push(slow->next->value);
        slow = slow->next;
        fast = fast->next->next;
    }
    cout<<"middle elem value is "<<slow->next->value<<endl;
    if(fast->next != nullptr)
    {
        cout<<"the list has odd num of node"<<endl;
        slow =slow->next;
    }
    int cur_value;
    while(!list_value.empty())
    {
        cur_value = list_value.top();
        cout<<"stack top value is"<<cur_value<<endl;
        cout<<"list value is "<<slow->next->value<<endl;
        if(cur_value != slow->next->value)
        {
            return false;
        }
        list_value.pop();
        slow = slow->next;
    }
    return true;
}
