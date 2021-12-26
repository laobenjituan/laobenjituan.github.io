#include<stdio.h>
int all=0;
bool mp[8][8];
//列   左对角线   右对角线 
bool col[10],left[20],right[20];
bool check(int r,int i){
	return !(col[i]||left[r+i]||right[r-i+8]);//若该行皇后的列或两个对角线未被战领，则返回true 
}
void go(int r){
	if(r==8){
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				if(mp[i][j]){
					printf("Q");//该二维数组为true时,说明该处有皇后 
				}
				else{
					printf("*");//该二维数组为false时,说明该处未有皇后 
				}
			}	
				printf("\n");//输出一行后,再下一行继续输出 
		}
		printf("\n");//分隔开每一种解 
		all++;//增加解的次数 
		return;
	}
	for(int i=0;i<8;i++){
		if(check(r,i)){
			mp[r][i]=true;//表示有皇后 
			col[i]=left[r+i]=right[r-i+8]=true;//将该皇后可占领的区域占领 
			go(r+1);
			mp[r][i]=false;//表示该处不可有皇后，从下一列继续查找 
			col[i]=left[r+i]=right[r-i+8]=false;//还原递归前的状态 
		}
	}
}
int main(){
	go(0); //执行算法 
	printf("共有%d种解法\n",all);//输出八皇后的解数 
	return 0; 
}
