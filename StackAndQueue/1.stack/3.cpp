//判断输出序列是否合法
bool Judge(char A[]){
	int i=0;
	int j=0,k=0;
	while(A[i] != '\0'){
		switch (A[i]){
		case 'I':
			j++;
			break;
		case 'O':
			k++;
			if(k>j) {cout<<"非法序列"<<endl; system ("pause");}
		}
	i++;
	}
	if(j != k){
		cout<<"非法序列"<<endl;
		return false;
	}
	else{
		cout<<"序列合法."<<endl;
		return true;
	}
}
