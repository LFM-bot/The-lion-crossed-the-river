#include<iostream>
#include<string.h>
using namespace std;
int f[7];
bool samejudge(char c[],char b[],int n){
	for(int i=1;i<=n;i++){
		int flag=0;
	  for(int j=0;j<7;j++)
	    if(c[i]==b[j]){flag=1;break;}
      if(flag==0)return 0;
	}
	return 1;
}
bool abjudge(char c[]){
	memset(f,0,sizeof(f));
	for(int i=1;i<3;i++)
      if(c[i]=='b')f[5]=1;
      else if(c[i]=='c')f[6]=1;
    if(f[5]&&f[6])return 0;
    else return 1;
}
bool judge(char l[]){
	for(int i=0;i<7;i++)
	  if(l[i]!='z')return 0;
    return 1;
}
int DeathJ(char c[],int n){
	memset(f,0,sizeof(f));
    /*for(int i=0;i<n;i++){
		cout<<c[i]<<" ";
	}
	cout<<endl;*/
	for(int i=0;i<n;i++){
		if(c[i]=='z')continue;
		if(c[i]=='A')f[1]=1;
		if(c[i]=='B')f[2]=1;
		if(c[i]=='C')f[3]=1;
		if(c[i]=='a')f[4]=1;
		if(c[i]=='b')f[5]=1;
		if(c[i]=='c')f[6]=1;
	}
	/*cout<<"f=";
	for(int i=1;i<=6;i++)
	  cout<<f[i]<<" ";
    cout<<endl;*/
	for(int i=6;i>=4;i--){
		if(f[i])
			for(int j=1;j<=3;j++){
				if(f[i-3])break;
				else if(j==i-3)continue;
                else if(!f[i-3]&&f[j])return 0;
			}
	}
	return 1;
}
bool cmp(char a,char b){
	return int(a)<int(b);
}
void Out(char l[],char r[]){
	sort(l,l+7,cmp);
	sort(r,r+7,cmp);
	for(int i=0;i<7;i++)
	  if(l[i]=='z')break;
	  else cout<<l[i]<<" ";
    cout<<"��-------ˮ ";
	for(int i=0;i<7;i++)
	  if(r[i]=='z')break;
	  else cout<<r[i]<<" ";
	cout<<endl;
	return ;	  
}
int main(){
	cout<<"��ӭ������Сʨ�ӹ��ӣ��۹�����"<<endl<<endl;
	cout<<"A,B,C��ʾĸʨ�ӣ�a,b,c��ʾСʨ��"<<endl;
	cout<<"�ڴ��ϣ��󰶣��Ұ���ĸʨ�ӻ�Ե����Լ�������û��ĸʨ�ӱ�����Сʨ��"<<endl;
	cout<<"���������ֻʨ�ӣ���Сʨ����ֻ��a�Ὺ��"<<endl;
	cout<<"�ǵô���Ҫ���˿������������Լ�����"<<endl;
	cout<<"�����ر���Ϸ���Ӻ�����ʨ�Ӷ�Ĭ���ϰ���û�д��ڴ��ϵ����"<<endl; 
	cout<<"�����������ɰ���ʨ����ƽ�����Ӱ�"<<endl<<endl; 
	char l[7],r[7];
	for(int i=0;i<7;i++){
	  r[i]='z';
	  l[i]='z';
	}
	l[1]='A';l[2]='B';l[3]='C';l[4]='a';l[5]='b';l[6]='c';
	Out(l,r);
	int ship=1,flag=1; 
	while(!judge(l)){
		string s;
		char c[4];
		c[0]='z';
		if(ship==1){
			int n=0;
			cout<<"��������ϴ���ʨ�ӣ�1��2ֻ"<<endl;
			getline(cin,s); 
			for(int i=0;i<s.length();i++)
				if((64<int(s[i])&&int(s[i])<68)||(96<int(s[i])&&int(s[i])<100))
					c[++n]=s[i];
			/*cout<<"c[i]=";
			for(int i=0;i<3;i++)
			  cout<<c[i]<<" ";
	        cout<<endl;*/
		    if((n!=1&&n!=2)||c[1]==c[2]){
			  cout<<"�������,��������"<<endl;
			  Out(l,r);
		    }
		    else if(!samejudge(c,l,n)){
			  cout<<"��ʨ�Ӳ����ڣ���������"<<endl; 
			  Out(l,r);
		    }
			else if(n==2&&!DeathJ(c,3)){
			  cout<<"���ϵ�Сʨ������,��������"<<endl;
			  Out(l,r);
			}
			else if(n==2&&!abjudge(c)||(n==1&&(c[1]=='b'||c[1]=='c'))){
				  cout<<"b��c�����Ữ������������"<<endl;
				  Out(l,r); 
    		}
			else {
				for(int i=1;i<=n;i++)
				  for(int j=0;j<7;j++)
				    if(c[i]==l[j])l[j]='z';
		        for(int i=1;i<=n;i++)
          		  for(int j=0;j<7;j++)
		            if(r[j]=='z'){r[j]=c[i];break;}
				Out(l,r);
				if(!DeathJ(l,7)){
				  cout<<"�����ʨ�ӱ���,��Ϸ����"<<endl;
			      flag=0;break;
				}
				if(!DeathJ(r,7)){
				  cout<<"�ұ���ʨ�ӱ���,��Ϸ����"<<endl;
			      flag=0;break;
				}
				cout<<"���ӳɹ�"<<endl; 
				for(int i=0;i<3;i++)
				  c[i]='z';
				ship=0; 	 
			}
		}
		else if(ship==0){
			int n=0;
			cout<<"�����ұ��ϴ���ʨ�ӣ�1��2ֻ"<<endl;
			getline(cin,s); 
			for(int i=0;i<s.length();i++)
				if((64<int(s[i])&&int(s[i])<68)||(96<int(s[i])&&int(s[i])<100))
					c[++n]=s[i];
			/*cout<<"c[i]=";
			for(int i=0;i<3;i++)
			  cout<<c[i]<<" ";
	        cout<<endl;*/
		   if((n!=1&&n!=2)||c[1]==c[2]){
			  cout<<"�������,��������"<<endl;
			  Out(l,r);
		    }
		    else if(!samejudge(c,r,n)){
			  cout<<"��ʨ�Ӳ����ڣ���������"<<endl; 
			  Out(l,r);
		    }
			else if(n==2&&!DeathJ(c,3)){
			  cout<<"���ϵ�Сʨ������,��������"<<endl;
			  Out(l,r);
			}
			else if(n==2&&!abjudge(c)||(n==1&&(c[1]=='b'||c[1]=='c'))){
				  cout<<"b��c�����Ữ������������"<<endl;
				  Out(l,r); 
    		}
			else {
				for(int i=1;i<=n;i++)
				  for(int j=0;j<7;j++)
				    if(c[i]==r[j])r[j]='z';
		        for(int i=1;i<=n;i++)
          		  for(int j=0;j<7;j++)
		            if(l[j]=='z'){l[j]=c[i];break;}
				Out(l,r);
				if(!DeathJ(l,7)){
				  cout<<"�����ʨ�ӱ���,��Ϸ����"<<endl;
			      flag=0;break;
				}
				if(!DeathJ(r,7)){
				  cout<<"�ұ���ʨ�ӱ���,��Ϸ����"<<endl;
				  flag=0;break;
				}
				cout<<"���ӳɹ�"<<endl; 
				for(int i=0;i<3;i++)
				  c[i]='z';
				ship=1; 	 
			}
		}
	}
    int end;
	if(flag==1){
	cout<<"��ϲ�㣬��ս�ɹ���"<<endl;
	cout<<"���δ��,�����´��ټ�"<<endl; 
	}
	else cout<<"�汧Ǹ��Ϸʧ��,����һ�Σ�"<<endl;
	cout<<"����1����"<<endl; 
	cin>>end;
    return 0;
}