# 背包DP

## 0/1背包

- 问题描述：给定n件物品和一个背包。物品 i 的体积为 v[i] , 价值为 w[i] , 背包总容量为 C 。求背包所能装的物品的最大价值。

- 状态定义：用`dp[i][j]`表示在前i件物品中选若干件装入容量为 j 的背包中可获得的最大价值。

- 状态转移方程：
	$$
	dp[i][j]=max(dp[i-1][j],dp[i-1][j-v[i]]+w[i])
	$$

- 空间复杂度优化( 滚动数组法 )
	考虑到`dp[i][j]`只和`dp[i-1][j]和dp[i-1][j-v[i]]`有关，可逆向遍历用新数组覆盖原数组。

- 

- 代码：

	```c++
	for(int i=1;i<=n;i++)
	    for(int j=C;j>=v[i];j--)
	        dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
	```

## 完全背包

- 问题描述：给定n种物品，每种物品数量无限，和一个背包。物品 i 的体积为 v[i] , 价值为 w[i] , 背包总容量为 C 。求背包所能装的物品的最大价值。

- 状态定义：用`dp[i][j]`表示前i种物品中选若干件物品装入容量为 j 的背包中可获得的最大价值。

- 状态转移方程
	$$
	dp[i][j]=max(dp[i-1][j],dp[i][j-v[i]]+w[i])
	$$

- 空间复杂度优化( 滚动数组法 )
	`dp[i][j]`可由`dp[i-1][j]和dp[i][j-v[i]]`推出，可正向遍历用新数组覆盖原数组。

- 代码：

	```c++
	for(int i=1;i<=n;i++)
	    for(int j=w[i];j<=C;j++)
	        dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
	```

## 多重背包

- 问题描述：给定n种物品和一个背包。物品 i 的数量为s[i], 体积为 w[i] , 价值为 v[i] , 背包总容量为 C 。求背包所能装的物品的最大价值。

- 将*S*个物品合并成⌈*log*2*S*⌉份物品，按照倍增思想，每一份分别为1,2,4,...,2*k*,*C*个物品来划分，转化为0/1背包问题。

- 代码

	```c++
	for(int i=1;i<=n;i++){
		int a,b,s;
	    cin>>a>>b>>s;
	    int k=1;
	    while(k<=s){
	        idx++;
	        v[idx]=a*k;
	        w[idx]=b*k;
	        s-=k;
	        k*=2;
	    }
	    if(s>0){
	        idx++;
	        v[idx]=a*s;
	        w[idx]=b*s;
	    }
	}
	for(int i=1;i<=index;i++)
	    for(int j=C;j>=v[i];j--)
	        dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
	
	```

## 分组背包

- 问题描述：给定n组物品和一个背包。第 i组物品 的数量为s[i], 其中第j件物品体积为 `v[i][j]` , 价值为`w[i][j]` ,每组物品中最多只能选择其中的一个物品, 背包总容量为 C 。求背包所能装的物品的最大价值。

- 代码

	```c++
	for(int i = 1; i <= n; i++){
	    cin>>s[i];
	    for(int j = 1; j <= s[i]; j++)
	        cin>>v[i][j]>>w[i][j];
	}
	for(int i = 1; i <= n; i++)
	    for(int j = C; j >= 0; j--)
	        for(int k = 1; k <= s[i]; k++)
	            if(j >= v[i][k])
	                dp[j] = max(dp[j], dp[j - v[i][k]] + w[i][k]);
	```

	

## 二维背包

- 问题描述：给定n种物品和一个背包。取第i种物品需要付出代价w1和w2，价值为v，背包的两种代价上限为C1和C2。求背包所能装的物品的最大价值。

- 状态定义：用`dp[i][j][k]`表示前i件物品付出两种代价不超出j和k时可获得的最大价值。

- 状态转移方程：

	- 0/1背包：
		$$
		dp[i][j][k]=max(dp[i-1][j][k],dp[i-1][j-w1[i]][k-w2[i]]+v[i])
		$$

	- 完全背包：
		$$
		dp[i][j][k]=max(dp[i-1][j][k],dp[i][j-w1[i]][k-w2[i]]+v[i])
		$$

# 线性DP

## 最长上升子序列

### dp做法

- 思路：用`dp[i]`表示以`a[i]`结尾的最长上升子序列的长度，则`dp[i] = max(dp[j] + 1)`,对于所有的`j < i && a[j] < a[i]`。

- 复杂度：dp的总状态数为n，每次状态转移的需要遍历前i - 1个数，总复杂度为$O(n^2)$

- 代码：

	```c++
	for(int i = 1; i <= n; i++){
	    dp[i] = 1;
	    cin>>a[i];
	}
	for(int i = 1; i <= n; i++)
	    for(int j = 1; j < i; j++)
	        if(a[j] < a[i])
	            dp[i] = max(dp[i], dp[j] + 1);
	```

