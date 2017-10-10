// LOCKED LEETCODE PROBLEMS

// 161-One Edit Distance
// from Leetcode 50 - beautiful code !
bool isOneEditDistance(string s, string t) {
  int m = s.size(), n = t.size();
  if (m > n) return isOneEditDistance(t, s);
  if (n - m > 1) return false;
  int i = 0, shift = n - m;
  while (i < m && s[i] == t[i]) i++;
  if (i == m) return shift > 0;
  if (shift == 0) i++;
  while (i < m && s[i] == t[i + shift]) i++;
  return i == m;
}

// 346-Moving Average from Data Stream
// from Coding_Interview_in_Java_v3
class MovingAverage {
public:
  MovingAverage(int size) {
    this->size = size;
    sum = 0;
  }

  double next(int val) {
    if (q.size() >= size) {
      sum -= q.front();
      q.pop();
    }
    q.push(val);
    sum += val;
    return sum / q.size();
  }

private:
  queue<int> q;
  int size;
  double sum;
}

// 314-Binary Tree Vertical Order Traversal
// from Coding_Interview_in_Java_v3
vector<vector<int>> verticalOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) return res;
    map<int, vector<int>> m;
    queue<pair<int, TreeNode*>> q;
    q.push({0, root});
    while (!q.empty()) {
      auto a = q.front(); q.pop();
      m[a.first].push_back(a.secong->val);
      if (a.second->left) q.push({a.first - 1, a.second->left});
      if (a.second->right) q.push({a.first + 1, a.second->right});
    }
    for (auto a : m) {
      res.push_back(a.second);
    }
    return res;
}

// 298-Binary Tree Longest Consecutive Sequence
// from Coding_Interview_in_Java_v3
// recursive
int longestConsecutive(TreeNode* root) {
  if (!root) return 0;
  int res = 0;
  dfs(root, root->val, 0, res);
  return res;
}
void dfs(TreeNode *root, int v, int out, int &res) {
  if (!root) return;
  if (root->val == v + 1) ++out;
  else out = 1;
  res = max(res, out);
  dfs(root->left, root->val, out, res);
  dfs(root->right, root->val, out, res);
}
// iterative
int longestConsecutive(TreeNode *root) {
  if (!root) return 0;
  int res = 0;
  queue<TreeNode*> q;
  q.push(root);
  while (!q.empty()) {
    int len = 1;
    TreeNode *t = q.front(); q.pop();
    while ((t->left && t->left->val == t->val + 1) || (t->right && t->right->val == t->val + 1)) {
      if (t->left && t->left->val == t->val + 1) {
        if (t->right) q.push(t->right);
        t = t->left;
      } else if (t->right && t->right->val == t->val + 1) {
        if (t->left) q.push(t->left);
        t = t->right;
      }
      ++len;
    }
    if (t->left) q.push(t->left):
    if (t->right) q.push(t->right);
    res = max(res, len);
  }
  return res;
}

// 549-Binary Tree Longest Consecutive Sequence II
// from Coding_Interview_in_Java_v3
int longestConsecutive(TreeNode *root) {
  int res = 0;
  helper(root, root, res);
  return res;
}

pair<int, int> helper(TreeNode *node, TreeNode *parent, int &res) {
  if (!node) return {0, 0};
  auto left = helper(node->left, node, res);
  auto right = helper(node->right, node, res);
  res = max(res, left.first + right.second + 1);
  res = max(res, left.second + right.first + 1);
  int inc = 0, dec = 0;
  if (node->val == parent->val + 1) {
    inc = max(left.first, right.first) + 1;
  } else if (node->val + 1 == parent->val) {
    dec = max(left.second, right.second) + 1;
  }
  return {inc, dec};
}
// Second Way
int longestConsecutive(TreeNode *root) {
  if (!root) return 0;
  int res = helper(root, 1) + helper(root, -1) + 1;
  return max(res, max(longestConsecutive(root->left), longestConsecutive(root->right)));
}
int helper(TreeNode *node, int diff) {
  if (!node) return 0;
  int left = 0, right = 0;
  if (node->left && node->val - node->left->val == diff) {
    left = 1 + helper(node->left, diff);
  }
  if (node->right && node->val - node->right->val == diff) {
    right = 1 + helper(node->right, diff);
  }
  return max(left, right);
}

// 270-Closest Binary Search Tree Value
// from Coding_Interview_in_Java_v3


// 272-Closest Binary Search Tree Value II
// from Coding_Interview_in_Java_v3























