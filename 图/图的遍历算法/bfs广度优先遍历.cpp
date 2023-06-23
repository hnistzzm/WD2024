/**
 * BFS广度优先遍历
 * 实现思路:
 *     核心: 用队列存储下一轮可能会访问的顶点
 *      注意点:要考虑连通图和非连通图两种情况,
 *             故在BFSTraverse函数中应该对每个顶点都调用一次BFS，以使得所有顶点都能遍历到.
 *              但实际上BFS函数调用的次数等于图的连通分量的个数,大概率是遍历不了n次的
 *      1.初始化队列，并对n个顶点调用bfs函数
 *      2.出队，并访问当前顶点的邻接顶点，并修改visited[]数组
 *      3.重复2操作，直至队列为空，遍历结束
*/

void BFSTraverse(Graph G) {
    int i;
    for(i=0;i<G.vexNum;i++) {
        visted[i] = false;
    }
    InitQueue(Q);
    for(i=0;i<G.vexNum;i++) {
        if(!visited[i]) {
            BFS(G,i);
        }
    }
}
void BFS(Graph G,int v) {
    visit(v);
    visited[v] = true;
    EnQueue(Q,v);
    while(!isempty(Q)) {
        DeQueue(Q,v);
        for(w=FirstNeibhor(G,v);w;w=NextNeibhor(G,v,w)) {
            if(!visted[w]) {
                visit(w);
                visted[w] = true;
                EnQueue(Q,v);
            }   
        }
    }
}