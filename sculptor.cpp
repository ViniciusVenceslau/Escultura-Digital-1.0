#include "sculptor.h" // Header que permite a utilizacao da classe sculptor e o struct de tipo Voxel.
#include <iostream> // Biblioteca padrao do C++, promove a entrada e saida de dados no programa.
#include <fstream> // Torna possivel a entrada e saida de dados para um disco rigido, alem de ter a finalidade de escrever ou ler arquivos.
#include <string> // Biblioteca que concede a manipulação de strings/agrupamento de caracteres.
#include <math.h> // Biblioteca matematica, a qual a abrange determinadas operacoes como: potenciacao, para facilitar o desenvolvimento do codigo.

/* @info Principais fontes para elaboracao do metodo abaixo:
  https://www.techiedelight.com/dynamic-memory-allocation-in-c-for-2d-3d-array/
  https://www.youtube.com/watch?v=mGl9LO-je3o&ab_channel=CodeBeauty
 */

Sculptor::Sculptor(int _nx, int _ny, int _nz){ // Neste ponto, ocorre a chamada do membro da classe Sculptor, o qual, conscidentemente, se chama "Sculptor".
    nx = _nx; 
    ny = _ny;
    nz = _nz;
// as variaveis "nx, ny e nz" recebem seus respectivos valores provenientes do argumento do metodo acima.

// Agora no codigo, eh feita a alocação dinamica de memoria utilizando-se a sintaxe do C++. Nesse sentido, como o projeto eh feito em tres dimensoes (3D), ocorre o uso do ponteiro "v" triplo que aponta para o endereco de memoria de outro ponteiro duplo que, por sua vez, aponta para um ponteiro simples, que indica os enderecos de memoria de seu respectivo array.
// Tal alocacao lida com diversos lacos de repeticoes para o seu adequado funcionamento.
    v = new Voxel **[nx]; 
    for(int sxloop = 0; sxloop < nx; sxloop++){
        v[sxloop] = new Voxel *[ny];
    }
    for(int sxloop = 0; sxloop < nx; sxloop++){
        for(int syloop = 0; syloop < ny; syloop++){
            v[sxloop][syloop] = new Voxel [nz];
        }
    }

    for(int sxloop = 0; sxloop < nx; sxloop++){
        for(int syloop = 0; syloop < ny; syloop++){
            for(int szloop = 0; szloop < nz; szloop++){
               v[sxloop][syloop][szloop].isOn = false;
               v[sxloop][syloop][szloop].r = r;
               v[sxloop][syloop][szloop].g = g;
               v[sxloop][syloop][szloop].b = b;
               v[sxloop][syloop][szloop].a = a;
               /*Este trecho do codigo inicializa todos os voxels especificados ao permitir a associacao entre os elementos da matriz tridimensional e as cores RGB (Vermelho, verde e azul), alem de vincular-se a transparencia, representada pela variavel "a".*/
            }
        }
    }
}

// Chamada do Destrutor, o qual produz a liberação da memoria usada anteriormente na alocação.
// Vale ressaltar que a liberacao dos espaços de memoria manuseados ocorre de dentro para fora, ou seja, do conteudo presente no ponteiro simples ateh o que estah presente no ponteiro triplo.
Sculptor::~Sculptor(){
    int ax, ay;
    ax = nx;
    ay = ny;
    for(int axloop = 0; axloop < ax; axloop++){
        for(int ayloop = 0; ayloop < ay; ayloop++){
            delete[] v[axloop][ayloop];
        }
    }
    for(int axloop = 0; axloop < ax; axloop++){
        delete [] v[axloop];
    }
    delete [] v;
    v = NULL;
}

/*Chamada de mais um membro da classe: Sculptor, desta vez, o metodo setColor, o qual 
define a cor da figura. Nesse contexto, o parametro "r" recebe float atrelado ao valor de "r"ed (Vermelho); O parametro "g" recebe float correspondente ao valor de "g" reen (Verde); Jah, o parametro "b" recebe float relativo ao valor de "b"lue (Azul); Por fim, o parametro alpha recebe float relacionado ao valor de "a" (tranparencia da peca).*/
void Sculptor::setColor(float r, float g, float b, float alpha){
    this -> r = r;
    this -> g = g;
    this -> b = b;
    a = alpha;
}

