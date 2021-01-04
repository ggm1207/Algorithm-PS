#include "math.h"
#include <vector>

using namespace std;

// 초등학교 알고리즘
// num[]의 자릿수 올림을 처리한다.
void normalize(vector<int>& num){
    num.push_back(0);
    // 자릿수 올림을 처리한다.
    for(int i=0; i+1 < num.size(); ++i){
        if(num[i] < 0){
            int borrow = (abs(num[i]) + 9) / 10;
            num[i+1] -= borrow;
            num[i] += borrow * 10;
        } else {
            num[i+1] += num[i] / 10;
            num[i] %= 10;
        }
    }
    while(num.size() > 1 && num.back() == 0) num.pop_back();
}

// 두 긴 자연수의 곱을 반환한다.
// 각 배열에는 각 수의 자릿수가 1의 자리에서부터 시작해 저장되어 있다.
// multiply([3,2,1], [6,5,4]) = 123 * 456 = 56088 = [8,8,0,6,5]
vector<int> multiply(const  vector<int>& a, const vector<int>& b){
    vector<int> c(a.size() + b.size() + 1, 0);
    for(int i=0; i< a.size(); ++i)
        for(jnt j=0; j< b.size(); ++j)
            c[i+j] += a[i] * b[j];
    normalize(c);
    return c;
}

void addTo(vector<int>& a, const vector<int>& b, int k);
void subFrom(vector<int>& a, const vector<int>& b);
vector<int> karatsuba(const vector<int>& a, const vector<int>& b){
    int an = a.size(), bn = b.size();
    // a가 보다 짧을 경우 둘을 바꾼다.
    if(an < bn) return karatsuba(b,a);
    // 기저 사레: a나 b가 비어 있는 경우
    if(an == 0 || bn == 0) return vector<int>();
    // 기저 사례: a가 비교적 짧은 경우 O(n^2) 곱셉으로 변경한다.
    if(an <= 50) return multiply(a, b);
    
    int half =  an / 2;
    // a와 b를 밑에서 half자리와 나머지로 분리한다.
    vector<int> a0(a.begin(), a.begin() + half);
    vector<int> a1(a.begin() + half, a.end());
    vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
    vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());

    // z2 = a1*b1
    vector<int> z2 = karatsuba(a1, b1);
    // z0 = z0 * b0
    vector<int> z0 = karatsuba(a0, b0);
    // a0 = a0 + a1; b0 = b0 + b1 
    addTo(a0, a1, 0); addTo(b0, b1, 0); 
    // z1 = (a0*b0) -z0 - z2;
    vector<int> z1 = karatsuba(a0, b0);
    subFrom(z1, z0);
    subFrom(z1, z2);
    // ret = z0 + z1 * 10^half + z2 * a0 ^ (half*2)
    vector<int> ret; 
    addTo(ret, z0, 0);
    addTo(ret, z1, half);
    addTo(ret, z2, half + half);
    return ret;
}





































































































