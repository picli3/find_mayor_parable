#include <stdio.h>
#include <math.h>
#include <float.h>

typedef struct data{
	int f;
	float mag;
	
}resp;

resp r1[]={{10, 9.92},
{12, 11.67},
{14, 14.04},
{16, 12.99},
{18, 13.91},
{20, 15.89},
{22, 17.60},
{24, 19.64},
{26, 22.02},
{28, 27.93},
{30, 26.76},
{32, 29.73},
{34, 32.47},
{36, 36.17},
{38, 39.89},
{40, 40.33},
{42, 42.50},
{44, 43.86},
{46, 44.22},
{48, 45.57},
{50, 44.35},
{52, 43.20},
{54, 42.32},
{56, 39.91},
{58, 38.07},
{60, 36.09},
{62, 33.77},
{64, 32.52},
{66, 30.43},
{68, 29.21},
{70, 27.38},
{72, 26.67},
{74, 24.93},
{76, 23.91},
{78, 23.32},
{80, 22.68},
{82, 22.00},
{84, 20.86},
{86, 20.65},
{88, 19.79},
{90, 19.00},
{92, 18.54},
{94, 18.23},
{96, 17.26},
{98, 16.65},
{100, 16.52},
{102, 16.13},
{104, 15.36},
{106, 15.06},
{108, 14.98},
{110, 14.64},
{112, 14.22},
{114, 14.18},
{116, 13.99},
{118, 13.68},
{120, 13.34},
{122, 13.27},
{124, 12.95},
{126, 12.62},
{128, 12.54},
{130, 12.49},
{132, 12.54},
{134, 12.15},
{136, 12.15},
{138, 12.04},
{140, 11.85},
{142, 11.69},
{144, 11.85},
{146, 11.44},
{148, 11.29},
{150, 11.33},
{152, 11.33},
{154, 10.94},
{156, 10.88},
{158, 10.78},
{160, 10.98},
{162, 10.88},
{164, 10.59},
{166, 10.59},
{168, 10.74},
{170, 10.59},
};


resp r[]={{10, 6.84},
{12, 7.99},
{14, 9.02},
{16, 9.97},
{18, 10.79},
{20, 11.51},
{22, 12.11},
{24, 12.52},
{26, 13.21},
{28, 13.65},
{30, 14.12},
{32, 14.53},
{34, 14.90},
{36, 15.30},
{38, 15.71},
{40, 16.15},
{42, 16.60},
{44, 17.07},
{46, 17.62},
{48, 18.23},
{50, 18.95},
{52, 19.79},
{54, 20.84},
{56, 22.16},
{58, 23.85},
{60, 26.00},
{62, 28.74},
{64, 32.30},
{66, 36.68},
{68, 41.33},
{70, 45.26},
{72, 47.06},
{74, 45.95},
{76, 43.06},
{78, 39.72},
{80, 36.06},
{82, 32.91},
{84, 30.51},
{86, 28.17},
{88, 26.10},
{90, 24.88},
{92, 23.68},
{94, 22.69},
{96, 22.10},
{98, 21.52},
{100, 21.05},
{102, 20.86},
{104, 20.55},
{106, 20.36},
{108, 20.36},
{110, 20.13},
{112, 19.60},
{114, 19.22},
{116, 19.09},
{118, 18.91},
{120, 18.56},
{122, 18.52},
{124, 18.28},
{126, 17.91},
{128, 17.81},
{130, 17.81},
{132, 17.54},
{134, 17.72},
{136, 17.54},
{138, 17.35},
{140, 17.46},
{142, 17.41},
{144, 17.43},
{146, 17.23},
{148, 17.17},
{150, 17.17},
{152, 17.17},
{154, 17.17},
{156, 17.17},
{158, 17.07},
{160, 17.07},
{162, 17.02},
{164, 17.02},
{166, 17.07},
{168, 16.95},
{170, 17.00},
{172, 16.89},
{174, 16.93},
{176, 16.89},
{178, 16.96},
{180, 16.95},};

resp a[10];
resp b[10];


float encontrarValorCercano(float numero, resp array[], int longitud) {
    float valorCercano = FLT_MAX;
    float diferenciaMinima = FLT_MAX;

    for (int i = 0; i < longitud; i++) {
        float diferencia = fabs(numero - array[i].mag);
        if (diferencia < diferenciaMinima) {
            diferenciaMinima = diferencia;
            valorCercano = array[i].f;
        }
    }
    return valorCercano;
}

int main(int argc, char const *argv[]){

	float target=18.28;
	float tol=2;
	int fs=72;
	int k=0;
	int z=0;
	int out[2];

	for (int i = 0; i < 81; ++i){
		if (fabs(r[i].mag-target)<tol){
			if (fs>r[i].f){
				a[k].f=r[i].f;
				a[k].mag=r[i].mag;
				k++;
			}else{
				b[z].f=r[i].f;
				b[z].mag=r[i].mag;
				z++;
			}
		}	
	}

	out[0]=encontrarValorCercano(target,a,k); 
	out[1]=encontrarValorCercano(target,b,z); 

	printf("Salida:\n");
	printf("%d,%d\n",out[0],out[1]);
	printf("Validacion\n");
	float val=sqrt(((float)out[0]*(float)out[1]));
	printf("%f\n",val-fs);
	return 0;
}