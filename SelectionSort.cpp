#include <iostream>
using namespace std;

// 배열 A의 인덱스 0부터 인덱스 last-1까지의 슬라이싱에서 
// max 값을 가지는 원소의 인덱스를 찾아 반환하는 함수
int find_max_idx(int* A, int last) {
    int idx = 0;
    int max = 0;
    for (int i = 0; i < last; i++) {
        if (A[i] > max) {
            max = A[i];
            idx = i;
        }
    }
    return idx;
}

// 배열 A의 크기가 N이고 선택 정렬에 의한 교환 횟수가 K일 때,
// K번째에 교환되는 두 개의 수를 출력하는 함수.
// 교환 횟수가 K보다 작으면 -1을 출력. 
void selection_sort(int* A, int N, int K) {

    int change = 0;
    int i;
    int temp;
    int last;
    for (last = N; last > 1; last--) {
        i = find_max_idx(A, last);
        if ((last - 1) != i) {

            int temp = A[last - 1];
            A[last - 1] = A[i];
            A[i] = temp;

            change++;

            if (change == K) {
                cout << A[i] << " " << A[last - 1];
                return;
            }
        }
    }
    cout << -1;
}

    int main() {
        // 1. input
        int N, K, num;
        cin >> N >> K;
        int* A = new int[N];
        if (N >= 5 && N <= 10000 && K >= 1 && K <= N) {
            for (int i = 0; i < N; i++) {
                cin >> num;
                if (num >= 1 && num <= 1000000000)
                    A[i] = num;
            }

        }
        // 2. output
        selection_sort(A, N, K);

        delete[] A;
        return 0;
    }
