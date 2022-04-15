#include "Grafo.h"

int main()
{
    FILE *arq;
    arq = fopen("dados2.txt", "r");
    if (arq == NULL)
    {
        printf("Problemas na CRIACAO do arquivo\n");
        return 1;
    }

    int V;
    cout << "Qtd de vertices: ";
    fscanf(arq, "%d", &V);
    cout << V << endl;

    Grafos G(V);
    G.ler_arquivo(arq);
    G.print();
    G.bfs(0);


    int acessos[100];
    for(int i =1; i<101; i++)
    {
        cout<<"Grafo numero "<<i<<" gerado"<<endl;
        Grafos teste(i);
        teste.gera_aleatorio();
        acessos[i-1]=teste.bfs_aleatorio(0);
    }
    for(int i =0; i<100; i++)
    {
        cout<<acessos[i]<<" ,";
    }
    return 0;
}
