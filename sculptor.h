#ifndef sculptor_h
#define sculptor_h
#include <iostream>

using namespace std;
/*
 @info O struc para Voxel - Miníma unidade de construção da figura.
 Armazena os valores de: 
  - Cores (RGB);
  - Alpha (transparencia);
  - Se esta ativo ou nao.
 */
struct Voxel {
    float r, g, b, a;
    bool isOn;
};

// @info A classe construtora (Sculptor)
class Sculptor {
protected:
  Voxel ***v;
  int nx, ny, nz;
  float r, g, b, a;
  
public:
	// @info O metodo construtor (Sculptor)
  Sculptor(int _nx, int _ny, int _nz);
	// @info O metodo destrutor (~Sculptor)
  ~Sculptor();
  /*
   @info setColor Define a cor da figura
   @parameter r Recebe float - o valor de 'r'ed (Vermelho)
   @parameter g Recebe float - o valor de 'g'reen (Verde)
   @parameter b Recebe float - o valor de 'b'lue (Azul)
   @parameter alpha Recebe float - o valor de alpha (tranparencia da peca)
   */
  void setColor(float r, float g, float b, float alpha);
  /*
   @info putVoxel Inicializa voxel
   @parameter x Atribui o valor para a coordenada x
   @parameter y Atribui o valor para a coordenada y
   @parameter z Atribui o valor para a coordenada z
   */
  void putVoxel(int x, int y, int z);
  /*
   @info cutVoxel Desabilida o voxel
   @parameter x Atribui o valor para a coordenada x
   @parameter y Atribui o valor para a coordenada y
   @parameter z Atribui o valor para a coordenada z
   */
  void cutVoxel(int x, int y, int z);
  /*
   @info putBox Habilita um cubo de voxels com a cor atual de desenho e de dimensoes:
     x = (x0 - x1)
     y = (y0 - y1)
     z = (z0 - z1)
   @parameter x0 valor inicial de x na formula
   @parameter x1 valor final de x na formula
   @parameter y0 valor inicial de y na formula
   @parameter y1 valor final de y na formula
   @parameter z0 valor inicial de z na formula
   @parameter z1 valor final de z na formula
   */
  void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
  /*
   @info putBox Desabilita um cubo de voxels com a cor atual de desenho e de dimensoes:
     x = (x0 - x1)
     y = (y0 - y1)
     z = (z0 - z1)
   @parameter x0 valor inicial de x na formula
   @parameter x1 valor final de x na formula
   @parameter y0 valor inicial de y na formula
   @parameter y1 valor final de y na formula
   @parameter z0 valor inicial de z na formula
   @parameter z1 valor final de z na formula
   */
  void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
  /*
   @info putSphere Cria uma esfera dentro da matriz tridimensional. Site que serviu de fonte para a fórmula utilizada:
   https://docs.ufpr.br/~jcvb/online/UERJ%20-%20calculo%20volume%203.pdf
   @parameter xcenter Coordenada do centro da esfera em x
   @parameter ycenter Coordenada do centro da esfera em y
   @parameter zcenter Coordenada do centro da esfera em z
   @parameter radius Raio da esfera
   */
  void putSphere(int xcenter, int ycenter, int zcenter, int radius);
  /*
   @info cutSphere Desabilita voxels em formato de esfera dentro da matriz tridimensional. Site que serviu de fonte para a fórmula utilizada:
   https://docs.ufpr.br/~jcvb/online/UERJ%20-%20calculo%20volume%203.pdf
   @parameter xcenter Coordenada do centro da esfera em x
   @parameter ycenter Coordenada do centro da esfera em y
   @parameter zcenter Coordenada do centro da esfera em z
   @parameter radius Raio da esfera
   */
  void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
  /*
   @info putEllipsoid Cria uma elipse dentro da matriz tridimensional. Site que serviu de fonte para a fórmula utilizada:
   https://docs.ufpr.br/~jcvb/online/UERJ%20-%20calculo%20volume%203.pdf
   @parameter xcenter Coordenada do centro da elipse em x
   @parameter ycenter Coordenada do centro da elipse em y
   @parameter zcenter Coordenada do centro da elipse em z
   @parameter rx Raio em x
   @parameter ry Raio em y
   @parameter rz Raio em z
   */
  void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  /*
   @info cutEllipsoid Desabilita voxels em formato de elipse dentro da matriz tridimensional. Site que serviu de fonte para a fórmula utilizada:
   https://docs.ufpr.br/~jcvb/online/UERJ%20-%20calculo%20volume%203.pdf
   @parameter xcenter Coordenada do centro da elipse em x
   @parameter ycenter Coordenada do centro da elipse em y
   @parameter zcenter Coordenada do centro da elipse em z
   @parameter rx Raio em x
   @parameter ry Raio em y
   @parameter rz Raio em z
   */
  void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  /*
   @info writeOFF Metodo que cria o arquivo .off
   @parameter filename Nome do arquivo criado
   */
  void writeOFF(char* filename);
};

#endif // SCULPTOR_H