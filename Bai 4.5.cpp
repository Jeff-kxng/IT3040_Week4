// Bài 4.5. Viết hàm void dfs(vector< list<int> > adj) thực hiện thuật toán DFS không sử dụng đệ quy trên đồ thị biểu diễn bằng danh sách kề. Đồ thị có n đỉnh được đánh số từ 1 đến n. Thuật toán DFS xuất phát từ đỉnh 1. Các đỉnh được thăm theo thứ tự ưu tiên từ trái sang phải trong danh sách kề. Yêu cầu hàm trả ra thứ tự các đỉnh được thăm (những đỉnh không thể thăm từ đỉnh 1 thì không phải in ra).

#include<bits/stdc++.h>
using namespace std;
// Sok Sokong 20211005

void dfs(std::vector< std::list<int> > adj) {
    std::stack<int> S;
    std::vector<bool> visited(adj.size());
    S.push(1); // B?t d?u t? d?nh s? 1
    while (!S.empty()) {
        int u=S.top();
        if (!visited[u]){
            visited[u] = true;
            std::cout<< u << std::endl;
        }
        if (!adj[u].empty()){
            int v=adj[u].front(); adj[u].pop_front();
            if(!visited[v]){
                S.push(v);
            }
        }else { S.pop();}
    }
}


