#ifndef DOGCONTROL_H
#define DOGCONTROL_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>

#include "dog_api.h"
#include <QString>

#define DUMP_COLS_PER_ROW     16
#define DUMP_SPACE_COLS        8

const unsigned char vendor_code[] =

        "t+8SQJkRWRO9dKx+gnFAL+iS/s7oK"
        "9heJc3zlkfN3m83mPfKF4GWTFmX+4"
        "fdMr5/XVUE4NRYeP+F4TaquLZtXmp"
        "db+NwjkmJte0A1WoU9czpeS/96wdS"
        "HGpYln3ldXSLQccrZaNpipJUI/tMl"
        "COlN6Vl5o3uJv01TwuPo2T2fMnLzj"
        "YFB6nzRgLEL3yEcWmwPld4ap3x34T"
        "F09xyeyfGeoVbyNtoc6PimyptgAo1"
        "1zXdQdE7TxMJeGnffMBAT7Oh4imAs"
        "yf2/WgmQZ/tiSUFF4eIiwEfdicAhw"
        "IS8I1hK9FEnDmk1jdsVkbcM+YL/mS"
        "N2VW4YeXTFg/BduOYg9xY+HlyjDp1"
        "laWtWzBo1mqkPuT4WZmzMgweI9iTH"
        "3T8i2K+PBB6HiCc8rAyIJv1h5cgF2"
        "wqaKeKAMVSWgGeEVxv+EcOt/por5m"
        "Fw0hiArx/6Ycm6Rccy2/NbRY2FQGp"
        "iPrCE59OZMs9vdEkUJ36pCF1Crg5o"
        "W5HazJsWQ/HpAxOSpzj8uGPiHcmBt"
        "FqOUn43CzFB/gWhHpMhOLnsK+GYGL"
        "Q+9b6aN0HQRLOVKQqHy70wN51+Xgw"
        "Gka4EW7fWLG8xDAEBTuVqWqaA+mNJ"
        "aF5rGrmykT1FSjc/kq5Mo8GvHA0Nq"
        "z9dS4ulumYVpz866U0hsph4qd1KyT"
        "2Mqjml0HRNFXcCduw3nQAo+e20Y4U"
        "kh03//5pOes1qVqxwb/6SxcB0EmQm"
        "C5FRVGn6Uk/UwSEbhsZM5Rh/pzryH"
        "fOpzQt0Iec0ykEzoGpMCpJfqUjOgD"
        "xj51aP5BQDkemzCPl1Ct9zQz+MFNv"
        "lCftfOUWDGO3W7w16n0Y5ogrnH8a0"
        "sT6ZlR+Pojo3kP/p2GQxaPQkxJxcU"
        "aZg35OlRoWPpqxwkT/SCNOSCuOOEQ"
        "EW8rju3GjG3RD+tCL/fiRPz74QKwC"
        "6yFnlc7CZxcGODFKqlRKfDquJy9ue"
        "BAc/h3ZBZJ9iaN7hs9rRw6xIA==";

//WKE FactoryView 2014
#define ENCRYPT_BUFFER_FEATUREID1 1    //feature id which is selected
#define SOURCE_BUFFER_LENGTH1 20    //length of source string
#define ENCRYPT_BUFFER_LENGTH1 20    //length of encrypt string

const int isString1 = 1;    //This is a string buffer
/*The encrypted array is in UTF-8 format. Please convert it to proper format before using it.*/

const unsigned char encryptStrArr1[20] = {
    0x54, 0x76, 0x04, 0xA9, 0x57, 0x08, 0xA9, 0x71, 0x71, 0xDE, 0x77, 0xC5, 0x18, 0xC5, 0x6D, 0x45, 0x26, 0x0B, 0x46, 0xF3
 };

typedef __int32 ENCRYPT_DATA_TYPE1;
#define SAFE_FREE(p) { if(p) { free(p); (p) = NULL; } }
dog_status_t CheckKey();
dog_status_t DecryptConst();
dog_status_t DecryptString(QString &retString);
ENCRYPT_DATA_TYPE1 getConstValue(unsigned char *bufdata);
void getStringValue(unsigned char *bufData);
void dump(unsigned char *data, unsigned int datalen, char *margin);
void dump_ascii(unsigned char *data, unsigned int datalen, char *margin);
void dump_hex(unsigned char *data, unsigned int datalen, char *margin);
bool getProductName(QString & strRet);

#endif // DOGCONTROL_H
