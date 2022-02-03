#include "sculptor.h"
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

int main(){
    Sculptor lightsaber(120,120,120);
    lightsaber.cutBox(0,119,0,119,0,119); // << Limpando a matriz
		// vv Eixo x (vermelho)
		lightsaber.setColor(0.8888,0.0001,0.0001,1);
		lightsaber.putBox(0,110,0,0,0,0);
		// vv Eixo y (verde)
		lightsaber.setColor(0.0001,0.8888,0.0001,1);
		lightsaber.putBox(0,0,0,110,0,0);
		// vv Eixo z (azul)
		lightsaber.setColor(0.0001,0.0001,0.8888,1);
		lightsaber.putBox(0,0,0,0,0,110);
		// vv Lamina do sabre (azul transparente)
		lightsaber.setColor(0.0001,0.3,0.8,0.3);
    lightsaber.putEllipsoid(15,50,15,3,40,3);
		lightsaber.putEllipsoid(15,75,15,3,40,3);
		lightsaber.putEllipsoid(15,30,15,3,29,3);
		lightsaber.putBox(13,17,15,20,13,17);
		lightsaber.cutBox(11,19,88,115,11,19);
		// vv Ponta do sabre
		lightsaber.putSphere(15,88,15,3);
		lightsaber.putBox(15,15,90,90,13,17);
		lightsaber.putBox(13,17,90,90,15,15);
		lightsaber.putBox(14,16,90,90,14,16);
		lightsaber.putBox(14,16,91,91,14,16);
		lightsaber.putBox(15,15,92,92,14,16);
		lightsaber.putBox(14,16,92,92,15,15);
		lightsaber.putVoxel(15,93,15);
		// vv Apararar rebarbas da elipse e da esfera que fazem a lâmina
		lightsaber.cutBox(12,12,0,90,13,17);
		lightsaber.cutBox(18,18,0,90,13,17);
		lightsaber.cutBox(13,17,0,90,12,12);
		lightsaber.cutBox(13,17,0,90,18,18);
		lightsaber.cutBox(13,13,17,90,13,13);
		lightsaber.cutBox (17,17,17,90,13,13);
		lightsaber.cutBox(13,13,17,90,17,17);
		lightsaber.cutBox(17,17,17,90,17,17);
		// vv Nucleo brilhante do sabre (branco)
		lightsaber.setColor(0.9999,0.9999,0.9999,1);
		lightsaber.putBox(14,16,0,88,14,16);
		lightsaber.putBox(15,15,89,89,14,16);
		lightsaber.putBox(14,16,89,89,15,15);
		lightsaber.putVoxel(15,90,15);
		// vv Cabo do sabre
		// vv Detalhes pretos
		lightsaber.setColor(0,0,0,1);
		lightsaber.putBox(13,17,0,6,13,17);
		lightsaber.putBox(12,18,0,6,15,15);
		lightsaber.putBox(15,15,0,6,12,18);
		// vv Parte metalica (cinza)
		lightsaber.setColor(0.5,0.5,0.5,1);
    lightsaber.putBox(13,17,0,6,14,16);
		lightsaber.putBox(14,16,0,6,13,17);
		lightsaber.putBox(13,17,7,18,13,17);
    lightsaber.putVoxel(14,19,13);
    lightsaber.putVoxel(14,19,17);
		lightsaber.putBox(13,13,19,21,13,17);
    lightsaber.putBox(13,13,22,22,14,16);
    lightsaber.putBox(12,12,19,20,15,15);
    lightsaber.putBox(12,12,17,17,15,15);
		// vv Botao vermelho
		lightsaber.setColor(0.8888,0.0001,0.0001,1);
		lightsaber.putVoxel(18,13,15);
		// vv Detalhe ocre
		lightsaber.setColor(0.6,0.5,0.1,1);
		lightsaber.putBox(15,15,8,10,18,18);
    lightsaber.writeOFF((char*)"lightsaber.off");
    cout << ">>>  Documento .off gerado.\n";
}