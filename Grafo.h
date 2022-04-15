#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

#include <iostream>
#include <vector>
#include <queue>
#include <random>

using namespace std;

class Grafos
{
public:
    int vertice;
    vector<vector<unsigned>> adj;

    Grafos(int v)
    {
        vertice = v;
        adj.resize(v);
    }


    void ler_arquivo(FILE *arq)
    {
        int aux, i, j;
        for (i = 0; i < vertice; i++)
        {
            for (j = 0; j < vertice; j++)
            {
                fscanf(arq, "%d", &aux);
                if (aux == 1)
                {
                    adj[i].push_back(j);
                }
            }
        }
    }

    void print()
    {
        for (int i = 0; i < (int)adj.size(); i++)
        {
            for (int j = 0; j < (int)adj[i].size(); j++)
            {
                cout << "Vertice " << i + 1 << " - ";
                cout << adj[i][j] + 1 << " Adicionado" << endl;
            }
        }
    }
    void bfs(int v)
    {
        vector<int> distancia;
        distancia.assign(vertice, -1);
        distancia[v] = 0;

        queue<int> l;
        l.push(v);
        cout << "BFS: " << endl;
        while (!l.empty())
        {
            int aux = l.front();
            cout << "Camada " << distancia[aux] +1 << ": ";
            l.pop();
            cout << aux + 1 << endl;
            for (int i : adj[aux])
            {
                if (distancia[i] == -1)
                {
                    distancia[i] = distancia[aux] + 1;
                    l.push(i);
                }
            }
        }
        cout << endl;
    }

    void gera_aleatorio()
    {
        int aux;
        int contador = 0;
        for (int i = 0; i < vertice; i++)
        {
            for (int j = 0; j < contador; j++)
            {
                aux = rand() % 100 + 1;
                if (j != i)
                {
                    if (aux < 25)
                    {
                        this->adj[i].push_back(j);
                        this->adj[j].push_back(i);
                    }
                }
            }
            contador++;
        }
    }

    int bfs_aleatorio(int v)
    {
        int cont=0;
        vector<int> distancia;
        distancia.assign(vertice, -1);
        distancia[v] = 0;

        queue<int> l;
        l.push(v);
        while (!l.empty())
        {
            int aux = l.front();
            l.pop();
            for (int i : adj[aux])
            {
                if (distancia[i] == -1)
                {
                    distancia[i] = distancia[aux] + 1;
                    l.push(i);
                }
                cont++;
            }
        }
        return cont;
    }
};

#endif // GRAFO_H_INCLUDED
