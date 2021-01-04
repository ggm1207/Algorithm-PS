#include <iostream>
#include "math.h"

using namespace std;

// 무식하게 메모이제이션 적용하기
// MAX_NUMBER: 한 칸에 들어갈 숫자의 최대치
int n, triangle[100][100];
int cache[100][100][MAX_NUMBER*100+1];
// (y, x) 위치까지 내려오기 전에 만난 숫자들의 합이 sum 일 때
// 맨 아래줄까지 내려가면서 얻을 수 있는 최대 경로를 반환한다.
int path1(int y, int x, int sum){
    // 기저 사례: 맨 아래 줄까지 도달했을 경우
    if(y == n-1) return sum + triangle[y][x];
    // 메모이제이션
    int& ret = cache[y][x][sum];
    if(ret != -1) return ret;
    sum += triangle[y][x];
    return ret = max(path1(y+1, x+1, sum), path1(y+1, x, sum));
}

int cache2[100 ][100];
// (y, x) 위치부터 맨 아래줄까지 내려가면서 얻을 수 있는 최대 경로의 합을 반환한다.
int path2(int y, int x){
    // 기저 사례
    if(y == n-1) return triangle[y][x];
    // 메모이제이션
    int& ret = cache2[y][x];
    if(ret != -1) return ret;
    return ret = max(path2(y+1, x), path2(y+1, x+1)) + triangle[y][x];
}
