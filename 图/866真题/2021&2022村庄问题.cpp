/**
 * 题目描述：给定n个村庄之间的交通图，现拟在n个村庄之间选择一个村庄建立小学，
 * 请设计一个算法求解该小学应该建立在哪个村庄才能使得距离最远的村庄到小学的路程最短。
 * （21和22年考研原题，21年给了ADT，22年没给ADT）
 * 实现思路：
 *     该题本质是求最短路径问题，涉及多个顶点间的最短距离。应该采用floyd算法
 *     步骤:
 *          1.floyd算法求出各个顶点之间的最短距离
 *          2.找出每个顶点到其他顶点间最短距离的最长的一个距离
 *          3.比较2中所有最长边的距离，找到最小的那个距离对应的边
*/

int distance(Graph G) {
    int dist[n][n];
    for(int i=0; i<G.vexNum; i++) {
        for(int j=0; j<G.vexNum; j++>) {
            dist[i][j] = G.edge[i][j];
        }
    }
    //floyd算法主过程
    for(int k=0; k<G.vexNum; k++) {
        for(int i=0; i<G.vexNum; i++) {
            for(int j=0; j<G.vexNum; j++) {
                if(dist[i][k] + dist[k][j] < dist[i][j]) {
                     dist[i][j] =  dist[i][k] + dist[k][j];
                }
            }
        }
    }
    int minDis=999999;//最长距离合集中最短的一个距离
    for(int i = 0; i <G.vexNum; i++) {//找到
        int maxDistance = 0;
        for(int j = 0; j < G.vexNum; j++) {//找i到其他各村庄的最短路径中最长的那一个路径的距离
            if(dist[i][j] > maxDistance) {
                maxDistance = dist[i][j];
            }
        }
        if(maxDistance < minDis) {//最长距离合集中最短的一个距离
            minDis = maxDistance;
            k = i;
        }
    }
    return k;
}