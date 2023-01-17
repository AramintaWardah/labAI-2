#include <iostream>
#include <math.h>

using namespace std;

float a, b, c, d, x, y, Y, y2, a1, a2, miu;

void inputlinear(){
    cout << "Masukkan nilai x = ";
    cin >> x;

    cout << "Masukkan nilai a(batas bawah) = ";
    cin >> a;

    cout << "Masukkan nilai b(batas atas) = ";
    cin >> b;
}

void input_segitiga(){
    cout << "Masukkan nilai x = ";
    cin >> x;

    cout << "Masukkan nilai a(batas bawah) = ";
    cin >> a;

    cout << "Masukkan nilai b(batas tengah) = ";
    cin >> b;

    cout << "Masukkan nilai c(batas atas) = ";
    cin >> c;
}

void input_trapesium(){
    cout << "Masukkan nilai x = ";
    cin >> x;

    cout << "Masukkan nilai a(batas bawah) = ";
    cin >> a;

    cout << "Masukkan nilai b(batas tengah 1) = ";
    cin >> b;

    cout << "Masukkan nilai c(batas tengah 2) = ";
    cin >> c;

    cout << "Masukkan nilai d(batas atas) = ";
    cin >> d;
}

void input_sigmoidPertumbuhan(){
    cout << "Masukkan nilai x = ";
    cin >> x;

    //a1 = alpha
    cout << "Masukkan nilai a(batas bawah) = ";
    cin >> a1;

    //a2 = sigma
    cout << "Masukkan nilai b(batas atas) = ";
    cin>> a2;
}

void input_sigmoidPenyusutan(){
    cout << "Masukkan nilai x = ";
    cin >> x;

    //a1 = alpha
    cout << "Masukkan nilai a(batas bawah) = ";
    cin >> a1;

    //a2 = sigma
    cout << "Masukkan nilai b(batas atas) = ";
    cin>> a2;
}

void input_lonceng(){
    cout << "Masukkan nilai x = ";
    cin >> x;

    //a1 = R1
    cout << "Masukkan nilai a(batas bawah) = ";
    cin >> a1;

     //a2 = R2
    cout << "Masukkan nilai b(batas atas) = ";
    cin >> a2;
}

void linear_naik(){
    if (x<=a){
        miu = 0;
    } else if (x>=a && x<=b){
        miu =(x-a)/(b-a);
    } else{
        miu = 1;
    }
}

void linear_turun(){
    if (x<=a){
        miu = 1;
    } else if (x>=a && x<=b){
        miu =(b-x)/(b-a);
    } else {
        miu = 0;
    }
}

void segitiga(){
    if (x<=a || x >=c){
        miu = 0;
    } else if(x>=b && x <=c){
        miu =(c-x)/(c-b);
    } else if (x>=a && x<=b){
        miu =(x-a)/(b-a);
    } else {
        miu = 1;
    }
}

void trapesium(){
    if (x<=a || x >=d){
        miu = 0;
    } else if(x>=c && x <=d){
        miu =(d-x)/(d-c);
    } else if (x>=a && x<=b){
        miu =(x-a)/(b-a);
    } else {
        miu = 1;
    }
}

void sigmoid_pertumbuhan(){
    //y = beta
    y = (a2+a1)/2;
    if (x<=a1)
    {
        miu = 0;
    }else if(x>a1 && x<y){
        miu = 2*pow((x-a1)/(a2-a1),2);
    }else if(x>y && x<a2){
        miu = 1-2*pow((a2-x)/(a2-a1),2);
    }else{
        miu = 1;
    }
}
void sigmoid_penyusutan(){
    //y = beta
    y = (a2+a1)/2;
    if (x<=a1)
    {
        miu = 1;
    }else if(x>a1 && x<y){
        miu = 1-2*pow((x-a1)/(a2-a1),2);
    }else if(x>y && x<a2){
        miu = 2*pow((a2-x)/(a2-a1),2);
    }else{
        miu = 0;
    }
}

void lonceng(){
    //Y = alpha
    Y = (a1+a2)/2;
    //y = beta1
    y = (Y+a1)/2;
    //y2 = beta2
    y2 = (Y+a2)/2;

    if (x <= a1 || x >= a2){
        miu = 0;
    }else if (x>a1 && x<y){
        miu = 2*pow((x-a1)/(Y-a1),2);
    }else if (x>y && x<Y ){
        miu = 1-2*pow((Y-x)/(Y-a1),2);
    }else if (x>Y && x<y2){
        miu = 1-2*pow((x-Y)/(a2-Y),2);
    }else if(x>y2 && x<a2){
        miu = 2*pow((a2-x)/(a2-Y),2);
    }else{
        miu =1;
    }
}

int main(){
    int pilihan;
    cout << "   Araminta Wardah Zonda   " << endl;
    cout << "         203510161        " << endl;
    cout << "========== MENU ==========" << endl;
    cout << "1. Kurva Linear Naik " << endl;
    cout << "2. Kurva Linear Turun " << endl;
    cout << "3. Kurva Segitiga" << endl;
    cout << "4. Kurva Trapesium " << endl;
    cout << "5. Kurva Sigmoid Pertumbuhan " << endl;
    cout << "6. Kurva Sigmoid Penyusutan " << endl;
    cout << "7. Kurva Lonceng(Phi) " << endl << endl;


    cout << "Pilihan Anda : ";
    cin >> pilihan;

    switch(pilihan){
        case 1 :
            inputlinear();
            linear_naik();
            break;
        case 2 :
            inputlinear();
            linear_turun();
            break;
        case 3 :
            input_segitiga();
            segitiga();
            break;
        case 4 :
            input_trapesium();
            trapesium();
            break;
        case 5 :
            input_sigmoidPertumbuhan();
            sigmoid_pertumbuhan();
            break;
        case 6 :
            input_sigmoidPenyusutan();
            sigmoid_penyusutan();
            break;
        case 7 :
            input_lonceng();
            lonceng();
            break;
    }

    cout << "\nMaka nilai miu adalah = " << miu;
    return 0;
}