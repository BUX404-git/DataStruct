//�ж���������Ƿ�Ϸ�
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
			if(k>j) {cout<<"�Ƿ�����"<<endl; system ("pause");}
		}
	i++;
	}
	if(j != k){
		cout<<"�Ƿ�����"<<endl;
		return false;
	}
	else{
		cout<<"���кϷ�."<<endl;
		return true;
	}
}
