#include<bits/stdc++.h>

using namespace std;

string getFinalColors(string inputColors) {
    stack<char> st;
    for (char color : inputColors) {
        if (!st.empty() && st.top() == color) {
            st.pop();
        } else if (!st.empty() && ((st.top() == 'R' && color == 'G') || (st.top() == 'G' && color == 'R'))) {
            st.pop();
            if (!st.empty() && st.top() == 'Y') {
                st.pop();
            } else {
                st.push('Y');
            }
        } else if (!st.empty() && ((st.top() == 'R' && color == 'B') || (st.top() == 'B' && color == 'R'))) {
            st.pop();
            if (!st.empty() && st.top() == 'P') {
                st.pop();
            } else {
                st.push('P');
            }
        } else if (!st.empty() && ((st.top() == 'B' && color == 'G') || (st.top() == 'G' && color == 'B'))) {
            st.pop();
            if (!st.empty() && st.top() == 'C') {
                st.pop();
            } else {
                st.push('C');
            }
        } else {
            st.push(color);
        }
    }

    string result;
    while (!st.empty()) {
        result = st.top() + result;
        st.pop();
    }

    return result;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string colors;
        cin >> colors;
        string result = getFinalColors(colors);
        cout << result << endl;
    }

    return 0;
}