// Convocacao do método putVoxel que introduz um voxel, utilizando-se como parametros, as coordenadas "x,y,z" de um plano. 
void Sculptor::putVoxel(int x, int y, int z){
    v[x][y][z].isOn = true; /*Quando o membro da classe "isOn" esta ativo, ou seja, com valor igual a "true" um voxel eh inicializado. A posicao deste voxel varia de acordo com suas coordenadas, assim como sua coloracao se diferencia pelos valores r, g, b e a.*/
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
}

/*Em contrapartida, ao utlizar o metodo cutVoxel, o voxel de uma determinada regiao eh excluido, uma vez que o membro "isOn" da classe: Voxel, possui valor igual a "false".*/
void  Sculptor::cutVoxel (int x, int y, int z){
    v[x][y][z].isOn = false;
}

// Por meio de um aglomerado/juncao de voxel, o metodo putBox constrói um cubo ou caixa com coloracao e dimensoes variáveis.
// Assim, eh preciso informar a posicao inicial e final de cada voxel em cada uma das coordenadas do plano para a confeccao da caixa.
void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for(int i = x0; i <= x1; i++){
        for(int j = y0; j <= y1; j++){
            for(int k = z0; k <= z1; k++){
               putVoxel(i, j, k);
            }
        }
    }
}

// Por outro lado, o metodo cutBox, remove um cubo de voxels atraves de suas dimensoes.
void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for(int i = x0; i <= x1; i++){
        for(int j = y0; j <= y1; j++){
            for(int k = z0; k <= z1; k++){
                cutVoxel(i, j, k);
            }
        }
    }
}

// Cria-se uma esfera de voxels dentro da matriz tridimensional, usando como criterio a equaçao da esfera.
// Logo, sao necessarias as coordenadas do centro desta esfera nas tres regioes do plano, e tambem, o valor de seu raio.
void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
    for (int i = 0 ; i < (2*xcenter); i ++){
        for (int j = 0 ; j < (2*ycenter); j ++){
            for (int k = 0 ; k < (2*zcenter); k ++){
                if (((i - xcenter)*(i - xcenter) + (j - ycenter)*(j-ycenter) + (k-zcenter)*(k-zcenter)) <= (radius*radius)){
                   putVoxel(i, j, k);/*A condicao determinada acima eh fundamental, pois corresponde a equacao matematica de uma esfera.*/
                }
            }
        }
    }
}

// O metodo cutSphere exclui voxels em formato de esfera dentro da matriz tridimensional.
void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
    for (int i = 0 ; i <(2*xcenter); i ++){
        for (int j = 0 ; j < (2*ycenter); j ++){
            for (int k = 0 ; k < (2*zcenter); k ++){
                if (((i - xcenter) * (i - xcenter) + (j - ycenter) * (j - ycenter) + (k - zcenter) * (k - zcenter)) <= (radius*radius)){
                   cutVoxel(i,j,k);
                }
            }
        }
    }
}

// O metodo putEllipsoid fruto da classe Sculptor, cria uma elipse de voxels dentro da matriz tridimensional, usando como criterio a equacao da elipse.
// Portando, os parametros desta funcao exige os valores do centro da elipse nas tres coordenadas e seus respectivos raios.
void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    for(int i = xcenter - rx; i < xcenter + rx; i++){
        for(int j = ycenter - ry; j < ycenter + ry; j++){
            for(int k = zcenter - rz; k < zcenter + rz; k++){
                if ((pow(i - xcenter, 2)/pow(rx, 2)) + (pow(j - ycenter, 2)/pow(ry, 2)) + (pow(k - zcenter, 2)/pow(rz, 2)) <= 1){
                   putVoxel(i, j, k);/*A condicao preestabelecida acima eh essencial, pois corresponde a equacao matematica de uma elipse.*/
                }
            }
        }
    }
}

// Outrossim, o metodo cutEllipsoid desabilita voxels em formato de elipse dentro da matriz tridimensional.
void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    for(int i = xcenter - rx; i < xcenter + rx; i++){
        for(int j = ycenter - ry; j < ycenter + ry; j++){
            for(int k = zcenter - rz; k < zcenter + rz; k++){
                if ((pow(i - xcenter, 2)/pow(rx, 2)) + (pow(j - ycenter, 2)/pow(ry, 2)) + (pow(k - zcenter, 2)/pow(rz, 2)) <= 1){
                   cutVoxel(i, j, k);
                }
            }
        }
    }
}

// Metodo "WriteOFF", responsavel pela escrita do arquivo .off de acordo com o formato proprio desse tipo de arquivo.
// Para o desenvolvimento com maior exatidao, utilizamos como fonte de pesquisa o seguinte site: https://www.inf.ufpr.br/ci208/NotasAula/notas-30_Arquivos.html

