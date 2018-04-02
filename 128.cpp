/* 128. Longest Consecutive Sequence
 * link: https://leetcode.com/problems/longest-consecutive-sequence/description/
 * status: ac
 * 2018.4.2
 */

class Tree {
    public: 
        int id;
        int parent;
        int count;
        Tree(int p_id, int p_parent, int p_count) : id(p_id), parent(p_parent), count(p_count) {} ;
        Tree() {};
};

class Solution {
    public: 
        unordered_map<int, Tree> trees;
        Tree *find_root(int x)
        {
            if (trees.find(x) == trees.end()) {
                return NULL;
            }
            Tree *curr = &trees[x];
            Tree *last = NULL;
            while (curr->parent != curr->id) {
                last = curr;
                last->parent = curr->parent;
                curr = &trees[curr->parent];
            }

            return curr;
        }
        void merge(Tree *root, Tree *leaf)
        {
            leaf->parent = root->id;
            root->count += leaf->count;
        }
        int longestConsecutive(vector<int>& nums) 
        {
            int max = 0;
            for (int i = 0; i < nums.size(); i++) {
                int x = nums[i];
                if (trees.find(x) == trees.end()) {
                    Tree new_tree(x, x, 1);
                    trees[x] = new_tree;
                }
                Tree *curr = find_root(x);
                Tree *left = find_root(x - 1);
                Tree *right = find_root(x + 1);

                if (left && left->id != curr->id) {
                    merge(curr, left);
                }
                if (right && right->id != curr->id) {
                    if (left == NULL || left->id != right->id) {
                        merge(curr, right);
                    }
                }

                if (curr->count > max) {
                    max = curr->count;
                }
            }

            return max;
        }
};
