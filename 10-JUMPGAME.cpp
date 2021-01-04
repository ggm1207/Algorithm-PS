
int n, board[100][100];

int recursiveJump(int y, int x){
    // 기저 사례: 게임판 밖을 벗어난 경우
    if ( y >= n || x >= n ) return false;
    // 기저 사례: 마지막 칸에 도착한 경우
    if ( y == n-1 && x == n-1 ) return true;
    int jumpSize = board[y][x];
    return recursiveJump(y+jumpSize, x) || recursiveJump(y, x + jumpSize);
}

int cache[100][100];
int jump(int y, int x){
    if ( y >= n || x >= n ) return false;
    if ( y == n-1 && x == n-1 ) return true;
    // 메모이제이션
    int& ret = cache[y][x];
    if(ret != -1) return ret;
    int jumpSize = board[y][x];
    return ret = (jump(y + jumpSize, x) || jump(y, x + jumpSize));
}
