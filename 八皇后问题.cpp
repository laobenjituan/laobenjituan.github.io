#include<stdio.h>
int all=0;
bool mp[8][8];
//��   ��Խ���   �ҶԽ��� 
bool col[10],left[20],right[20];
bool check(int r,int i){
	return !(col[i]||left[r+i]||right[r-i+8]);//�����лʺ���л������Խ���δ��ս�죬�򷵻�true 
}
void go(int r){
	if(r==8){
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				if(mp[i][j]){
					printf("Q");//�ö�ά����Ϊtrueʱ,˵���ô��лʺ� 
				}
				else{
					printf("*");//�ö�ά����Ϊfalseʱ,˵���ô�δ�лʺ� 
				}
			}	
				printf("\n");//���һ�к�,����һ�м������ 
		}
		printf("\n");//�ָ���ÿһ�ֽ� 
		all++;//���ӽ�Ĵ��� 
		return;
	}
	for(int i=0;i<8;i++){
		if(check(r,i)){
			mp[r][i]=true;//��ʾ�лʺ� 
			col[i]=left[r+i]=right[r-i+8]=true;//���ûʺ��ռ�������ռ�� 
			go(r+1);
			mp[r][i]=false;//��ʾ�ô������лʺ󣬴���һ�м������� 
			col[i]=left[r+i]=right[r-i+8]=false;//��ԭ�ݹ�ǰ��״̬ 
		}
	}
}
int main(){
	go(0); //ִ���㷨 
	printf("����%d�ֽⷨ\n",all);//����˻ʺ�Ľ��� 
	return 0; 
}