void Sculptor::writeOFF(char* filename){
    int i = 0, j = 0, k = 0; // Declaracao das variaveis auxiliares, as quais foram operadas no lacos de repeticoes.
    putVoxel(i, j, k); // Metodo para inserir voxels (cubos) em um programa, como teste. 
    ofstream arq; // Um arquivo quando aberto precisa estar associado a um tipo de stream como: ofstream, ifstream ou fstream. Pois, esses tipos de variaveis permitem relacionar um arquivo em disco que tem nome determinado com as operacoes de leitura e gravacao. O ofstream permite a saida de dados para o arquivo.
  
    int total = 0; // Criacao da variavel do tipo inteiro "total" para associa-la ao numero de voxels ativos no programa.
    for(int i = 0; i < nz; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nx; k++){
                if(v[i][j][k].isOn == true){
                    total++;
                }
            }
        }
    }
// Para obtermos os vertices totais e faces totais no codigo, basta analisar o numero de voxels ativos, representado pela variavel "total" e, respectivamente, multiplica-la por 8 e 6.
    int vertices = 8*total;
		int faces = 6*total;
    arq.open(filename); /*Para abrir um arquivo, deve ser usada a funcao open() ao final da variavel atrelada a um dos tipos de stream mencionados anteriomente. Diante disso, vale salientar que toda abertura de um documento necessita de um fechamento, o qual é feito ao final de seu uso.*/
// Nesse instante da codificacao, cada linha a seguir eh gravada no documento que foi ligado a variavel "arq".
    arq << "OFF" << endl;
    arq << vertices << " " << faces << " 0" << endl;
// O programa nao manipula o numero de arestas criados/manuseados.
    for(int i = 0; i < nz; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nx; k++){
                if(v[i][j][k].isOn == true){ 
// Tendo em vista que os tamanhos dos lados do cubo sao iguais a 1, utiliza-se os padroes de somar ou diminuir 0.5 em cada uma das coordenadas para que as os vertices do cubo que envolve o voxel sejam criados nos pontos corretos.
                    arq << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << endl;
                    arq << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << endl;
                    arq << i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << endl;
                    arq << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << endl;
                    arq << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << endl;
                    arq << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << endl;
                    arq << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << endl;
                    arq << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << endl;
                }
            }
        }
    }

    int indiceVoxel = 0;

    for(int i = 0; i < nz; i++){
        for(int j = 0; j < nx; j++){
            for(int k = 0; k < ny; k++){
                if(v[i][j][k].isOn == true){
// Neste instante do codigo, os vertices criados sao percorridos para que aja a criacao correta das faces dos voxels funcionais do programa. Ademais, os valores das componentes RGB e as transparencias das pecas sao escritos neste arquivo aberto.
                    int verticeInicial = indiceVoxel*8;
                    arq << "4 " << verticeInicial << " " << verticeInicial + 3 << " " << verticeInicial + 2 << " " << verticeInicial + 1;
                    arq << " " << v[i][j][k].r << " " << v[i][j][k].g << " "<<v[i][j][k].b << " " <<v[i][j][k].a<<endl;
                    arq << "4 " << verticeInicial + 4 << " " << verticeInicial + 5 << " " << verticeInicial + 6 << " " << verticeInicial + 7;
                    arq << " " << v[i][j][k].r << " " << v[i][j][k].g << " " <<v[i][j][k].b<<" " <<v[i][j][k].a<<endl;
                    arq << "4 " << verticeInicial << " " << verticeInicial+1 << " " << verticeInicial+5 << " " << verticeInicial+4;
                    arq << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    arq << "4 " << verticeInicial << " " << verticeInicial + 4 << " " << verticeInicial + 7 <<  " " << verticeInicial + 3;
                    arq << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    arq << "4 " << verticeInicial + 3 << " " << verticeInicial + 7 << " " << verticeInicial + 6 << " " << verticeInicial + 2;
                    arq << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    arq<< "4 " << verticeInicial + 1 << " " << verticeInicial + 2 << " " << verticeInicial + 6 << " " << verticeInicial + 5;
                    arq << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    indiceVoxel++;
                }
              }
            }
        }
    arq.close(); // Encerramento do arquivo com dados e informacoes transcritas nele, além de sua criacao com compliador.
}