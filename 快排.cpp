int once_quick_sort(vector<int> &data, int left, int right)
{
    int key = data[left];
    while (left < right)
    {
        while (left < right && key <= data[right])
        {
            right--;
        }
        if (left < right)
        {
            data[left++] = data[right];
        }
        while (left < right && key > data[left])
        {
            left++;
        }
        if (left < right)
        {
            data[right--] = data[left];
        }
    }
    data[left] = key;
    return left;
}

int quick_sort(vector<int> & data, int left, int right)
{
    if (left >= right )
    {
        return 1;
    }
    int middle = 0;
    middle = once_quick_sort(data, left, right);
    quick_sort(data, left, middle-1);
    quick_sort(data, middle + 1, right);

};
