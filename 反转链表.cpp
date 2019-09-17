Void reversal_list(mylist * a_list)
{
    mylist * forward_node = nullptr;
    mylist * cur_node = a_list->next;
    mylist* next_node = cur_node->next;
    if(cur_node == nullptr)
    {
        return ;

    }
    while(1)
    {
        cur_node->next = forward_node;
        forward_node = cur_node;
        cur_node = next_node;
        if(cur_node == nullptr)
        {
            break;

        }
        next_node = cur_node->next;
    }
    a_list->next = forward_node;
}
