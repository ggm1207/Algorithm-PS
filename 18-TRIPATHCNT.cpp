#include <algorithm>
#include "./12-TRIANGLEPATH.cpp"
int countCache[100][100];
// (y, x)에서 시작해서 맨 아래줄까지 내려가는 경로 중 최대 경로의
// 개수를 반환한다.
int count(int y, int x){
    // 기저 사례: 맨 아래줄에 도달한 경우
    if(y == n-1) return 1;
    // 메모이제이션
    int& ret = countCache[y][x];
    if(ret != -1) return ret;
    ret = 0;
    if(path2(y+1, x+1) >= path2(y+1, x)) ret += count(y+1, x+1);
    if(path2(y+1, x+1) <= path2(y+1, x)) ret += count(y+1, x);
    return ret;
}
