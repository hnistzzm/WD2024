/**
 * Floyd算法
 * 实现思路:
 *      主要包含两个数组：
 *          1.dist[][]:记录两点间的距离
 *          2.path[][]:记录两点间最短路径的前驱结点
 *      1.初始化dist和path
 *      2.迭代n轮：
 *          1.若dist[i][k]+dist[k][j] < dist[i][j] 则更新dist[i][j]以及path[i][j]
*/
void Floyd(Graph G) {
    int i,j,k;
    for ( i = 0; i < G.vexNum; i++){//初始化
        for ( j = 0; j < G.vexNum; j++){
            dist[i][j] = G.edge[i][j];
            path[i][j] = -1;
        }
    }
    for( k = 0; k < G.vexNum; k++){//迭代n轮 修改dist值 
        for( i = 0; i < G.vexNum; i++){
            for( j = 0; j < G.vexNum; j++){
                if(dist[i][k]+dist[k][j] < dist[i][j] ){//core
                    dist[i][j] = dist[i][k]+dist[k][j];
                    path[i][j] = k;
                }
            }
        }
    }
    
}