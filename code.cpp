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
    cout<<"河-------水 ";
	for(int i=0;i<7;i++)
	  if(r[i]=='z')break;
	  else cout<<r[i]<<" ";
	cout<<endl;
	return ;	  
}
int main(){
	cout<<"欢迎来到大小狮子过河，哇哈哈哈"<<endl<<endl;
	cout<<"A,B,C表示母狮子，a,b,c表示小狮子"<<endl;
	cout<<"在船上，左岸，右岸，母狮子会吃掉除自己孩子外没有母狮子保护的小狮子"<<endl;
	cout<<"船最多坐两只狮子，且小狮子中只有a会开船"<<endl;
	cout<<"记得船需要有人开回来，不会自己回来"<<endl;
	cout<<"还有呢本游戏过河后所有狮子都默认上岸，没有待在船上的情况"<<endl; 
	cout<<"接下来帮助可爱的狮子们平安过河吧"<<endl<<endl; 
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
			cout<<"输入左边上船的狮子，1或2只"<<endl;
			getline(cin,s); 
			for(int i=0;i<s.length();i++)
				if((64<int(s[i])&&int(s[i])<68)||(96<int(s[i])&&int(s[i])<100))
					c[++n]=s[i];
			/*cout<<"c[i]=";
			for(int i=0;i<3;i++)
			  cout<<c[i]<<" ";
	        cout<<endl;*/
		    if((n!=1&&n!=2)||c[1]==c[2]){
			  cout<<"输入错误,重新输入"<<endl;
			  Out(l,r);
		    }
		    else if(!samejudge(c,l,n)){
			  cout<<"有狮子不存在，重新输入"<<endl; 
			  Out(l,r);
		    }
			else if(n==2&&!DeathJ(c,3)){
			  cout<<"船上的小狮子死亡,重新坐船"<<endl;
			  Out(l,r);
			}
			else if(n==2&&!abjudge(c)||(n==1&&(c[1]=='b'||c[1]=='c'))){
				  cout<<"b和c都不会划船，重新坐船"<<endl;
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
				  cout<<"左边有狮子被吃,游戏结束"<<endl;
			      flag=0;break;
				}
				if(!DeathJ(r,7)){
				  cout<<"右边有狮子被吃,游戏结束"<<endl;
			      flag=0;break;
				}
				cout<<"过河成功"<<endl; 
				for(int i=0;i<3;i++)
				  c[i]='z';
				ship=0; 	 
			}
		}
		else if(ship==0){
			int n=0;
			cout<<"输入右边上船的狮子，1或2只"<<endl;
			getline(cin,s); 
			for(int i=0;i<s.length();i++)
				if((64<int(s[i])&&int(s[i])<68)||(96<int(s[i])&&int(s[i])<100))
					c[++n]=s[i];
			/*cout<<"c[i]=";
			for(int i=0;i<3;i++)
			  cout<<c[i]<<" ";
	        cout<<endl;*/
		   if((n!=1&&n!=2)||c[1]==c[2]){
			  cout<<"输入错误,重新输入"<<endl;
			  Out(l,r);
		    }
		    else if(!samejudge(c,r,n)){
			  cout<<"有狮子不存在，重新输入"<<endl; 
			  Out(l,r);
		    }
			else if(n==2&&!DeathJ(c,3)){
			  cout<<"船上的小狮子死亡,重新坐船"<<endl;
			  Out(l,r);
			}
			else if(n==2&&!abjudge(c)||(n==1&&(c[1]=='b'||c[1]=='c'))){
				  cout<<"b和c都不会划船，重新坐船"<<endl;
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
				  cout<<"左边有狮子被吃,游戏结束"<<endl;
			      flag=0;break;
				}
				if(!DeathJ(r,7)){
				  cout<<"右边有狮子被吃,游戏结束"<<endl;
				  flag=0;break;
				}
				cout<<"过河成功"<<endl; 
				for(int i=0;i<3;i++)
				  c[i]='z';
				ship=1; 	 
			}
		}
	}
    int end;
	if(flag==1){
	cout<<"恭喜你，挑战成功！"<<endl;
	cout<<"动次打次,朋友下次再见"<<endl; 
	}
	else cout<<"真抱歉游戏失败,再来一次？"<<endl;
	cout<<"输入1结束"<<endl; 
	cin>>end;
    return 0;
}