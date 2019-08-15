//为该类型函数添加赋值运算符函数


class CMyString
{
    public:
        CMyString(char* pData = nullptr);
        CMyString(const CMyString& str);
        ~CMyString(void);

        CMyString& operator = (const CMyString& str);

        void Print();

    private:
        char* m_pData;

};




//方法一
CMyString& CMystring::operator=(const CMyString& str)  
{
    if(this == &str)
    {
        return *this;
    }

    delete []m_PData;
    m_pData = nullptr;
    
    m_PData = new char[strlen(str.m_pData) + 1];
    strcpy(m_PData, str.m_PData);

    return *this;
}
//返回值类型为该类型的引用，并在函数前返回实例自身的引用，才能拿连续赋值。
//传参应为类型声明的常量引用。如果传参不是引用而是实例，那么从形参到实参会调用一次复制构造函数，可能会造成一直递归调用
//释放自身原有内容，防止出现内存泄露


//方法二
CMyString& CMyString::operator=(const CMyString& str)
{
    if(this != &str)
    {
        CMyString tmp(str);
        
        char* pTmp = tmp.m_pData;
        tmp.m_pData = m_pData;
        m_pData = pTmp;
    }

    return *this;
}
//tmp.m_pData 和 m_pData进行了交换
//在 tmp 出了 if 后会自动调用析构函数释放内存，而tmp.m_pData指向的就是原来m_pData的内存，从而释放了实例的内存
