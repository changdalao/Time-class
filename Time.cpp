#include<iostream>
using namespace std;

class Time
{
private:
	int _hour;
	int _minute;
	int _sec;
public:
	Time(int, int, int);//全缺省构造函数
	Time(Time& t);//拷贝构造函数
	~Time();//析构函数
	void operator+(Time& t);//时间的加法
	void operator-(Time& t);//时间的减法
	void Show();//显示函数
};

Time::Time(int hour = 24, int minute = 0, int sec = 0)
{
	_hour = hour;
	_minute = minute;
	_sec = sec;
	//cout << "调用了构造函数" << endl;
}
Time::Time(Time& t)
{
	_hour = t._hour;
	_minute = t._minute;
	_sec = t._sec;
	cout << "调用了拷贝构造函数" << endl;
}
Time::~Time()
{
	cout << "调用了析构函数" << endl;
}
void Time::Show()
{
	cout << _hour << ":" << _minute << ":" << _sec << endl;
}
void Time::operator+(Time& t)
{
	_hour = this->_hour + t._hour;
	_minute = this->_minute + t._minute;
	_sec = this->_sec + t._sec;
	if (_hour > 24)
		_hour = _hour % 24;
	if (_minute > 60)
	{
		int tmp = _minute / 60;
		_hour += tmp;
		_minute = _minute % 60;
	}
	if (_sec > 60)
	{
		int tmp = _sec / 60;
		_minute += tmp;
		if (_minute > 60)
		{
			int tmp = _minute / 60;
			_hour += tmp;
			_minute %= 60;
		}
		_sec = _sec % 60;
	}
}
void Time::operator-(Time& t)
{
	_hour -= t._hour;
	_minute -= t._minute;
	_sec -= t._sec;
	if (_sec < 0)
	{
		int pos = -_sec;//将负数转为正，方便计算
		int tmp = pos / 60;//方便计算分钟
		if (pos > 60)
		{
			_sec = pos - 60;
		}
		else
			_sec = 60 - pos;
		//秒处理完后，可能影响到分钟，处理分钟
			if (tmp == 0)
				_minute -= 1;
			else
				_minute -= tmp;
	}
	if (_minute < 0)
	{
		int pos = -_minute;
		int tmp = pos / 60;
		if (pos < 60)
			_minute = 60 - pos;
		else
			_minute = pos - 60;
		//处理小时，分钟处理后可能影响到小时
			if (tmp == 0)
				_hour -= 1;
			else
				_hour -= tmp;
	}
	if (_hour < 0)
	{
		int pos = -_hour;
		if (pos < 24)
			_hour = 24 - pos;
		else
			_hour = pos % 24;
	}
}
int main()
{
	{
		Time t1;
		Time t2(t1);//验证拷贝构造函数
		Time t3(3,30,30);
		Time t4(12,0,59);
		cout << "初始时间>";
		t1.Show();
		
		cout << "时间相加>";
		t3.Show();
		cout << "1.相加后>";
		t1 + t3;
		t1.Show(); 

		cout << "时间相减>";
		t4.Show();
		cout << "2.相减后>";
		t1 - t4;
		t1.Show();
		cout << "时间相加>";
		t4.Show();
		t1 + t4;
		cout << "3.相加后>";
		t1.Show();
	}

	//在对象生命周期结束后，编译器会自动调用析构函数，先构造的后析构
	system("pause");
	return 0;
}