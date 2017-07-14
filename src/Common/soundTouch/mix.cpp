//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//
//#define SIZE_AUDIO_FRAME (2)
//
//void Mix(char sourseFile[10][SIZE_AUDIO_FRAME], int number, char *objectFile){
//    int const MAX = 32767;
//    int const MIN = -32768;
//    double f = 1;
//    int output;
//    int i = 0, j = 0;
//    for (i = 0; i<SIZE_AUDIO_FRAME / 2; i++){
//        int temp = 0;
//        for (j = 0; j<number; j++){
//            temp += *(short*)(sourseFile[j] + i * 2);
//        }
//        output = (int)(temp*f);
//        if (output>MAX){
//            f = (double)MAX / (double)(output);
//            output = MAX;
//        }
//        if (output<MIN){
//            f = (double)MIN / (double)(output);
//            output = MIN;
//        }
//        if (f<1){
//            f += ((double)1 - f) / (double)32;
//        }
//        *(short*)(objectFile + i * 2) = (short)output;
//    }
//}
//
//int main() {
//
//    FILE * fp1, *fp2, *fpm;
//    fp1 = fopen("out.wav", "rb");
//    fp2 = fopen("zuor.wav", "rb");
//    fpm = fopen("mix.wav", "wb");
//
//    short data1, data2, date_mix;
//    int ret1, ret2;
//    char sourseFile[10][2];
//    while (1){
//        ret1 = fread(&data1, 2, 1, fp1);
//        ret2 = fread(&data2, 2, 1, fp2);
//        *(short*)sourseFile[0] = data1;
//        *(short*)sourseFile[1] = data2;
//        if (ret1>0 && ret2>0){
//            Mix(sourseFile, 2, (char *)&date_mix);
//            /*
//            if( data1 < 0 && data2 < 0)
//            date_mix = data1+data2 - (data1 * data2 / -(pow(2,16-1)-1));
//            else
//            date_mix = data1+data2 - (data1 * data2 / (pow(2,16-1)-1));
//            */
//            if (date_mix > pow(2, 16 - 1) || date_mix < -pow(2, 16 - 1))
//                printf("mix error\n");
//        }else if ((ret1 > 0) && (ret2 == 0)){
//            date_mix = data1;
//        }else if ((ret2 > 0) && (ret1 == 0)){
//            date_mix = data2;
//        }else if ((ret1 == 0) && (ret2 == 0)){
//            break;
//        }
//        fwrite(&date_mix, 2, 1, fpm);
//    }
//    fclose(fp1);
//    fclose(fp2);
//    fclose(fpm);
//    printf("OK Done!\n");
//}
