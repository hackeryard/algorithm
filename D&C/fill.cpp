#include<bits/stdc++.h>
using namespace std;

void Fill(int **a, int i, int j, int n, int x, int y){
    if(n == 2){
//        cout<<"reach base case"<<endl;
        //base case
        //directly fill a L module
        for(int k = 0; k < 2; k++){
            for(int m = 0; m < 2; m++){
                if(i+k != x || j+m != y){
//                    cout<<"fill a cell."<<endl;
                    a[i+k][j+m] = 1;
                }
            }
        }
        return;
    }

    int mid = n>>1;
//    cout<<"mid: "<<mid<<endl;
//    exit(-1);
    int x2, y2, x3, y3, x4, y4, x1, y1;
    x1 = x2 = x3 = x4 = -1;
    y1 = y2 = y3 = y4 = -1;
    x1 = i+mid-1;
    y1 = j+mid-1;
    x2 = i+mid-1;
    y2 = j+mid;
    x3 = i+mid;
    y3 = j+mid-1;
    x4 = i+mid;
    y4 = j+mid;
    // judge the missing cell's sub-square
    if(x >= i && x < i+mid && y >= j && y < j+mid ){
        //sub 1
        x1 = y1 = -1;
        //fill a L shape


    } else if (x >= i && x < i+mid && y >= j+mid && y < j+n ){
        // sub 2
        x2 = y2 = -1;
    } else if (x >= i+mid && x < i+n && y >= j && y < j+mid ){
        //sub 3 left
        x3 = y3 = -1;
    } else {
        //sub 4 right
        x4 = y4 = -1;
    }

    // sub-problem
    if(x1 == -1){
        Fill(a, i, j, n>>1, x, y);
    } else {
        // fill a cell
        a[x1][y1] = 1;
        Fill(a, i, j, n>>1, x1, y1);
    }

    if(x2 == -1){
        Fill(a, i, j+mid, n>>1, x, y);
    } else {
        a[x2][y2] = 1;
        Fill(a, i, j+mid, n>>1, x2, y2);
    }

    if(x3 == -1){
        Fill(a, i+mid, j, n>>1, x, y);
    } else {
        a[x3][y3] = 1;
        Fill(a, i+mid, j, n>>1, x3, y3);
    }

    if(x4 == -1){
        Fill(a, i+mid, j+mid, n>>1, x, y);
    } else {
        a[x4][y4] = 1;
        Fill(a, i+mid, j+mid, n>>1, x4, y4);
    }
}



int main(){
    int n;
    cout<<"input size n:"<<endl;
    cin>>n;
    int **a;
    a = new int *[n];
    for(int i = 0; i < n; i++){
        a[i] = new int[n];
//        memset(a[i], 0, n);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            a[i][j] = 0;
//            cout<<a[i][j]<<" ";
        }
//        cout<<endl;
    }

    Fill(a, 0, 0, n, n-1, n-1);

    cout<<"fill result:"<<endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
