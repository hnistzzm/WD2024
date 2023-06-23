/**
 * BFS求无权图单源最短路径
 * 实现思路:
 *      主要包含三个数组:
 *          1.dist[j]:用来记录u到j的的距离
 *          2.path[j]:记录u到j的最短路径的前驱结点
 *          3.Visited[j]:记录j是否已被访问
 *      BFS遍历中队列是核心,故要设置队列存储下一轮可能需要访问的顶点
 *      1.初始化 dist path visited,并将顶点u入队
 *      2.出队，并访问当前顶点的邻接顶点，设置其dist path visited，其中dist[w] = dist[u] + 1;(★)
 *      3.重复操作2，直至队列为空
*/

#define Max_Length = 2147483647;
void BFS_MIN_Distance(Graph G,int u) {
    int i;
    for(i=0;i<G.vexNum;i++) { //初始化
        dist[i] = Max_Length;
        path[i] = -1;
        visited[i] = false;
    }
    InitQueue(Q);
    EnQueue(Q,u);
    while(!isEmpty(Q)) {//bfs算法主过程
        DeQueue(Q,u);
        for(w=FirstNeihbor(Q,u);w>=0;w=NextNeihbor(Q,u,w)) {//找到当前顶点的邻接顶点,访问它并修改visited dist path
            if(!visited[w]) {
                visited[w] = true;
                dist[w] = d[u] +1;
                path[w] = u;
                Enqueue(Q,w); //顶点w入队
            }
        }
    }
}