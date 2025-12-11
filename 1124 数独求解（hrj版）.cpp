#include<bits/stdc++.h>
using namespace std;
const int N=10;
int arr[N][N];
bool row[N][N],col[N][N],arr1[N][N];
bool flag = false; 
void dfs(int x,int y){
    if(flag==true) return;
    if(arr[x][y]!=0){
        if(x==9&&y==9){
            flag = true; 
            return;
        }
        else if(y==9&&x<9){
            dfs(x+1,1);
        }
        else{
            dfs(x,y+1);
        }
        return; 
    }
    for(int i=1;i<=9;i++){
        int g = (x-1)/3*3 + (y-1)/3 + 1; 
        if(row[x][i]==0 && col[y][i]==0 && arr1[g][i]==0){
            arr[x][y] = i;
            row[x][i] = col[y][i] = arr1[g][i] = 1;
            if(x==9&&y==9){
                flag = true; 
                return;
            }
            else if(y==9){
                dfs(x+1,1);
            }
            else{
                dfs(x,y+1);
            }
            if(flag==0){
                arr[x][y] = 0;
                row[x][i] = col[y][i] = arr1[g][i] = 0;
            }
        }
    }
}
int main(){
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            int t;
            cin>>t;
            if(t>0){
                row[i][t] = col[j][t] = arr1[(i-1)/3*3+(j-1)/3+1][t] = 1;
            }
            arr[i][j] = t;
        }
    }
    dfs(1,1);
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
