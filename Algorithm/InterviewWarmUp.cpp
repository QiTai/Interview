// QuickSort
int partition(vector<int>& nums, int left, int right) {
    int pivot = nums[right];
    int r = left - 1;
    for (int i = left; i < right; i++) {
        if (nums[i] < pivot) {
            r++;
            swap(nums[i], nums[r]);
        }
    }
    r++;
    swap(nums[r], nums[right]);
    return r;
}

int partition(vector<int>& num, int p, int r) {
	int x = num[r];
	int i = p - 1;
	for (int j = p; j < r; j++) {
		if (num[j] <= x) {
			i = i + 1;
			// exchange num[i] and num[j];
			int tmp = num[i];
			num[i] = num[j];
			num[j] = tmp;
		}
	}
	// exchange num[i + 1] and num[r]
	int tmp = num[i + 1];
	num[i + 1] = num[r];
	num[r] = tmp;
	return i + 1;
}

void quickSort(vector<int>& num, int p, int r) {
	if (p < r) {
		int q = partition(num, p, r);
		quickSort(num, p, q - 1);
		quickSort(num, q + 1, r);
	}
}

// Reverse a List
ListNode* reverseList(ListNode* head) {
	    ListNode* prev = NULL;
	    while (head != NULL) {
	        ListNode* next = head->next;
	        head->next = prev;
	        prev = head;
	        head = next;
	    }
	    return prev;
    }

// Linked List Cycle
bool hasCycle(ListNode *head) {
    ListNode *p, *q;
    for (p = q = head; q; p = p->next, q = q->next) {
        q = q->next;
        if (!q) break;
        if (p == q) return true;
    }
    return false;
}

// Search For a Range
vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> res(2, -1);
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) left = mid + 1;
        else right = mid;
    }
    if (nums[right] != target) return res;
    res[0] = right;
    right = nums.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] <= target) left = mid + 1;
        else right= mid;
    }
    res[1] = left - 1;
    return res;
}

// Linked List Random Node
class Solution {
	ListNode *head;
public:
	/** @param head The linked list's head. Note that the head is guanranteed to be not null, so it contains at least one node. */
	Solution(ListNode* head) :head(head) {}

	/** Returns a random node's value. */
	int getRandom() {
		int ans = 0;
		ListNode *p = head;
		for (int cnt = 1; p; cnt++, p = p->next) if (rand() % cnt == 0) ans = p->val;
		return ans;
	}
};

// Balanced Binary Tree
class Solution {
public:
    int dfsHeight(TreeNode *root) {
        if (root == NULL) return 0;

        int leftHeight = dfsHeight (root -> left);
        if (leftHeight == -1) return -1;
        int rightHeight = dfsHeight (root -> right);
        if (rightHeight == -1) return -1;

        if (abs(leftHeight - rightHeight) > 1)  return -1;
        return max (leftHeight, rightHeight) + 1;
    }
    bool isBalanced(TreeNode *root) {
        return dfsHeight(root) != -1;
    }
};

// Longest Increasing Subsequences
int lengthOfLIS(vector<int>& nums) {
    vector<int> dp;
    for (int i = 0; i < nums.size(); ++i) {
        int left = 0, right = dp.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (dp[mid] < nums[i]) left = mid + 1;
            else right = mid;
        }
        if (right >= dp.size()) dp.push_back(nums[i]);
        else dp[right] = nums[i];
    }
    return dp.size();
}
