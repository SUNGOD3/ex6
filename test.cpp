#include <iostream>
#include <vector>
#include <set>
using namespace std;
long long n,sz[15],k,it,ansv,m;
vector <long long> v[15],ans,ban[200005];
set <vector<long long> > s;
int main(){
	std::ios::sync_with_stdio(false);std::cin.tie(0);
	cin >> n;
	for(int i=0;i<n;++i){
		cin >> sz[i];
		v[i].push_back(-1);
		for(int j=0;j<sz[i];++j){
			cin >> k;
			v[i].push_back(k);
		}
		ans.push_back(sz[i]);
	}
	cin >> m;
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j){
			cin >> k;
			ban[i].push_back(k);
		}
		s.insert(ban[i]);
	}
	if(s.count(ans)){
		while(it<m){
			long long tmp=0;
			for(int i=0;i<n;++i){
				tmp+=v[i][ban[it][i]];
			}
			if(tmp<ansv){
				++it;
				continue;
			}
			for(int i=0;i<n;++i){
				if(ban[it][i]>1){
					tmp-=v[i][ban[it][i]];
					ban[it][i]--;
					tmp+=v[i][ban[it][i]];
					if(tmp>ansv&&s.count(ban[it])==0){
						ansv=tmp;
						ans=ban[it];
					}
					tmp-=v[i][ban[it][i]];
					ban[it][i]++;
					tmp+=v[i][ban[it][i]];
				}
			}
			++it;
		}	
	}
	for(int i=0;i<n;++i){
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
} 
