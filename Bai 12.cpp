/* Bài tập 12. Lược đồ */
#include <iostream>
#include <stack>
#include <vector>
// Sok Sokong 20211005
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    int maxArea = 0;
    int n = heights.size();
    int i = 0;

    while (i < n) {
        if (st.empty() || heights[i] >= heights[st.top()]) {
            st.push(i);
            i++;
        } else {
            int top = st.top();
            st.pop();
            int area = heights[top] * (st.empty() ? i : i - st.top() - 1);
            maxArea = max(maxArea, area);
        }
    }

    while (!st.empty()) {
        int top = st.top();
        st.pop();
        int area = heights[top] * (st.empty() ? i : i - st.top() - 1);
        maxArea = max(maxArea, area);
    }

    return maxArea;
}

int main() {
    int n;
    cin >> n;

    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    int maxArea = largestRectangleArea(heights);

    cout << maxArea << endl;

    return 0;
}
