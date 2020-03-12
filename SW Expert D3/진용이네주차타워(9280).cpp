#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    int t;
    cin>>t;

    for(int tc=1; tc<=t; tc++) {
        int n, m;  // 주차공간, 차량수
        cin>>n>>m;
        vector<int> parkingFare(n+1, 0); // 주차공간 요금
        vector<int> carWeight(m+1, 0); // 차량 무게
        int answer = 0;  // 총 주차요금

        int temp;
        for(int i=1; i<=n; i++) {
            cin>>temp;
            parkingFare[i] = temp;
        }
        for(int i=1; i<=m; i++) {
            cin>>temp;
            carWeight[i] = temp;
        }

        queue<int> wait;  // 대기큐
        vector<int> parkingLot(n+1, 0);  // 현재 주차장
        vector<int> carPosition(m+1, 0);  // 각 차들이 주차된 곳 저장

        for(int i=0; i<2*m; i++) {
            cin>>temp;

            if(temp > 0) {
                wait.push(temp);
            } else {
                parkingLot[carPosition[-temp]] = 0;
            }

            if(!wait.empty()) {
                bool isEmpty = false;  // 꽉차있으면 false, 빈곳이 있으면 true
                int emptyIdx = 0;
                for(int idx=1; idx<=n; idx++) {
                    if(parkingLot[idx] == 0) {
                        emptyIdx = idx;
                        isEmpty = true;
                        break;
                    }
                }

                // 빈 곳이 있으면
                if(isEmpty) {
                    int currentCar = wait.front();
                    wait.pop();
                    parkingLot[emptyIdx] = currentCar;
                    carPosition[currentCar] = emptyIdx;
                    answer += parkingFare[emptyIdx] * carWeight[currentCar];
                }
            }
        }
        cout<<"#"<<tc<<" "<<answer<<endl;
    }

    return 0;
}