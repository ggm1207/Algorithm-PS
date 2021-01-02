#include <iostream>
#include <string.h>

using namespace std;

bool areFriends[10][10];
int n;

// taken[i] = i번째 학생이 짝을 이미 찾았으면 true, 아니면 false
int duplicateCountPairings(bool taken[10]){
    // 기저 사례: 모든 학생이 짝을 찾았으면 한 가지 방법을 찾았으니 종료한다.
    bool finished = true;
    for(int i=0; i<n; ++i) if (!taken[i]) finished = false;
    if (finished) return 1;
    
    int ret = 0;
    // 서로 친구인 두 학생을 찾아 짝을 지어 준다.
    for(int i=0; i<10; ++i){
        for(int j=0; j<10; ++j){
            if (!taken[i] && !taken[j] && areFriends[i][j]){
                taken[i] = taken[j] = true;
                ret += duplicateCountPairings(taken);
                taken[i] = taken[j] = false;
            }
        }
    }

    return ret;
}

int countPairings(bool taken[10]){
    int firstFree = -1;    
    
    for (int i=0; i<n; ++i){
        if(!taken[i]){
            firstFree = i;
            break;
        }
    }

    if (firstFree == -1) return 1;
    int ret = 0;

    // 이 학생과 짝지을 학생을 결정한다.
    for (int pairWith=firstFree; pairWith < n; ++pairWith) {
        if(!taken[pairWith] && areFriends[firstFree][pairWith]){
            taken[pairWith] = taken[firstFree] = true;
            ret += countPairings(taken);
            taken[pairWith] = taken[firstFree] = false;
        }
    }

    return ret;
}

void solution(int n, int m){
    int y, x;

    for(int i=0; i<m; i++){
        cin >> y; 
        cin >> x;
        areFriends[y][x] = true;
        areFriends[x][y] = true;
    }

    bool taken[10] = {0};
    memset(taken, false, sizeof(taken));
    
    for(int i=0; i<10; ++i)
        cout << taken[i] << " ";
    cout << endl;

    // int ret = duplicateCountPairings(taken);
    int ret = countPairings(taken);

    cout << "answer: " << ret << endl;
}


int main(){
    int t, m;
    freopen("./PICNIC.tc", "r", stdin);

    cin >> t; 
    
    for(int i=0; i<t; i++){
        cin >> n >> m;
        memset(areFriends, 0, sizeof(areFriends));  // 초기화
        solution(n, m);
    }

}
