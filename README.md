# 2022-fall-AI-Introduction-last-HW-1
## 初步思考
- step1: 尝试扩展节点并决策
- step2: 尝试建立评估函数

每个棋局用一个 01 串表示：
- 如果是 10 / 01 表示这里没有棋子
- 如果是 00 表示这里是我方棋子
- 如果是 11 表示这里是敌方棋子

每一行首尾相连构成一个长串

限定棋盘是 10 * 10 大小

那么假设使用 11 填满整个棋盘，最大值是 $2^{200} > 2^{64} > 2^{32}$ 

不可能使用 int 或者 long long 表示

假设博弈树有 k 层，那么最多需要检索的叶子节点有，

$$ \prod_{i = 100-k}^{100} i $$

*这样的空间大小是不可接受的，必须剪枝*

不过如果是深度优先遍历，实际上可以每次只保存一种棋局即可

所以如何扩展节点才是重要问题

## 扩展节点
使用递归的思想


