//N개의 정수 A[1], A[2], …, A[N]이 주어져 있을 때, 
// 이 안에 X라는 정수가 존재하는지 알아내는 프로그램을 작성하시오.

#include <iostream>
#include <algorithm>

using namespace std;

// A안에 k가 있으면 1, 없으면 0 출력
void Binary_Search(int A[], int N, int k) {
	int left = 0; int right = N - 1;
	int middle;
	while (left <= right) {
		middle = (left + right) / 2;
		if (A[middle] < k) left = middle + 1;
		else if (A[middle] == k) {
			cout << 1 << '\n';
			return;
		}
		else right = middle - 1; // A[middle] > k 
	}
	cout << 0 << '\n';
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N;
	int* A = new int[N];
	if (N >= 1 && N <= 100000) {
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}
	}
	sort(A, A+N);
	cin >> M;
	int* B = new int[M];
	if (M >= 1 && M <= 100000) {
		for (int j = 0; j < M; j++) {
			cin >> B[j];
			Binary_Search(A,N,B[j]);
		}
	}

	delete[] A;
	delete[] B;

	return 0;
}