### 贪心+二分

- 思路：我们维护一个数组d，用`d[i]`来存储长为i的上升子序列结尾元素的最小值，len表示当前最长上升子序列的长度。显然长为i + 1的上升子序列的结尾元素一定大于长为i的上升子序列的结尾元素。 因此我们可以从前到后遍历a数组，在d数组中二分查找第一个大于等于a[i]的数，将其替换为a[i]，并更新len的值。

- 复杂度：每一个数二分查找复杂度为$O(logn)$，一共n个数，总复杂度为$O(nlogn)$。

- 代码：

	```c++
	for(int i = 1; i <= n; i++)
	    scanf("%d", a + i);
	memset(d, 0x3f, sizeof d);
	for(int i = 1; i <= n; i++){
	    int r = lower_bound(d + 1, d + len + 1, a[i]) - d;
	    d[r] = a[i];
	    len = max(len, r);   
	}
	```

## 最长公共子序列

- 思路：用`dp[i][j]`表示a的前i位与b的前j位的最长公共子序列，则`dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])`,当`a[i] == b[j]`时，`dp[i][j] = max(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] + 1)`。

- 代码

	```c++
	for(int i = 1; i <= n; i++){
	    for(int j = 1; j <= m; j++){
	        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
	        if(a[i] == b[j])
	            dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
	    }
	}
	```


## 最短编辑距离

- 问题描述：给定两个字符串 A 和 B，现在要将 A 经过若干操作变为 B，可进行的操作有：

	1. 删除–将字符串 A 中的某个字符删除。
	2. 插入–在字符串 A 的某个位置插入某个字符。
	3. 替换–将字符串 A 中的某个字符替换为另一个字符。

	现在请你求出，将 A 变为 B 至少需要进行多少次操作。

- 思路：用`dp[i][j]`表示将a的前i位与b的前j位变得相同所需要的最小步数，`dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1`，当`a[i] == b[j]`时，`dp[i][j] = min(dp[i][j], dp[i -1][j - 1])`，否则`dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1)`。

- 代码：

	```c++
	for(int i = 0; i <= n; i++) dp[i][0] = i;
	for(int i = 0; i <= m; i++) dp[0][i] = i;
	for(int i = 1; i <= n; i++){
	    for(int j = 1; j <= m; j++){
	        dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
	        if(a[i] == b[j]) dp[i][j] = min(dp[i][j], dp[i -1][j - 1]);
	        else dp[i][j] = min(dp[i][j], dp[i -1][j - 1] + 1);
	    }
	}
	```

# 状压DP

状压dp通常用一个整数的二进制形式来表示一个状态，即状态压缩，状压dp的数据范围通常较小。

## 例题（[291. 蒙德里安的梦想 - AcWing题库](https://www.acwing.com/problem/content/293/)）

- 思路：当横向摆放的位置确定后，其余的均为纵向摆放，所以我们可以只考虑横向摆放的方案数。用`dp[i][j]`表示第i列，且第i - 1列伸出状态为j的方案数。其中j的二进制的每一位表示第i - 1列该行是否伸出。

- 状态转移：我们可以枚举第i行和i - 1所有的状态，当两个状态不冲突时，我们就可以更新`dp[i]`。

- 代码：

	```c++
	#include <iostream>
	#include <cstring>
	
	using namespace std;
	
	typedef long long ll;
	
	const int N = 12, M = 1 << N;
	
	ll dp[N][M];
	bool st[M];
	
	int main(){
	    int n, m;
	    // 预处理每种状态是否符合条件
	    while(cin >> n >> m, n || m){
	        for(int i = 0; i < 1<<n; i++){
	            st[i] = true;
	            int cnt = 0;
	            for(int j = 0; j < n; j++){
	                if(i >> j & 1){
	                    if(cnt & 1) st[i] = false;
	                    cnt = 0;
	                }
	                else cnt++;
	            }
	            if(cnt & 1) st[i] = false;
	        }
	        // 初始化
	        memset(dp, 0, sizeof dp);
	        dp[0][0] = 1;
	        // dp求解过程
	        // 只有当第i列和第i - 1列不在同一行伸出
	        // 且除去两列所占有的行，其余的行不含连续奇数个空位时，可以进行状态转移
	        for(int i = 1; i <= m; i++)
	            for(int j = 0; j < 1 << n; j++)
	                for(int k = 0; k < 1 << n; k++)
	                    if((j & k) == 0 && st[j | k])
	                        dp[i][j] += dp[i - 1][k];
	        // 最终答案位第m列伸出为0的方案总数
	        cout << dp[m][0] <<endl;
	    }
	    return 0;
	}
	```

	
