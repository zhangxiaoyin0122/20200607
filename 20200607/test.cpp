#include <iostream>
#include <string>

using namespace std;

class String {
public:
	typedef char* iterator;

	iterator begin() {
		return _str;
	}

	iterator end() {
		return _str + _size;
	}
	//构造函数
	String(const char* str) {
		_size = strlen(str);
		_str = new char[_size + 1];
		strcpy(_str, str);
		_capacity = _size;
	}
	//拷贝构造
	String(const String& str) 
		:_str(new char[str._capacity+1])
		,_size(str._size)
		,_capacity(str._capacity)
	{
		strcpy(_str, str._str);
	}
	//拷贝构造:现代写法
	String(const String& str)
		:_str(new char[str._capacity + 1])
		, _size(0)
		, _capacity(0)
	{
		//调用构造函数
		String tmp(str._str);
		Swap(tmp);
	}
	void Swap( String& str) {
		swap(_str, str._str);
		swap(_size, str._size);
		swap(_capacity, str._capacity);
	}
	String& operator=(const String& str) {
		if (this != &str) {
			char* tmp = new char[str._capacity + 1];
			strcpy(tmp,str._str);
			delete[]_str;
			_str = tmp;
			_size = str._size;
			_capacity = str._capacity;
		}
	}
	String& operator=(String str) {
		Swap(str);
		return *this;	
	}
	const char* c_str()const {
		return _str;
	}
	//析构函数
	~String() {
		if (_str) {
			delete[]_str;
			_size = _capacity = 0;
			_str = nullptr;
		}
	}
private:
	char* _str;
	size_t _size;
	size_t _capacity;
};

String operator+(const String& s, const String& str) {
	String ret(s);
	ret += str.c_str();
	return ret;
}
String operator+(const String& s, const char* str) {
	String ret(s);
	ret += str;
	return ret;
}
String operator+(const String& s, const char& ch) {
	String ret(s);
	ret += ch;
	return ret;
}
ostream& operator<<(ostream& cout,  String& str) {

	for (const auto& ch : str) {
		cout << ch;
	}
	cout << endl;
}
void test() {
	String s1("1234");
}
int main() {
	test();
	return 0;
}