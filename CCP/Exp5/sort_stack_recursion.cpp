#include <bits/stdc++.h>
using namespace std;

void insertSorted(stack<int>& st, int value) {
    if (st.empty() || st.top() <= value) {
        st.push(value);
        return;
    }

    int topValue = st.top();
    st.pop();
    insertSorted(st, value);
    st.push(topValue);
}

void sortStack(stack<int>& st) {
    if (st.empty()) {
        return;
    }

    int topValue = st.top();
    st.pop();
    sortStack(st);
    insertSorted(st, topValue);
}

void printStackBottomToTop(stack<int> st) {
    if (st.empty()) {
        return;
    }

    int topValue = st.top();
    st.pop();
    printStackBottomToTop(st);
    cout << topValue << " ";
}

int main() {
    stack<int> st;
    for (int value : {34, 3, 31, 98, 92, 23}) {
        st.push(value);
    }

    sortStack(st);

    cout << "Sorted stack from bottom to top: ";
    printStackBottomToTop(st);
    cout << endl;

    return 0;
}