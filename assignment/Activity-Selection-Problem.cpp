#include <bits/stdc++.h>

using namespace std;

typedef vector<pair<int, int>> neighborList;

neighborList schedule; // first = end, sec = start

void append(int start, int end){
    schedule.push_back(make_pair(end, start));
}

set<int> iterativeActivitySelector(neighborList schd){
    set<int> ans;
    ans.insert(0);
    int select = 0;
    for (int next = 1; next < schd.size(); next++){
        if (schd[next].second >= schd[select].first){
            ans.insert(next);
            select = next;
        }
    }
    return ans;
}

int main(){
    append(1,4);
    append(3,5);
    append(0,6);
    append(5,7);
    append(3,9);
    append(5,9);
    append(6,10);
    append(8,11);
    append(8,12);
    append(2,14);
    append(12,16);

    sort(schedule.begin(), schedule.end());
    printf("Act  Str Fin\n");
    for (auto s : iterativeActivitySelector(schedule)) {
        pair<int, int> time = schedule[s];
        printf("%2d | %2d → %-2d\n", s, time.second, time.first);
    }
    return 0;
}