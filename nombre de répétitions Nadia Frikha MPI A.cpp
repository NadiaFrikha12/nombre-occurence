//Ecriture d'un programme en C qui permet de lire une chaine de caractères et afficher le nombre de mots qui se répètent.

#include<stdio.h>
#include<string.h>
int main(){
	char c[100]; //chaine de caractere 
	int k=0;
	int j=0;
	char t[100][50];//tableau de caractere
	int occ[50];

	printf("saisir une chaine:");
	gets(c); //lecture de la chaine 
	
	//split: separer les mots chacune dans une ligne de t
	for(int i = 0; i <= strlen(c); i++){
        if (c[i] == ' ' || c[i] == '\0'){
            t[k][j] = '\0';
            k++;
            j = 0;
        }  
        else{
            t[k][j] = c[i]; //ajouter un caractere à une case du tableau 
            j++;
        }      
    }
	
	//chercher le nombre de repetition
	
	for (int m=0; m<k; m++){
		int nb=0;
		for (int h=0; h<k; h++){
			if(strcmp(t[m],t[h])==0)
				nb++;		
		}
	occ[m]=nb;	
	}
	
	//enlever les cases repetee
	for(int p = 0 ; p < k-1 ; p++){
        for(int r = p+1 ; j < k ; r++){
            while(strcmp(t[r], t[p]) == 0){
                for(int g = r ; g < k ; g++){
                    strcpy(t[g],t[g+1]);
                    occ[g] = occ[g+1];
                }
            k--;
            }
        }
    }
    
    //affichage 
    for (int l = 0; l < k; l++)
    {
        if (occ[l] > 1)
        printf("%s %d\n", t[l], occ[l]);
    }
}
