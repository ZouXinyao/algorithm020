学习笔记

#### 1、深度优先搜索DFS

非递归时，用栈；

模板：

```c++
void dfs(Node* root) {
	map<int, int> visited;
	if(!root) return ;

	stack<Node*> stackNode;
	stackNode.push(root);

	while (!stackNode.empty()) {
		Node* node = stackNode.top();
		stackNode.pop();
		if (visited.count(node->val)) continue;
		visited[node->val] = 1;
		
        // 下探
		for (int i = node->children.size() - 1; i >= 0; --i) {
			stackNode.push(node->children[i]);
		}
	}
	return ;
}
```

递归：

```c++
map<int, int> visited;

void dfs(Node* root) {
    // terminator
    if (!root) return ;

    if (visited.count(root->val)) {
    	// already visited
    	return ;
    }

    visited[root->val] = 1;

    // process current node here. 
    // ...
    for (int i = 0; i < root->children.size(); ++i) {
    	dfs(root->children[i]);
    }
    return ;
}
```

#### 2、广度优先搜索BFS

用队列

```c++
void bfs(Node* root) {
    map<int, int> visited;
    if(!root) return ;

    queue<Node*> queueNode;
    queueNode.push(root);

    while (!queueNode.empty()) {
    	Node* node = queueNode.top();
    	queueNode.pop();
    	if (visited.count(node->val)) continue;
    	visited[node->val] = 1;

		// 处理当前层
    	for (int i = 0; i < node->children.size(); ++i) {
    		queueNode.push(node->children[i]);
    	}
    }

    return ;
}
```

DFS、BFS注意需要增加一些状态变量，可以求一些其他其他信息



#### 3、贪心算法

贪心就是寻找当前的最优情况，并且这个情况也是全局最优；也可以是前面的选择不会影响后面的选择。

1. 注意一些贪心算法问题稍微改变一些前提条件就会变成动态规划解决的问题，也就是条件无法满足前面最优不影响后面选择；
2. 注意有的问题可以从后向前贪心。
3. 注意有的问题在思考贪心的情况时，需要更深层的理解。



#### 4、二分查找

二分的先决条件：连续存储；递增。

注意边界情况以及是否等于

模板：

```
int binarySearch(const vector<int>& nums, int target) {
    int left = 0, right = (int)nums.size()-1;

    while (left <= right) {
        int mid = left + (right - left)/ 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) left = mid + 1;
        else right = mid - 1;
    }

    return -1;
}
```

旋转排序数组：

先判断mid左右两边哪边是有序，再判断其他条件。

```
找最小值：
int findMin(vector<int>& nums) {
    int l = 0;
    int r = nums.size() - 1;
    int min = INT_MAX;
    while(l <= r) {
        int m = l + (r - l) / 2;
        min = min < nums[m] ? min : nums[m];
        if(nums[m] < nums[r]) r = m - 1;
        else l = m + 1;
    }
    return min;
}
```

