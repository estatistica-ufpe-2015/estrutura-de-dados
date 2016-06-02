
int busca_bin(int n, int* vet, int elem){
    /* No início consideramos todo o vetor */

    int ini = 0;
    int fim = n-1;
    int meio;

    /* Enquanto a oarte restante for maor que zero */
    while (ini <= fim) {
        meio = (ini + fim)/2;
        if(elem < vet[meio]){
            fim = meio - 1;
        } else if(elem > vet[meio]){
            ini = meio + 1;
        } else {
            return meio;
        }
    }

    return -1;
}
