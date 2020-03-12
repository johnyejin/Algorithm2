#include<iostream>
#include<string>
using namespace std;
int main() {
    int t;
    cin >> t;

    for(int testcase=1; testcase<=t; testcase++) {
        int n;
        cin>>n;
        string correct, seok;
        cin>>correct;
        cin>>seok;
        int answer = 0;

        for(int i=0; i<n; i++) {
            if(correct[i] == seok[i]) {
                answer++;
            }
        }

        cout<<"#"<<testcase<<" "<<answer<<endl;
    }

    return 0;
}