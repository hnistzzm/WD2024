/**
 * Dijkstra算法
 * 实现思路:
 *      主要包含三个数组:
 *          1.dist[j]:用来记录u到j的的距离
 *          2.path[j]:记录u到j的最短路径的前驱结点
 *          3.final[j]:记录u到j是否已找到最短路径
 *      1.初始化dist path final数组
 *      2.遍历n轮:
 *          1.每轮找到一个dist值最小的结点，将其并入集合中(修改final[j]为true)
 *          2.若dist[v] + G.edge[v][j] < dist[j]则更新dist数组(注意已经找到最短路径的顶点,及final为true的顶点对应的dist无需修改)
 *      
 *        
*/
#define Max_Length = 2147483647;

void Dijkstra(Graph G,int u) {
    int i,j;
    for(i=0;i<G.vexNum;i++) {//初始化 
        final[i] = false;
        dist[i] = G.edge[u][i];
        if(G.edge[u][i] == Max_Length || G.edge[u][i] == 0) {
            path[i] = -1;
        }
    }
    final[u] = true;
    
    for(i=0;i<G.vexNum;i++) {
        int min = Max_Length;
        for(j=0;j<G.vexNum;j++) {//找dist最小的邻接点
            if(final[j]!= true && dist[j] < min) {
                min = G.edge[u][j];
                v = j;
            }
        }
        final[v] = true;
        for(j=0;j<G.vexNum;j++) {//更新dist数组
            if(final[j] !=true && dist[v] + G.edge[v][j] < dist[j] ) {
                dist[j] = dist[v] + G.edge[v][j];
                path[j] = v;
            }
        }

    }
}