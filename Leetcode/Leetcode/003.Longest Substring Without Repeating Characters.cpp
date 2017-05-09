#include <iostream>
#include <climits> 
#include <ctime>
using namespace std;

int lengthOfLongestSubString (string s)
{
	int len = s.size();
	int *sub = new int[len + 1]; //�洢��СΪi+1���Ӵ�����������Ӵ�����
	sub[0] = 1;
	int currLoc = -1; //��ǰ����ķ����ظ���λ�� 
	int currDis = INT_MAX; //��С���ظ�����
	int currRes = 0;
	int i = 1;
	char c = s[0]; //��ǰ���������ַ� 
	int dis = 0;
	int dis_2 = 0;
	int currNewLoc = -1;
	while (i < len)
	{
		//cout << "i = " << i << endl;
		//cout << "s.substr(0,i) = " << s.substr(0,i) << endl;
		//cout << "s.substr(0, i).find(c) = " << s.substr(0, i).find(c) << endl;
		c = s[i];
		if (s.substr(0, i).find(c) == string::npos) //��ǰ�治�ظ� 
		{
			dis = i - currLoc;
			if (dis > sub[i - 1])
			{
				cout << "cond1" << endl;
				sub[i] = sub[i - 1] + 1;
				currRes = sub[i];
			}
			else
			{
				cout << "cond2" << endl;
				sub[i] = sub[i - 1];
			}
		}
		else  //�����ظ�Ԫ�� 
		{
			dis = i - s.substr(0,i).find_last_of(c);
			currNewLoc = s.substr(0,i).find_last_of(c);				
			cout << "dis = " << dis << " currDis = " << currDis << endl;
			if (currNewLoc > currLoc)
			{
				currLoc = currNewLoc;
			} 
			if (dis > currDis)
			{
				cout << "cond3" << endl;
				dis_2 = i - currLoc;
				if (dis > dis_2 && dis_2 > sub[i - 1])
				{
					sub[i] = sub[i - 1] + 1;
				}
				else
				{
					sub[i] = sub[i - 1];
				}
			
			} 
			else
			{
				cout << "cond4" << endl;
				currLoc = s.substr(0,i).find_last_of(c);
				currDis = dis;
				sub[i] = sub[i - 1];
			}
			cout << "currLoc = " << currLoc << endl;
		}
		cout << "sub[" << i << "]" << sub[i] << endl;
		cout << "*************************" << endl;
		++i;
	} 
	return sub[len - 1];
	
}

int main()
{
	string s = "";
	//cout << s.size() << endl;
	//cout << lengthOfLongestSubstring1 (s) << endl;
	while (cin >> s)
	{
		clock_t begin = clock();
		cout << lengthOfLongestSubString (s) << endl;
		clock_t end = clock();
		cout << end - begin << "����" << endl;
	} 
		
	return 0;
}














