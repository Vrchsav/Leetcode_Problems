struct Node {
    Node* arr[2];

    bool containKey(int bit) { return (arr[bit] != nullptr); }
    Node* get(int bit) { return arr[bit]; }
    void put(int bit, Node* node) { arr[bit] = node; }
};

class Tries {
    Node* root;

public:
    Tries() { root = new Node(); }
    void insert(int num) {
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->containKey(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }
    int getMax(int num) {
        Node* node = root;
        int maxNum = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->containKey(1 - bit)) {
                maxNum = maxNum | (1 << i);
                node = node->get(1 - bit);

            } else {
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Tries trie;
        int n=nums.size();
        for (int i = 0; i < n; i++) {
            trie.insert(nums[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, trie.getMax(nums[i]));
        }
        return ans;
    }
};