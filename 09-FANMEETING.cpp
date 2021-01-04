// xor연산을 사용해서 풀면 괜찮을 것 같다고 생각을 했다.
#include <initializer_list>
#include <iostream>
#include <string.h>
#include <vector>
#include "./07-FASTMUL.cpp"

using namespace std;

int hugs(const string& members, const string& fans){
    int N = members.size(), M = fans.size();
    vector<int> A(N), B(M);
    for (int i=0; i<N; ++i) A[i] = (members[i] == 'M');
    for (int i=0; i<M; ++i) B[M-i-1] = (fans[i] == 'M');
    // karatsuba알고리즘에서 자리 올림은 생략한다. 
    vector<int> C = karatsuba(A, B);
    int allHugs = 0;
    for (int i=N-1; i < M; ++i) {
        ++allHugs;
    }
    return allHugs;
}
