#include <bits/stdc++.h>
using namespace std;

const float INF = numeric_limits<float>::infinity(); // 定义无穷大，用于初始化距离

class Dijkstra {
private:
    map<string, map<string, float>> graph; // 图的邻接表表示，存储每个节点及其相邻节点的权重
    vector<string> nodes; // 存储图中所有节点的列表

public:
    vector<map<string, float>> steps; // 存储每一步的距离更新情况
    map<string, float> finalDistances; // 存储从起点到每个节点的最终最短距离
    map<string, string> predecessors; // 存储每个节点的前驱节点，用于路径回溯

    // 构造函数，初始化图并提取节点列表
    Dijkstra(map<string, map<string, float>> g) : graph(g) {
        for (auto& pair : g) {
            nodes.push_back(pair.first); // 提取所有节点
        }
        sort(nodes.begin(), nodes.end()); // 对节点进行排序，便于输出
    }

    // Dijkstra算法实现，计算从起点到所有节点的最短路径
    void findShortestPath(string start) {
        map<string, float> distances; // 存储当前的最短距离
        map<string, bool> visited; // 标记节点是否已访问
        steps.clear(); // 清空步骤记录
        finalDistances.clear(); // 清空最终距离
        predecessors.clear(); // 清空前驱节点

        // 初始化距离和访问状态
        for (auto& node : nodes) {
            distances[node] = INF; // 初始距离为无穷大
            visited[node] = false; // 初始状态为未访问
        }
        distances[start] = 0; // 起点到自身的距离为0

        for (size_t i = 0; i < nodes.size(); ++i) { // 遍历所有节点
            string current;
            float minDist = INF;

            // 找到当前未访问的最小距离节点
            for (auto& node : nodes) {
                if (!visited[node] && distances[node] < minDist) {
                    minDist = distances[node];
                    current = node;
                }
            }

            if (minDist == INF) break; // 如果所有节点都不可达，退出循环
            visited[current] = true; // 标记当前节点为已访问

            // 更新相邻节点的距离
            for (auto& neighbor : graph[current]) {
                if (!visited[neighbor.first]) {
                    float newDist = distances[current] + neighbor.second; // 计算新距离
                    if (newDist < distances[neighbor.first]) { // 如果新距离更短，更新
                        distances[neighbor.first] = newDist;
                        predecessors[neighbor.first] = current; // 更新前驱节点
                    }
                }
            }

            steps.push_back(distances); // 记录当前步骤的距离
        }

        finalDistances = distances; // 保存最终的最短距离
    }

    // 打印Dijkstra算法的每一步
    void printSteps() {
        cout << "Dijkstra Algorithm Steps:" << endl;
        cout << left << setw(8) << "Step"; // 输出表头
        for (auto& node : nodes) {
            cout << setw(8) << node; // 输出节点名称
        }
        cout << endl;

        for (size_t i = 0; i < steps.size(); ++i) { // 遍历每一步
            cout << setw(8) << i+1; // 输出步骤编号
            for (auto& node : nodes) {
                if (steps[i][node] == INF)
                    cout << setw(8) << "INF"; // 如果距离为无穷大，输出INF
                else
                    cout << setw(8) << steps[i][node]; // 输出距离
            }
            cout << endl;
        }
    }

    // 打印从起点到目标节点的最短路径
    void printPath(string destination) {
        vector<string> path; // 存储路径
        string current = destination;

        while (predecessors.find(current) != predecessors.end()) { // 回溯路径
            path.push_back(current);
            current = predecessors[current];
        }
        path.push_back(current); // 添加起点

        reverse(path.begin(), path.end()); // 反转路径

        cout << "Shortest path: ";
        for (size_t i = 0; i < path.size(); ++i) {
            if (i > 0) cout << " -> "; // 输出路径箭头
            cout << path[i];
        }
        cout << "\nTotal distance: " << finalDistances[destination] << endl; // 输出总距离
    }

    // 获取节点列表（用于外部访问）
    const vector<string>& getNodes() const { return nodes; }
};

int main() {
    // 初始化图数据
    map<string, map<string, float>> graph = {
        {"A", {{"B", 10}, {"D", 4}}},
        {"B", {{"A", 10}, {"C", 8}, {"D", 2}, {"E", 6}}},
        {"C", {{"B", 8}, {"E", 1}, {"F", 5}}},
        {"D", {{"A", 4}, {"B", 2}, {"E", 6}}},
        {"E", {{"B", 6}, {"C", 1}, {"D", 6}, {"F", 12}}},
        {"F", {{"C", 5}, {"E", 12}}}
    };

    Dijkstra d(graph); // 创建Dijkstra对象
    string startNode = "A";

    d.findShortestPath(startNode); // 计算从起点到所有节点的最短路径
    
    cout << "Starting from node: " << startNode << endl;
    d.printSteps(); // 打印每一步的距离更新

    // 显示所有节点的最短路径
    cout << "\nFinal Results:" << endl;
    for (auto& node : d.getNodes()) {
        if (node != startNode) {
            d.printPath(node); // 打印从起点到目标节点的路径
            cout << endl;
        }
    }

    return 0;
}