/**
 * DFS深度优先遍历
 * 实现思路:递归访问，找到当前结点的所有未被访问过的邻接点，并执行DFS
 *      
*/
void DFSTraverse(Graph G) {
    int i;
    for(i=0;i<G.vexNum;i++) {
        visted[i] = false;
    }
    for(i=0;i<G.vexNum;i++) {
        if(!visited[i]) {
            DFS(G,i);
        }
    }
}
void DFS(Graph G ,int v) {
    visit[v];
    visited[v]=true;
    for(w=FirstNeighbour(G,v);w>=0;w=NextNeighbour(G,v,w)) {
        if(!visited[w]) {
            DFS(G,w)
        }
    }
}