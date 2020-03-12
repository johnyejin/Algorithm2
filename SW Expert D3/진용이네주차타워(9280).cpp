#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    int t;
    cin>>t;

    for(int tc=1; tc<=t; tc++) {
        int n, m;  // ��������, ������
        cin>>n>>m;
        vector<int> parkingFare(n+1, 0); // �������� ���
        vector<int> carWeight(m+1, 0); // ���� ����
        int answer = 0;  // �� �������

        int temp;
        for(int i=1; i<=n; i++) {
            cin>>temp;
            parkingFare[i] = temp;
        }
        for(int i=1; i<=m; i++) {
            cin>>temp;
            carWeight[i] = temp;
        }

        queue<int> wait;  // ���ť
        vector<int> parkingLot(n+1, 0);  // ���� ������
        vector<int> carPosition(m+1, 0);  // �� ������ ������ �� ����

        for(int i=0; i<2*m; i++) {
            cin>>temp;

            if(temp > 0) {
                wait.push(temp);
            } else {
                parkingLot[carPosition[-temp]] = 0;
            }

            if(!wait.empty()) {
                bool isEmpty = false;  // ���������� false, ����� ������ true
                int emptyIdx = 0;
                for(int idx=1; idx<=n; idx++) {
                    if(parkingLot[idx] == 0) {
                        emptyIdx = idx;
                        isEmpty = true;
                        break;
                    }
                }

                // �� ���� ������
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