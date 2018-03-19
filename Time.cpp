#include<iostream>
using namespace std;

class Time
{
private:
	int _hour;
	int _minute;
	int _sec;
public:
	Time(int, int, int);//ȫȱʡ���캯��
	Time(Time& t);//�������캯��
	~Time();//��������
	void operator+(Time& t);//ʱ��ļӷ�
	void operator-(Time& t);//ʱ��ļ���
	void Show();//��ʾ����
};

Time::Time(int hour = 24, int minute = 0, int sec = 0)
{
	_hour = hour;
	_minute = minute;
	_sec = sec;
	//cout << "�����˹��캯��" << endl;
}
Time::Time(Time& t)
{
	_hour = t._hour;
	_minute = t._minute;
	_sec = t._sec;
	cout << "�����˿������캯��" << endl;
}
Time::~Time()
{
	cout << "��������������" << endl;
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
		int pos = -_sec;//������תΪ�����������
		int tmp = pos / 60;//����������
		if (pos > 60)
		{
			_sec = pos - 60;
		}
		else
			_sec = 60 - pos;
		//�봦����󣬿���Ӱ�쵽���ӣ��������
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
		//����Сʱ�����Ӵ�������Ӱ�쵽Сʱ
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
		Time t2(t1);//��֤�������캯��
		Time t3(3,30,30);
		Time t4(12,0,59);
		cout << "��ʼʱ��>";
		t1.Show();
		
		cout << "ʱ�����>";
		t3.Show();
		cout << "1.��Ӻ�>";
		t1 + t3;
		t1.Show(); 

		cout << "ʱ�����>";
		t4.Show();
		cout << "2.�����>";
		t1 - t4;
		t1.Show();
		cout << "ʱ�����>";
		t4.Show();
		t1 + t4;
		cout << "3.��Ӻ�>";
		t1.Show();
	}

	//�ڶ����������ڽ����󣬱��������Զ����������������ȹ���ĺ�����
	system("pause");
	return 0;
}