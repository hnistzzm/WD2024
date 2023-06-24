/**
 * DFS实现拓扑排序
 * 实现思路:
 *      拓扑排序中一个结点的祖先结点一定排在子孙结点之前，而DFS是先访问子孙结点
 *      正常来说DFS遍历是实现一个逆拓扑排序，要想实现我们的要求，可以新增一个time变量
 *      来标记递归调用中结点访问的结束时间，因为递归调用中，祖先节点一定比子孙结点结束时间晚,
 *      故每次在一个结点即将递归退栈前，将time+1，表示当前结点的结束时间晚于他的子节点
 *      在dfs结束后，将finishTime及存储的是各结点的结束时间，由大到小即可的出拓扑排序序列
 *  代码实现与DFS几乎一行,仅仅是新增了time变量
*/

void DFSTraverse(Graph G) {
    for(int i=0;i<G.vexNum;i++) {
        visited[i] = false;
    }
    int time=0;
    for(int i=0;i<G.vexNum;i++) {
        if(!visited[i]) {
            DFS(G,i);
        }
    }
}
void DFS(Graph G, int v) {
    visited[v] = true;
    for(int w=FirstNeighbor(G,v);w>=1;w= w=NextNeighbor(G,v,w)) {
        if(!visited[w]){
            DFS(G,w);
        }
    }
    time = time+1;finishTime[v] = time;
}