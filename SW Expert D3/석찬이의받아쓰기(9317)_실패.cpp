// 테스트케이스 9개만 맞음
#include<iostream>
#include<vector>
#include<deque>
using namespace std;
int main(){
    int t;
    cin>>t;

    for(int tc=1; tc<=t; tc++) {
        int n, m;  // 주차공간, 차량수
        cin>>n>>m;
        vector<pair<int, int>> parking; // 주차공간 요금
        vector<int> carWeight(m, 0); // 차량 무게
        deque<int> wait;
        int answer = 0;  // 총 주차요금

        int temp;
        for(int i=0; i<n; i++) {
            cin>>temp;
            parking.push_back(make_pair(temp, 0));
        }
        for(int i=0; i<m; i++) {
            cin>>temp;
            carWeight[i] = temp;
        }
        for(int i=0; i<2*m; i++) {
            cin>>temp;
            bool flag = false;  // 꽉차있으면 false, 빈곳이 있으면 true
            
            // 빈자리 찾기
            if(temp > 0) {
                for(int a=0; a<n; a++) {
                    if(parking[a].second == 0) {
                        parking[a].second = temp;
                        answer += parking[a].first * carWeight[temp-1];
                        flag = true;
                        break;
                    }
                }
                // 꽉차있으면 대기큐에 넣어주기
                if(!flag) 
                    wait.push_back(temp);
            } 
            else {  // 차 빼기
                for(int a=0; a<n; a++) {
                    if(parking[a].second == -temp) {
                        if(wait.size() >= 1) {
                            parking[a].second = temp;
                            answer += parking[a].first * carWeight[wait[0]-1];
                            wait.pop_front();
                        } else {
                            parking[a].second = 0;
                        }
                        break;
                    }
                }
            }
            
        }
        cout<<"#"<<tc<<" "<<answer<<endl;
    }

    return 0;
}