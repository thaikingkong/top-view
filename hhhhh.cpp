#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

void printTopView(Node* root) {
    if (root == NULL) return;

    map<int, int> hdToVal;  // Lưu giữ giá trị đầu tiên của mỗi cột
    queue<Node*> q;
    queue<int> hdQ;         // Lưu giữ độ cao của mỗi nút
    q.push(root);
    hdQ.push(0);

    while (!q.empty()) {
        Node* cur = q.front();
        q.pop();
        int hd = hdQ.front();
        hdQ.pop();

        if (hdToVal.find(hd) == hdToVal.end()) {
            hdToVal[hd] = cur->data;
            cout << cur->data << " ";
        }

        if (cur->left != NULL) {
            q.push(cur->left);
            hdQ.push(hd - 1);
        }
        if (cur->right != NULL) {
            q.push(cur->right);
            hdQ.push(hd + 1);
        }
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->right = new Node(5);
    root->left->right->right->right = new Node(6);

    cout << "Top view of the binary tree is: ";
    printTopView(root);
    cout << endl;

    return 0;
}
