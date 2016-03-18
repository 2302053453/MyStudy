#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;
/*
	2016-03-18
	merge 예제
	두개의 정렬된 구간을 합칠 때 사용
	두 구간과 겹치지 않은 곳에 합친 결과를 넣어야 한다
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

	// 정렬하지 않고 merge후 결과 출력
	merge(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), vec3.begin());
	for (itr = vec3.begin(); itr != vec3.end(); ++itr)
		cout << *itr << endl;
	cout << endl;

	// 정렬하고 merge후 결과 출력
	sort(vec1.begin(), vec1.end(), greater<int>());
	sort(vec2.begin(), vec2.end(), greater<int>());
	merge(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), vec4.begin());
	for (itr = vec4.begin(); itr != vec4.end(); ++itr)
		cout << *itr << endl;
	cout << endl;

	return 0;
}