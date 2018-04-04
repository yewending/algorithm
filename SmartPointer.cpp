/*
������һ��������ָ���demo��
����ָ���ཫһ������������ָ��Ķ�������������ü������ٸ����ж��ٸ�������ͬһָ�롣
ÿ�δ�������¶���ʱ����ʼ��ָ�벢�����ü�����Ϊ1��
��������Ϊ��һ����ĸ���������ʱ���������캯������ָ�벢������֮��Ӧ�����ü�����
��һ��������и�ֵʱ����ֵ�������������������ָ��������ü�����������ü���Ϊ����0����ɾ�����󣩣�
�������Ҳ�������ָ��������ü�����������������ʱ�����캯���������ü�����������ü�������0����ɾ���������󣩡�
����ָ�����ģ��ָ�붯�����ࡣ���е�����ָ�붼������->�� * ��������
����ָ�뻹������������ܣ��Ƚ����õ����Զ����١�����Ҫ������ջ����������������Լ���ʱ��������������ʵ�֣�
���������ͷ��ڴ档
*/


#include <iostream>
#include <memory>

template<typename T>
class SmartPointer {
private:
	T* _ptr;
	size_t* _count;
public:
	SmartPointer(T* ptr = nullptr) :
		_ptr(ptr) {
		if (_ptr)
		{
			_count = new size_t(1);
		}
		else
		{
			_count = new size_t(0);
		}
	}
	//��������
	SmartPointer(const SmartPointer& ptr)
	{
		if (this != &ptr)
		{
			this->_ptr = ptr._ptr;
			this->_count = ptr._count;
			(*this->_count)++;
		}
	}
	//��ֵ����
	SmartPointer& operator=(const SmartPointer& ptr)
	{
		if (this->_ptr == ptr._ptr)
		{
			return *this;
		}
		if (this->_ptr)
		{
			(*this->_count)--;
			if (this->_count == 0)
			{
				delete this->_ptr;
				delete this->_count;
			}
		}
		this->_ptr = ptr._ptr;
		this->_count = ptr._count;
		(*this->_count)++; 
	}

	T& operator*()
	{
		assert(this->_ptr == nullptr);
		return *(this->_ptr);
	}
	T* operator->()
	{
		assert(this->_ptr == nullptr);
		return this->_ptr;

	}

	~SmartPointer()
	{
		(*this->_count)--;
		if (*this->_count == 0)
		{
			delete this->_ptr;
			delete this->_count;
		}
	}
	size_t use_count()
	{
		return *this->_count;
	}

};

int main()
{
	SmartPointer<int> sp(new int(10));
	std::cout << sp.use_count() << std::endl;
	SmartPointer<int> sp2(sp);
	std::cout << sp.use_count() << std::endl;
	SmartPointer<int> sp3(new int(20)); 
	sp2 = sp3; 
	std::cout << sp3.use_count() << std::endl;

	return 0;
}