#include <iostream>
#include <cstring>

void bubbleSort(std::string arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j].c_str(), arr[j + 1].c_str()) > 0) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void selectionSort(std::string arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[j].c_str(), arr[min_index].c_str()) < 0) {
                min_index = j;
            }
        }
        if (min_index != i) {
            std::swap(arr[i], arr[min_index]);
        }
    }
}

void insertionSort(std::string arr[], int n) {
    for (int i = 1; i < n; i++) {
        std::string key = arr[i];
        int j = i - 1;
        while (j >= 0 && strcmp(arr[j].c_str(), key.c_str()) > 0) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(std::string arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::string L[n1];
    std::string R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (strcmp(L[i].c_str(), R[j].c_str()) <= 0) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(std::string arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    FILE *arquivo;
    char linha[100][100];
    int numNomes = 0;
    int opcao;

    arquivo = fopen("nomes2.txt", "r");

    if (arquivo == NULL) {
        std::cerr << "Erro ao abrir o arquivo." << std::endl;
        return 1;
    }

    while (numNomes < 100 && fgets(linha[numNomes], sizeof(linha[0]), arquivo)) {
        linha[numNomes][strcspn(linha[numNomes], "\n")] = '\0';
        numNomes++;
    }

    fclose(arquivo);

    std::string nomes[numNomes];

    for (int i = 0; i < numNomes; i++) {
        nomes[i] = linha[i];
    }

    printf("Selecione a opção de ordenacao:\n");
    printf("1. BubbleSort\n2. SelectionSort\n3. InsertionSort\n4. MergeSort\n5. Sair\n");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            printf("Bubble Sort: \n");
            bubbleSort(nomes, numNomes);
            std::cout << "Nomes ordenados:" << std::endl;
                for (int i = 0; i < numNomes; i++) {
                    std::cout << nomes[i] << std::endl;
                }
            break;
        case 2:
            printf("Selection Sort: \n");
            selectionSort(nomes, numNomes);
            std::cout << "Nomes ordenados:" << std::endl;
                for (int i = 0; i < numNomes; i++) {
                    std::cout << nomes[i] << std::endl;
                }
            break;
        case 3:
            printf("Insertion Sort: \n");
            insertionSort(nomes, numNomes);
            std::cout << "Nomes ordenados:" << std::endl;
                for (int i = 0; i < numNomes; i++) {
                    std::cout << nomes[i] << std::endl;
                }
            break;
        case 4:
            printf("Merge Sort: \n");
            mergeSort(nomes, 0, numNomes - 1);
            std::cout << "Nomes ordenados:" << std::endl;
                for (int i = 0; i < numNomes; i++) {
                    std::cout << nomes[i] << std::endl;
                }
            break;
        case 5:
            printf("Voce escolheu sair \n");
            break;
        default:
            printf("Opção inválida. Por favor, escolha um número de 1 a 5.\n");
    }

    return 0;
}
