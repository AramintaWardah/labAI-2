#include <iostream>
using namespace std;

int main()
{
    int n, nx, i, j, out, db, fx;
    float th;
    int ak, akurasi = 0;
    char pilihan;
    cout << "Masukkan Banyak Data\t: ";
    cin >> n;
    cout << "Input Banyak x\t\t: ";
    cin >> nx;
    cout << "Masukkan Treshold\t: ";
    cin >> th;

    int dw[nx], w[nx], x[n][nx], t[nx];

    for (i = 0; i < nx; i++){
        w[i] = 0;
        dw[i] = 0;
    }

    cout << endl;

    // Tahap Input
    for (i = 0; i < n; i++){
        for (j = 0; j < nx; j++){
            cout << "Input X" << j + 1 << " Data Ke-" << i + 1 << "\t= ";
            cin >> x[i][j];
        }
        cout << "Input T Data Ke-" << i + 1 << "\t= ";
        cin >> t[i];
        cout << endl;
    }

    // Tahap Learning
    int a = 1, epoch = 1, b = 0;
    while (akurasi != 1){
        cout << "\n                                       epoch ke -" << epoch << endl;
        cout << "===========================================================================================" << endl;
        for (i = 0; i < nx; i++){
            cout << "x" << i+1 <<"\t";
        }
        cout << "T\t";
        cout << "f(x)\t";
        cout << "Y\t";
        cout << "akurasi\t";
        for (i = 0; i < nx; i++){
            cout << "w" << i+1 << "\t";
        }
        cout << "b";
        cout << endl;
        for (i = 0; i < n; i++){
            for (j = 0; j < nx; j++){
                cout << x[i][j]<<"\t";
            }
            cout << t[i]<<"\t";
            fx = 0;
            for (j = 0; j < nx; j++){
                fx = fx + (w[j] * x[i][j]);
            }
            fx = fx + b;
            cout << fx << "\t";

            out = 0;
            if (fx > th){
                out = 1;
            }
            else if (fx < th * -1){
                out = -1;
            }
            else
                out = 0;
            if(out == t[i]){
                ak = 1;
            } else {
                ak = 0;
            }
            cout << out << "\t";
            cout << ak << "\t";
            if (ak == 0){
                for (j = 0; j < nx; j++){
                    dw[j] = a * x[i][j] * t[i];
                }
                db = a * t[i];
                for (j = 0; j < nx; j++){
                    w[j] = w[j] + dw[j];
                }
                b = b + db;
            } else {
                akurasi++;
            }
            for (j = 0; j < nx; j++){
                cout << w[j] << "\t";
            }
            cout << b << "\t";
            cout << endl;
        }
        akurasi = akurasi / n;
        epoch++;
    }

    //Tahap Testing
    start:
    cout << endl << endl;
    cout << "===== Algoritma Testing =====" << endl;

        for (i = 0; i < nx; i++){
            cout << "w" << i+1 << " = " << w[i] << endl;
        }
        cout << "B = " << b << endl;

        int tx[nx];
        for (i = 0; i < nx; i++){
            cout << "Input x" << i+1 << " = "; cin >> tx[i];
        }
        fx=0;

        for (i = 0; i < nx; i++){
            fx = fx + (w[i] * tx[i]);
        }
        fx = fx + b;

        cout << endl;
        cout << "=== Hasil Algoritma Testing ===" << endl;
        cout << "f(x) = " << fx << endl;

            if (fx > th){
                out = 1;
            }
            else if (fx < th * -1){
                out = -1;
            }
            else
                out = 0;

        cout << "Y = " << out << endl;

        cout << "\nUlang [y/n] = ";
        cin >> pilihan;

        if(pilihan=='Y' || pilihan=='y'){
            goto start;
        } if(pilihan=='N' || pilihan=='n'){
                goto finish;
        }

    finish :
        cout << endl;
        cout << "------------Selesai------------";

}
