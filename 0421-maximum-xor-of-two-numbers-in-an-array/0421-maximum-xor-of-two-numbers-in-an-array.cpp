struct Node {
    Node* link[2];

    // Node() {
    //     link[0] = nullptr;
    //     link[1] = nullptr;
    // }

    void put(int ch, Node* node) {
        link[ch] = node;
    }

    Node* get(int ch) {
        return link[ch];
    }

    bool containKey(int ch) {
        return link[ch] != nullptr;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(int num) {
        Node* node = root;

        int i = 31;

        while (i >= 0) {

            int ch = (num >> i) & 1;

            if (!node->containKey(ch)) {
                node->put(ch, new Node());
            }

            node = node->get(ch);

            i--;
        }
    }

    int getMax(int num) {
        Node* node = root;

        int ans = 0;
        int i = 31;

        while (i >= 0) {

            int ch = (num >> i) & 1;

            if (node->containKey(1 - ch)) {
                ans = ans | (1 << i);
                node = node->get(1 - ch);
            }
            else {
                node = node->get(ch);
            }

            i--;
        }

        return ans;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {

        Trie* obj = new Trie();

        int i = 0;

        while (i < nums.size()) {
            obj->insert(nums[i]);
            i++;
        }

        int maxi = 0;

        i = 0;

        while (i < nums.size()) {
            maxi = max(maxi, obj->getMax(nums[i]));
            i++;
        }

        return maxi;
    }
};