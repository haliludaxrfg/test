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
                nums.push_back(vector<int>()); // 为新行分配空间
            }
            nums[i].push_back(ch);
        }else if(nums.size() > i){
            i++; // 只有在当前行不为空时才增加行号
        }
    }

    ans.resize(nums.size()); // 初始化 ans 的大小

    for(i = 0; i < nums.size(); i++){
        for(int k = 0; k < nums[i].size(); k++){
            for(int l = k + 1; l < nums[i].size(); l++){ // l 应该从 k+1 开始
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