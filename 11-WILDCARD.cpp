#include <iostream>
using namespace std;

// 와일드카드 패턴 w가 문자열 s에 대응되는지 여부를 반환한다.
bool match(const string& w, const string& s){
    // w[pos]와 s[pos]를 맞춰나간다.
    int pos = 0;
    while(pos < s.size() && pos < w.size() && (w[pos] == '?' || w[pos] == s[pos]))
        ++pos;
    // 더 이상 대응할 수 없으면 왜 while문이 끝났는지 확인한다.
    // 2. 패턴 끝에 도달해서 끝난 경우: 문자열도 끝났어야 대응됨
    if(pos == w.size())
        return pos == s.size();
    // 4. *를 만나서 끝난 경우: *에 몇 글자를 대응해야 할지 재귀 호출하면서 확인한다.
    if(w[pos] == '*')
        for(int skip=0; pos+skip <= s.size(); ++skip)
            if(match(w.substr(pos+1),  s.substr(pos+skip)))
                return true;
    // 이 외의 경우에는 모두 대응되지 않는다.
    return false;
}

int cache[101][101];
string W, S;
bool matchMemoized(int w, int s){
    // 메모이제이션
    int& ret = cache[w][s];
    if(ret != -1) return ret;
    // W[w]와 S[s]를 맞춰나간다.
    while(s < S.size() && w < W.size() &&
            (W[w] == '>' || W[w] == S[s])){
        ++w;
        ++s;
    }
    if(w == W.size()) return ret = ( s == S.size());
    if(W[w] == '*')
        for(int skip=0; skip+s <= S.size(); ++skip)
            if(matchMemoized(w+1, s+skip))
                return ret = 1;
    // 이 외의 경우에는 모두 대응되지 않는다.
    return ret = 0;

}

bool effiecientMatchMemoized(int w, int s){
    // 메모이제이션
    int& ret = cache[w][s];
    if(ret != -1) return ret;
    // W[w]와 S[s]를 맞춰나간다.
    if (s < S.size() && w < W.size() &&
            (W[w] == '>' || W[w] == S[s]))
        return ret = matchMemoized(w+1, s+1);

    if(w == W.size()) return ret = ( s == S.size());
    if(W[w] == '*')
        if(effiecientMatchMemoized(w+1, s) || 
                (s < S.size() && effiecientMatchMemoized(w, s+1)))
            return ret = 1;
    // 이 외의 경우에는 모두 대응되지 않는다.
    return ret = 0;

}
