#include <iostream>
#include <math.h>

using namespace std;

float x, y, z, z1, z2, z3, z4, def_z, a_pre1, a_pre2, a_pre3, a_pre4;

void inputan(){
    cout << "Masukkan permintaan = ";
    cin >> x;

    cout << "Masukkan persediaan = ";
    cin >> y;
}

//TAHAP FUZZYFICATION
float permintaanNaik(float x){
    float miu;
    if (x <= 1000){
        miu = 0;
    } else if (x >= 1000 && x <= 5000){
        miu =(x - 1000) / (4000);
    } else {
        miu = 1;
    }
    return miu;
}

float permintaanTurun(float x){
    float miu;
    if (x <= 1000){
        miu = 1;
    } else if (x>=1000 && x<=5000){
        miu =(5000 - x) / (4000);
    } else{
        miu = 0;
    }
    return miu;
}

float persediaanBanyak(float y){
    float miu;
    if (y <= 100){
        miu = 0;
    } else if (y > 100 && y < 600){
        miu = (y - 100)/(500);
    } else {
        miu = 1;
    }
    return miu;
}

float persediaanSedikit(float y){
    float miu;
    if (y <= 100){
        miu = 1;
    } else if (y > 100 && y < 600){
        miu =(600 - y) / (500);
    } else {
        miu = 0;
    }
    return miu;
}

//TAHAP INFERENCE
float inference(){
    cout << "   [R1] IF Permintaan TURUN And Persediaan BANYAK THEN Produksi Barang BERKURANG" << endl;
    a_pre1 = min(permintaanTurun(x), persediaanBanyak(y));
    cout << "   a-prediket1 = " << a_pre1 << endl;
    z1 = (8000) - (6000 * a_pre1);
    cout << "   Z1 = " << z1 << endl << endl;

    cout << "   [R2] IF Permintaan TURUN And Persediaan SEDIKIT THEN Produksi Barang BERKURANG" << endl;
    a_pre2 = min(permintaanTurun(x), persediaanSedikit(y));
    cout << "   a-prediket2 = " << a_pre2 << endl;
    z2 = 8000 - (6000 * a_pre2);
    cout << "   Z2 = " << z2 << endl << endl;

    cout << "   [R3] IF Permintaan NAIK And Persediaan BANYAK THEN Produksi Barang BERTAMBAH" << endl;
    a_pre3 = min(permintaanNaik(x), persediaanBanyak(y));
    cout << "   a-prediket3 = " << a_pre3 << endl;
    z3 = (2000) + (6000 * a_pre3);
    cout << "   Z3 = " << z3 << endl << endl;

    cout << "   [R4] IF Permintaan NAIK And Persediaan SEDIKIT THEN Produksi Barang BERTAMBAH" << endl;
    a_pre4 = min(permintaanNaik(x), persediaanSedikit(y));
    cout << "   a-prediket4 = " << a_pre4 << endl;
    z4 = (2000) + (6000 * a_pre4);
    cout << "   Z4 = " << z4 << endl << endl;

    return a_pre1;
    return a_pre2;
    return a_pre3;
    return a_pre4;
}

int main(){

    inputan();
    cout << endl << endl;
    cout << "1. TAHAP FUZZYFICATION" << endl;
    cout << "   MIU Permintaan Naik = " << permintaanNaik(x) << endl;
    cout << "   MIU Permintaan Turun = " << permintaanTurun(x) << endl;
    cout << "   MIU Persediaan Banyak = " << persediaanBanyak(y) << endl;
    cout << "   MIU Persediaan Sedikit = " << persediaanSedikit(y) << endl;
    cout << endl << endl;

    cout << "2. TAHAP INFERENCE" << endl;
    inference();
    cout << endl;

    cout << "3. TAHAP DEFUZZIFICATION" << endl;
    //TAHAP DEFUZZIFICATION
    z = ((a_pre1 * z1)+(a_pre2 * z2)+(a_pre3 * z3)+(a_pre4 * z4)) / (a_pre1 + a_pre2 + a_pre3 + a_pre4);
    cout << "   z* = " << z << endl << endl;
    def_z = round(z);
    cout << "   Jadi jumlah kemasan makanan jenis ABC yang harus diproduksi sebanyak " << def_z << endl;

    return 0;
}