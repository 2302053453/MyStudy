//#include<iostream>
//#include<deque>
//using namespace std;
///*
//	2016-03-10
//	deque를 사용하여 스택 구현(FIFO, LIFO)
//*/
//
//template <typename T> class Stack
//{
//public:
//	Stack() 
//	{ 
//		Clear(); 
//	}
//	void SetLIFO(bool isLIFO)
//	{ 
//		IsFIFO = isLIFO; 
//	}
//
//	bool IsEmpty()
//	{ 
//		return dataList.empty();
//	}
//	void Clear() 
//	{ 
//		dataList.clear(); 
//	}
//	int GetStackSize() 
//	{ 
//		return dataList.size(); 
//	}
//	void Push(T data)
//	{
//		dataList.push_back(data);
//	}
//	void Pop(T *data)
//	{
//		if (IsEmpty())
//			return ;
//		else
//		{
//			memcpy(data, IsFIFO ? &dataList.back() : &dataList.front(), sizeof(T));
//			IsFIFO ? dataList.pop_back() : dataList.pop_front();
//		}
//	}
//private:
//	deque<T> dataList;
//	bool	IsFIFO;
//};
//
//void main()
//{
//	int value;
//	int count;
//	Stack<int> stack1;
//	stack1.SetLIFO(true);
//	stack1.Push(1);
//	stack1.Push(2);
//	stack1.Push(3);
//	count = stack1.GetStackSize();
//	while(count > 0)
//	{ 
//		stack1.Pop(&value);
//		cout << value << endl;
//		count--;
//	}
//
//	stack1.SetLIFO(false);
//	stack1.Push(1);
//	stack1.Push(2);
//	stack1.Push(3);
//	count = stack1.GetStackSize();
//	while (count > 0)
//	{
//		stack1.Pop(&value);
//		cout << value << endl;
//		count--;
//	}
//	system("PAUSE");
//}