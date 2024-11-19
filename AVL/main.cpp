#include"AVL.h"
#include<time.h>
#include<vector>
int main()
{
	const int N = 10000;
	vector<int> v;
	v.reserve(N);
	srand(time(0));

	for (size_t i = 0; i < N; i++)
	{
		v.push_back(rand() + i);
		//cout << v.back() << endl;
	}

	size_t begin2 = clock();
	AVL<int> t;
	for (auto e : v)
	{
		t.insert(e);
		//cout << "Insert:" << e << "->" << t.IsBalance() << endl;
	}
	size_t end2 = clock();

	cout << "Insert:" << end2 - begin2 << endl;
	//cout << t.IsBalance() << endl;

	cout << "Height:" << t.Height() << endl;
	

	size_t begin1 = clock();
	
}