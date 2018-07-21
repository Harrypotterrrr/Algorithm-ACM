#include<iostream>
#include<functional>
#include<queue>
#include<vector>
using namespace std;

//定义比较结构
struct cmp1 {
	bool operator ()(int &a, int &b) {
		return a > b;//最小值优先
	}
};

struct cmp2 {
	bool operator ()(int &a, int &b) {
		return a < b;//最大值优先
	}
};

//自定义数据结构
struct number1 {
	int x;
	bool operator < (const number1 &a) const {
		return x > a.x;//最小值优先
	}
};
struct number2 {
	int x;
	bool operator < (const number2 &a) const {
		return x < a.x;//最大值优先
	}
};
int a[] = { 14,10,56,7,83,22,36,91,3,47,72,0 };
number1 num1[] = { 14,10,56,7,83,22,36,91,3,47,72,0 };
number2 num2[] = { 14,10,56,7,83,22,36,91,3,47,72,0 };

int main()
{
	priority_queue<int>que;//采用默认优先级构造队列

	priority_queue<int, vector<int>, cmp1>que1;//最小值优先
	priority_queue<int, vector<int>, cmp2>que2;//最大值优先

	priority_queue<int, vector<int>, greater<int> >que3;//注意“>>”会被认为错误，
	priority_queue<int, vector<int>, less<int> >que4;////最大值优先

	priority_queue<number1>que5; //最小优先级队列
	priority_queue<number2>que6;  //最大优先级队列

	int i;
	for (i = 0; a[i]; i++) {
		que.push(a[i]);
		que1.push(a[i]);
		que2.push(a[i]);
		que3.push(a[i]);
		que4.push(a[i]);
	}
	for (i = 0; num1[i].x; i++)
		que5.push(num1[i]);
	for (i = 0; num2[i].x; i++)
		que6.push(num2[i]);


	printf("采用默认优先关系:/n(priority_queue<int>que;)/n");
	printf("Queue 0:/n");
	while (!que.empty()) {
		printf("%3d", que.top());
		que.pop();
	}
	puts("");
	puts("");

	printf("采用结构体自定义优先级方式一:/n(priority_queue<int,vector<int>,cmp>que;)/n");
	printf("Queue 1:/n");
	while (!que1.empty()) {
		printf("%3d", que1.top());
		que1.pop();
	}
	puts("");
	printf("Queue 2:/n");
	while (!que2.empty()) {
		printf("%3d", que2.top());
		que2.pop();
	}
	puts("");
	puts("");
	printf("采用头文件/functional/内定义优先级:/n(priority_queue<int,vector<int>,greater<int>/less<int> >que;)/n");
	printf("Queue 3:/n");
	while (!que3.empty()) {
		printf("%3d", que3.top());
		que3.pop();
	}
	puts("");
	printf("Queue 4:/n");
	while (!que4.empty()) {
		printf("%3d", que4.top());
		que4.pop();
	}
	puts("");
	puts("");
	printf("采用结构体自定义优先级方式二:/n(priority_queue<number>que)/n");
	printf("Queue 5:/n");
	while (!que5.empty()) {
		printf("%3d", que5.top());
		que5.pop();
	}
	puts("");
	printf("Queue 6:/n");
	while (!que6.empty()) {
		printf("%3d", que6.top());
		que6.pop();
	}
	puts("");
	return 0;
}

/////////////////////////////////////////////////////
//												   //
//												   //
//												   //
//												   //
/////////////////////////////////////////////////////
struct node
{
	int x, y;
	bool operator < (const node & a) const
	{
		return x<a.x;
	}
}k;
int main2()
{
	priority_queue <node> q;
	k.x = 10, k.y = 100; q.push(k);
	k.x = 12, k.y = 60; q.push(k);
	k.x = 14, k.y = 40; q.push(k);
	k.x = 6, k.y = 80; q.push(k);
	k.x = 8, k.y = 20; q.push(k);
	while (!q.empty())
	{
		node m = q.top(); q.pop();
		printf("(%d,%d) ", m.x, m.y);
	}
}

/////////////////////////////////////////////////////
//												   //
//												   //
//												   //
//												   //
/////////////////////////////////////////////////////
int N, M, K;
struct Student
{
	int id;
	int arrive_time;
	int office_num;
	int finish_time;
	std::vector<pair<int, int> > register_offices;
};
Student students[10005];
struct Event
{
	int student_idx;
	int office;
	int begin;
	int duration;
	Event(int s, int o, int b, int d) : student_idx(s), office(o), begin(b), duration(d) {};
};
struct Cmp
{
	bool operator()(const Event &e1, const Event &e2) {
		if (e1.begin == e2.begin)
			return students[e1.student_idx].id > students[e2.student_idx].id;
		return e1.begin > e2.begin;
	}
};
priority_queue<Event, vector<Event>, Cmp> pq;
int pre[105];
int pos[10005];
void Solve() {
	for (int i = 0; i<N; ++i) {
		pq.push(Event(i, students[i].register_offices[0].first, students[i].arrive_time + K, students[i].register_offices[0].second));
		pos[i] = 1;
	}
	memset(pre, -1, sizeof(pre));
	while (!pq.empty()) {
		Event e = pq.top();
		pq.pop();
		int st = e.student_idx;
		if (pre[e.office] > e.begin) {
			e.begin = pre[e.office];
		}
		int finish_time = e.begin + e.duration;
		if (pos[st] == students[st].office_num) {
			students[st].finish_time = finish_time;
		}
		else {
			int office = students[st].register_offices[pos[st]].first;
			int duration = students[st].register_offices[pos[st]].second;
			pq.push(Event(st, office, finish_time + K, duration));
			pos[st]++;
		}
		pre[e.office] = finish_time;
	}
}
int main()
{
	scanf("%d%d%d", &N, &M, &K);
	int p, o, w;
	for (int i = 0; i<N; ++i) {
		scanf("%d%d%d", &students[i].id, &students[i].arrive_time, &p);
		students[i].office_num = p;
		for (int j = 0; j<p; ++j) {
			scanf("%d%d", &o, &w);
			students[i].register_offices.push_back(make_pair(o, w));
		}
	}
	Solve();
	for (int i = 0; i<N; ++i) {
		printf("%d\n", students[i].finish_time);
	}
	return 0;
}