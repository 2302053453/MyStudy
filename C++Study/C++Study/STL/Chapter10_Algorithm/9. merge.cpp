#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;
/*
	2016-03-18
	merge ����
	�ΰ��� ���ĵ� ������ ��ĥ �� ���
	�� ������ ��ġ�� ���� ���� ��ģ ����� �־�� �Ѵ�
*/

int main()
{
	vector<int> vec1;
	vector<int> vec2;
	vector<int> vec3(6);
	vector<int> vec4(6);
	vector<int>::iterator itr;

	vec1.push_back(10);
	vec1.push_back(30);
	vec1.push_back(20);

	vec2.push_back(28);
	vec2.push_back(15);
	vec2.push_back(3);

	// �������� �ʰ� merge�� ��� ���
	merge(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), vec3.begin());
	for (itr = vec3.begin(); itr != vec3.end(); ++itr)
		cout << *itr << endl;
	cout << endl;

	// �����ϰ� merge�� ��� ���
	sort(vec1.begin(), vec1.end(), greater<int>());
	sort(vec2.begin(), vec2.end(), greater<int>());
	merge(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), vec4.begin());
	for (itr = vec4.begin(); itr != vec4.end(); ++itr)
		cout << *itr << endl;
	cout << endl;

	return 0;
}