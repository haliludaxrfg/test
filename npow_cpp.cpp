#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> nums;
    vector<int> ans;
    int ch;
    int i = 0;
    while (scanf_s("%d", &ch) == 1 && ch != -1){
        if(ch != 0){
            if(nums.size() <= i){
                nums.push_back(vector<int>()); // Ϊ���з���ռ�
            }
            nums[i].push_back(ch);
        }else if(nums.size() > i){
            i++; // ֻ���ڵ�ǰ�в�Ϊ��ʱ�������к�
        }
    }

    ans.resize(nums.size()); // ��ʼ�� ans �Ĵ�С

    for(i = 0; i < nums.size(); i++){
        for(int k = 0; k < nums[i].size(); k++){
            for(int l = k + 1; l < nums[i].size(); l++){ // l Ӧ�ô� k+1 ��ʼ
                if(nums[i][k] == n * nums[i][l] || nums[i][k] * n == nums[i][l]){
                    ans[i]++;
                }
            }
        }
    }

    for(const auto &p : ans){
        cout << p << endl;
    }

    return 0;
}