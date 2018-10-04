#include "headers/libraries.h"

//int main()
//{
//    int *i;
//    int j[2] = {55, 60};
//    i = &j[0];
//
//    cout << "j[1] = " << *i << endl;
//    cout << "i = " << i << endl;
//
//    int *k = i+1;
//
//    cout << "j[2] = " << *i << endl;
//    cout << "i = " << i << endl;
//    cout << "K-i = " << k-i << endl;
//    cout << " k = " << k << endl;
//    cout << "k < i? " << bool(k > i) << endl;
//
//    int vec[] = {6,5,1, -37, 9, 6, 7, 1, 4, 3, 159, 354, 456, 123123, 3,2,4};
//
//    for(int i = 0; i < sizeof(vec)/sizeof(int); i++) {
//        cout << vec[i] << " ";
//    }; cout << endl;
//
//    ///
//    //quickSort(vec, &vec[sizeof(vec)/sizeof(int)-1]);
//    countingSort(vec, sizeof(vec)/sizeof(int));
//    ///
//
//    for(int i = 0; i < sizeof(vec)/sizeof(int); i++) {
//        cout << vec[i] << " ";
//    }; cout << endl;
//
//    /*
//    int v2[] = {6,5,7,2,4,3};
//    int *vPtr = new int[6];
//    for(int i = 0; i < 6; i++) {
//        cin >> *(vPtr+i);
//    }
//
//    cout << "*****************" << endl;
//    int *vecAux = new int(*vPtr);
//    for(int i = 0; i < 6; i++) {
//        cout << vPtr[i] << " ";
//    }
//    */
//
//    int s = 6;
//    int *arr = new int[s]();
//    printVec(arr, 6);
//
//
//
//
//
//
//    return 0;
//}


///********************************
/// PARTE 1: ANÁLISE DOS ALGORITMOS


