#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    int t;
    cin>>t;

    for(int tc=1; tc<=t; tc++) {
        int n, m;  // 과자봉지 개수, 무게 제한
        cin>>n>>m;
        vector<int> snack;

        int temp;
        for(int i=0; i<n; i++) {
            cin>>temp;
            snack.push_back(temp);
        }
        sort(snack.begin(), snack.end());

        // 예외처리
        if(snack[0] + snack[1] > m){
            cout<<"#"<<tc<<" "<<-1<<endl;
            continue;
        }

        int max = 0;
        int sum = 0;
        for(int i=0; i<snack.size()-1; i++) {
            for(int j=i+1; j<snack.size(); j++) {
                sum = snack[i] + snack[j];
                if(sum > max){
                    if(sum > m) {
                        break;
                    }
                    max = sum;
                }
            }            
        }
        cout<<"#"<<tc<<" "<<max<<endl;
    }

    return 0;
}