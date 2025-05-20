/*在一个无向图中任意给定两点实现最短路径计算。要求采用dijkstra（深度或广度或弗洛伊德或者Bellman-Ford）
算法以及堆排序算法或其他排序算法，利用递归、vector支持邻接表方式，
对于路径和选择路径进行界面显示（可仅仅显示而不交互）。主要目的：vector的理解，可视化编程的理解。  
（1）按照自己的理解描述题目要求；  
（2）分析程序难点，并讨论解决问题思路；  
（3）分析所实现程序的优点和缺点；  
（4）没有完成的原因；  
（5）你的收获。 */

#include <bits/stdc++.h>
using namespace std;

const float INF = numeric_limits<float>::infinity();

class Dijkstra {
public:
    vector<vector<pair<int, float>>> adjList; // 邻接表：索引 -> [(邻居索引, 权重)]
    vector<string> nodeNames;                // 索引到节点名称的映射
    map<string, int> nodeIndex;              // 节点名称到索引的映射

    vector<map<string, float>> steps;       // 记录每一步的距离状态
    map<string, float> finalDistances;      // 最终最短距离
    map<string, string> predecessors;       // 前驱节点用于路径回溯

    // 构造函数：将输入的map转换为vector邻接表
    Dijkstra(const map<string, map<string, float>>& graph) {
        // 收集所有节点并按名称排序
        for (const auto& pair : graph) {
            nodeNames.push_back(pair.first);
        }
        sort(nodeNames.begin(), nodeNames.end());
        
        // 构建名称到索引的映射
        for (size_t i = 0; i < nodeNames.size(); ++i) {
            nodeIndex[nodeNames[i]] = i;
        }
        
        // 初始化邻接表
        adjList.resize(nodeNames.size());
        for (const auto& pair : graph) {
            int u = nodeIndex[pair.first];
            for (const auto& neighbor : pair.second) {
                int v = nodeIndex[neighbor.first];
                float weight = neighbor.second;
                adjList[u].emplace_back(v, weight); // 添加边（无向图需双向）
            }
        }
    }

    // Dijkstra算法实现
    void findShortestPath(string start) {
        if (nodeIndex.find(start) == nodeIndex.end()) return; // 节点不存在
        
        int startIdx = nodeIndex[start];
        int n = nodeNames.size();
        vector<float> distances(n, INF);    // 距离数组
        vector<bool> visited(n, false);      // 访问标记
        vector<int> pred(n, -1);             // 前驱索引
        
        distances[startIdx] = 0;
        steps.clear();
        finalDistances.clear();
        predecessors.clear();

        for (int i = 0; i < n; ++i) {
            // 选择当前未访问的最小距离节点
            int current = -1;
            float minDist = INF;
            for (int j = 0; j < n; ++j) {
                if (!visited[j] && distances[j] < minDist) {
                    minDist = distances[j];
                    current = j;
                }
            }
            if (current == -1) break;        // 剩余节点不可达
            visited[current] = true;
            
            // 更新邻居节点的距离
            for (const auto& neighbor : adjList[current]) {
                int v = neighbor.first;
                float weight = neighbor.second;
                if (!visited[v] && distances[current] + weight < distances[v]) {
                    distances[v] = distances[current] + weight;
                    pred[v] = current;
                }
            }
            
            // 记录当前步骤（转换为节点名称的map）
            map<string, float> step;
            for (int j = 0; j < n; ++j) {
                step[nodeNames[j]] = distances[j];
            }
            steps.push_back(step);
        }

        // 转换为最终结果
        for (int i = 0; i < n; ++i) {
            finalDistances[nodeNames[i]] = distances[i];
            if (pred[i] != -1) {
                predecessors[nodeNames[i]] = nodeNames[pred[i]];
            }
        }
    }

    // 打印算法步骤
    void printSteps() {
        cout << "Dijkstra Steps:" << endl;
        cout << left << setw(8) << "Step";
        for (const auto& name : nodeNames) {
            cout << setw(8) << name;
        }
        cout << endl;

        for (size_t i = 0; i < steps.size(); ++i) {
            cout << setw(8) << i + 1;
            for (const auto& name : nodeNames) {
                float val = steps[i][name];
                if (val == INF) cout << setw(8) << "INF";
                else cout << setw(8) << val;
            }
            cout << endl;
        }
    }

    // 打印路径
    void printPath(string dest) {
        if (predecessors.find(dest) == predecessors.end() && dest != nodeNames[0]) {
            cout << "No path to " << dest << endl;
            return;
        }
        
        vector<string> path;
        string current = dest;
        while (predecessors.count(current)) {
            path.push_back(current);
            current = predecessors[current];
        }
        path.push_back(current);
        reverse(path.begin(), path.end());

        cout << "Path to " << dest << ": ";
        for (size_t i = 0; i < path.size(); ++i) {
            if (i > 0) cout << " -> ";
            cout << path[i];
        }
        cout << " (Distance: " << finalDistances[dest] << ")\n";
    }
};

int main() {
    // 构建无向图（确保边双向存在）
    map<string, map<string, float>> graph = {
        {"A", {{"B", 5}, {"C", 21}, {"D", 9}, {"F", 36}}},
        {"B", {{"A", 5}, {"C", 13}, {"F", 27}, {"G", 43},{"H",8}}},
        {"C", {{"A", 21}, {"B", 13}, {"D", 7}, {"E", 17}, {"G", 14}}},
        {"D", {{"A", 9}, {"C", 7}}},
        {"E", {{"C", 17}, {"F", 8}, {"H", 15}}},
        {"F", {{"A", 36}, {"B", 27},{"E", 8}, {"G", 22}}},
        {"G", {{"B", 43}, {"C", 14}, {"F", 22}, {"H", 6}}},
        {"H", {{"B",8},{"E", 15}, {"G", 6}}}
    };

    Dijkstra d(graph);
    d.findShortestPath("A");
    
    cout << "Starting from node A:\n";
    d.printSteps();
    
    cout << "\nShortest Paths:\n";
    for (const auto& node : d.nodeNames) {
        if (node != "A") {
            d.printPath(node);
        }
    }

    return 0;
}