int main() {

    fstream entrada, saida, deputados;

    entrada.open("entrada.txt", ios::in | ios::binary);

    if(!entrada.is_open()) {
        cout << "Sem entrada." << endl;
        return 0;
    }

    int N, nLines, i, j, k, lineCount, randLine, comp, trocas;
    int *conjuntoIds;
    string line, tableCell, filename;
    //char aspas;
    GastoDeputado *allDeputados, *conjuntoDeputados;
    clock_t startTime, endTime;
    double cpuTime;

    entrada >> N;

    int *NValues, *seedVec;
    NValues = new int[N];
    seedVec = new int[5];

    for(j = 0; j < N; j++) {
        entrada >> NValues[j];
    }

    entrada.close();

    //Ler deputados:

    deputados.open("deputies_dataset_tratado.csv", ios::in);

    if(!deputados.is_open()) {
        cout << "Sem dataset." << endl;
        return 0;
    }

    nLines = 0;

    while(getline(deputados, line)) { //conta o numero de linhas do arquivo
        nLines++;
    }; nLines--; // desconta o cabeçalho

    allDeputados = new GastoDeputado[nLines];

    deputados.clear();              // clearing e
    deputados.seekg(0, ios::beg);   // voltando ao inicio do arquivo

    getline(deputados, line);       // pulando o cabeçalho
    cout << line << endl;
    lineCount = 0;
    while(getline(deputados, tableCell, ';')) {
        allDeputados[lineCount].setBuggedDate(tableCell);
        cout << tableCell << ";";

        getline(deputados, tableCell, ';');
        allDeputados[lineCount].setReceiptDate(tableCell);
        cout << tableCell << ";";

        getline(deputados, tableCell, ';');
        allDeputados[lineCount].setDeputyId(stoi(tableCell));
        //cout << "stoi 1" << endl;
        cout << tableCell << ";";

        getline(deputados, tableCell, ';');
        allDeputados[lineCount].setPoliticalParty(tableCell);
        cout << tableCell << ";";

        getline(deputados, tableCell, ';');
        allDeputados[lineCount].setStateCode(tableCell);
        cout << tableCell << ";";

        getline(deputados, tableCell, ';');
        allDeputados[lineCount].setDeputyName(tableCell);
        cout << tableCell << ";";

        getline(deputados, tableCell, ';');
        allDeputados[lineCount].setReceiptSocialSecurityNumber(tableCell);
        cout << tableCell << ";";


        /*
        deputados.get(aspas);
        if(aspas == '"') {
            getline(deputados, tableCell, '"');
            allDeputados[lineCount].setReceiptDescription(string(1, aspas) + tableCell);
            cout << tableCell << ",";

            deputados.get(aspas);
            if(aspas != ';') {
                cout << "Erro de Leitura. Field: Receipt Description" << endl;
                return 0;
            }
        } else {
            getline(deputados, tableCell, ';');
            allDeputados[lineCount].setReceiptDescription(string(1, aspas) + tableCell);
            cout << tableCell << ",";
        }
        */

        getline(deputados, tableCell, ';');
        allDeputados[lineCount].setReceiptDescription(tableCell);
        cout << tableCell << ";";


        /*
        deputados.get(aspas);
        if(aspas == '"') {
            getline(deputados, tableCell, '"');
            allDeputados[lineCount].setEstablishmentName(string(1, aspas) + tableCell);

            deputados.get(aspas);
            while(aspas == '"') {
                getline(deputados, tableCell, '"');
                allDeputados[lineCount].setEstablishmentName(allDeputados[lineCount].getEstablishmentName() + tableCell);
                deputados.get(aspas);
            }

            cout << tableCell << ",";
            if(aspas != ';') {
                cout << "Erro de Leitura. Field: Establishment Name" << endl;
                return 0;
            }
        } else {
            getline(deputados, tableCell, ';');
            allDeputados[lineCount].setEstablishmentName(string(1, aspas) + tableCell);
            cout << tableCell << ",";
        }
        */

        getline(deputados, tableCell, ';');
        allDeputados[lineCount].setEstablishmentName(tableCell);
        cout << tableCell << ";";

        getline(deputados, tableCell, '\n');
        allDeputados[lineCount].setReceiptValue(stoi(tableCell));
        //cout << "stoi 2" << endl;
        cout << tableCell << endl;


        cout << "\n\n" << "lido: " << endl;
        cout << allDeputados[lineCount].getBuggedDate() << ";";
        cout << allDeputados[lineCount].getReceiptDate() << ";";
        cout << allDeputados[lineCount].getDeputyId() << ";";
        cout << allDeputados[lineCount].getPoliticalParty() << ";";
        cout << allDeputados[lineCount].getStateCode() << ";";
        cout << allDeputados[lineCount].getDeputyName() << ";";
        cout << allDeputados[lineCount].getReceiptSocialSecurityNumber() << ";";
        cout << allDeputados[lineCount].getReceiptDescription() << ";";
        cout << allDeputados[lineCount].getEstablishmentName() << ";";
        cout << allDeputados[lineCount].getReceiptValue() << endl;


        lineCount++;
        cout << "\n" << lineCount << "\n---------------" << "\n\n" << endl;
    }

    deputados.close();


    /*
    Pseudocode:

    aloca(seedVec[5]); ~

    srand(time(NULL));  **
    for(i = 0; i < 5; i++) {
        seedVec[i] <- randNum(-inf,+inf);
    }

    TIME tempoOrd;
    int comparacoes, trocas;

    // 1. Gerar 5 sementes (**)       --done
    // 2. Para cada semente, criar um arquivo de saida. srand(seedVec[k])    --done
    // 3. Nesse arquivo de saida, para cada valor de N (NValues[i], i = 1,...,N), gerar um conjunto com NValues[i] elementos
    //      a partir da tabela dos deputados. Isso será feito da seguinte maneira:
    //  3.1. Para j = 1:NValues[i], conjunto[j] = deputados[linha randNum(1, numero de linhas da tabela)]. conjunto é um conjunto da classe GastoDeputado, de tamanho NValues[i]
    //  3.2. fim para
    // 4. Ordena o conjunto, com cada algoritmo pedido, retornando o conjunto ordenado, o tempo gasto, o numero de comparacoes, e o numero de trocas.
    // 5. Contabiliza as estatisicas de desempenho
    // 6. Escreve no arquivo de saida: N = NValues[i], algoritmo 1: tempo, comparacoes, trocas; algoritmo 2: tempo, comparacoes, trocas; ...
    // 7. fim para cada valor de N
    // 8. fim para cada seed


    for(i = 0; i < N; i++) { //para cada valor de N lido da entrada, gerar 5 conjuntos aleatorios, cada um com uma semente diferente
        1.Gera cada um dos conjuntos de elementos
            - para um valor fixo de N (NValues[i]), gera 5 conjuntos com NValues[i] elementos cada


        2. ordena
        3. contabiliza estatísticas de desempenho
        4. Armazena estatísticas de desempenho em arquivo de saída (saida.txt)

    }
    */


    //srand(time(NULL));
    srand(1);
    for(i = 0; i < 5; i++) {
        seedVec[i] = randomInt(0, pow(2, 31));
    }

    for(i = 0; i < 5; i++) {
        filename = "saida_seed_" + std::to_string(seedVec[i]) + ".txt";
        saida.open(filename, ios::out | ios::binary); //arquivo de saída da seed

        saida << "/* N\n" << " * Ordenado Deputados(0/1)\n" << " * Tempo Deputados\n" << " * Comparações Deputados\n" << " * Trocas Deputados\n";
        saida << " * Ordenado Inteiros(0/1)\n" << " * Tempo Inteiros\n" << " * Comparações Inteiros\n" << " * Trocas Inteiros\n" << "*/\n";

        srand(seedVec[i]); //i-ésima seed, para o i-ésimo conjunto, i = 1,...,5
        for(j = 0; j < N; j++) { // para cada valor de N

            saida << NValues[j] << endl;

            conjuntoDeputados = new GastoDeputado[NValues[j]];
            conjuntoIds = new int[NValues[j]];

            for(k = 0; k < NValues[j]; k++) { // para 1:Valor atual de N, adicionar um deputado aleatorio ao conjunto
                randLine = randomInt(0, nLines); // gera numero aleatorio randLin
                conjuntoDeputados[k] = allDeputados[randLine]; // armazena a randLine linha no vetor de deputados
                conjuntoIds[k] = allDeputados[randLine].getDeputyId(); // armazena o deputyId linha no vetor de inteiros
            }

            for(k = 0; k < NValues[j]; k++) {
                cout << conjuntoDeputados[k].getDeputyId() << "   conjuntoDeputados pre" << endl;
            }

            for(k = 0; k < NValues[j]; k++) {
                cout << conjuntoIds[k] << "   conjuntoIds pre" << endl;
            }

            // ordena o conjunto

            comp = 0; trocas = 0; //numero de comparacoes entre chaves, e de trocas de chaves

            startTime = clock();

            quickSortDeputyId(&(conjuntoDeputados[0]), &(conjuntoDeputados[NValues[j]-1]));

            endTime = clock();
            cpuTime = (double)(endTime - startTime)/(CLOCKS_PER_SEC);

            //cout << "\n\n cpuTimeDeputados = " << cpuTime << "\n\n" << endl;
            saida << ordenado(&(conjuntoDeputados[0]), NValues[j]) << endl;
            saida << cpuTime << endl;
            saida << comp << endl;
            saida << trocas << endl;

            comp = 0; trocas = 0;

            startTime = clock();

            quickSort(&(conjuntoIds[0]), &(conjuntoIds[NValues[j]-1]));

            endTime = clock();
            cpuTime = (double)(endTime - startTime)/(CLOCKS_PER_SEC);

            //cout << "\n\n cpuTimeInteiros = " << cpuTime << "\n\n" << endl;
            saida << ordenado(&(conjuntoIds[0]), NValues[j]) << endl;
            saida << cpuTime << endl;
            saida << comp << endl;
            saida << trocas << endl;


            /*
            for(k = 0; k < NValues[j]; k++) {
                cout << conjuntoDeputados[k].getDeputyId() << "   conjunto ord" << endl;
            }

            for(k = 0; k < NValues[j]; k++) {
                cout << conjuntoIds[k] << "   conjuntoIds ord" << endl;
            }*/

            //checa se esta ordenado
            /*
            if(!ordenado(&(conjuntoDeputados[0]), NValues[j]))
                cout << "ConjuntoDeputados nao foi ordenado corretamente." << endl;
            else cout << "ConjuntoDeputados Ordenado." << endl;

            if(!ordenado(&(conjuntoIds[0]), NValues[j]))
                cout << "ConjuntoIds nao foi ordenado corretamente." << endl;
            else cout << "ConjuntoIds Ordenado." << endl;
            */

            // Valor de N atual (NValues[j]), numero de comparacoes, numero de copias e tempo de execucao
            // coloca em saida.txt
            delete conjuntoIds;
        }


        saida.close();
    }

    delete NValues;
    delete seedVec;

    return 0;
}





