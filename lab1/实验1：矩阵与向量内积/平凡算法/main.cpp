#include<iostream>
#include<Windows.h>
#include<stdlib.h>
using namespace std;
const int N =10001;
double b[N][N],sum[N];
double a[N];
void init(int n) {
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        b[i][j]=i+j;
    for (int i = 0; i < n; i++)
        a[i] = i + 1;
}
int main() {
    long long head, tail, freq;
    init(N);
    QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
    int step = 10;
       for (int n = 20; n < N; n += step) {
        int counter = 0;
        double total_time = 0.0;
        QueryPerformanceCounter((LARGE_INTEGER*)&head);
        while (total_time < 1.0) { // �ۼ�ʱ�䳬��1�뼴�ɹ۲����
            counter++;
            for (int i = 0; i < n; i++) {
                sum[i] = 0.0;
                for (int j = 0; j < n; j++) {
                    sum[i] += b[j][i] * a[j];
                }
            }
            QueryPerformanceCounter((LARGE_INTEGER*)&tail);
            // ���㵱ǰִ��ʱ�䲢�ۼ�
            total_time = (tail - head) * 1.0 / freq;//�����¾�����Ӱ��
        }
        cout << n << ' ' << counter << ' ' << total_time << ' ' <<total_time/counter*1000<<endl;
        if (n == 100) step = 100;
        if (n == 1000)step = 1000;
    }
    return 0;
}
