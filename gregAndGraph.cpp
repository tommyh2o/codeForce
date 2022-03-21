# include <iostream>
# include <cstdio>
# include <algorithm>

using namespace std;
int gam [501][501], answer[501];
int toDelete[501];
bool vis[501];

int main () {
    int numVertices;
    // Get the number of vertices
    scanf("%d", &numVertices);


    // Get the graph adjacency matrix
    for(int i = 0; i < numVertices; i++) {
        for(int j = 0 ;j < numVertices; j++) {
            cin >> gam [i][j];
            answer[0] += gam [i][j];
        }
    }

    // Get the vertices to be deleted 
    for(int i = 0; i < numVertices; i++) {
        cin >> toDelete[i];
    }
    for(int i = 0 ; i < numVertices; i++) {
        vis[i] = false;
    }

    for(int curr = 0; curr < numVertices; curr++) {
        answer[curr] = 0;
        int k = toDelete[curr];
        vis[k] = true;
        for(int i = 1; i <= numVertices; i++) {
            for(int j = 1; j <= numVertices; j++) {
                gam[i][j] = min(gam[i][j],gam[i][k]+gam[k][j]);
                if(vis[i] && vis[j])
                    answer[curr] += gam[i][j];
            }
        }
    }
    for(int i = 0; i < numVertices; i++) {
        cout<<answer[i]<<" ";
    }
	return 0;    
}