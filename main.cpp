#include <bits/stdc++.h>

using namespace std;

#define MAX 100

int main(){

	vector<int> primos;
	int numero;
	for(int i=2; i<=MAX; i++){
		primos.push_back(i);
	}

	for(int i=0; primos[i]<=sqrt(MAX); i++ ){

		for(int j=i+1 ; j<primos.size() ;j++){
			if(primos[j]%primos[i] == 0){
				primos.erase(primos.begin()+j);
			}
			
		}

	}


	vector<vector<int>> lista(101, vector<int>(primos.size())) ;
	

	bool arr[MAX+1] = {0};

	arr[2] = 1;
	lista[2][0] = 1;

	while(cin>>numero and numero!=0){
		

		if(arr[numero] == 0){
			for(int i=3;i<=numero;i++){
				int temp_numero = i;
				int iterar = 0;
				
				if(arr[i]==0){
					while(temp_numero>1){
						if(temp_numero % primos[iterar] == 0){
							temp_numero/=primos[iterar];
							lista[i][iterar]++;
						}
						else{
							iterar++;
						}
					}

					for(int j=0;j<primos.size();j++){
						lista[i][j] = lista[i][j] + lista[i-1][j];
					}
					arr[i] = 1;
				}
				

			}
		}
		int cantidad_numeros = 0;
		bool impresion_extra = 0;
		std::cout<<setw(3)<<numero<<"! =";
		for(int j=0; j<primos.size() and lista[numero][j] != 0; j++){
			if(j==15){impresion_extra = 1; break;}			
			std::cout<<setw(3)<<lista[numero][j];
		}
		if(impresion_extra){
			std::cout<<"\n      ";
			for(int j=15; j<primos.size() and lista[numero][j] != 0;j++){
				std::cout<<setw(3)<<lista[numero][j];
			}
			
		}
		std::cout<<std::endl;


		

		

	}

	
	

	return 0;
}