#include<iostream>
#include<vector>
using namespace std;
int main() {
    int t;
    cin>>t;

    for(int tc=1; tc<=t; tc++) {
        int k;
        cin>>k;
        vector<int> receipt;
        int answer = 0;

        int temp;
        for(int i=0; i<k; i++) {
            cin>>temp;
            if(temp == 0){
                answer -= receipt[receipt.size()-1];
                receipt.pop_back();
            } else {
                answer += temp;
                receipt.push_back(temp);
            }
        }
        cout<<"#"<<tc<<" "<<answer<<endl;
    }

    return 0;
}