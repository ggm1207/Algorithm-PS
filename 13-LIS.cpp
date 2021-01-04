#include <iostream>
#include "math.h"
#include <iterator>
#include <vector>

using namespace std;

int lis(const vector<int>& A){
    // 기저 사례: A가 텅 비어 있을 때
    if(A.empty()) return 0;
    int ret = 0;
    for (int i=0; i < A.size(); ++i) {
        vector<int> B;
        for (int j=i+1; j<A.size(); ++j)
            if(A[i] < A[j])
                B.push_back(A[j]);
        ret = max(ret, 1 + lis(B));
    }
    return ret;
}


int n;
int cache[100], S[100];
// S[start]에서 시작하는 증가 부분 수열 중 최대 길이를 반환한다.
int lis2(int start){
    int ret = cache[start];
    if(ret != -1) return ret;
    // 항상 S[start]는 있기 때문에 길이는 최하 1
    ret = 1;
    for(int next= start+1; next < n; ++next)
        if(S[start] < S[next])
            ret = max(ret, lis2(next) + 1);
    return ret;
}

int maxLen = 0;
for(int begin=0; begin < n; ++begin)
    maxLen = max(maxLen, lis2(begin));

int n2;
int cache2[101], S[100];
// S[start]에서 시작하는 증가 부분 수열 중 최대 길이를 반환한다.
int lis3(int start){
    int ret = cache2[start+1];
    if(ret != -1) return ret;
    // 항상 S[start]는 있기 때문에 길이는 최하 1
    ret = 1;
    for(int next= start+1; next < n2; ++next)
        if(start == -1 || S[start] < S[next])
            ret = max(ret, lis2(next) + 1);
    return ret;
}
